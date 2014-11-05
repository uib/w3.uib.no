<?php
/**
 * @file
 * uib_geography.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function uib_geography_taxonomy_default_vocabularies() {
  return array(
    'uib_geography' => array(
      'name' => 'uib_geography',
      'machine_name' => 'uib_geography',
      'description' => 'Continents and iso 3166 countries imported from FS  ',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
