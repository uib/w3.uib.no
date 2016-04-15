<?php
/**
 * @file
 * uib_geography.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_geography_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
