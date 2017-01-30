<?php
/**
 * @file
 * uib_ansatte.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uib_ansatte_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'persons';
  $context->description = '';
  $context->tag = 'block';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'ansatte:page_1' => 'ansatte:page_1',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('block');
  $export['persons'] = $context;

  return $export;
}
