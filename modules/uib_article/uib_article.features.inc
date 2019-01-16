<?php

/**
 * @file
 * uib_article.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_article_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function uib_article_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function uib_article_node_info() {
  $items = array(
    'uib_article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Articles is the main content type.  We use it for news, events and pages.  Articles belong to areas.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
