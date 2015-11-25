<?php
/**
 * @file
 * uib_setup.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uib_setup_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "ldap_servers" && $api == "ldap_servers") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function uib_setup_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function uib_setup_image_default_styles() {
  $styles = array();

  // Exported image style: area_bottom.
  $styles['area_bottom'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 340,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'area_bottom',
  );

  // Exported image style: area_main.
  $styles['area_main'] = array(
    'label' => 'area_main',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => 450,
          'upscale' => 0,
        ),
        'weight' => 0,
      ),
    ),
  );

  // Exported image style: colophone_logo.
  $styles['colophone_logo'] = array(
    'label' => 'Colophone logo',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 200,
          'height' => 120,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: content_main.
  $styles['content_main'] = array(
    'label' => 'content_main',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1260,
          'height' => 947,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: content_main_mobile_1x.
  $styles['content_main_mobile_1x'] = array(
    'label' => 'content_main_mobile_1x',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 559,
          'height' => 419,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: content_main_narrow_1x.
  $styles['content_main_narrow_1x'] = array(
    'label' => 'content_main_narrow_1x',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 859,
          'height' => 644,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: content_main_wide_1x.
  $styles['content_main_wide_1x'] = array(
    'label' => 'content_main_wide_1x',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1260,
          'height' => 945,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: content_sidebar.
  $styles['content_sidebar'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 177,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'content_sidebar',
  );

  // Exported image style: custom_logo.
  $styles['custom_logo'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 70,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'custom_logo',
  );

  // Exported image style: full_width_16_9.
  $styles['full_width_16_9'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 708,
          'height' => 398.25,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'full_width_16_9',
  );

  // Exported image style: user_thumbnail.
  $styles['user_thumbnail'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 80,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'user_thumbnail',
  );

  // Exported image style: wide_thumbnail.
  $styles['wide_thumbnail'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 531,
          'height' => 375,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'wide_thumbnail',
  );

  return $styles;
}
