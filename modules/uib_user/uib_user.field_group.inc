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
  $field_group->identifier = 'group_alt_address|user|user|form';
  $field_group->group_name = 'group_alt_address';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bottom_tabs';
  $field_group->data = array(
    'label' => 'Visitor address',
    'weight' => '49',
    'children' => array(
      0 => 'field_uib_user_alt_address',
      1 => 'field_uib_user_room',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Visitor address',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-alt-address field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_alt_address|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bottom_tabs|user|user|form';
  $field_group->group_name = 'group_bottom_tabs';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Bottom tabs',
    'weight' => '41',
    'children' => array(
      0 => 'group_alt_address',
      1 => 'group_communication',
      2 => 'group_current_projects',
      3 => 'group_field',
      4 => 'group_homepage_cv',
      5 => 'group_opt_content',
      6 => 'group_publications',
      7 => 'group_resources',
      8 => 'group_social_media',
      9 => 'group_static_information',
      10 => 'group_teaching',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-bottom-tabs field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_bottom_tabs|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_communication|user|user|form';
  $field_group->group_name = 'group_communication';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bottom_tabs';
  $field_group->data = array(
    'label' => 'Communication',
    'weight' => '43',
    'children' => array(
      0 => 'field_uib_user_communication',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-communication field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_communication|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cristin|user|user|form';
  $field_group->group_name = 'group_cristin';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_publications';
  $field_group->data = array(
    'label' => 'CRIStin settings',
    'weight' => '15',
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
  $field_group->identifier = 'group_current_projects|user|user|form';
  $field_group->group_name = 'group_current_projects';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bottom_tabs';
  $field_group->data = array(
    'label' => 'Current projects',
    'weight' => '46',
    'children' => array(
      0 => 'field_uib_user_projects',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-current-projects field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_current_projects|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_field|user|user|form';
  $field_group->group_name = 'group_field';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bottom_tabs';
  $field_group->data = array(
    'label' => 'Research / Work',
    'weight' => '42',
    'children' => array(
      0 => 'field_uib_user_field',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-field field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_field|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_homepage_cv|user|user|form';
  $field_group->group_name = 'group_homepage_cv';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bottom_tabs';
  $field_group->data = array(
    'label' => 'Home page and CV',
    'weight' => '50',
    'children' => array(
      0 => 'field_uib_user_url',
      1 => 'field_uib_user_cv',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-homepage-cv field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_homepage_cv|user|user|form'] = $field_group;

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
  $field_group->identifier = 'group_opt_content|user|user|form';
  $field_group->group_name = 'group_opt_content';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bottom_tabs';
  $field_group->data = array(
    'label' => 'Optional tab',
    'weight' => '47',
    'children' => array(
      0 => 'field_uib_user_opt_content',
      1 => 'field_uib_user_opt_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Optional tab',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-opt-content field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_opt_content|user|user|form'] = $field_group;

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
      0 => 'field_uib_user_alt_position',
      1 => 'field_uib_user_domain',
      2 => 'field_uib_first_name',
      3 => 'field_uib_last_name',
      4 => 'account',
      5 => 'picture',
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
  $field_group->identifier = 'group_publications|user|user|form';
  $field_group->group_name = 'group_publications';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bottom_tabs';
  $field_group->data = array(
    'label' => 'Publications',
    'weight' => '45',
    'children' => array(
      0 => 'field_uib_user_publications',
      1 => 'group_cristin',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_publications|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_resources|user|user|form';
  $field_group->group_name = 'group_resources';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bottom_tabs';
  $field_group->data = array(
    'label' => 'RSS and documents',
    'weight' => '51',
    'children' => array(
      0 => 'field_uib_user_feed',
      1 => 'field_uib_user_docs',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'RSS and documents',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-resources field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_resources|user|user|form'] = $field_group;

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
    'weight' => '2',
    'children' => array(
      0 => 'field_uib_user_competence',
      1 => 'field_uib_user_relation',
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
  $field_group->identifier = 'group_social_media|user|user|form';
  $field_group->group_name = 'group_social_media';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bottom_tabs';
  $field_group->data = array(
    'label' => 'Social media',
    'weight' => '48',
    'children' => array(
      0 => 'field_uib_user_social_media',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Social media',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-social-media field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_social_media|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_static_information|user|user|form';
  $field_group->group_name = 'group_static_information';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bottom_tabs';
  $field_group->data = array(
    'label' => 'Static information',
    'weight' => '53',
    'children' => array(
      0 => 'field_uib_position',
      1 => 'field_uib_phone',
      2 => 'field_uib_user_alt_lastname',
      3 => 'field_uib_user_ou',
      4 => 'field_uib_user_alt_firstname',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-static-information field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_static_information|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaching|user|user|form';
  $field_group->group_name = 'group_teaching';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_bottom_tabs';
  $field_group->data = array(
    'label' => 'Teaching',
    'weight' => '44',
    'children' => array(
      0 => 'field_uib_user_teaching',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-teaching field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_teaching|user|user|form'] = $field_group;

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
    'weight' => '3',
    'children' => array(
      0 => 'field_uib_position_code',
      1 => 'field_uib_position_category',
      2 => 'field_uib_slug',
      3 => 'field_uib_sort_name',
      4 => 'googleanalytics',
      5 => 'redirect',
      6 => 'timezone',
      7 => 'locale',
      8 => 'wysiwyg',
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
      1 => 'field_uib_phone',
      2 => 'field_uib_user_cv',
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
      0 => 'field_uib_position',
      1 => 'field_uib_user_alt_position',
      2 => 'field_uib_user_ou',
      3 => 'field_uib_last_name',
      4 => 'field_uib_first_name',
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
      0 => 'field_uib_search_manual_boost',
      1 => 'field_uib_user_feed',
      2 => 'field_uib_user_relation',
      3 => 'field_uib_user_docs',
      4 => 'field_uib_user_competence',
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
      1 => 'field_uib_user_projects',
      2 => 'field_uib_user_publications',
      3 => 'field_uib_user_opt_title',
      4 => 'field_uib_user_opt_content',
      5 => 'field_uib_user_communication',
      6 => 'field_uib_user_teaching',
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
  t('Bottom tabs');
  t('CRIStin settings');
  t('Communication');
  t('Contact info');
  t('Contact info first');
  t('Contact info second');
  t('Contact wrapper');
  t('Current projects');
  t('First');
  t('Hidden');
  t('Home page and CV');
  t('Main information');
  t('Media element');
  t('Optional tab');
  t('Personal media');
  t('Publications');
  t('RSS and documents');
  t('Research / Work');
  t('Second');
  t('Secondary information');
  t('Social media');
  t('Static information');
  t('Teaching');
  t('Visitor address');
  t('Work information');

  return $field_groups;
}
