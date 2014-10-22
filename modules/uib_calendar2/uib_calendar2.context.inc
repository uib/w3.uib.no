<?php
/**
 * @file
 * uib_calendar2.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uib_calendar2_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'calendar2_form';
  $context->description = 'Calendar form';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'calendar2' => 'calendar2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'uib_calendar2-cal2form' => array(
          'module' => 'uib_calendar2',
          'delta' => 'cal2form',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Calendar form');
  $export['calendar2_form'] = $context;

  return $export;
}
