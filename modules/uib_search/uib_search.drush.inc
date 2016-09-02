<?php

function uib_search_drush_command() {
  $items['uib-search-user'] = array(
    'description' => 'Retrieve a user object as it will be inserted into '
      . 'the elastic search index. Options --index and --drop are mutually '
      . 'exclusive.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array('identificator' => 'Either UID or username of the user'),
    'required-arguments' => true,
    'options' => array(
      'index' => 'Also index this user',
      'drop' => 'Drop the user from elastic index',
    ),
  );
  $items['uib-search-node'] = array(
    'description' => 'Retrieve a node as it will be inserted into '
      . 'the elastic search index. Options --index and --drop are mutually '
      . 'exclusive.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array('nid' => 'Node id of the node'),
    'required-arguments' => true,
    'options' => array(
      'index' => 'Also index this node',
      'drop' => 'Drop the node from elastic index',
    ),
  );
  $items['uib-search'] = array(
    'description' => 'Do a search in the elasticsearch database and prettyprint the results.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array('query' => 'The search query'),
    'required-arguments' => FALSE,
    'options' => array(
      'size=s' => 'Number of results to return',
      'json' => 'Show the raw json result',
      ),
  );
  $items['uib-search-drop-index'] = array(
    'description' => 'Drop the current elastic index. The index will be '
      . 'recreated when new content is added. If the readonly index and the '
      . 'admin index are different, it is the admin index that will be dropped.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  $items['uib-search-index'] = array(
    'description' => 'Index entities in the database to the elastic '
      . 'search database. Currently supports users and nodes.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'aliases' => array(),
    'arguments' => array('type' => 'Entity type node / user. Defaults to user'),
    'options' => array(
      'stop=n' => 'Stop after n iterations. Defaults to 10.',
    ),
  );
  $items['uib-search-url'] = array(
    'description' => 'Print URL that can be used to access the elastic server.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'options' => array(
      'admin' => 'Return URL that gives you admin access',
    ),
  );
  return $items;
}

function drush_uib_search_user($identificator) {
  print json_encode(uib_search__search_any('user', $identificator), JSON_PRETTY_PRINT) . "\n";
}

function drush_uib_search_node($nid) {
  print json_encode(uib_search__search_any('node', $nid), JSON_PRETTY_PRINT) . "\n";
}

function uib_search__search_any($type, $id){
  $id = trim($id);
  $e = FALSE;
  switch ($type) {
    case 'user':
      if (is_numeric($id)) {
        $e = user_load($id);
      }
      else {
        $e = user_load_by_name($id);
      }
      break;
    case 'node':
      $e = node_load($id);
      break;
  }
  if (!$e) {
    uibx_log("Entity $type with id $id not found", 'notice');
    return NULL;
  }
  $entity = entity_metadata_wrapper($type, $e);
  if (drush_get_option('index')) {
    $output = uib_search__index_entity($entity);
  }
  else if (drush_get_option('drop')) {
    $output = uib_search__index_entity($entity, TRUE);
  }
  else {
    $output = uib_search__get_elastic_entity_array($entity);
  }
  return $output;
}

function drush_uib_search() {
  $query = implode(' ', func_get_args());

  $px = uib_search__parameter_prefix();
  $url = variable_get($px . 'url') . '/' . variable_get($px . 'index')
    . '/_search?';
  if (drush_get_option('json')) {
    $url .= '&pretty';
  }

  if (!$query) {
    $q = array(
      'query' => array(
        'wildcard' => array('generic.title' => '*')
      ),
    );
  }
  else {
    $q = array(
      'query' => array(
        'match' => array('_all' => $query)
      ),
    );
  }
  if (drush_get_option('size')){
    $q['size'] = intval(drush_get_option('size'));
  }

  $result = uib_search__run_elastic_request($url, json_encode($q), 'GET');
  if (drush_get_option('json')) {
    echo $result->data;
    return;
  }

  $result = drupal_json_decode($result->data);
  $hits = $result['hits'];
  $total = $hits['total'];
  foreach ($hits['hits'] as $hit) {
    $hit = $hit['_source'];
    printf("%-50s  %-30s\n", $hit['generic']['title'], $hit['generic']['link']);
    $desc = explode("\n", trim($hit['generic']['excerpt']));
    $desc = substr($desc[0], 0, 80);
    printf("%-80s\n", $desc);
    echo str_repeat('-', 80) . "\n";
  }
  if ($total) {
    print "*** $total hits\n";
  }
  else {
    print "*** No hits\n";
  }
}

function drush_uib_search_drop_index() {
  $px = uib_search__parameter_prefix(1);
  $url = variable_get($px . 'url') . '/' . variable_get($px . 'index') . '/';
  $stat = uib_search__run_elastic_request($url, null, 'DELETE', 5);
  if ($stat->code == 200) {
    echo "Elastic index dropped successfully\n";
  }
  else {
    uibx_log(
      'Failed to delete <' . $url .
      '>: ' . $stat->code . ' ' . $stat->status_message . '.',
      'error'
    );
  }
}


function drush_uib_search_index($type = 'user') {
  if (!uib_search__check_elastic_settings(1)) {
    uibx_log("Elasticsearch is not setup. Please consult the " .
    "documentation.", 'error');
    return;
  }

  $stop = drush_get_option('stop', 10);
  $last_processed_key = "uib_search_last_processed_{$type}";
  $last_processed_id = variable_get($last_processed_key, 0);
  $verbose = drush_get_option('verbose');

  switch ($type) {
    case 'user':
      $table = 'users';
      $id_key = 'uid';
      break;
    case 'node':
      $table = 'node';
      $id_key = 'nid';
      break;
    default:
      uibx_log("Indexing type {$type} is not implemented. Only type user and node is " .
      "available.", 'error');
      return;
  }

  $query = "SELECT max(a.{$id_key}) maxid FROM {$table} a WHERE a.status = 1";
  $result = db_query($query)->fetch();
  $maxid = $result->maxid;
  if ($last_processed_id == $maxid) {
    if ($verbose) {
      uibx_log("All {$type}s have been processed", 'notice');
    }
    return;
  }


  $select = db_select($table, 'a');
  $select->addField('a', $id_key);
  $select->condition('a.status', 1);
  $select->condition("a.{$id_key}", $last_processed_id, '>' );
  $select->orderBy("a.{$id_key}");
  $select->range(NULL, $stop);
  if ($type == 'node') {
    $ignore = variable_get('uib_search_nodetype_noindex', array());
    $select->condition('type', $ignore, 'not in');
  }
  $result = $select->execute();

  $rowcount = $result->rowCount();

  $prefix = uib_search__parameter_prefix(1);
  $index = variable_get($prefix.'index');
  $url = variable_get($prefix.'url');
  $url="{$url}/{$index}/_bulk";

  $batch = '';
  $line = 0;
  $action = 'index';
  foreach ($result as $key => $value) {
    if ($stop && $line >= $stop) {
      break;
    }
    $line++;
    if ($value->$id_key == $maxid) {
      variable_set($last_processed_key, 9E8); // high number
    }
    else {
      variable_set($last_processed_key, $value->$id_key);
    }
    $batch .= '{ "'.$action.'" : { "_index" : "' . $index . '", '
      . '"_type" : "' . $type
      . '", "_id" : "' . $value->$id_key . '" } }'."\n";
    $loader = $type . '_load'; // node_load or user_load
    $entity = entity_metadata_wrapper($type, $loader($value->$id_key));
    $batch .= json_encode(uib_search__get_elastic_entity_array($entity))."\n";
    if ($line % 50 == 0) {
      $stat = uib_search__run_elastic_request($url, $batch, 'PUT', true, 10);
      if ($stat->code != 200) {
        uibx_log("$stat->code $stat->status_message", 'error');
      }
      $batch = '';
      if ($verbose && $line % 500 == 0) {
        uibx_log(sprintf('%d %ss updated (%.0f%% done)', $line, $type, 100 * $line / $rowcount), 'notice');
      }
    }
  }
  if ($batch) {
    $stat = uib_search__run_elastic_request($url, $batch, 'PUT', true, 10);
    if ($stat->code != 200) {
      uibx_log("$stat->code $stat->status_message", 'error');
    }
  }

  $remaining = db_query("SELECT count(*) FROM {node} WHERE nid > :last", array(':last' => variable_get($last_processed_key, 0)))->fetchField();
  print("Updated $rowcount ${type}s; $remaining remaining.\n");
}



function drush_uib_search_url() {
  $px = uib_search__parameter_prefix(drush_get_option('admin'));
  $url = variable_get($px . 'url') . '/' . variable_get($px . 'index') . '/';
  if (substr($url, 0, 8) == 'https://') {
    $url = substr($url, 0, 8) . variable_get($px . 'user') . ':' . variable_get($px . 'password') . '@' . substr($url, 8);
  }
  return $url;
}
