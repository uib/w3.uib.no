<?php
/**
 * @file
 * uib_message.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uib_message_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uib_message_en|node|uib_message|form';
  $field_group->group_name = 'group_uib_message_en';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_message';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Message (English)',
    'weight' => '6',
    'children' => array(
      0 => 'field_uib_message_link_en',
      1 => 'field_uib_message_text_en',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Message (English)',
      'instance_settings' => array(
        'id' => 'group_uib_message_en',
        'classes' => 'group-uib-message-en field-group-html5',
        'wrapper' => 'section',
      ),
    ),
  );
  $field_groups['group_uib_message_en|node|uib_message|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uib_message_nb|node|uib_message|form';
  $field_group->group_name = 'group_uib_message_nb';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_message';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Message (Norwegian)',
    'weight' => '5',
    'children' => array(
      0 => 'field_uib_message_link_nb',
      1 => 'field_uib_message_text_nb',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Message (Norwegian)',
      'instance_settings' => array(
        'id' => 'group_uib_message_nb',
        'classes' => 'group-uib-message-nb field-group-html5',
        'wrapper' => 'section',
      ),
    ),
  );
  $field_groups['group_uib_message_nb|node|uib_message|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Message (English)');
  t('Message (Norwegian)');

  return $field_groups;
}
