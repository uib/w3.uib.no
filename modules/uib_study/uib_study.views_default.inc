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
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Nullstill';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Synkende';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'term_node_tid_depth_1' => array(
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
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'term_node_tid_depth' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
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
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_uib_study_country_target_id']['id'] = 'field_uib_study_country_target_id';
  $handler->display->display_options['relationships']['field_uib_study_country_target_id']['table'] = 'field_data_field_uib_study_country';
  $handler->display->display_options['relationships']['field_uib_study_country_target_id']['field'] = 'field_uib_study_country_target_id';
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
  /* Sort criterion: Content: Title (field_uib_study_title) */
  $handler->display->display_options['sorts']['field_uib_study_title_value']['id'] = 'field_uib_study_title_value';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['field'] = 'field_uib_study_title_value';
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
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth_1']['id'] = 'term_node_tid_depth_1';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['value'] = array(
    2273 => '2273',
    2317 => '2317',
    2283 => '2283',
    2294 => '2294',
    2318 => '2318',
    2308 => '2308',
    2271 => '2271',
  );
  $handler->display->display_options['filters']['term_node_tid_depth_1']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['operator_id'] = 'term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['label'] = 'Search for faculty';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['operator'] = 'term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['identifier'] = 'term_node_tid_depth_1';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['vocabulary'] = 'uib_organisation';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['depth'] = '3';
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = '';
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Search for country or continent';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['description'] = 'Display exchange agreements with one or more countries.';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'uib_geography';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';
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

  /* Display: Blokk */
  $handler = $view->new_display('block', 'Blokk', 'b1');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Nullstill';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Synkende';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'term_node_tid_depth_1' => array(
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
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'term_node_tid_depth' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
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
    'field_uib_study_code_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => 'Display exchange agreements that are connected to a study programme. Use the <a href="/en/studyprogramme">study programme code</a>.',
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_uib_study_country_target_id']['id'] = 'field_uib_study_country_target_id';
  $handler->display->display_options['relationships']['field_uib_study_country_target_id']['table'] = 'field_data_field_uib_study_country';
  $handler->display->display_options['relationships']['field_uib_study_country_target_id']['field'] = 'field_uib_study_country_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_uib_study_part_of_target_id']['id'] = 'field_uib_study_part_of_target_id';
  $handler->display->display_options['relationships']['field_uib_study_part_of_target_id']['table'] = 'field_data_field_uib_study_part_of';
  $handler->display->display_options['relationships']['field_uib_study_part_of_target_id']['field'] = 'field_uib_study_part_of_target_id';
  $handler->display->display_options['relationships']['field_uib_study_part_of_target_id']['label'] = 'Innhold entity referenced from field_uib_study_part_of';
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'exchange' => 'exchange',
  );
  $handler->display->display_options['filters']['field_uib_study_type_value']['group'] = 1;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    2924 => '2924',
  );
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'uib_study_labels';
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth_1']['id'] = 'term_node_tid_depth_1';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['value'] = array(
    2273 => '2273',
    2317 => '2317',
    2283 => '2283',
    2294 => '2294',
    2318 => '2318',
    2308 => '2308',
    2271 => '2271',
  );
  $handler->display->display_options['filters']['term_node_tid_depth_1']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['operator_id'] = 'term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['label'] = 'Filter by faculty';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['operator'] = 'term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['identifier'] = 'term_node_tid_depth_1';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['vocabulary'] = 'uib_organisation';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['depth'] = '3';
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = '';
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Filter by country or continent';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['description'] = 'Display exchange agreements with one or more countries.';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'uib_geography';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';
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
  /* Filter criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['filters']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['filters']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['relationship'] = 'field_uib_study_part_of_target_id';
  $handler->display->display_options['filters']['field_uib_study_code_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_uib_study_code_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_study_code_value']['expose']['operator_id'] = 'field_uib_study_code_value_op';
  $handler->display->display_options['filters']['field_uib_study_code_value']['expose']['label'] = 'Filter by study programme';
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

  /* Display: Teacher exchange block */
  $handler = $view->new_display('block', 'Teacher exchange block', 'b2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_uib_study_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_study_title']['settings'] = array(
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'exchange' => 'exchange',
  );
  $handler->display->display_options['filters']['field_uib_study_type_value']['group'] = 1;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    2925 => '2925',
  );
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'uib_study_labels';
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth_1']['id'] = 'term_node_tid_depth_1';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['value'] = array(
    2273 => '2273',
    2317 => '2317',
    2283 => '2283',
    2294 => '2294',
    2318 => '2318',
    2308 => '2308',
    2271 => '2271',
  );
  $handler->display->display_options['filters']['term_node_tid_depth_1']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['operator_id'] = 'term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['label'] = 'Search for faculty';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['operator'] = 'term_node_tid_depth_1_op';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['identifier'] = 'term_node_tid_depth_1';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth_1']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth_1']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['vocabulary'] = 'uib_organisation';
  $handler->display->display_options['filters']['term_node_tid_depth_1']['depth'] = '3';
  /* Filter criterion: Content: Has taxonomy terms (with depth) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = '';
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Search for country or continent';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['description'] = 'Display exchange agreements with one or more countries.';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'uib_geography';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';
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
  $translatables['exchange_agreements'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Nullstill'),
    t('Sort by'),
    t('Stigende'),
    t('Synkende'),
    t('Select any filter and click on Apply to see results'),
    t('Translations'),
    t('Taxonomy term entity referenced from field_uib_study_country'),
    t('Read student report'),
    t('<span class="agreement-title">[field_uib_study_title]</span><span class="studentreport-ref">[field_uib_study_code]</span>'),
    t('Search for faculty'),
    t('Search for country or continent'),
    t('Display exchange agreements with one or more countries.'),
    t('Blokk'),
    t('Innhold entity referenced from field_uib_study_part_of'),
    t('Filter by faculty'),
    t('Filter by country or continent'),
    t('Filter by study programme'),
    t('Teacher exchange block'),
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
        'any_label' => '',
        'bef_filter_description' => '',
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
    'tid' => array(
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
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['text'] = '<a href="[path]">[field_uib_study_code] / [field_uib_study_title]</a>';
  $handler->display->display_options['fields']['field_uib_study_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_study_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_uib_study_title']['settings'] = array(
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
  /* Sort criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['sorts']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['sorts']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['sorts']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
  /* Sort criterion: Content: Title (field_uib_study_title) */
  $handler->display->display_options['sorts']['field_uib_study_title_value']['id'] = 'field_uib_study_title_value';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['field'] = 'field_uib_study_title_value';
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
    2273 => '2273',
    2317 => '2317',
    2283 => '2283',
    2294 => '2294',
    2318 => '2318',
    2308 => '2308',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Filter by faculty';
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
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'uib_organisation';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '3';

  /* Display: Quota */
  $handler = $view->new_display('page', 'Quota', 'quota');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Master\'s Programmes - Quota';
  $handler->display->display_options['path'] = 'education/quota';

  /* Display: Self-financing */
  $handler = $view->new_display('page', 'Self-financing', 'self_financing');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Master\'s Programmes - Self-financing';
  $handler->display->display_options['path'] = 'education/self-financing';

  /* Display: Exchange */
  $handler = $view->new_display('block', 'Exchange', 'b1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['sorts']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['sorts']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['sorts']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
  /* Sort criterion: Content: Title (field_uib_study_title) */
  $handler->display->display_options['sorts']['field_uib_study_title_value']['id'] = 'field_uib_study_title_value';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['field'] = 'field_uib_study_title_value';
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
    2273 => '2273',
    2317 => '2317',
    2283 => '2283',
    2294 => '2294',
    2318 => '2318',
    2308 => '2308',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Filter by faculty';
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
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'uib_organisation';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '3';
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    2687 => '2687',
    2686 => '2686',
  );
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Filter by semester';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'uib_study_labels';
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
    t('<a href="[path]">[field_uib_study_code] / [field_uib_study_title]</a>'),
    t('Filter by faculty'),
    t('Has taxonomy terms (with depth)'),
    t('Quota'),
    t('Master\'s Programmes - Quota'),
    t('Self-financing'),
    t('Master\'s Programmes - Self-financing'),
    t('Exchange'),
    t('Filter by semester'),
  );
  $export['special_study_listings'] = $view;

  $view = new view();
  $view->name = 'study_blocks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Study blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Study programmes';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_tags'] = array(
    0 => 'uib_study_order_by_title',
  );
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['label'] = 'Oversettelser';
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
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Place (field_uib_ou) */
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['id'] = 'field_uib_ou_target_id';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['table'] = 'field_data_field_uib_ou';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['field'] = 'field_uib_ou_target_id';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['validate_options']['code'] = '$handler->argument = uib_area__get_ou_nids_recursive($argument);
return !empty($handler->argument);';
  $handler->display->display_options['arguments']['field_uib_ou_target_id']['break_phrase'] = TRUE;
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
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Title (field_uib_study_title:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: All courses block */
  $handler = $view->new_display('block', 'All courses block', 'courses_all_b1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'uib-all-courses';
  $handler->display->display_options['display_description'] = 'Listing all courses';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_uib_study_points_rank_value' => array(
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
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
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
    'tid_1' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
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
    'tid_2' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
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
    'tid_3' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
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
    'tid_4' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 1,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
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
    'field_uib_study_category_value' => array(
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Found @total courses';
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
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_title']['element_label_colon'] = FALSE;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_uib_study_category']['id'] = 'field_uib_study_category';
  $handler->display->display_options['fields']['field_uib_study_category']['table'] = 'field_data_field_uib_study_category';
  $handler->display->display_options['fields']['field_uib_study_category']['field'] = 'field_uib_study_category';
  $handler->display->display_options['fields']['field_uib_study_category']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['sorts']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['sorts']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['sorts']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
  /* Sort criterion: Content: Title (field_uib_study_title) */
  $handler->display->display_options['sorts']['field_uib_study_title_value']['id'] = 'field_uib_study_title_value';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['field'] = 'field_uib_study_title_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'course' => 'course',
  );
  $handler->display->display_options['filters']['field_uib_study_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_uib_study_type_value']['expose']['operator_id'] = 'field_uib_study_type_value_op';
  $handler->display->display_options['filters']['field_uib_study_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['expose']['operator'] = 'field_uib_study_type_value_op';
  $handler->display->display_options['filters']['field_uib_study_type_value']['expose']['identifier'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_uib_study_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  /* Filter criterion: Content: Title (field_uib_study_title:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: Content: Study points rank (field_uib_study_points_rank) */
  $handler->display->display_options['filters']['field_uib_study_points_rank_value']['id'] = 'field_uib_study_points_rank_value';
  $handler->display->display_options['filters']['field_uib_study_points_rank_value']['table'] = 'field_data_field_uib_study_points_rank';
  $handler->display->display_options['filters']['field_uib_study_points_rank_value']['field'] = 'field_uib_study_points_rank_value';
  $handler->display->display_options['filters']['field_uib_study_points_rank_value']['group'] = 1;
  $handler->display->display_options['filters']['field_uib_study_points_rank_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_study_points_rank_value']['expose']['operator_id'] = 'field_uib_study_points_rank_value_op';
  $handler->display->display_options['filters']['field_uib_study_points_rank_value']['expose']['label'] = 'Filter by ECTS credits';
  $handler->display->display_options['filters']['field_uib_study_points_rank_value']['expose']['operator'] = 'field_uib_study_points_rank_value_op';
  $handler->display->display_options['filters']['field_uib_study_points_rank_value']['expose']['identifier'] = 'studypoints_rank';
  $handler->display->display_options['filters']['field_uib_study_points_rank_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_uib_study_points_rank_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  /* Filter criterion: Content: Category (field_uib_study_category) */
  $handler->display->display_options['filters']['field_uib_study_category_value']['id'] = 'field_uib_study_category_value';
  $handler->display->display_options['filters']['field_uib_study_category_value']['table'] = 'field_data_field_uib_study_category';
  $handler->display->display_options['filters']['field_uib_study_category_value']['field'] = 'field_uib_study_category_value';
  $handler->display->display_options['filters']['field_uib_study_category_value']['value'] = array(
    'undergraduate' => 'undergraduate',
    'postgraduate' => 'postgraduate',
    'arsstudium' => 'arsstudium',
    'phdkurs' => 'phdkurs',
    'evu' => 'evu',
  );
  $handler->display->display_options['filters']['field_uib_study_category_value']['group'] = 1;
  $handler->display->display_options['filters']['field_uib_study_category_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_study_category_value']['expose']['operator_id'] = 'field_uib_study_category_value_op';
  $handler->display->display_options['filters']['field_uib_study_category_value']['expose']['label'] = 'Filter by level';
  $handler->display->display_options['filters']['field_uib_study_category_value']['expose']['operator'] = 'field_uib_study_category_value_op';
  $handler->display->display_options['filters']['field_uib_study_category_value']['expose']['identifier'] = 'field_uib_study_category_value';
  $handler->display->display_options['filters']['field_uib_study_category_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_uib_study_category_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['field_uib_study_category_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    2 => '2',
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['filters']['tid']['group'] = 2;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Humanities and aesthetic studies';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['tid']['group_info']['label'] = 'Has taxonomy term';
  $handler->display->display_options['filters']['tid']['group_info']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'uib_nus';
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_1']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_1']['value'] = array(
    9 => '9',
    10 => '10',
    11 => '11',
    12 => '12',
  );
  $handler->display->display_options['filters']['tid_1']['group'] = 2;
  $handler->display->display_options['filters']['tid_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['operator_id'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['label'] = 'Teacher training and pedagogy';
  $handler->display->display_options['filters']['tid_1']['expose']['operator'] = 'tid_1_op';
  $handler->display->display_options['filters']['tid_1']['expose']['identifier'] = 'tid_1';
  $handler->display->display_options['filters']['tid_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['tid_1']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['tid_1']['vocabulary'] = 'uib_nus';
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid_2']['id'] = 'tid_2';
  $handler->display->display_options['filters']['tid_2']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_2']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_2']['value'] = array(
    14 => '14',
    15 => '15',
    16 => '16',
    17 => '17',
    18 => '18',
    19 => '19',
    20 => '20',
    21 => '21',
    22 => '22',
  );
  $handler->display->display_options['filters']['tid_2']['group'] = 2;
  $handler->display->display_options['filters']['tid_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_2']['expose']['operator_id'] = 'tid_2_op';
  $handler->display->display_options['filters']['tid_2']['expose']['label'] = 'Political science and Development studies';
  $handler->display->display_options['filters']['tid_2']['expose']['operator'] = 'tid_2_op';
  $handler->display->display_options['filters']['tid_2']['expose']['identifier'] = 'tid_2';
  $handler->display->display_options['filters']['tid_2']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['tid_2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['tid_2']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['tid_2']['type'] = 'select';
  $handler->display->display_options['filters']['tid_2']['vocabulary'] = 'uib_nus';
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid_3']['id'] = 'tid_3';
  $handler->display->display_options['filters']['tid_3']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_3']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_3']['value'] = array(
    24 => '24',
    25 => '25',
    26 => '26',
    27 => '27',
    28 => '28',
    29 => '29',
  );
  $handler->display->display_options['filters']['tid_3']['group'] = 2;
  $handler->display->display_options['filters']['tid_3']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_3']['expose']['operator_id'] = 'tid_3_op';
  $handler->display->display_options['filters']['tid_3']['expose']['label'] = 'Natural sciences and techincal subjects';
  $handler->display->display_options['filters']['tid_3']['expose']['operator'] = 'tid_3_op';
  $handler->display->display_options['filters']['tid_3']['expose']['identifier'] = 'tid_3';
  $handler->display->display_options['filters']['tid_3']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['tid_3']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['tid_3']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['tid_3']['type'] = 'select';
  $handler->display->display_options['filters']['tid_3']['vocabulary'] = 'uib_nus';
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid_4']['id'] = 'tid_4';
  $handler->display->display_options['filters']['tid_4']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_4']['field'] = 'tid';
  $handler->display->display_options['filters']['tid_4']['value'] = array(
    31 => '31',
    32 => '32',
    33 => '33',
    34 => '34',
    35 => '35',
    36 => '36',
    37 => '37',
  );
  $handler->display->display_options['filters']['tid_4']['group'] = 2;
  $handler->display->display_options['filters']['tid_4']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_4']['expose']['operator_id'] = 'tid_4_op';
  $handler->display->display_options['filters']['tid_4']['expose']['label'] = 'Health and welfare';
  $handler->display->display_options['filters']['tid_4']['expose']['operator'] = 'tid_4_op';
  $handler->display->display_options['filters']['tid_4']['expose']['identifier'] = 'tid_4';
  $handler->display->display_options['filters']['tid_4']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['tid_4']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['tid_4']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['tid_4']['type'] = 'select';
  $handler->display->display_options['filters']['tid_4']['vocabulary'] = 'uib_nus';
  /* Filter criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['filters']['field_uib_study_code_value_1']['id'] = 'field_uib_study_code_value_1';
  $handler->display->display_options['filters']['field_uib_study_code_value_1']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['filters']['field_uib_study_code_value_1']['field'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value_1']['operator'] = '!=';
  $handler->display->display_options['filters']['field_uib_study_code_value_1']['value'] = 'EKSTWEB100';

  /* Display: All studyprogrammes block */
  $handler = $view->new_display('block', 'All studyprogrammes block', 'studypr_all_b1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'uib-all-studyprogrammes';
  $handler->display->display_options['display_description'] = 'Listing all study programmes';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
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
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
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
    'field_uib_study_category_value' => array(
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
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uib_study_category',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Found @total study programmes';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No result';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Your criteria did not match any results';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title (field_uib_study_title) */
  $handler->display->display_options['sorts']['field_uib_study_title_value']['id'] = 'field_uib_study_title_value';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['sorts']['field_uib_study_title_value']['field'] = 'field_uib_study_title_value';
  /* Sort criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['sorts']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['sorts']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['sorts']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'program' => 'program',
  );
  $handler->display->display_options['filters']['field_uib_study_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_uib_study_type_value']['expose']['operator_id'] = 'field_uib_study_type_value_op';
  $handler->display->display_options['filters']['field_uib_study_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['expose']['operator'] = 'field_uib_study_type_value_op';
  $handler->display->display_options['filters']['field_uib_study_type_value']['expose']['identifier'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_uib_study_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
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
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
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
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'uib_nus';
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '3';
  /* Filter criterion: Content: Category (field_uib_study_category) */
  $handler->display->display_options['filters']['field_uib_study_category_value']['id'] = 'field_uib_study_category_value';
  $handler->display->display_options['filters']['field_uib_study_category_value']['table'] = 'field_data_field_uib_study_category';
  $handler->display->display_options['filters']['field_uib_study_category_value']['field'] = 'field_uib_study_category_value';
  $handler->display->display_options['filters']['field_uib_study_category_value']['value'] = array(
    'integrertemasterpr-profesjonsst' => 'integrertemasterpr-profesjonsst',
    'bachelorprogram' => 'bachelorprogram',
    'arsstudium' => 'arsstudium',
    'masterprogram' => 'masterprogram',
  );
  $handler->display->display_options['filters']['field_uib_study_category_value']['group'] = 1;
  $handler->display->display_options['filters']['field_uib_study_category_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_study_category_value']['expose']['operator_id'] = 'field_uib_study_category_value_op';
  $handler->display->display_options['filters']['field_uib_study_category_value']['expose']['label'] = 'Filter by level';
  $handler->display->display_options['filters']['field_uib_study_category_value']['expose']['operator'] = 'field_uib_study_category_value_op';
  $handler->display->display_options['filters']['field_uib_study_category_value']['expose']['identifier'] = 'category';
  $handler->display->display_options['filters']['field_uib_study_category_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_uib_study_category_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['field_uib_study_category_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Title (field_uib_study_title:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $translatables['study_blocks'] = array(
    t('Master'),
    t('Study programmes'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Oversettelser'),
    t('<a href="[path]">[field_uib_study_title]</a>'),
    t('All'),
    t('All courses block'),
    t('Listing all courses'),
    t('Select any filter and click on Apply to see results'),
    t('Found @total courses'),
    t('<a href="[path]">[field_uib_study_code] / [field_uib_study_title]</a>'),
    t('Type'),
    t('Filter by ECTS credits'),
    t('Filter by level'),
    t('Humanities and aesthetic studies'),
    t('Has taxonomy term'),
    t('Teacher training and pedagogy'),
    t('Political science and Development studies'),
    t('Natural sciences and techincal subjects'),
    t('Health and welfare'),
    t('All studyprogrammes block'),
    t('Listing all study programmes'),
    t('Found @total study programmes'),
    t('No result'),
    t('Your criteria did not match any results'),
    t('Filter by subject'),
  );
  $export['study_blocks'] = $view;

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
