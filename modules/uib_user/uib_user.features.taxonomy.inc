<?php
/**
 * @file
 * uib_user.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function uib_user_taxonomy_default_vocabularies() {
  return array(
    'uib_research_fields' => array(
      'name' => 'uib_research_fields',
      'machine_name' => 'uib_research_fields',
      'description' => 'Fields of research',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
