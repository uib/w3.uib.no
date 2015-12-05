<?php
/**
 * @file
 * uib_newsarchive.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uib_newsarchive_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'newsarchive';
  $context->description = '';
  $context->tag = 'block';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'recent_news:newsarchive' => 'recent_news:newsarchive',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-recent_news-block_date_selector' => array(
          'module' => 'views',
          'delta' => 'recent_news-block_date_selector',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('block');
  $export['newsarchive'] = $context;

  return $export;
}
