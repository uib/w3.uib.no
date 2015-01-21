<?php
/**
 * @file
 * uib_area.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uib_area_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bottom_wrapper|node|area|default';
  $field_group->group_name = 'group_bottom_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bottom wrapper',
    'weight' => '7',
    'children' => array(
      0 => 'field_uib_bottom_text',
      1 => 'field_uib_bottom_media',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Bottom wrapper',
      'instance_settings' => array(
        'classes' => ' group-bottom-wrapper field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_bottom_wrapper|node|area|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_first|node|area|default';
  $field_group->group_name = 'group_column_first';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_two_column';
  $field_group->data = array(
    'label' => 'Column first',
    'weight' => '11',
    'children' => array(
      0 => 'field_uib_link_section',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Column first',
      'instance_settings' => array(
        'classes' => 'group-column-first field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_column_first|node|area|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_second|node|area|default';
  $field_group->group_name = 'group_column_second';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_two_column';
  $field_group->data = array(
    'label' => 'Column second',
    'weight' => '12',
    'children' => array(
      0 => 'field_uib_tertiary_text',
      1 => 'field_uib_profiled_testimonial',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Column second',
      'instance_settings' => array(
        'classes' => 'group-column-second field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_column_second|node|area|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_info|node|uib_ou|teaser';
  $field_group->group_name = 'group_contact_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_ou';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_office_hours';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '2',
    'children' => array(
      0 => 'field_uib_phone',
      1 => 'field_uib_visit_address',
      2 => 'field_uib_custom_email',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'classes' => 'group-contact-info field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact_info|node|uib_ou|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_level_1|node|area|form';
  $field_group->group_name = 'group_level_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'For level 1',
    'weight' => '1',
    'children' => array(
      0 => 'field_uib_menu_style',
      1 => 'field_uib_area_type',
      2 => 'field_uib_w2_id',
      3 => 'field_uib_sebra_id',
      4 => 'field_uib_area_parents',
      5 => 'field_uib_offices',
      6 => 'field_uib_area_banner',
      7 => 'field_uib_ou',
      8 => 'title',
      9 => 'field_uib_image_map',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-level-1 field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_level_1|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_management|node|area|form';
  $field_group->group_name = 'group_management';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Management',
    'weight' => '2',
    'children' => array(
      0 => 'field_uib_content_manager',
      1 => 'field_uib_important_message',
      2 => 'field_uib_staff',
      3 => 'field_uib_colophone_logos',
      4 => 'field_uib_show_staff',
      5 => 'field_uib_logo',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-management field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_management|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_content|node|uib_article|teaser';
  $field_group->group_name = 'group_media_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_media_wrapper';
  $field_group->data = array(
    'label' => '',
    'weight' => '3',
    'children' => array(
      0 => 'field_uib_lead',
      1 => 'field_uib_kicker',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => 'media_content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_media_content|node|uib_article|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_wrapper|node|uib_article|teaser';
  $field_group->group_name = 'group_media_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '2',
    'children' => array(
      0 => 'group_media_content',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => 'media_wrapper',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_media_wrapper|node|uib_article|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_office_hours|node|uib_ou|teaser';
  $field_group->group_name = 'group_office_hours';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_ou';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Office information',
    'weight' => '1',
    'children' => array(
      0 => 'field_uib_custom_hours',
      1 => 'field_uib_hours',
      2 => 'group_contact_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Office information',
      'instance_settings' => array(
        'classes' => 'group-office-information field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_office_hours|node|uib_ou|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_text|node|area|form';
  $field_group->group_name = 'group_profile_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'W2 profile text',
    'weight' => '3',
    'children' => array(
      0 => 'field_uib_text2',
      1 => 'field_uib_media',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-profile-text field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_profile_text|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_two_column|node|area|default';
  $field_group->group_name = 'group_two_column';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'two_column',
    'weight' => '6',
    'children' => array(
      0 => 'field_uib_profiled_message',
      1 => 'group_column_first',
      2 => 'group_column_second',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'two_column',
      'instance_settings' => array(
        'classes' => ' group-two-column field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_two_column|node|area|default'] = $field_group;

  return $export;
}
