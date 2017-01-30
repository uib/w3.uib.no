<?php
/**
 * @file
 * uib_webdesk.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uib_webdesk_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'webdesk';
  $context->description = 'Drop regons based on context';
  $context->tag = 'layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'webdesk' => 'webdesk',
        'webdesk/*' => 'webdesk/*',
      ),
    ),
  );
  $context->reactions = array(
    'region' => array(
      'adminimal' => array(
        'disable' => array(
          'hidden' => 0,
          'content_before' => 0,
          'sidebar_left' => 0,
          'content' => 0,
          'sidebar_right' => 0,
          'content_after' => 0,
          'help' => 0,
          'page_top' => 0,
          'page_bottom' => 0,
        ),
      ),
      'uib_w3' => array(
        'disable' => array(
          'header' => 0,
          'subheader' => 0,
          'content_top' => 0,
          'content' => 0,
          'content_bottom' => 0,
          'footer_top' => 0,
          'footer' => 0,
          'footer_bottom' => 0,
          'help' => 0,
          'page_bottom' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Drop regons based on context');
  t('layout');
  $export['webdesk'] = $context;

  return $export;
}
