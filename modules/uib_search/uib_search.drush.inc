<?php

function uib_search_drush_command() {
  $items['uib-search-study'] = array(
    'description' => 'Retrieve a study object as it will be inserted into '
      . 'the elastic search index. Options --index and --drop are mutually '
      . 'exclusive.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array('study_code' => 'Study code'),
    'required-arguments' => true,
    'options' => array(
      'index' => 'Also index this study object',
      'drop' => 'Drop the study object from elastic index',
    ),
  );
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
  $items['uib-search-setup'] = array(
    'description' => 'Setup elastic search. By default setup mapping found in '
    . 'the file uib_search/elastic/mapping.json. Alternative file can be given '
    . 'as optional argument.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array('file' => 'Alternative json file'),
    'required-arguments' => FALSE,
    'options' => array(
      'drop' => 'Drop the current index.',
      'show' => 'Show current mapping and exit.',
    ),
  );
  $items['uib-search-index'] = array(
    'description' => 'Index entities in the database to the elastic '
      . 'search database. Currently supports users and nodes.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'aliases' => array(),
    'arguments' => array('type' => 'Entity type node, user or study. Defaults '
    . 'to user. The study - option will simply index nodes of type uib_study.'),
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
function drush_uib_search_study($study_code) {
  $nid = uib_study__nid_from_study_code($study_code);
  if (!$nid) {
    uibx_log('No such study code: ' . $study_code);
    return;
  }
  $output = uib_search__search_any('study', $nid);
  if ($output) {
    print json_encode($output, JSON_PRETTY_PRINT). "\n";
  }
}

function uib_search__search_any($type, $id){
  $id = trim($id);
  $e = FALSE;
  $study = $type == 'study';
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
    case 'study':
      $type = 'node';
      $e = node_load($id);
      break;
  }
  if (!$e) {
    uibx_log("Entity $type with id $id not found", 'notice');
    return NULL;
  }
  $drop = drush_get_option('drop');
  if ($e->status == 0 && !$drop) {
    uibx_log("Entity $type with id $id is not published", 'notice');
    return NULL;
  }

  $entity = entity_metadata_wrapper($type, $e);
  if (drush_get_option('index')) {
    if ($study) {
      $output = uib_search__index_study($entity);
    }
    else {
      $output = uib_search__index_entity($entity);
    }
  }
  else if ($drop) {
    $output = uib_search__index_entity($entity, TRUE);
  }
  else {
    $output = uib_search__get_elastic_entity_array($entity);
    if ($study) {
      $fs = uib_search__get_elastic_study_array($entity);
      $output = uib_search__merge_study_arrays($output, $fs);
    }
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
        'match_all' => new stdClass()
      )
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
    if (isset($hit['_source']['generic'])) {
      $output = $hit['_source']['generic'];
      $output['title'] = $hit['_id'] . ': ' . $output['title'];
    }
    else {
      $output = array(
        'title' => "TYPE: {$hit['_type']}  ID: {$hit['_id']}  JSON:",
        'link' => '',
        'excerpt' => json_encode($hit['_source']),
      );
    }
    $hit = $hit['_source'];
    printf("%-50s  %-30s\n", substr($output['title'], 0, 50), $output['link']);
    $desc = explode("\n", trim($output['excerpt']));
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
    case 'study':
      $table = 'node';
      $id_key = 'nid';
      break;
    default:
      uibx_log("Type {$type} is not implemented. Only type user and node is " .
      "available.", 'error');
      return;
  }

  $query = "SELECT max(a.{$id_key}) maxid FROM {$table} a WHERE a.status = 1";
  if ($type == 'study') {
    $query .= " AND a.type = 'uib_study'";
  }
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
  if ($type == 'study') {
    $select->condition('a.type', 'uib_study');
  }

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
    $ntype = $type == 'study' ? 'node' : $type;
    $batch .= '{ "'.$action.'" : { "_index" : "' . $index . '", '
      . '"_type" : "' . $type
      . '", "_id" : "' . $value->$id_key . '" } }'."\n";
    $entity = entity_metadata_wrapper(
      $ntype,
      current(entity_load($ntype, array($value->$id_key)))
    );
    $nodearray = uib_search__get_elastic_entity_array($entity);
    $sarr = uib_search__get_elastic_study_array($entity);
    if($sarr && count($sarr)) {
      $nodearray = uib_search__merge_study_arrays($nodearray, $sarr);
    }
    $batch .= json_encode($nodearray)."\n";
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

  $remaining = db_query(
    "SELECT count(*) FROM {node} WHERE nid > :last" .
      ($type == 'study' ? " AND type='uib_study'" : ""),
    array(':last' => variable_get($last_processed_key, 0))
  )->fetchField();
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

/**
 * Setup and display current mapping in elastic.
 */
function drush_uib_search_setup() {
  $prefix = uib_search__parameter_prefix(1);
  $index = variable_get($prefix.'index');
  $url = variable_get($prefix.'url');
  $url="{$url}/{$index}/";
  $args = func_get_args();
  if (drush_get_option('show')) {
    $url .= '_mapping';
    $url .= (count($args) ? '/' . $args[0] : '');
    $url .= '?pretty';
    $stat = uib_search__run_elastic_request($url, "", 'GET', TRUE);
    echo $stat->data;
    return;
  }
  $file = current($args);
  if (!$file) {
    $file = __DIR__ . '/elastic/mapping.json';
  }
  if (!file_exists($file)) {
    if (!file_exists( '../' . $file)) {
      echo '../' . $file;
      uibx_log('No such file ' . $file);
      return;
    }
    $file = '../' . $file;
  }
  if (drush_get_option('drop')) {
    drush_uib_search_drop_index();
  }

  $mapping = file_get_contents($file);
  $stat = uib_search__run_elastic_request($url, $mapping, 'POST', TRUE);
  if ($stat->code == 200) {
    uibx_log("File {$file} imported without errors");
  }
  else {
    print_r(json_encode($stat, JSON_PRETTY_PRINT));
  }
}
