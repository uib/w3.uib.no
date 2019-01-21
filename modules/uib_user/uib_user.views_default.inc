<?php

/**
 * @file
 * uib_user.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uib_user_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'user_name_overrides';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User name overrides';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User name overrides';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    176168899 => '176168899',
    74573517 => '74573517',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_uib_first_name' => 'field_uib_first_name',
    'field_uib_user_alt_firstname' => 'field_uib_user_alt_firstname',
    'field_uib_last_name' => 'field_uib_last_name',
    'field_uib_user_alt_lastname' => 'field_uib_user_alt_lastname',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uib_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uib_user_alt_firstname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uib_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_uib_user_alt_lastname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_uib_first_name']['id'] = 'field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['table'] = 'field_data_field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['field'] = 'field_uib_first_name';
  $handler->display->display_options['fields']['field_uib_first_name']['element_default_classes'] = FALSE;
  /* Field: User: Synchronised first name */
  $handler->display->display_options['fields']['field_uib_user_alt_firstname']['id'] = 'field_uib_user_alt_firstname';
  $handler->display->display_options['fields']['field_uib_user_alt_firstname']['table'] = 'field_data_field_uib_user_alt_firstname';
  $handler->display->display_options['fields']['field_uib_user_alt_firstname']['field'] = 'field_uib_user_alt_firstname';
  $handler->display->display_options['fields']['field_uib_user_alt_firstname']['element_default_classes'] = FALSE;
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_uib_last_name']['id'] = 'field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['table'] = 'field_data_field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['field'] = 'field_uib_last_name';
  $handler->display->display_options['fields']['field_uib_last_name']['element_default_classes'] = FALSE;
  /* Field: User: Synchronised last name */
  $handler->display->display_options['fields']['field_uib_user_alt_lastname']['id'] = 'field_uib_user_alt_lastname';
  $handler->display->display_options['fields']['field_uib_user_alt_lastname']['table'] = 'field_data_field_uib_user_alt_lastname';
  $handler->display->display_options['fields']['field_uib_user_alt_lastname']['field'] = 'field_uib_user_alt_lastname';
  $handler->display->display_options['fields']['field_uib_user_alt_lastname']['element_default_classes'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
  );
  /* Filter criterion: Global: Fields comparison */
  $handler->display->display_options['filters']['fields_compare']['id'] = 'fields_compare';
  $handler->display->display_options['filters']['fields_compare']['table'] = 'views';
  $handler->display->display_options['filters']['fields_compare']['field'] = 'fields_compare';
  $handler->display->display_options['filters']['fields_compare']['operator'] = '<>';
  $handler->display->display_options['filters']['fields_compare']['group'] = 1;
  $handler->display->display_options['filters']['fields_compare']['right_field'] = 'field_uib_user_alt_firstname';
  $handler->display->display_options['filters']['fields_compare']['left_field'] = 'field_uib_first_name';
  /* Filter criterion: Global: Fields comparison */
  $handler->display->display_options['filters']['fields_compare_1']['id'] = 'fields_compare_1';
  $handler->display->display_options['filters']['fields_compare_1']['table'] = 'views';
  $handler->display->display_options['filters']['fields_compare_1']['field'] = 'fields_compare';
  $handler->display->display_options['filters']['fields_compare_1']['operator'] = '<>';
  $handler->display->display_options['filters']['fields_compare_1']['group'] = 1;
  $handler->display->display_options['filters']['fields_compare_1']['right_field'] = 'field_uib_user_alt_lastname';
  $handler->display->display_options['filters']['fields_compare_1']['left_field'] = 'field_uib_last_name';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'user_name_overrides');
  $handler->display->display_options['path'] = 'webdesk/user-name-overrides';
  $translatables['user_name_overrides'] = array(
    t('Master'),
    t('User name overrides'),
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
    t('First name'),
    t('Synchronised first name'),
    t('Last name'),
    t('Synchronised last name'),
    t('Page'),
  );
  $export['user_name_overrides'] = $view;

  return $export;
}
