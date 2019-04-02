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
      0 => 'field_uib_lead',
      1 => 'field_uib_text',
      2 => 'field_uib_quote',
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
      0 => 'field_uib_fact_box',
      1 => 'field_uib_media',
      2 => 'group_uib_testimonial_personalia',
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
      0 => 'field_uib_lead',
      1 => 'field_uib_text',
      2 => 'field_uib_quote',
      3 => 'field_uib_kicker',
      4 => 'field_uib_area',
      5 => 'title',
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
  $field_group->identifier = 'group_media_content|node|uib_testimonial|teaser';
  $field_group->group_name = 'group_media_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_testimonial';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_media_wrapper';
  $field_group->data = array(
    'label' => '',
    'weight' => '22',
    'children' => array(
      0 => 'field_uib_kicker',
      1 => 'field_uib_lead',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-media-content field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_media_content|node|uib_testimonial|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_wrapper|node|uib_testimonial|teaser';
  $field_group->group_name = 'group_media_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_testimonial';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '19',
    'children' => array(
      0 => 'group_media_content',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-media-wrapper field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_media_wrapper|node|uib_testimonial|teaser'] = $field_group;

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
      1 => 'field_uib_position',
      2 => 'field_uib_exchange_place',
      3 => 'field_uib_name',
      4 => 'field_uib_exchange_text',
      5 => 'field_uib_study_programmes',
      6 => 'field_uib_organization',
      7 => 'field_uib_education',
      8 => 'group_small_images',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_small_images|node|uib_testimonial|form';
  $field_group->group_name = 'group_small_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_testimonial';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sidebar';
  $field_group->data = array(
    'label' => 'Images',
    'weight' => '14',
    'children' => array(
      0 => 'field_uib_imagecaptions2',
      1 => 'field_uib_media',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-small-images field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_small_images|node|uib_testimonial|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_uib_testimonial_personalia|node|uib_testimonial|default';
  $field_group->group_name = 'group_uib_testimonial_personalia';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uib_testimonial';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_article_sidebar';
  $field_group->data = array(
    'label' => 'Personalia',
    'weight' => '2',
    'children' => array(
      0 => 'field_uib_position',
      1 => 'field_uib_exchange_place',
      2 => 'field_uib_organization',
      3 => 'field_uib_birth_year',
      4 => 'field_uib_name',
      5 => 'field_uib_exchange_text',
      6 => 'field_uib_study_programmes',
      7 => 'field_uib_education',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => 'group-uib-testimonial-personalia field-group-div',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_uib_testimonial_personalia|node|uib_testimonial|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Images');
  t('Information');
  t('Personalia');
  t('Sidebar');
  t('article-main');
  t('article-sidebar');

  return $field_groups;
}
