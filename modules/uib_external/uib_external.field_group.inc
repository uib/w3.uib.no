<?php

/**
 * @file
 * uib_external.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uib_external_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uib_media|node|uib_external_content|form';
  $field_group->group_name = 'group_uib_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_external_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Photo',
    'weight' => '5',
    'children' => array(
      0 => 'field_uib_imagecaptions2',
      1 => 'field_uib_media',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-uib-media field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_uib_media|node|uib_external_content|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Photo');

  return $field_groups;
}
