<?php
/**
 * @file
 * uib_area.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function uib_area_taxonomy_default_vocabularies() {
  return array(
    'uib_organisation' => array(
      'name' => 'uib_organisation',
      'machine_name' => 'uib_organisation',
      'description' => 'Hierarchical taxonomy of uib faculties, institutes, and units - related to the content types uib_ou and area.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
