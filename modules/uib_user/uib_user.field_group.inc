<?php
/**
 * @file
 * uib_user.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uib_user_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cristin|user|user|form';
  $field_group->group_name = 'group_cristin';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_primary';
  $field_group->data = array(
    'label' => 'CRIStin settings',
    'weight' => '9',
    'children' => array(
      0 => 'field_uib_user_cristin_nr',
      1 => 'field_uib_user_cristin_place',
      2 => 'field_uib_user_cristin_sort',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cristin|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_element|user|user|default';
  $field_group->group_name = 'group_media_element';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_user_first';
  $field_group->data = array(
    'label' => 'Media element',
    'weight' => '38',
    'children' => array(
      0 => 'group_user_contact_wrapper',
      1 => 'group_user_media',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Media element',
      'instance_settings' => array(
        'classes' => 'group-media-element field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_media_element|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_primary|user|user|form';
  $field_group->group_name = 'group_primary';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main information',
    'weight' => '0',
    'children' => array(
      0 => 'field_uib_user_url',
      1 => 'field_uib_user_publications',
      2 => 'field_uib_user_cv',
      3 => 'field_uib_user_room',
      4 => 'field_uib_last_name',
      5 => 'field_uib_phone',
      6 => 'field_uib_user_field',
      7 => 'field_uib_user_domain',
      8 => 'field_uib_position',
      9 => 'field_uib_user_alt_firstname',
      10 => 'field_uib_user_social_media',
      11 => 'field_uib_user_alt_lastname',
      12 => 'field_uib_first_name',
      13 => 'field_uib_user_opt_content',
      14 => 'field_uib_user_opt_title',
      15 => 'field_uib_user_communication',
      16 => 'field_uib_user_alt_position',
      17 => 'field_uib_user_alt_address',
      18 => 'field_uib_user_teaching',
      19 => 'account',
      20 => 'picture',
      21 => 'group_cristin',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Main information',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_primary|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_secondary|user|user|form';
  $field_group->group_name = 'group_secondary';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Secondary information',
    'weight' => '1',
    'children' => array(
      0 => 'field_uib_user_feed',
      1 => 'field_uib_user_competence',
      2 => 'field_uib_user_projects',
      3 => 'field_uib_user_docs',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Secondary information',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_secondary|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uib_hidden|user|user|form';
  $field_group->group_name = 'group_uib_hidden';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Hidden',
    'weight' => '33',
    'children' => array(
      0 => 'field_uib_position_code',
      1 => 'field_uib_w2_id',
      2 => 'field_uib_slug',
      3 => 'field_uib_position_category',
      4 => 'field_uib_sort_name',
      5 => 'field_uib_user_ou',
      6 => 'googleanalytics',
      7 => 'redirect',
      8 => 'timezone',
      9 => 'locale',
      10 => 'wysiwyg',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Hidden',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_uib_hidden|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_ci_1|user|user|default';
  $field_group->group_name = 'group_user_ci_1';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_user_contact';
  $field_group->data = array(
    'label' => 'Contact info first',
    'weight' => '13',
    'children' => array(
      0 => 'field_uib_user_url',
      1 => 'field_uib_user_cv',
      2 => 'field_uib_phone',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact info first',
      'instance_settings' => array(
        'classes' => 'group-user-ci-1 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_ci_1|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_ci_2|user|user|default';
  $field_group->group_name = 'group_user_ci_2';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_user_contact';
  $field_group->data = array(
    'label' => 'Contact info second',
    'weight' => '11',
    'children' => array(
      0 => 'field_uib_user_room',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact info second',
      'instance_settings' => array(
        'classes' => 'group-user-ci-2 field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_ci_2|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_contact_wrapper|user|user|default';
  $field_group->group_name = 'group_user_contact_wrapper';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_media_element';
  $field_group->data = array(
    'label' => 'Contact wrapper',
    'weight' => '40',
    'children' => array(
      0 => 'group_user_contact',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact wrapper',
      'instance_settings' => array(
        'classes' => 'group-user-contact-wrapper field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_contact_wrapper|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_contact|user|user|default';
  $field_group->group_name = 'group_user_contact';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_user_contact_wrapper';
  $field_group->data = array(
    'label' => 'Contact info',
    'weight' => '1',
    'children' => array(
      0 => 'field_uib_first_name',
      1 => 'field_uib_position',
      2 => 'field_uib_last_name',
      3 => 'field_uib_user_ou',
      4 => 'field_uib_user_alt_position',
      5 => 'group_user_ci_1',
      6 => 'group_user_ci_2',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact info',
      'instance_settings' => array(
        'classes' => 'group-user-contact field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_contact|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_first|user|user|default';
  $field_group->group_name = 'group_user_first';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'First',
    'weight' => '0',
    'children' => array(
      0 => 'group_media_element',
      1 => 'group_user_work_1',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'First',
      'instance_settings' => array(
        'classes' => 'group-user-first field-group-div clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_first|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_media|user|user|default';
  $field_group->group_name = 'group_user_media';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_media_element';
  $field_group->data = array(
    'label' => 'Personal media',
    'weight' => '39',
    'children' => array(
      0 => 'field_uib_user_social_media',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Personal media',
      'instance_settings' => array(
        'classes' => 'group-user-media field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_media|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_second|user|user|default';
  $field_group->group_name = 'group_user_second';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Second',
    'weight' => '1',
    'children' => array(
      0 => 'field_uib_user_feed',
      1 => 'field_uib_user_competence',
      2 => 'field_uib_user_projects',
      3 => 'field_uib_user_docs',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Second',
      'instance_settings' => array(
        'classes' => 'group-user-second field-group-div clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_second|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_work_1|user|user|default';
  $field_group->group_name = 'group_user_work_1';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_user_first';
  $field_group->data = array(
    'label' => 'Work information',
    'weight' => '41',
    'children' => array(
      0 => 'field_uib_user_field',
      1 => 'field_uib_user_opt_title',
      2 => 'field_uib_user_teaching',
      3 => 'field_uib_user_communication',
      4 => 'field_uib_user_publications',
      5 => 'field_uib_user_opt_content',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Work information',
      'instance_settings' => array(
        'classes' => 'group-user-work-1 field-group-div uib-tabs-container clearfix',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_user_work_1|user|user|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('CRIStin settings');
  t('Contact info');
  t('Contact info first');
  t('Contact info second');
  t('Contact wrapper');
  t('First');
  t('Hidden');
  t('Main information');
  t('Media element');
  t('Personal media');
  t('Second');
  t('Secondary information');
  t('Work information');

  return $field_groups;
}
