<?php

function uib_search_drush_command() {
  $items['uib-search-user'] = array(
    'description' => 'Retrieve a flat user object as it will be inserted into '
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
  $items['uib-search'] = array(
    'description' => 'Do a search in the elasticsearch database and prettyprint the results.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array('query' => 'The search query'),
    'required-arguments' => true,
    'options' => array(
      'no-pretty' => 'Do not pretty-print the results',
      'size=s' => 'Number of results to return',
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
    'description' => 'Index all users in the database to the elastic '
      . 'search database',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'aliases' => array(),
    'arguments' => array(),
    'options' => array(
      'stop=n' => 'Stop after n iterations',
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
  $identificator = trim($identificator);
  if (is_numeric($identificator)) {
    $account = user_load($identificator);
  }
  else {
    $account = user_load_by_name($identificator);
  }
  if (!$account) {
    print "No user identified by '$identificator'\n";
    return;
  }
  if (drush_get_option('index')) {
    uib_search__index_user($account);
  }
  else if (drush_get_option('drop')) {
    $account->status = 0;
    uib_search__index_user($account);
    echo "Dropped user {$account->name}\n";
    return;
  }
  print_r(uib_search__get_elastic_user_array($account));
}

function drush_uib_search() {
  $query = implode(' ', func_get_args());
  $px = uib_search__parameter_prefix();
  $url = variable_get($px . 'url') . '/' . variable_get($px . 'index')
    . '/_search?';
  if(!drush_get_option('no-pretty')){
    $url .= '&pretty';
  }

  $q = array(
    'query' => array(
      'match' => array('_all' => $query)
    ),
  );
  if (drush_get_option('size')){
    $q['size'] = intval(drush_get_option('size'));
  }

  $result = uib_search__run_elastic_request($url, json_encode($q), 'GET');
  echo $result->data;
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

function drush_uib_search_index(){
  if (!uib_search__check_elastic_settings(1)) {
    return;
  }

  $stop = drush_get_option('stop');
  $verbose = drush_get_option('verbose');

  $select = db_select('users', 'u');
  $select->addField('u', 'uid');
  $select->condition('u.status', 1);
  $result = $select->execute();

  $rowcount = $stop ?: $result->rowCount();

  $prefix = uib_search__parameter_prefix(1);
  $index = variable_get($prefix.'index');
  $type = 'user';
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
    $batch .= '{ "'.$action.'" : { "_index" : "' . $index . '", '
      . '"_type" : "' . $type
      . '", "_id" : "' . $value->uid . '" } }'."\n";
    $account = user_load($value->uid);
    $batch .= json_encode(uib_search__get_elastic_user_array($account))."\n";
    if ($line % 50 == 0) {
      $stat = uib_search__run_elastic_request($url, $batch, 'PUT', true, 10);
      if ($stat->code != 200) {
        uibx_log("$stat->code $stat->status_message", 'error');
      }
      $batch = '';
      if ($verbose && $line % 500 == 0) {
        uibx_log(sprintf('%d users updated (%.0f%% done)', $line, 100 * $line / $rowcount), 'notice');
      }
    }
  }
  if ($batch) {
    $stat = uib_search__run_elastic_request($url, $batch, 'PUT', true, 10);
    if ($stat->code != 200) {
      uibx_log("$stat->code $stat->status_message", 'error');
    }
  }
  if ($verbose) {
    uibx_log("$line users updated", 'notice');
  }
}

function drush_uib_search_url() {
  $px = uib_search__parameter_prefix(drush_get_option('admin'));
  $url = variable_get($px . 'url') . '/' . variable_get($px . 'index') . '/';
  if (substr($url, 0, 8) == 'https://') {
    $url = substr($url, 0, 8) . variable_get($px . 'user') . ':' . variable_get($px . 'password') . '@' . substr($url, 8);
  }
  return $url;
}
