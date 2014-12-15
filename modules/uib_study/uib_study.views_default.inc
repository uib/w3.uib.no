<?php
/**
 * @file
 * uib_study.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uib_study_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'exchange_agreements';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Exchange_agreements';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find exchange agreements';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_uib_study_code_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => 'Display recommended exchange agreements available for your <a class="uib-study-filter-link" href="studyprogramme">study programme</a>. Use the programme code.',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_uib_ou_title_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => 'Display exchange agreements for faculty or department.',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_uib_geographic_name_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => 'Display exchange agreements with one or more countries.',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'plain_text';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uib_geographic_name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>The University of Bergen has bilateral agreements, Erasmus agreements, and other network agreements with approximately 450 renowned universities around the world. This search page makes it easier for you to find the agreement most suitable for you. Filter by your study programme to get an overview of recommended exchange agreements. Alternatively, you may filter by faculty/department to obtain a list of exchange agreements that belong to your faculty/department. If you filter by "University of Bergen" (university-wide agreements) you will get an overview of exchange agreements through which most UiB students may apply for exchange.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_uib_study_part_of_target_id']['id'] = 'field_uib_study_part_of_target_id';
  $handler->display->display_options['relationships']['field_uib_study_part_of_target_id']['table'] = 'field_data_field_uib_study_part_of';
  $handler->display->display_options['relationships']['field_uib_study_part_of_target_id']['field'] = 'field_uib_study_part_of_target_id';
  $handler->display->display_options['relationships']['field_uib_study_part_of_target_id']['label'] = 'Study referenced from field_uib_study_part_of';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_uib_study_country_target_id']['id'] = 'field_uib_study_country_target_id';
  $handler->display->display_options['relationships']['field_uib_study_country_target_id']['table'] = 'field_data_field_uib_study_country';
  $handler->display->display_options['relationships']['field_uib_study_country_target_id']['field'] = 'field_uib_study_country_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_uib_ou_target_id']['id'] = 'field_uib_ou_target_id';
  $handler->display->display_options['relationships']['field_uib_ou_target_id']['table'] = 'field_data_field_uib_ou';
  $handler->display->display_options['relationships']['field_uib_ou_target_id']['field'] = 'field_uib_ou_target_id';
  /* Field: Taxonomy term: Geographic name */
  $handler->display->display_options['fields']['field_uib_geographic_name']['id'] = 'field_uib_geographic_name';
  $handler->display->display_options['fields']['field_uib_geographic_name']['table'] = 'field_data_field_uib_geographic_name';
  $handler->display->display_options['fields']['field_uib_geographic_name']['field'] = 'field_uib_geographic_name';
  $handler->display->display_options['fields']['field_uib_geographic_name']['relationship'] = 'field_uib_study_country_target_id';
  $handler->display->display_options['fields']['field_uib_geographic_name']['label'] = '';
  $handler->display->display_options['fields']['field_uib_geographic_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_geographic_name']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: ID */
  $handler->display->display_options['fields']['field_uib_study_code']['id'] = 'field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['field'] = 'field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_code']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_code']['alter']['text'] = 'Read student report';
  $handler->display->display_options['fields']['field_uib_study_code']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_code']['alter']['path'] = 'node/[nid]#uib-tabs-student-reports';
  $handler->display->display_options['fields']['field_uib_study_code']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_uib_study_title']['id'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['field'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_uib_study_title']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="agreement-title">[field_uib_study_title]</span><span class="studentreport-ref">[field_uib_study_code]</span>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'views-field views-field-field-uib-study-title';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Taxonomy term: Geographic name (field_uib_geographic_name) */
  $handler->display->display_options['sorts']['field_uib_geographic_name_value']['id'] = 'field_uib_geographic_name_value';
  $handler->display->display_options['sorts']['field_uib_geographic_name_value']['table'] = 'field_data_field_uib_geographic_name';
  $handler->display->display_options['sorts']['field_uib_geographic_name_value']['field'] = 'field_uib_geographic_name_value';
  $handler->display->display_options['sorts']['field_uib_geographic_name_value']['relationship'] = 'field_uib_study_country_target_id';
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
    'uib_study' => 'uib_study',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'exchange' => 'exchange',
  );
  $handler->display->display_options['filters']['field_uib_study_type_value']['group'] = 1;
  /* Filter criterion: Content: Title (field_uib_study_title:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: Taxonomy term: Geographic name (field_uib_geographic_name:language) */
  $handler->display->display_options['filters']['language_1']['id'] = 'language_1';
  $handler->display->display_options['filters']['language_1']['table'] = 'field_data_field_uib_geographic_name';
  $handler->display->display_options['filters']['language_1']['field'] = 'language';
  $handler->display->display_options['filters']['language_1']['relationship'] = 'field_uib_study_country_target_id';
  $handler->display->display_options['filters']['language_1']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language_1']['group'] = 1;
  $handler->display->display_options['filters']['language_1']['expose']['operator_id'] = 'language_1_op';
  $handler->display->display_options['filters']['language_1']['expose']['label'] = 'Geographic name (field_uib_geographic_name:language)';
  $handler->display->display_options['filters']['language_1']['expose']['operator'] = 'language_1_op';
  $handler->display->display_options['filters']['language_1']['expose']['identifier'] = 'language_1';
  $handler->display->display_options['filters']['language_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['language_1']['group_info']['label'] = 'Geographic name (field_uib_geographic_name:language)';
  $handler->display->display_options['filters']['language_1']['group_info']['identifier'] = 'language_1';
  $handler->display->display_options['filters']['language_1']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['language_1']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['filters']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['filters']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['relationship'] = 'field_uib_study_part_of_target_id';
  $handler->display->display_options['filters']['field_uib_study_code_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_uib_study_code_value']['group'] = 1;
  $handler->display->display_options['filters']['field_uib_study_code_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_study_code_value']['expose']['operator_id'] = 'field_uib_study_code_value_op';
  $handler->display->display_options['filters']['field_uib_study_code_value']['expose']['label'] = 'Filter by study programmes';
  $handler->display->display_options['filters']['field_uib_study_code_value']['expose']['operator'] = 'field_uib_study_code_value_op';
  $handler->display->display_options['filters']['field_uib_study_code_value']['expose']['identifier'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  /* Filter criterion: Content: Name (field_uib_ou_title) */
  $handler->display->display_options['filters']['field_uib_ou_title_value']['id'] = 'field_uib_ou_title_value';
  $handler->display->display_options['filters']['field_uib_ou_title_value']['table'] = 'field_data_field_uib_ou_title';
  $handler->display->display_options['filters']['field_uib_ou_title_value']['field'] = 'field_uib_ou_title_value';
  $handler->display->display_options['filters']['field_uib_ou_title_value']['relationship'] = 'field_uib_ou_target_id';
  $handler->display->display_options['filters']['field_uib_ou_title_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_uib_ou_title_value']['group'] = 1;
  $handler->display->display_options['filters']['field_uib_ou_title_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_ou_title_value']['expose']['operator_id'] = 'field_uib_ou_title_value_op';
  $handler->display->display_options['filters']['field_uib_ou_title_value']['expose']['label'] = 'Filter by faculty/department';
  $handler->display->display_options['filters']['field_uib_ou_title_value']['expose']['operator'] = 'field_uib_ou_title_value_op';
  $handler->display->display_options['filters']['field_uib_ou_title_value']['expose']['identifier'] = 'field_uib_ou_title_value';
  $handler->display->display_options['filters']['field_uib_ou_title_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_uib_ou_title_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['field_uib_ou_title_value']['group_info']['label'] = 'Name (field_uib_ou_title)';
  $handler->display->display_options['filters']['field_uib_ou_title_value']['group_info']['identifier'] = 'field_uib_ou_title_value';
  $handler->display->display_options['filters']['field_uib_ou_title_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_uib_ou_title_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Taxonomy term: Geographic name (field_uib_geographic_name) */
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['id'] = 'field_uib_geographic_name_value';
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['table'] = 'field_data_field_uib_geographic_name';
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['field'] = 'field_uib_geographic_name_value';
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['relationship'] = 'field_uib_study_country_target_id';
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['expose']['operator_id'] = 'field_uib_geographic_name_value_op';
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['expose']['label'] = 'Filter by country';
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['expose']['operator'] = 'field_uib_geographic_name_value_op';
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['expose']['identifier'] = 'field_uib_geographic_name_value';
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['group_info']['label'] = 'Geographic name (field_uib_geographic_name)';
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['group_info']['identifier'] = 'field_uib_geographic_name_value';
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_uib_geographic_name_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'exchange-agreement';
  $translatables['exchange_agreements'] = array(
    t('Master'),
    t('Find exchange agreements'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('<p>The University of Bergen has bilateral agreements, Erasmus agreements, and other network agreements with approximately 450 renowned universities around the world. This search page makes it easier for you to find the agreement most suitable for you. Filter by your study programme to get an overview of recommended exchange agreements. Alternatively, you may filter by faculty/department to obtain a list of exchange agreements that belong to your faculty/department. If you filter by "University of Bergen" (university-wide agreements) you will get an overview of exchange agreements through which most UiB students may apply for exchange.</p>'),
    t('Translations'),
    t('Study referenced from field_uib_study_part_of'),
    t('Taxonomy term entity referenced from field_uib_study_country'),
    t('Content entity referenced from field_uib_ou'),
    t('Read student report'),
    t('<span class="agreement-title">[field_uib_study_title]</span><span class="studentreport-ref">[field_uib_study_code]</span>'),
    t('Geographic name (field_uib_geographic_name:language)'),
    t('Filter by study programmes'),
    t('Filter by faculty/department'),
    t('Name (field_uib_ou_title)'),
    t('Filter by country'),
    t('Geographic name (field_uib_geographic_name)'),
    t('Page'),
  );
  $export['exchange_agreements'] = $view;

  $view = new view();
  $view->name = 'special_study_listings';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Special study listings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Courses for exchange students';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'term_node_tid_depth' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = TRUE;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'uib_study_labels' => 'uib_study_labels',
    'uib_nus' => 0,
  );
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Field: Content: ID */
  $handler->display->display_options['fields']['field_uib_study_code']['id'] = 'field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['field'] = 'field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_code']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_uib_study_title']['id'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['field'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['text'] = '<a href="[path]">[field_uib_study_title]</a>';
  $handler->display->display_options['fields']['field_uib_study_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_study_title']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Title (field_uib_study_title) */
  $handler->display->display_options['sorts']['field_uib_study_title_value']['id'] = 'field_uib_study_title_value';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['field'] = 'field_uib_study_title_value';
  /* Sort criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['sorts']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['sorts']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['sorts']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
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
    'uib_study' => 'uib_study',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['name']['value'] = 'english';
  /* Filter criterion: Content: Title (field_uib_study_title:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    1 => '1',
    8 => '8',
    13 => '13',
    23 => '23',
    30 => '30',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Filter by subject';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['label'] = 'Has taxonomy terms (with depth)';
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'uib_nus';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '3';

  /* Display: Exchange */
  $handler = $view->new_display('page', 'Exchange', 'exchange');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: ID */
  $handler->display->display_options['fields']['field_uib_study_code']['id'] = 'field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['field'] = 'field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_code']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_uib_study_title']['id'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['field'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['text'] = '<a href="[path]">[field_uib_study_code] / [field_uib_study_title]</a>';
  $handler->display->display_options['fields']['field_uib_study_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_study_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['sorts']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['sorts']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['sorts']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
  /* Sort criterion: Content: Title (field_uib_study_title) */
  $handler->display->display_options['sorts']['field_uib_study_title_value']['id'] = 'field_uib_study_title_value';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['field'] = 'field_uib_study_title_value';
  $handler->display->display_options['path'] = 'education/exchange';

  /* Display: Quota */
  $handler = $view->new_display('page', 'Quota', 'quota');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Master\'s Programmes - Quota';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'uib_study' => 'uib_study',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['name']['value'] = 'kvote';
  /* Filter criterion: Content: Title (field_uib_study_title:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    1 => '1',
    8 => '8',
    13 => '13',
    23 => '23',
    30 => '30',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Filter by subject';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['label'] = 'Has taxonomy terms (with depth)';
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'uib_nus';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '3';
  $handler->display->display_options['path'] = 'education/quota';

  /* Display: Self-financing */
  $handler = $view->new_display('page', 'Self-financing', 'self_financing');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Master\'s Programmes - Self-financing';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'uib_study' => 'uib_study',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['name']['value'] = 'intgrad';
  /* Filter criterion: Content: Title (field_uib_study_title:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    1 => '1',
    8 => '8',
    13 => '13',
    23 => '23',
    30 => '30',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Filter by subject';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['label'] = 'Has taxonomy terms (with depth)';
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['term_node_tid_depth']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'uib_nus';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '3';
  $handler->display->display_options['path'] = 'education/self-financing';
  $translatables['special_study_listings'] = array(
    t('Master'),
    t('Courses for exchange students'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('term'),
    t('Translations'),
    t('<a href="[path]">[field_uib_study_title]</a>'),
    t('Filter by subject'),
    t('Has taxonomy terms (with depth)'),
    t('Exchange'),
    t('<a href="[path]">[field_uib_study_code] / [field_uib_study_title]</a>'),
    t('Quota'),
    t('Master\'s Programmes - Quota'),
    t('Self-financing'),
    t('Master\'s Programmes - Self-financing'),
  );
  $export['special_study_listings'] = $view;

  $view = new view();
  $view->name = 'uib_nus_overview';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Disciplines';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Studies';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'uib_nus' => 'uib_nus',
  );
  /* Filter criterion: Taxonomy term: Parent term */
  $handler->display->display_options['filters']['parent']['id'] = 'parent';
  $handler->display->display_options['filters']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['filters']['parent']['field'] = 'parent';
  $handler->display->display_options['filters']['parent']['value']['value'] = '0';
  /* Filter criterion: Taxonomy term: NUS ID (field_uib_nus_id) */
  $handler->display->display_options['filters']['field_uib_nus_id_value']['id'] = 'field_uib_nus_id_value';
  $handler->display->display_options['filters']['field_uib_nus_id_value']['table'] = 'field_data_field_uib_nus_id';
  $handler->display->display_options['filters']['field_uib_nus_id_value']['field'] = 'field_uib_nus_id_value';
  $handler->display->display_options['filters']['field_uib_nus_id_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_uib_nus_id_value']['value'] = '9';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'education/nus';
  $translatables['uib_nus_overview'] = array(
    t('Master'),
    t('Studies'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Page'),
  );
  $export['uib_nus_overview'] = $view;

  $view = new view();
  $view->name = 'uib_study_specialization';
  $view->description = 'List all specializations that belong to a study';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Specializations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Specializations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'specialization';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_uib_study_title']['id'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['field'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['text'] = '<a href="[path]">[field_uib_study_title]</a>';
  $handler->display->display_options['fields']['field_uib_study_title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title (field_uib_study_title) */
  $handler->display->display_options['sorts']['field_uib_study_title_value']['id'] = 'field_uib_study_title_value';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['field'] = 'field_uib_study_title_value';
  /* Contextual filter: Content: Part of study (field_uib_study_part_of) */
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['id'] = 'field_uib_study_part_of_target_id';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['table'] = 'field_data_field_uib_study_part_of';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['field'] = 'field_uib_study_part_of_target_id';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['summary_options']['items_per_page'] = '25';
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
    'uib_study' => 'uib_study',
  );
  /* Filter criterion: Content: Title (field_uib_study_title:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'specialization' => 'specialization',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Specializations';

  /* Display: Subview */
  $handler = $view->new_display('attachment', 'Subview', 'attachment_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Part of study (field_uib_study_part_of) */
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['id'] = 'field_uib_study_part_of_target_id';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['table'] = 'field_data_field_uib_study_part_of';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['field'] = 'field_uib_study_part_of_target_id';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_study_part_of_target_id']['specify_validation'] = TRUE;
  $translatables['uib_study_specialization'] = array(
    t('Master'),
    t('Specializations'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a href="[path]">[field_uib_study_title]</a>'),
    t('Alle'),
    t('Block'),
    t('Subview'),
  );
  $export['uib_study_specialization'] = $view;

  $view = new view();
  $view->name = 'uib_taxonomy_term';
  $view->description = 'A view to emulate Drupal core\'s handling of taxonomy/term.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'UiB Taxonomy term';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uib_study_category',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_uib_study_category']['id'] = 'field_uib_study_category';
  $handler->display->display_options['fields']['field_uib_study_category']['table'] = 'field_data_field_uib_study_category';
  $handler->display->display_options['fields']['field_uib_study_category']['field'] = 'field_uib_study_category';
  $handler->display->display_options['fields']['field_uib_study_category']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_study_category']['type'] = 'i18n_list_default';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_uib_study_title']['id'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['field'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['text'] = '<a href="[path]">[field_uib_study_title]</a>';
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['path'] = '!1';
  $handler->display->display_options['fields']['field_uib_study_title']['element_type'] = '0';
  $handler->display->display_options['fields']['field_uib_study_title']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Global: View */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['view']['view'] = 'uib_study_specialization';
  $handler->display->display_options['fields']['view']['display'] = 'attachment_1';
  $handler->display->display_options['fields']['view']['arguments'] = '[%nid]';
  /* Sort criterion: Content: Category (field_uib_study_category) */
  $handler->display->display_options['sorts']['field_uib_study_category_value']['id'] = 'field_uib_study_category_value';
  $handler->display->display_options['sorts']['field_uib_study_category_value']['table'] = 'field_data_field_uib_study_category';
  $handler->display->display_options['sorts']['field_uib_study_category_value']['field'] = 'field_uib_study_category_value';
  /* Sort criterion: Content: Title (field_uib_study_title) */
  $handler->display->display_options['sorts']['field_uib_study_title_value']['id'] = 'field_uib_study_title_value';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['field'] = 'field_uib_study_title_value';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['specify_validation'] = TRUE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 1;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'program' => 'program',
  );
  $handler->display->display_options['filters']['field_uib_study_type_value']['group'] = 1;
  /* Filter criterion: Content: Title (field_uib_study_title:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title (field_uib_study_title) */
  $handler->display->display_options['sorts']['field_uib_study_title_value']['id'] = 'field_uib_study_title_value';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['field'] = 'field_uib_study_title_value';
  $handler->display->display_options['path'] = 'taxonomy/term/%';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 15;
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'taxonomy/term/%/%/feed';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'page' => 0,
  );
  $translatables['uib_taxonomy_term'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Translations'),
    t('<a href="[path]">[field_uib_study_title]</a>'),
    t('All'),
    t('%1'),
    t('Page'),
    t('Feed'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
  );
  $export['uib_taxonomy_term'] = $view;

  return $export;
}
