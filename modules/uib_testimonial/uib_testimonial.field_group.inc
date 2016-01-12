<?php
/**
 * @file
 * uib_testimonial.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uib_testimonial_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_main|node|uib_testimonial|default';
  $field_group->group_name = 'group_article_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_testimonial';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'article-main',
    'weight' => '0',
    'children' => array(
      0 => 'field_uib_quote',
      1 => 'field_uib_lead',
      2 => 'field_uib_text',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'article-main',
      'instance_settings' => array(
        'classes' => ' group-article-main field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_article_main|node|uib_testimonial|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_sidebar|node|uib_testimonial|default';
  $field_group->group_name = 'group_article_sidebar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_testimonial';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'article-sidebar',
    'weight' => '1',
    'children' => array(
      0 => 'field_uib_name',
      1 => 'field_uib_study_programmes',
      2 => 'field_uib_birth_year',
      3 => 'field_uib_organization',
      4 => 'field_uib_position',
      5 => 'field_uib_education',
      6 => 'field_uib_exchange_place',
      7 => 'field_uib_media',
      8 => 'field_uib_exchange_text',
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
  $field_groups['group_article_sidebar|node|uib_testimonial|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_information|node|uib_testimonial|form';
  $field_group->group_name = 'group_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_testimonial';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_uib_area',
      1 => 'field_uib_quote',
      2 => 'field_uib_lead',
      3 => 'field_uib_text',
      4 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'clearfix group-information field-group-div',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_information|node|uib_testimonial|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sidebar|node|uib_testimonial|form';
  $field_group->group_name = 'group_sidebar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_testimonial';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sidebar',
    'weight' => '2',
    'children' => array(
      0 => 'field_uib_birth_year',
      1 => 'field_uib_study_programmes',
      2 => 'field_uib_name',
      3 => 'field_uib_related_programmes',
      4 => 'field_uib_position',
      5 => 'field_uib_organization',
      6 => 'field_uib_education',
      7 => 'field_uib_exchange_place',
      8 => 'field_uib_media',
      9 => 'field_uib_exchange_text',
    ),
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
  $field_groups['group_sidebar|node|uib_testimonial|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Information');
  t('Sidebar');
  t('article-main');
  t('article-sidebar');

  return $field_groups;
}
