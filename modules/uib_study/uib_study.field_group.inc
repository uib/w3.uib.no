<?php
/**
 * @file
 * uib_study.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uib_study_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_content|node|uib_study|form';
  $field_group->group_name = 'group_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_study';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '21',
    'children' => array(
      0 => 'field_uib_study_relation',
      1 => 'field_uib_related_content_label',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_related_content|node|uib_study|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Related content');

  return $field_groups;
}
