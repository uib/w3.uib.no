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

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'area_blocks';
  $context->description = '';
  $context->tag = 'block';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'area' => 'area',
        'uib_article' => 'uib_article',
        'uib_content_list' => 'uib_content_list',
        'uib_testimonial' => 'uib_testimonial',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'views' => array(
      'values' => array(
        'ansatte' => 'ansatte',
        'area_map' => 'area_map',
        'courses' => 'courses',
        'recent_news:newsarchive' => 'recent_news:newsarchive',
        'recent_phds' => 'recent_phds',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('block');
  $export['area_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'area_persons';
  $context->description = 'Area staff/person listing [area_name/persons]';
  $context->tag = 'persons';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'ansatte:page_2' => 'ansatte:page_2',
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
  t('Area staff/person listing [area_name/persons]');
  t('persons');
  $export['area_persons'] = $context;

  return $export;
}
