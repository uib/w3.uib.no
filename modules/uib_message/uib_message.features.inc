<?php
/**
 * @file
 * uib_message.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_message_ctools_plugin_api($module = NULL, $api = NULL) {
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
function uib_message_node_info() {
  $items = array(
    'uib_message' => array(
      'name' => t('Message'),
      'base' => 'node_content',
      'description' => t('Service for providing short specific messages to users'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
