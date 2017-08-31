<?php
/**
 * @file
 * uib_area.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uib_area_field_group_info() {
  $field_groups = array();

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
    'weight' => '9',
    'children' => array(
      0 => 'field_uib_bottom_media',
      1 => 'field_uib_bottom_text',
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
  $field_groups['group_bottom_wrapper|node|area|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_first|node|area|default';
  $field_group->group_name = 'group_column_first';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_two_column';
  $field_group->data = array(
    'label' => 'Column first',
    'weight' => '110',
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
  $field_groups['group_column_first|node|area|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_column_second|node|area|default';
  $field_group->group_name = 'group_column_second';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_two_column';
  $field_group->data = array(
    'label' => 'Column second',
    'weight' => '120',
    'children' => array(
      0 => 'field_uib_profiled_testimonial',
      1 => 'field_uib_tertiary_text',
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
  $field_groups['group_column_second|node|area|default'] = $field_group;

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
      0 => 'field_uib_email',
      1 => 'field_uib_phone',
      2 => 'field_uib_visit_address',
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
  $field_groups['group_contact_info|node|uib_ou|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_info|node|uib_article|default';
  $field_group->group_name = 'group_event_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_article_sidebar';
  $field_group->data = array(
    'label' => 'Event info',
    'weight' => '46',
    'children' => array(
      0 => 'field_uib_contacts',
      1 => 'field_uib_deadline',
      2 => 'field_uib_registration_link',
      3 => 'field_uib_date',
      4 => 'field_uib_location',
      5 => 'field_uib_event_type',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Event info',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-event-info',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_event_info|node|uib_article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_info|node|uib_article|form';
  $field_group->group_name = 'group_event_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event info',
    'weight' => '12',
    'children' => array(
      0 => 'field_uib_contacts',
      1 => 'field_uib_registration_link',
      2 => 'field_uib_location',
      3 => 'field_uib_deadline',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-info field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_info|node|uib_article|form'] = $field_group;

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
      0 => 'field_uib_offices',
      1 => 'field_uib_area_parents',
      2 => 'field_uib_menu_style',
      3 => 'field_uib_ou',
      4 => 'field_uib_image_map',
      5 => 'field_uib_search_keywords',
      6 => 'field_uib_search_manual_boost',
      7 => 'field_uib_area_type',
      8 => 'field_uib_area_banner',
      9 => 'field_uib_sebra_id',
      10 => 'title',
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
  $field_groups['group_level_1|node|area|form'] = $field_group;

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
    'weight' => '5',
    'children' => array(
      0 => 'field_uib_staff',
      1 => 'field_uib_content_manager',
      2 => 'field_uib_colophone_logos',
      3 => 'field_uib_important_message',
      4 => 'field_uib_logo',
      5 => 'field_uib_show_staff',
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
  $field_groups['group_management|node|area|form'] = $field_group;

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
  $field_groups['group_media_content|node|uib_article|teaser'] = $field_group;

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
  $field_groups['group_media_wrapper|node|uib_article|teaser'] = $field_group;

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
      0 => 'field_uib_hours_custom',
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
  $field_groups['group_office_hours|node|uib_ou|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_text|node|area|form';
  $field_group->group_name = 'group_profile_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'W2 profile text',
    'weight' => '7',
    'children' => array(
      0 => 'field_uib_media',
      1 => 'field_uib_text2',
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
  $field_groups['group_profile_text|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relevant_links|node|area|form';
  $field_group->group_name = 'group_relevant_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Relevant links',
    'weight' => '3',
    'children' => array(
      0 => 'field_uib_link_section',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-relevant-links field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_relevant_links|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_resources|node|uib_article|form';
  $field_group->group_name = 'group_resources';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links and attachments',
    'weight' => '9',
    'children' => array(
      0 => 'field_uib_files',
      1 => 'field_uib_links',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Links and attachments',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-resources field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_resources|node|uib_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rss|node|area|form';
  $field_group->group_name = 'group_rss';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'RSS',
    'weight' => '4',
    'children' => array(
      0 => 'field_uib_feed',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-rss field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_rss|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_search|node|area|form';
  $field_group->group_name = 'group_search';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Search',
    'weight' => '5',
    'children' => array(
      0 => 'field_uib_search_description',
      1 => 'field_uib_search_keywords',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-search field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_search|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_media|node|area|form';
  $field_group->group_name = 'group_social_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social media',
    'weight' => '2',
    'children' => array(
      0 => 'field_uib_social_media',
      1 => 'field_uib_show_twitter_feed',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-social-media field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_social_media|node|area|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
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
  $field_groups['group_two_column|node|area|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Bottom wrapper');
  t('Column first');
  t('Column second');
  t('Contact');
  t('Event info');
  t('For level 1');
  t('Links and attachments');
  t('Management');
  t('Office information');
  t('RSS');
  t('Relevant links');
  t('Search');
  t('Social media');
  t('W2 profile text');
  t('two_column');

  return $field_groups;
}
