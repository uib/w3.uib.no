<?php
/**
 * @file
 * uib_message.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function uib_message_taxonomy_default_vocabularies() {
  return array(
    'uib_message_tag' => array(
      'name' => 'uib_message_tag',
      'machine_name' => 'uib_message_tag',
      'description' => 'Channel list for messageservice',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
