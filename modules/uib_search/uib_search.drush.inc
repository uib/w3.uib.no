<?php

function uib_search_drush_command() {
  $items['uib-search-user'] = array(
    'description' => 'Retrieve a flat user object as it will be inserted into the elastic search index.',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array('identificator' => 'Either UID or username of the user'),
    'required-arguments' => true,
    'options' => array(
      'index' => 'Also index this user',
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
  return $items;
}

function drush_uib_search_user($identificator) {
  $identificator = trim($identificator);
  if (is_numeric($identificator)){
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
