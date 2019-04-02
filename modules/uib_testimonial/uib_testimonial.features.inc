<?php

/**
 * @file
 * uib_testimonial.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_testimonial_ctools_plugin_api($module = NULL, $api = NULL) {
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
function uib_testimonial_node_info() {
  $items = array(
    'uib_testimonial' => array(
      'name' => t('Testimonial'),
      'base' => 'node_content',
      'description' => t('Testimonials from former and current students or researchers shows what it is like to be a part of UiB and maybe how their time at UiB helped them get the job they wanted. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
