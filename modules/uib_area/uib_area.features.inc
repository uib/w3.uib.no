<?php

/**
 * @file
 * uib_area.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_area_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function uib_area_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function uib_area_node_info() {
  $items = array(
    'area' => array(
      'name' => t('Area'),
      'base' => 'node_content',
      'description' => t('The site is divided into areas.  All content belongs to areas.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'uib_ou' => array(
      'name' => t('Organisational Unit'),
      'base' => 'node_content',
      'description' => t('Organisational Units matches the places as defined by PAGA and Sebra.  Places are idenitifed by a 6-digit place ID. These nodes and their fields are automatically updated from Sebra.

All areas belong to a single organisational unit.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
