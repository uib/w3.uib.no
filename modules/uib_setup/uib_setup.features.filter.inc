<?php
/**
 * @file
 * uib_setup.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function uib_setup_filter_default_formats() {
  $formats = array();

  // Exported format: Advanced editor.
  $formats['advanced_editor'] = array(
    'format' => 'advanced_editor',
    'name' => 'Advanced editor',
    'cache' => 1,
    'status' => 0,
    'weight' => -9,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'media_filter' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Basic HTML.
  $formats['basic_html'] = array(
    'format' => 'basic_html',
    'name' => 'Basic HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'filter_html' => array(
        'weight' => -50,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<br> <p> <a> <strong> <em> <ul> <li> <ol> <h2> <h3> <h4> <blockquote> <table> <tbody> <tr> <td>',
          'filter_html_help' => 0,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_h2' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_uib_url' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_uib_markup' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_studycodes' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -43,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Full HTML (Raw).
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML (Raw)',
    'cache' => 1,
    'status' => 1,
    'weight' => -7,
    'filters' => array(
      'filter_h2' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Restricted HTML.
  $formats['restricted_html'] = array(
    'format' => 'restricted_html',
    'name' => 'Restricted HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'filters' => array(
      'filter_html' => array(
        'weight' => -50,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<br> <p> <a> <strong> <em> <ul> <li> <ol> <h3> <h4> ',
          'filter_html_help' => 0,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_url' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_uib_url' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_uib_markup' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_studycodes' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Simple editor.
  $formats['simple_editor'] = array(
    'format' => 'simple_editor',
    'name' => 'Simple editor',
    'cache' => 1,
    'status' => 0,
    'weight' => -8,
    'filters' => array(
      'filter_html' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <em> <strong> <cite> <blockquote> <ul> <ol> <li> <dl> <dt> <dd> <br> <p> <h2> <h3> <h4> <img>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'media_filter' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
