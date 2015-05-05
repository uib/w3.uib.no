<?php
/**
 * @file
 * uib_calendar.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uib_calendar_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'calendar';
  $view->description = 'Lists accouring to date field';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Calendar';
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uib_date_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry, no events';
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_uib_area_target_id']['id'] = 'field_uib_area_target_id';
  $handler->display->display_options['relationships']['field_uib_area_target_id']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['relationships']['field_uib_area_target_id']['field'] = 'field_uib_area_target_id';
  $handler->display->display_options['relationships']['field_uib_area_target_id']['required'] = TRUE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_uib_date] - [title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date_1']['id'] = 'field_uib_date_1';
  $handler->display->display_options['fields']['field_uib_date_1']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date_1']['settings'] = array(
    'format_type' => 'day_and_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Event type */
  $handler->display->display_options['fields']['field_uib_event_type']['id'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['field'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['text'] = '<h2>[field_uib_event_type]</h2>';
  $handler->display->display_options['fields']['field_uib_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['field_uib_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['type'] = 'i18n_list_default';
  /* Sort criterion: Content: Date -  start date (field_uib_date) */
  $handler->display->display_options['sorts']['field_uib_date_value']['id'] = 'field_uib_date_value';
  $handler->display->display_options['sorts']['field_uib_date_value']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['sorts']['field_uib_date_value']['field'] = 'field_uib_date_value';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );

  /* Display: Area calendar block */
  $handler = $view->new_display('block', 'Area calendar block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View full calendar';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_2';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Event type */
  $handler->display->display_options['fields']['field_uib_event_type']['id'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['field'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_event_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['type'] = 'i18n_list_default';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_uib_date] - [title] ([field_uib_event_type])';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date_1']['id'] = 'field_uib_date_1';
  $handler->display->display_options['fields']['field_uib_date_1']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date_1']['settings'] = array(
    'format_type' => 'day_and_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Date -  start date (field_uib_date) */
  $handler->display->display_options['filters']['field_uib_date_value']['id'] = 'field_uib_date_value';
  $handler->display->display_options['filters']['field_uib_date_value']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['filters']['field_uib_date_value']['field'] = 'field_uib_date_value';
  $handler->display->display_options['filters']['field_uib_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_uib_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Event type (field_uib_event_type) */
  $handler->display->display_options['filters']['field_uib_event_type_value']['id'] = 'field_uib_event_type_value';
  $handler->display->display_options['filters']['field_uib_event_type_value']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['filters']['field_uib_event_type_value']['field'] = 'field_uib_event_type_value';
  $handler->display->display_options['filters']['field_uib_event_type_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_uib_event_type_value']['value'] = array(
    'exhibition' => 'exhibition',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['block_description'] = 'Calendar';

  /* Display: Month */
  $handler = $view->new_display('page', 'Month', 'page_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'field_uib_event_type_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['pager_position'] = 'bottom';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uib_date_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Entity: Rendered entity */
  $handler->display->display_options['header']['entity']['id'] = 'entity';
  $handler->display->display_options['header']['entity']['table'] = 'entity__global';
  $handler->display->display_options['header']['entity']['field'] = 'entity';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Event type */
  $handler->display->display_options['fields']['field_uib_event_type']['id'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['field'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_event_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['text'] = '<h2>[field_uib_event_type]</h2>';
  $handler->display->display_options['fields']['field_uib_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['field_uib_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['type'] = 'i18n_list_default';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_uib_date] - [title] ([field_uib_event_type])';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date_1']['id'] = 'field_uib_date_1';
  $handler->display->display_options['fields']['field_uib_date_1']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date_1']['settings'] = array(
    'format_type' => 'day_and_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_uib_date.field_uib_date_value' => 'field_data_field_uib_date.field_uib_date_value',
  );
  /* Contextual filter: Content: Event type (field_uib_event_type) */
  $handler->display->display_options['arguments']['field_uib_event_type_value']['id'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['field'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_event_type_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'node/%/calendar';

  /* Display: Day */
  $handler = $view->new_display('page', 'Day', 'page_4');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'field_uib_event_type_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'dateday';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Event type */
  $handler->display->display_options['fields']['field_uib_event_type']['id'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['field'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_event_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['text'] = '<h2>[field_uib_event_type]</h2>';
  $handler->display->display_options['fields']['field_uib_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['field_uib_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['type'] = 'i18n_list_default';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_uib_date] - [title] ([field_uib_event_type])';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date_1']['id'] = 'field_uib_date_1';
  $handler->display->display_options['fields']['field_uib_date_1']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date_1']['settings'] = array(
    'format_type' => 'day_and_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_uib_date.field_uib_date_value' => 'field_data_field_uib_date.field_uib_date_value',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'node/%/calendar/day';

  /* Display: Mini calendar */
  $handler = $view->new_display('block', 'Mini calendar', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Show entire year.';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'node/!1/calendar/year';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '2';
  $handler->display->display_options['style_options']['mini'] = '1';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'uib_article' => '#ffffff',
    'area' => '#ffffff',
    'uib_ou' => '#ffffff',
    'uib_testimonial' => '#ffffff',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_uib_date.field_uib_date_value' => 'field_data_field_uib_date.field_uib_date_value',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Exhibitions  */
  $handler = $view->new_display('block', 'Exhibitions ', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Exhibitions ';
  $handler->display->display_options['display_description'] = 'List all events of type exhibitions ';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] <br>([field_uib_date])';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date_1']['id'] = 'field_uib_date_1';
  $handler->display->display_options['fields']['field_uib_date_1']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date_1']['settings'] = array(
    'format_type' => 'day_and_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Event type */
  $handler->display->display_options['fields']['field_uib_event_type']['id'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['field'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_event_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['text'] = '<h2>[field_uib_event_type]</h2>';
  $handler->display->display_options['fields']['field_uib_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['field_uib_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['type'] = 'i18n_list_default';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Event type (field_uib_event_type) */
  $handler->display->display_options['filters']['field_uib_event_type_value']['id'] = 'field_uib_event_type_value';
  $handler->display->display_options['filters']['field_uib_event_type_value']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['filters']['field_uib_event_type_value']['field'] = 'field_uib_event_type_value';
  $handler->display->display_options['filters']['field_uib_event_type_value']['value'] = array(
    'exhibition' => 'exhibition',
  );
  /* Filter criterion: Content: Date - end date (field_uib_date:value2) */
  $handler->display->display_options['filters']['field_uib_date_value2']['id'] = 'field_uib_date_value2';
  $handler->display->display_options['filters']['field_uib_date_value2']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['filters']['field_uib_date_value2']['field'] = 'field_uib_date_value2';
  $handler->display->display_options['filters']['field_uib_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_uib_date_value2']['default_date'] = 'now';
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['block_description'] = 'Exhibitions ';

  /* Display: Event filter */
  $handler = $view->new_display('block', 'Event filter', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = '';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['date_argument']['default_argument_options']['code'] = 'if (isset($_GET["date"])) {return $_GET["date"];} else {return date_format(date_now(), "Y-m");}';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_uib_date.field_uib_date_value' => 'field_data_field_uib_date.field_uib_date_value',
  );
  /* Contextual filter: Content: Event type (field_uib_event_type) */
  $handler->display->display_options['arguments']['field_uib_event_type_value']['id'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['field'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['human'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_event_type_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_event_type_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['link_field'] = 'path';
  $handler->display->display_options['row_options']['description_field'] = 'nothing';
  $handler->display->display_options['row_options']['creator_field'] = 'uid';
  $handler->display->display_options['row_options']['date_field'] = 'created';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'nid',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_uib_date] - [title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date_1']['id'] = 'field_uib_date_1';
  $handler->display->display_options['fields']['field_uib_date_1']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['label'] = 'Start date';
  $handler->display->display_options['fields']['field_uib_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = 'End date';
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Event type */
  $handler->display->display_options['fields']['field_uib_event_type']['id'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['field'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['text'] = '<h2>[field_uib_event_type]</h2>';
  $handler->display->display_options['fields']['field_uib_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['field_uib_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['type'] = 'i18n_list_default';
  /* Field: Content: Lead */
  $handler->display->display_options['fields']['field_uib_lead']['id'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['table'] = 'field_data_field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['field'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['label'] = '';
  $handler->display->display_options['fields']['field_uib_lead']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_lead']['hide_alter_empty'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'r';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_uib_date_1] - [field_uib_date]
[field_uib_lead]';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_uib_date) */
  $handler->display->display_options['sorts']['field_uib_date_value']['id'] = 'field_uib_date_value';
  $handler->display->display_options['sorts']['field_uib_date_value']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['sorts']['field_uib_date_value']['field'] = 'field_uib_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Date -  start date (field_uib_date) */
  $handler->display->display_options['filters']['field_uib_date_value']['id'] = 'field_uib_date_value';
  $handler->display->display_options['filters']['field_uib_date_value']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['filters']['field_uib_date_value']['field'] = 'field_uib_date_value';
  $handler->display->display_options['filters']['field_uib_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_uib_date_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'node/%/calrss.xml';

  /* Display: Year */
  $handler = $view->new_display('page', 'Year', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Calendar - Year';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'field_uib_event_type_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'dateyear';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uib_date_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Entity: Rendered entity */
  $handler->display->display_options['header']['entity']['id'] = 'entity';
  $handler->display->display_options['header']['entity']['table'] = 'entity__global';
  $handler->display->display_options['header']['entity']['field'] = 'entity';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Event type */
  $handler->display->display_options['fields']['field_uib_event_type']['id'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['field'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_event_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['text'] = '<h2>[field_uib_event_type]</h2>';
  $handler->display->display_options['fields']['field_uib_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['field_uib_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['type'] = 'i18n_list_default';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_uib_date] - [title] ([field_uib_event_type])';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date_1']['id'] = 'field_uib_date_1';
  $handler->display->display_options['fields']['field_uib_date_1']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date_1']['settings'] = array(
    'format_type' => 'day_and_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_uib_date.field_uib_date_value' => 'field_data_field_uib_date.field_uib_date_value',
  );
  /* Contextual filter: Content: Event type (field_uib_event_type) */
  $handler->display->display_options['arguments']['field_uib_event_type_value']['id'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['field'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_event_type_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'node/%/calendar/year';

  /* Display: Event filter year */
  $handler = $view->new_display('block', 'Event filter year', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['date_argument']['default_argument_options']['code'] = 'if (isset($_GET["dateyear"])) {return $_GET["dateyear"];} else {return date_format(date_now(), "Y");}';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_uib_date.field_uib_date_value' => 'field_data_field_uib_date.field_uib_date_value',
  );
  /* Contextual filter: Content: Event type (field_uib_event_type) */
  $handler->display->display_options['arguments']['field_uib_event_type_value']['id'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['field'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['human'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_event_type_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_event_type_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $translatables['calendar'] = array(
    t('Master'),
    t('Calendar'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Sorry, no events'),
    t('Content entity referenced from field_uib_area'),
    t('[field_uib_date] - [title]'),
    t('<h2>[field_uib_event_type]</h2>'),
    t('All'),
    t('Area calendar block'),
    t('View full calendar'),
    t('[field_uib_date] - [title] ([field_uib_event_type])'),
    t('Month'),
    t('Advanced options'),
    t('Select any filter and click on Apply to see results'),
    t('Day'),
    t('Mini calendar'),
    t('Show entire year.'),
    t('Exhibitions '),
    t('List all events of type exhibitions '),
    t('[title] <br>([field_uib_date])'),
    t('Event filter'),
    t('Feed'),
    t('Start date'),
    t('End date'),
    t('Post date'),
    t('Path'),
    t('Custom text'),
    t('[field_uib_date_1] - [field_uib_date]
[field_uib_lead]'),
    t('Year'),
    t('Calendar - Year'),
    t('Event filter year'),
  );
  $export['calendar'] = $view;

  $view = new view();
  $view->name = 'global_calendar';
  $view->description = 'Lists accouring to date field';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Global calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Calendar';
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uib_date_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Sorry, no events';
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_uib_date] - [title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date_1']['id'] = 'field_uib_date_1';
  $handler->display->display_options['fields']['field_uib_date_1']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date_1']['settings'] = array(
    'format_type' => 'day_and_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Event type */
  $handler->display->display_options['fields']['field_uib_event_type']['id'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['field'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['text'] = '<h2>[field_uib_event_type]</h2>';
  $handler->display->display_options['fields']['field_uib_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['field_uib_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['type'] = 'i18n_list_default';
  /* Sort criterion: Content: Date -  start date (field_uib_date) */
  $handler->display->display_options['sorts']['field_uib_date_value']['id'] = 'field_uib_date_value';
  $handler->display->display_options['sorts']['field_uib_date_value']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['sorts']['field_uib_date_value']['field'] = 'field_uib_date_value';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Show in global calendar (field_uib_show_global_calendar) */
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['id'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['table'] = 'field_data_field_uib_show_global_calendar';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['field'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['value'] = array(
    0 => '0',
  );

  /* Display: Month */
  $handler = $view->new_display('page', 'Month', 'page_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'field_uib_event_type_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['pager_position'] = 'bottom';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uib_date_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Entity: Rendered entity */
  $handler->display->display_options['header']['entity']['id'] = 'entity';
  $handler->display->display_options['header']['entity']['table'] = 'entity__global';
  $handler->display->display_options['header']['entity']['field'] = 'entity';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Event type */
  $handler->display->display_options['fields']['field_uib_event_type']['id'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['field'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_event_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['text'] = '<h2>[field_uib_event_type]</h2>';
  $handler->display->display_options['fields']['field_uib_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['field_uib_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['type'] = 'i18n_list_default';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_uib_date] - [title] ([field_uib_event_type])';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date_1']['id'] = 'field_uib_date_1';
  $handler->display->display_options['fields']['field_uib_date_1']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date_1']['settings'] = array(
    'format_type' => 'day_and_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_uib_date.field_uib_date_value' => 'field_data_field_uib_date.field_uib_date_value',
  );
  /* Contextual filter: Content: Event type (field_uib_event_type) */
  $handler->display->display_options['arguments']['field_uib_event_type_value']['id'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['field'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_event_type_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Show in global calendar (field_uib_show_global_calendar) */
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['id'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['table'] = 'field_data_field_uib_show_global_calendar';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['field'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'calendar';

  /* Display: Day */
  $handler = $view->new_display('page', 'Day', 'page_4');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'field_uib_event_type_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'dateday';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Event type */
  $handler->display->display_options['fields']['field_uib_event_type']['id'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['field'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_event_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['text'] = '<h2>[field_uib_event_type]</h2>';
  $handler->display->display_options['fields']['field_uib_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['field_uib_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['type'] = 'i18n_list_default';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_uib_date] - [title] ([field_uib_event_type])';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date_1']['id'] = 'field_uib_date_1';
  $handler->display->display_options['fields']['field_uib_date_1']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date_1']['settings'] = array(
    'format_type' => 'day_and_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_uib_date.field_uib_date_value' => 'field_data_field_uib_date.field_uib_date_value',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: Show in global calendar (field_uib_show_global_calendar) */
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['id'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['table'] = 'field_data_field_uib_show_global_calendar';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['field'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'calendar/day';

  /* Display: Mini calendar */
  $handler = $view->new_display('block', 'Mini calendar', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Show entire year.';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'calendar/year';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '2';
  $handler->display->display_options['style_options']['mini'] = '1';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['calendar_colors_type'] = array(
    'uib_article' => '#ffffff',
    'area' => '#ffffff',
    'uib_ou' => '#ffffff',
    'uib_testimonial' => '#ffffff',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_uib_date.field_uib_date_value' => 'field_data_field_uib_date.field_uib_date_value',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: Show in global calendar (field_uib_show_global_calendar) */
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['id'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['table'] = 'field_data_field_uib_show_global_calendar';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['field'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['operator'] = 'not empty';

  /* Display: Event filter */
  $handler = $view->new_display('block', 'Event filter', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = '';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_2';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['date_argument']['default_argument_options']['code'] = 'if (isset($_GET["date"])) {return $_GET["date"];} else {return date_format(date_now(), "Y-m");}';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_uib_date.field_uib_date_value' => 'field_data_field_uib_date.field_uib_date_value',
  );
  /* Contextual filter: Content: Event type (field_uib_event_type) */
  $handler->display->display_options['arguments']['field_uib_event_type_value']['id'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['field'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['human'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_event_type_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_event_type_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: Show in global calendar (field_uib_show_global_calendar) */
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['id'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['table'] = 'field_data_field_uib_show_global_calendar';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['field'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['value'] = array(
    1 => '1',
  );

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['link_field'] = 'path';
  $handler->display->display_options['row_options']['description_field'] = 'nothing';
  $handler->display->display_options['row_options']['creator_field'] = 'uid';
  $handler->display->display_options['row_options']['date_field'] = 'created';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'nid',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_uib_date] - [title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date_1']['id'] = 'field_uib_date_1';
  $handler->display->display_options['fields']['field_uib_date_1']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['label'] = 'Start date';
  $handler->display->display_options['fields']['field_uib_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = 'End date';
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Event type */
  $handler->display->display_options['fields']['field_uib_event_type']['id'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['field'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['text'] = '<h2>[field_uib_event_type]</h2>';
  $handler->display->display_options['fields']['field_uib_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['field_uib_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['type'] = 'i18n_list_default';
  /* Field: Content: Lead */
  $handler->display->display_options['fields']['field_uib_lead']['id'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['table'] = 'field_data_field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['field'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['label'] = '';
  $handler->display->display_options['fields']['field_uib_lead']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_lead']['hide_alter_empty'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'r';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_uib_date_1] - [field_uib_date]
[field_uib_lead]';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_uib_date) */
  $handler->display->display_options['sorts']['field_uib_date_value']['id'] = 'field_uib_date_value';
  $handler->display->display_options['sorts']['field_uib_date_value']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['sorts']['field_uib_date_value']['field'] = 'field_uib_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Date -  start date (field_uib_date) */
  $handler->display->display_options['filters']['field_uib_date_value']['id'] = 'field_uib_date_value';
  $handler->display->display_options['filters']['field_uib_date_value']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['filters']['field_uib_date_value']['field'] = 'field_uib_date_value';
  $handler->display->display_options['filters']['field_uib_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_uib_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Show in global calendar (field_uib_show_global_calendar) */
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['id'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['table'] = 'field_data_field_uib_show_global_calendar';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['field'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'calrss.xml';

  /* Display: Year */
  $handler = $view->new_display('page', 'Year', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Calendar - Year';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'field_uib_event_type_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'dateyear';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uib_date_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Entity: Rendered entity */
  $handler->display->display_options['header']['entity']['id'] = 'entity';
  $handler->display->display_options['header']['entity']['table'] = 'entity__global';
  $handler->display->display_options['header']['entity']['field'] = 'entity';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Event type */
  $handler->display->display_options['fields']['field_uib_event_type']['id'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['field'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_event_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['text'] = '<h2>[field_uib_event_type]</h2>';
  $handler->display->display_options['fields']['field_uib_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['field_uib_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['type'] = 'i18n_list_default';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_uib_date] - [title] ([field_uib_event_type])';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date_1']['id'] = 'field_uib_date_1';
  $handler->display->display_options['fields']['field_uib_date_1']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date_1']['settings'] = array(
    'format_type' => 'day_and_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_uib_date.field_uib_date_value' => 'field_data_field_uib_date.field_uib_date_value',
  );
  /* Contextual filter: Content: Event type (field_uib_event_type) */
  $handler->display->display_options['arguments']['field_uib_event_type_value']['id'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['field'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_event_type_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: Show in global calendar (field_uib_show_global_calendar) */
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['id'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['table'] = 'field_data_field_uib_show_global_calendar';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['field'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'calendar/year';

  /* Display: Event filter year */
  $handler = $view->new_display('block', 'Event filter year', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['format'] = 'restricted_html';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['date_argument']['default_argument_options']['code'] = 'if (isset($_GET["dateyear"])) {return $_GET["dateyear"];} else {return date_format(date_now(), "Y");}';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_uib_date.field_uib_date_value' => 'field_data_field_uib_date.field_uib_date_value',
  );
  /* Contextual filter: Content: Event type (field_uib_event_type) */
  $handler->display->display_options['arguments']['field_uib_event_type_value']['id'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['field'] = 'field_uib_event_type_value';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_event_type_value']['summary']['human'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_event_type_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_event_type_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: Show in global calendar (field_uib_show_global_calendar) */
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['id'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['table'] = 'field_data_field_uib_show_global_calendar';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['field'] = 'field_uib_show_global_calendar_value';
  $handler->display->display_options['filters']['field_uib_show_global_calendar_value']['value'] = array(
    1 => '1',
  );
  $translatables['global_calendar'] = array(
    t('Master'),
    t('Calendar'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Sorry, no events'),
    t('[field_uib_date] - [title]'),
    t('<h2>[field_uib_event_type]</h2>'),
    t('All'),
    t('Month'),
    t('Advanced options'),
    t('Select any filter and click on Apply to see results'),
    t('[field_uib_date] - [title] ([field_uib_event_type])'),
    t('Day'),
    t('Mini calendar'),
    t('Show entire year.'),
    t('Event filter'),
    t('Feed'),
    t('Start date'),
    t('End date'),
    t('Post date'),
    t('Path'),
    t('Custom text'),
    t('[field_uib_date_1] - [field_uib_date]
[field_uib_lead]'),
    t('Year'),
    t('Calendar - Year'),
    t('Event filter year'),
  );
  $export['global_calendar'] = $view;

  return $export;
}
