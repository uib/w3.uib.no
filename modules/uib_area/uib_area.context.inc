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
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'uib_area-area_offices' => array(
          'module' => 'uib_area',
          'delta' => 'area_offices',
          'region' => 'above_content',
          'weight' => '0',
        ),
        'uib_area-ouprosjektet_logo' => array(
          'module' => 'uib_area',
          'delta' => 'ouprosjektet_logo',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'uib_area-area_parents' => array(
          'module' => 'uib_area',
          'delta' => 'area_parents',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'uib_calendar3-calendar3' => array(
          'module' => 'uib_calendar3',
          'delta' => 'calendar3',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'uib_calendar3-exhibitions3' => array(
          'module' => 'uib_calendar3',
          'delta' => 'exhibitions3',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-recent_news-block' => array(
          'module' => 'views',
          'delta' => 'recent_news-block',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'uib_area-feed' => array(
          'module' => 'uib_area',
          'delta' => 'feed',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'uib_area-paahoyden_logo' => array(
          'module' => 'uib_area',
          'delta' => 'paahoyden_logo',
          'region' => 'sidebar_second',
          'weight' => '-4',
        ),
        'uib_area-jobbnorge' => array(
          'module' => 'uib_area',
          'delta' => 'jobbnorge',
          'region' => 'sidebar_second',
          'weight' => '-3',
        ),
        'views-relevant_links-relevant_links' => array(
          'module' => 'views',
          'delta' => 'relevant_links-relevant_links',
          'region' => 'sidebar_second',
          'weight' => '-2',
        ),
        'views-79622ce408d27be255f959dc886a6751' => array(
          'module' => 'views',
          'delta' => '79622ce408d27be255f959dc886a6751',
          'region' => 'sidebar_second',
          'weight' => '-1',
        ),
        'views-e35933dcbeaec830701d3e48e98f0046' => array(
          'module' => 'views',
          'delta' => 'e35933dcbeaec830701d3e48e98f0046',
          'region' => 'sidebar_second',
          'weight' => '0',
        ),
        'views-59c9268577c7dee7af4089857ed7ab4e' => array(
          'module' => 'views',
          'delta' => '59c9268577c7dee7af4089857ed7ab4e',
          'region' => 'sidebar_second',
          'weight' => '1',
        ),
        'views-87d291272c77934f60566c1a5bccebdf' => array(
          'module' => 'views',
          'delta' => '87d291272c77934f60566c1a5bccebdf',
          'region' => 'sidebar_second',
          'weight' => '2',
        ),
      ),
    ),
  );
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
      'uib_zen' => array(
        'disable' => array(
          'sidebar_second' => 'sidebar_second',
          'header' => 0,
          'navigation' => 0,
          'above_content' => 0,
          'highlighted' => 0,
          'help' => 0,
          'content_top' => 0,
          'content' => 0,
          'footer' => 0,
          'bottom' => 0,
          'page_top' => 0,
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
