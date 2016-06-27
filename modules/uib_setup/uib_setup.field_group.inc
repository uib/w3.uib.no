<?php
/**
 * @file
 * uib_setup.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uib_setup_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_info|file|image|content_main';
  $field_group->group_name = 'group_media_info';
  $field_group->entity_type = 'file';
  $field_group->bundle = 'image';
  $field_group->mode = 'content_main';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media info',
    'weight' => '9',
    'children' => array(
      0 => 'field_uib_copyright',
      1 => 'field_uib_description',
      2 => 'field_uib_owner',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Media info',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'uib-media-info',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_media_info|file|image|content_main'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Media info');

  return $field_groups;
}
