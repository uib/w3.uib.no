<?php
  function uib_setup_drush_command() {
    $items['fix-media-library-settings'] = array(
      'description' => 'Fixing',
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
      'arguments' => array(),
      'options' => array(),
    );
    return $items;
  }

  function drush_uib_setup_fix_media_library_settings() {
    $fields = array(
      'uib_testimonial' => array('field_uib_media',),
      'area' => array('field_uib_feature_mobile_media',),
      'uib_external_content' => array('field_uib_media',),
      'uib_article' => array('field_uib_feature_mobile_media', 'field_uib_main_media_teaser',),
    );
    foreach ($fields as $key => $field) {
      foreach ($field as $f) {
        $field_info = field_info_instance('node', $f, $key);
        foreach ($field_info as $k => $fi) {
          if ($k == 'widget') {
            uibx_log('Updating media browser setting for ' . $f . ' in type ' . $key);
            $field_info['widget']['settings']['browser_plugins']['media_default--media_browser_1'] = 0;
            field_update_instance($field_info);
          }
        }
      }
    }
  }