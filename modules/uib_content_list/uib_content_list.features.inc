<?php
/**
 * @file
 * uib_content_list.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_content_list_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function uib_content_list_node_info() {
  $items = array(
    'uib_content_list' => array(
      'name' => t('Content list'),
      'base' => 'node_content',
      'description' => t('A content list makes it possible to create a sequence of content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
