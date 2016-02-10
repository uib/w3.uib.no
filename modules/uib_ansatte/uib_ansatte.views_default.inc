<?php
/**
 * @file
 * uib_ansatte.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uib_ansatte_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ansatte';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Staff';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Staff';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uib_sort_name',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_uib_staff_target_id']['id'] = 'field_uib_staff_target_id';
  $handler->display->display_options['relationships']['field_uib_staff_target_id']['table'] = 'field_data_field_uib_staff';
  $handler->display->display_options['relationships']['field_uib_staff_target_id']['field'] = 'field_uib_staff_target_id';
  $handler->display->display_options['relationships']['field_uib_staff_target_id']['required'] = TRUE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'uib_research_fields' => 'uib_research_fields',
    'uib_nus' => 0,
    'uib_study_labels' => 0,
  );
  /* Field: User: Rendered User */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_user';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'uib_user_teaser';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Sort criterion: User: Sort name (field_uib_sort_name) */
  $handler->display->display_options['sorts']['field_uib_sort_name_value']['id'] = 'field_uib_sort_name_value';
  $handler->display->display_options['sorts']['field_uib_sort_name_value']['table'] = 'field_data_field_uib_sort_name';
  $handler->display->display_options['sorts']['field_uib_sort_name_value']['field'] = 'field_uib_sort_name_value';
  $handler->display->display_options['sorts']['field_uib_sort_name_value']['relationship'] = 'field_uib_staff_target_id';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Staff at %1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['nid']['validate_options']['code'] = 'global $base_url;
    $node = drupal_get_normal_path($argument, $language = NULL);

    if ($argument == $node) {
      uibx_log(\'Node not found\');
    }

    if ($argument != $node) {
      uibx_log(\'node: \' . $node);
      $nid = substr(strrchr($node, "/"), 1);
    }

    return TRUE;
  ';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  /* Contextual filter: User: Position category (field_uib_position_category) */
  $handler->display->display_options['arguments']['field_uib_position_category_value']['id'] = 'field_uib_position_category_value';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['table'] = 'field_data_field_uib_position_category';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['field'] = 'field_uib_position_category_value';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['title'] = '%2 at %1';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['limit'] = '0';
  /* Filter criterion: User: First name (field_uib_first_name) */
  $handler->display->display_options['filters']['field_uib_first_name_value']['id'] = 'field_uib_first_name_value';
  $handler->display->display_options['filters']['field_uib_first_name_value']['table'] = 'field_data_field_uib_first_name';
  $handler->display->display_options['filters']['field_uib_first_name_value']['field'] = 'field_uib_first_name_value';
  $handler->display->display_options['filters']['field_uib_first_name_value']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['filters']['field_uib_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_uib_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_first_name_value']['expose']['operator_id'] = 'field_uib_first_name_value_op';
  $handler->display->display_options['filters']['field_uib_first_name_value']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_uib_first_name_value']['expose']['operator'] = 'field_uib_first_name_value_op';
  $handler->display->display_options['filters']['field_uib_first_name_value']['expose']['identifier'] = 'field_uib_first_name_value';
  $handler->display->display_options['filters']['field_uib_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: User: Last name (field_uib_last_name) */
  $handler->display->display_options['filters']['field_uib_last_name_value']['id'] = 'field_uib_last_name_value';
  $handler->display->display_options['filters']['field_uib_last_name_value']['table'] = 'field_data_field_uib_last_name';
  $handler->display->display_options['filters']['field_uib_last_name_value']['field'] = 'field_uib_last_name_value';
  $handler->display->display_options['filters']['field_uib_last_name_value']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['filters']['field_uib_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_uib_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_last_name_value']['expose']['operator_id'] = 'field_uib_last_name_value_op';
  $handler->display->display_options['filters']['field_uib_last_name_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_uib_last_name_value']['expose']['operator'] = 'field_uib_last_name_value_op';
  $handler->display->display_options['filters']['field_uib_last_name_value']['expose']['identifier'] = 'field_uib_last_name_value';
  $handler->display->display_options['filters']['field_uib_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: User: Fields of competence (field_uib_user_competence) */
  $handler->display->display_options['filters']['field_uib_user_competence_tid']['id'] = 'field_uib_user_competence_tid';
  $handler->display->display_options['filters']['field_uib_user_competence_tid']['table'] = 'field_data_field_uib_user_competence';
  $handler->display->display_options['filters']['field_uib_user_competence_tid']['field'] = 'field_uib_user_competence_tid';
  $handler->display->display_options['filters']['field_uib_user_competence_tid']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['filters']['field_uib_user_competence_tid']['value'] = '';
  $handler->display->display_options['filters']['field_uib_user_competence_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_uib_user_competence_tid']['expose']['operator_id'] = 'field_uib_user_competence_tid_op';
  $handler->display->display_options['filters']['field_uib_user_competence_tid']['expose']['label'] = 'Fields of competence';
  $handler->display->display_options['filters']['field_uib_user_competence_tid']['expose']['operator'] = 'field_uib_user_competence_tid_op';
  $handler->display->display_options['filters']['field_uib_user_competence_tid']['expose']['identifier'] = 'field_uib_user_competence';
  $handler->display->display_options['filters']['field_uib_user_competence_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    64272948 => 0,
    170699807 => 0,
    74573517 => 0,
    176168899 => 0,
  );
  $handler->display->display_options['filters']['field_uib_user_competence_tid']['vocabulary'] = 'uib_research_fields';

  /* Display: List of all persons */
  $handler = $view->new_display('page', 'List of all persons', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Staff at %1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  /* Contextual filter: User: Position category (field_uib_position_category) */
  $handler->display->display_options['arguments']['field_uib_position_category_value']['id'] = 'field_uib_position_category_value';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['table'] = 'field_data_field_uib_position_category';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['field'] = 'field_uib_position_category_value';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['exception']['title'] = 'All staff';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['title'] = '%2 at %1';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['limit'] = '0';
  $handler->display->display_options['path'] = 'persons';
  $handler->display->display_options['menu']['title'] = 'Staff';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'area';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: List of staff for area */
  $handler = $view->new_display('page', 'List of staff for area', 'page_2');
  $handler->display->display_options['display_description'] = 'Lists the all staff belonging to an area.  By adding "faculity" or "staff" to the URL limit to that kind.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Staff at %1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  /* Contextual filter: User: Position category (field_uib_position_category) */
  $handler->display->display_options['arguments']['field_uib_position_category_value']['id'] = 'field_uib_position_category_value';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['table'] = 'field_data_field_uib_position_category';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['field'] = 'field_uib_position_category_value';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['exception']['title'] = 'All employees at %1';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['title'] = '%2 at %1';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['breadcrumb_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['breadcrumb'] = '%1';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['validate_options']['code'] = 'if ($argument == \'faculty\') {
  $handler->validated_title = t(\'Faculty\');
}
elseif ($argument == \'staff\') {
  $handler->validated_title = t(\'Administrative staff\');
}
else {
  return FALSE;
}
return TRUE;
';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['limit'] = '0';
  $handler->display->display_options['path'] = 'node/%/persons';
  $handler->display->display_options['menu']['title'] = 'Staff';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'area';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Staff list on bottom of area frontpage */
  $handler = $view->new_display('page', 'Staff list on bottom of area frontpage', 'page_3');
  $handler->display->display_options['display_description'] = 'This is the staff listing shown on selected area frontpages. No exposed filters on this view.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = 'Staff at %1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  /* Contextual filter: User: Position category (field_uib_position_category) */
  $handler->display->display_options['arguments']['field_uib_position_category_value']['id'] = 'field_uib_position_category_value';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['table'] = 'field_data_field_uib_position_category';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['field'] = 'field_uib_position_category_value';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['relationship'] = 'field_uib_staff_target_id';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['exception']['title'] = 'All staff';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['title'] = '%2 at %1';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_position_category_value']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['field_uib_position_category_value']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'persons';
  $handler->display->display_options['menu']['title'] = 'Staff';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'area';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['ansatte'] = array(
    t('Master'),
    t('Staff'),
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
    t('User entity referenced from field_uib_staff'),
    t('term'),
    t('All'),
    t('Staff at %1'),
    t('%2 at %1'),
    t('First name'),
    t('Last name'),
    t('Fields of competence'),
    t('List of all persons'),
    t('All staff'),
    t('List of staff for area'),
    t('Lists the all staff belonging to an area.  By adding "faculity" or "staff" to the URL limit to that kind.'),
    t('All employees at %1'),
    t('%1'),
    t('Staff list on bottom of area frontpage'),
    t('This is the staff listing shown on selected area frontpages. No exposed filters on this view.'),
  );
  $export['ansatte'] = $view;

  return $export;
}
