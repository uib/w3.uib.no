<?php
/**
 * @file
 * uib_external.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_external_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function uib_external_node_info() {
  $items = array(
    'uib_external_content' => array(
      'name' => t('External content'),
      'base' => 'node_content',
      'description' => t('Enable you to reference external URL/pages from an article.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
