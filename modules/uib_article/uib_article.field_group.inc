<?php
/**
 * @file
 * uib_article.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uib_article_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_sidebar|node|uib_article|default';
  $field_group->group_name = 'group_article_sidebar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'article-sidebar',
    'weight' => '5',
    'children' => array(
      0 => 'field_uib_deadline',
      1 => 'field_uib_files',
      2 => 'field_uib_event_type',
      3 => 'field_uib_date',
      4 => 'field_uib_location',
      5 => 'field_uib_media',
      6 => 'field_uib_contacts',
      7 => 'field_uib_fact_box',
      8 => 'field_uib_registration_link',
      9 => 'field_uib_links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'article-sidebar',
      'instance_settings' => array(
        'classes' => ' group-article-sidebar field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_article_sidebar|node|uib_article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_information|node|uib_article|form';
  $field_group->group_name = 'group_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Information',
    'weight' => '2',
    'children' => array(
      0 => 'field_uib_area',
      1 => 'field_uib_date',
      2 => 'field_uib_text',
      3 => 'field_uib_published_timestamp',
      4 => 'field_uib_article_type',
      5 => 'field_uib_kicker',
      6 => 'field_uib_event_type',
      7 => 'field_uib_external_author',
      8 => 'field_uib_main_media',
      9 => 'field_uib_lead',
      10 => 'field_uib_search_keywords',
      11 => 'field_uib_show_global_calendar',
      12 => 'field_uib_byline',
      13 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'clearfix group-information field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_information|node|uib_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_content|node|uib_article|default';
  $field_group->group_name = 'group_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content group',
    'weight' => '7',
    'children' => array(
      0 => 'field_uib_relation',
      1 => 'field_uib_related_content_label',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Related content group',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-related-content field-group-html5',
        'wrapper' => 'section',
      ),
    ),
  );
  $field_groups['group_related_content|node|uib_article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_content|node|uib_article|form';
  $field_group->group_name = 'group_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '20',
    'children' => array(
      0 => 'field_uib_relation',
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
  $field_groups['group_related_content|node|uib_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_persons|node|uib_article|default';
  $field_group->group_name = 'group_related_persons';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related persons group',
    'weight' => '6',
    'children' => array(
      0 => 'field_uib_related_persons',
      1 => 'field_related_persons_label',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Related persons group',
      'instance_settings' => array(
        'classes' => 'group-related-persons field-group-html5',
        'wrapper' => 'section',
      ),
    ),
  );
  $field_groups['group_related_persons|node|uib_article|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_persons|node|uib_article|form';
  $field_group->group_name = 'group_related_persons';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related persons',
    'weight' => '19',
    'children' => array(
      0 => 'field_uib_related_persons',
      1 => 'field_related_persons_label',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-persons field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_related_persons|node|uib_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sidebar|node|uib_article|form';
  $field_group->group_name = 'group_sidebar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sidebar',
    'weight' => '1',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Sidebar',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'clearfix group-sidebar field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_sidebar|node|uib_article|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Information');
  t('Related content');
  t('Related content group');
  t('Related persons');
  t('Related persons group');
  t('Sidebar');
  t('article-sidebar');

  return $field_groups;
}
