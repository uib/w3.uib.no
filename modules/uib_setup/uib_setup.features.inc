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
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
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
      8 => array(
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
      6 => array(
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
      14 => array(
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
      12 => array(
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
      10 => array(
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
    'label' => 'content_sidebar',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 400,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
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

  // Exported image style: feature_full_width_1x.
  $styles['feature_full_width_1x'] = array(
    'label' => 'feature_full_width_1x',
    'effects' => array(
      25 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 3400,
          'height' => 1700,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: feature_image.
  $styles['feature_image'] = array(
    'label' => 'Feature image',
    'effects' => array(
      26 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 4800,
          'height' => 2550,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: feature_mobile_1_5x.
  $styles['feature_mobile_1_5x'] = array(
    'label' => 'feature_mobile_1_5x',
    'effects' => array(
      23 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 800,
          'height' => 1100,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: feature_mobile_1x.
  $styles['feature_mobile_1x'] = array(
    'label' => 'feature_mobile_1x',
    'effects' => array(
      24 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 800,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: feature_mobile_2x.
  $styles['feature_mobile_2x'] = array(
    'label' => 'feature_mobile_2x',
    'effects' => array(
      22 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 1280,
          'height' => 1600,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: feature_narrow_1x.
  $styles['feature_narrow_1x'] = array(
    'label' => 'feature_narrow_1x',
    'effects' => array(
      28 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 860,
          'height' => 480,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: feature_wide_1x.
  $styles['feature_wide_1x'] = array(
    'label' => 'feature_wide_1x',
    'effects' => array(
      27 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1280,
          'height' => 720,
        ),
        'weight' => 1,
      ),
    ),
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

  // Exported image style: full_width_image.
  $styles['full_width_image'] = array(
    'label' => 'Full width image',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 2667,
          'height' => 1500,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: full_width_image_full_width_1x.
  $styles['full_width_image_full_width_1x'] = array(
    'label' => 'full_width_image_full_width_1x',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 2667,
          'height' => 1500,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: full_width_image_mobile_1x.
  $styles['full_width_image_mobile_1x'] = array(
    'label' => 'full_width_image_mobile_1x',
    'effects' => array(
      3 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 560,
          'height' => 350,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: full_width_image_narrow_1x.
  $styles['full_width_image_narrow_1x'] = array(
    'label' => 'full_width_image_narrow_1x',
    'effects' => array(
      4 => array(
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

  // Exported image style: full_width_image_wide_1x.
  $styles['full_width_image_wide_1x'] = array(
    'label' => 'full_width_image_wide_1x',
    'effects' => array(
      5 => array(
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

  // Exported image style: twittercard.
  $styles['twittercard'] = array(
    'label' => 'twittercard',
    'effects' => array(
      2 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 300,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: user_thumbnail.
  $styles['user_thumbnail'] = array(
    'label' => 'user_thumbnail',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 500,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: wide_thumbnail.
  $styles['wide_thumbnail'] = array(
    'label' => 'wide_thumbnail',
    'effects' => array(
      3 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 531,
          'height' => 375,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
