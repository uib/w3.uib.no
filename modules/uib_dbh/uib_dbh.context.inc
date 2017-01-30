<?php
/**
 * @file
 * uib_dbh.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uib_dbh_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'aboutpage_blocks';
  $context->description = 'Blocks that are unique to the about page';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'om' => 'om',
        'about' => 'about',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks that are unique to the about page');
  t('block');
  $export['aboutpage_blocks'] = $context;

  return $export;
}
