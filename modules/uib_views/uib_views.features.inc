<?php
/**
 * @file
 * uib_views.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_views_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function uib_views_node_info() {
  $items = array(
    'uib_views_page' => array(
      'name' => t('Views page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
