<?php
/**
 * @file
 * uib_calendar2.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_calendar2_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}
