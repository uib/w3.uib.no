<?php
/**
 * @file
 * uib_market.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_market_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function uib_market_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function uib_market_node_info() {
  $items = array(
    'uib_market' => array(
      'name' => t('UiB internal market notice'),
      'base' => 'node_content',
      'description' => t('Advertise apartments or residences for rent or wanted'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
