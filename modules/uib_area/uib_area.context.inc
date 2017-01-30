<?php
/**
 * @file
 * uib_area.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uib_area_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'ansattside_blocks';
  $context->description = 'Blocks that are unique to employee pages';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'foransatte' => 'foransatte',
        'foransatte/*' => 'foransatte/*',
        'en/foremployees' => 'en/foremployees',
        'en/foremployees/*' => 'en/foremployees/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks that are unique to employee pages');
  t('block');
  $export['ansattside_blocks'] = $context;

  return $export;
}
