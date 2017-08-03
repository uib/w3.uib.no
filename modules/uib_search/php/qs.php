<?php
/*
* This file bootstrap drupal to include variables, and then run the query
* against elastic search.
*/

define(
  'DRUPAL_ROOT',
  dirname(dirname(dirname(__DIR__))) . DIRECTORY_SEPARATOR . 'drupal'
);
require_once( dirname(dirname(dirname(__DIR__))) . "/drupal/includes/bootstrap.inc");
require_once( dirname(dirname(dirname(__DIR__))) . "/drupal/includes/common.inc");
drupal_bootstrap(DRUPAL_BOOTSTRAP_VARIABLES);
require_once(dirname(__DIR__) . DIRECTORY_SEPARATOR . "uib_search.module");
$url = rtrim(uib_search__get_setup('url'), '/');
$url .= '/' .uib_search__get_setup('index');
$url .= '/_search';
$data = uib_search__create_query();
$result = uib_search__run_elastic_request($url, json_encode($data), 'GET', FALSE, 5);
drupal_json_output();
$qstr = '"querynum":' . intval($_REQUEST['querynum']) . ',';
$result->data = preg_replace('/\{/', '{' . $qstr, $result->data, 1);
print $result->data;
