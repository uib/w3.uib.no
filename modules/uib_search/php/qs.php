<?php
/*
* This file bootstrap drupal to include variables, and then run the query
* against elastic search.
*/

$drupal_root = dirname(dirname(dirname(__DIR__))) . '/drupal';
if (!is_dir($drupal_root)) $drupal_root = '/var/www/html';
define('DRUPAL_ROOT', $drupal_root);
require_once( DRUPAL_ROOT . "/includes/bootstrap.inc");
require_once( DRUPAL_ROOT . "/includes/common.inc");
drupal_bootstrap(DRUPAL_BOOTSTRAP_VARIABLES);
require_once(dirname(__DIR__) . DIRECTORY_SEPARATOR . "uib_search.module");
$url = variable_get('uib_elasticsearch_url', 'https://api.search.uib.no:443');
$url .= '/' . uib_search__get_index();
$url .= '/_search';
$data = uib_search__create_query();
$result = uib_search__run_elastic_request($url, json_encode($data), 'GET', FALSE, 5);
drupal_json_output();
$qstr = '"querynum":' . intval($_REQUEST['querynum']) . ',';
$result->data = preg_replace('/\{/', '{' . $qstr, $result->data, 1);
print $result->data;
