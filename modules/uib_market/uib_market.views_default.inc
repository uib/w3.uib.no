<?php
/**
 * @file
 * uib_market.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uib_market_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'internal_market';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Internal market';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Internal market';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Bruk';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Nullstill';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Avanserte valgmuligheter',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_uib_market_category_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'plain_text';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uib_market_category',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = 'Displaying @total notices';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_uib_market_category']['id'] = 'field_uib_market_category';
  $handler->display->display_options['fields']['field_uib_market_category']['table'] = 'field_data_field_uib_market_category';
  $handler->display->display_options['fields']['field_uib_market_category']['field'] = 'field_uib_market_category';
  $handler->display->display_options['fields']['field_uib_market_category']['label'] = '';
  $handler->display->display_options['fields']['field_uib_market_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_market_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_market_category']['settings'] = array(
    'linked_field' => array(
      'linked' => 0,
      'destination' => '',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Category (field_uib_market_category) */
  $handler->display->display_options['sorts']['field_uib_market_category_value']['id'] = 'field_uib_market_category_value';
  $handler->display->display_options['sorts']['field_uib_market_category_value']['table'] = 'field_data_field_uib_market_category';
  $handler->display->display_options['sorts']['field_uib_market_category_value']['field'] = 'field_uib_market_category_value';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uib_market' => 'uib_market',
  );
  /* Filter criterion: Content: Category (field_uib_market_category) */
  $handler->display->display_options['filters']['field_uib_market_category_value']['id'] = 'field_uib_market_category_value';
  $handler->display->display_options['filters']['field_uib_market_category_value']['table'] = 'field_data_field_uib_market_category';
  $handler->display->display_options['filters']['field_uib_market_category_value']['field'] = 'field_uib_market_category_value';
  $handler->display->display_options['filters']['field_uib_market_category_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_market_category_value']['expose']['operator_id'] = 'field_uib_market_category_value_op';
  $handler->display->display_options['filters']['field_uib_market_category_value']['expose']['label'] = 'Filter by category';
  $handler->display->display_options['filters']['field_uib_market_category_value']['expose']['operator'] = 'field_uib_market_category_value_op';
  $handler->display->display_options['filters']['field_uib_market_category_value']['expose']['identifier'] = 'field_uib_market_category_value';
  $handler->display->display_options['filters']['field_uib_market_category_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_uib_market_category_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'foremployees/market';
  $translatables['internal_market'] = array(
    t('Master'),
    t('Internal market'),
    t('more'),
    t('Bruk'),
    t('Nullstill'),
    t('Sort by'),
    t('Ascending'),
    t('Descending'),
    t('Avanserte valgmuligheter'),
    t('Select any filter and click on Apply to see results'),
    t('Displaying @total notices'),
    t('Filter by category'),
    t('Page'),
  );
  $export['internal_market'] = $view;

  return $export;
}
