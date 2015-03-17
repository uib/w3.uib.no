<?php
/**
 * @file
 * uib_area.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uib_area_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'area_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Area map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Area map';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_uib_ou_node']['id'] = 'reverse_field_uib_ou_node';
  $handler->display->display_options['relationships']['reverse_field_uib_ou_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_uib_ou_node']['field'] = 'reverse_field_uib_ou_node';
  $handler->display->display_options['relationships']['reverse_field_uib_ou_node']['required'] = TRUE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_uib_geolocation']['id'] = 'field_uib_geolocation';
  $handler->display->display_options['fields']['field_uib_geolocation']['table'] = 'field_data_field_uib_geolocation';
  $handler->display->display_options['fields']['field_uib_geolocation']['field'] = 'field_uib_geolocation';
  $handler->display->display_options['fields']['field_uib_geolocation']['label'] = '';
  $handler->display->display_options['fields']['field_uib_geolocation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_geolocation']['click_sort_column'] = 'geom';
  $handler->display->display_options['fields']['field_uib_geolocation']['type'] = 'geofield_map_map';
  $handler->display->display_options['fields']['field_uib_geolocation']['settings'] = array(
    'geofield_map_width' => '100%',
    'geofield_map_height' => '300px',
    'geofield_map_zoom' => '17',
    'geofield_map_controltype' => 'default',
    'geofield_map_mtc' => 'menu',
    'geofield_map_pancontrol' => 0,
    'geofield_map_maptype' => 'map',
    'geofield_map_baselayers_map' => 1,
    'geofield_map_baselayers_satellite' => 1,
    'geofield_map_baselayers_hybrid' => 1,
    'geofield_map_baselayers_physical' => 0,
    'geofield_map_scale' => 0,
    'geofield_map_overview' => 0,
    'geofield_map_overview_opened' => 0,
    'geofield_map_scrollwheel' => 0,
    'geofield_map_draggable' => 1,
    'geofield_map_streetview_show' => 1,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_uib_ou_node';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]
[field_uib_visit_address]
';
  /* Field: Content: Visit Address */
  $handler->display->display_options['fields']['field_uib_visit_address']['id'] = 'field_uib_visit_address';
  $handler->display->display_options['fields']['field_uib_visit_address']['table'] = 'field_data_field_uib_visit_address';
  $handler->display->display_options['fields']['field_uib_visit_address']['field'] = 'field_uib_visit_address';
  $handler->display->display_options['fields']['field_uib_visit_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_uib_visit_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_uib_ou_node';
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uib_ou' => 'uib_ou',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'node/%/map';
  $translatables['area_map'] = array(
    t('Master'),
    t('Area map'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content referencing Content from field_uib_ou'),
    t('Name'),
    t('[title]
[field_uib_visit_address]
'),
    t('Visit Address'),
    t('All'),
    t('Page'),
  );
  $export['area_map'] = $view;

  $view = new view();
  $view->name = 'area_slideshow';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Area slideshow';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Area slideshow';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_tags'] = array(
    0 => 'slideshow_area',
  );
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_uib_lead' => 0,
    'field_uib_main_media' => 0,
    'title' => 0,
    'field_uib_main_media_1' => 0,
    'nid' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'nid' => 'nid',
    'field_uib_lead' => 0,
    'field_uib_main_media' => 0,
    'title' => 0,
    'field_uib_main_media_1' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_uib_profiled_article_node']['id'] = 'reverse_field_uib_profiled_article_node';
  $handler->display->display_options['relationships']['reverse_field_uib_profiled_article_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_uib_profiled_article_node']['field'] = 'reverse_field_uib_profiled_article_node';
  $handler->display->display_options['relationships']['reverse_field_uib_profiled_article_node']['required'] = TRUE;
  /* Field: Content: Teaser */
  $handler->display->display_options['fields']['field_uib_teaser']['id'] = 'field_uib_teaser';
  $handler->display->display_options['fields']['field_uib_teaser']['table'] = 'field_data_field_uib_teaser';
  $handler->display->display_options['fields']['field_uib_teaser']['field'] = 'field_uib_teaser';
  $handler->display->display_options['fields']['field_uib_teaser']['label'] = '';
  $handler->display->display_options['fields']['field_uib_teaser']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_teaser']['element_label_colon'] = FALSE;
  /* Field: Content: Lead */
  $handler->display->display_options['fields']['field_uib_lead']['id'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['table'] = 'field_data_field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['field'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['label'] = '';
  $handler->display->display_options['fields']['field_uib_lead']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_lead']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['field_uib_lead']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_uib_lead']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_lead']['empty'] = '[field_uib_teaser]';
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_uib_media']['id'] = 'field_uib_media';
  $handler->display->display_options['fields']['field_uib_media']['table'] = 'field_data_field_uib_media';
  $handler->display->display_options['fields']['field_uib_media']['field'] = 'field_uib_media';
  $handler->display->display_options['fields']['field_uib_media']['label'] = '';
  $handler->display->display_options['fields']['field_uib_media']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_uib_media']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_uib_media']['settings'] = array(
    'file_view_mode' => 'full_width_image',
    'field_multiple_limit' => '1',
    'field_multiple_limit_offset' => '0',
  );
  $handler->display->display_options['fields']['field_uib_media']['delta_offset'] = '0';
  /* Field: Content: Main media */
  $handler->display->display_options['fields']['field_uib_main_media']['id'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['table'] = 'field_data_field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['field'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['label'] = '';
  $handler->display->display_options['fields']['field_uib_main_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_main_media']['empty'] = '[field_uib_media]';
  $handler->display->display_options['fields']['field_uib_main_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_uib_main_media']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_uib_main_media']['settings'] = array(
    'file_view_mode' => 'full_width_image',
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
  );
  $handler->display->display_options['fields']['field_uib_main_media']['delta_offset'] = '0';
  /* Field: Content: Main media */
  $handler->display->display_options['fields']['field_uib_main_media_1']['id'] = 'field_uib_main_media_1';
  $handler->display->display_options['fields']['field_uib_main_media_1']['table'] = 'field_data_field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media_1']['field'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media_1']['label'] = '';
  $handler->display->display_options['fields']['field_uib_main_media_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_main_media_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_main_media_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_uib_main_media_1']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_uib_main_media_1']['settings'] = array(
    'file_view_mode' => 'wide_thumbnail',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<span class="ciclepager"></span>';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_uib_location']['id'] = 'field_uib_location';
  $handler->display->display_options['fields']['field_uib_location']['table'] = 'field_data_field_uib_location';
  $handler->display->display_options['fields']['field_uib_location']['field'] = 'field_uib_location';
  $handler->display->display_options['fields']['field_uib_location']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Field: Links */
  $handler->display->display_options['fields']['field_uib_links']['id'] = 'field_uib_links';
  $handler->display->display_options['fields']['field_uib_links']['table'] = 'field_data_field_uib_links';
  $handler->display->display_options['fields']['field_uib_links']['field'] = 'field_uib_links';
  $handler->display->display_options['fields']['field_uib_links']['label'] = '';
  $handler->display->display_options['fields']['field_uib_links']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_links']['empty'] = 'node/[nid_1]';
  $handler->display->display_options['fields']['field_uib_links']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_uib_links']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_uib_links']['settings'] = array(
    'field_multiple_limit' => '1',
    'field_multiple_limit_offset' => '0',
  );
  $handler->display->display_options['fields']['field_uib_links']['delta_offset'] = '0';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_uib_article_type']['id'] = 'field_uib_article_type';
  $handler->display->display_options['fields']['field_uib_article_type']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['fields']['field_uib_article_type']['field'] = 'field_uib_article_type';
  $handler->display->display_options['fields']['field_uib_article_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_article_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['text'] = '<div class="transparent">
<div class="slidecontent">
<h3>[title]</h3>
<p class="lead">[field_uib_lead]</p>
</div>
</div>';
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_uib_article_type']['alter']['path'] = 'node/[nid_1]';
  $handler->display->display_options['fields']['field_uib_article_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_article_type']['empty'] = '<a href="[field_uib_links]">
<div class="transparent">
<div class="slidecontent">
<h3>[title]</h3>
<p class="lead">[field_uib_lead]</p>
</div>
</div>
</a>';
  /* Field: Content: Event type */
  $handler->display->display_options['fields']['field_uib_event_type']['id'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['table'] = 'field_data_field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['field'] = 'field_uib_event_type';
  $handler->display->display_options['fields']['field_uib_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['text'] = '<div class="transparent">
<div class="slidecontent event">
<h3>[title]</h3>
<p class="lead">[field_uib_lead]</p>
</div>
<div class="eventdata">
<p>[field_uib_event_type]</p>
<p>[field_uib_date]</p>
<p>[field_uib_location]</p>
</div>
</div>';
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_uib_event_type']['alter']['path'] = 'node/[nid_1]';
  $handler->display->display_options['fields']['field_uib_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_event_type']['empty'] = '[field_uib_article_type]';
  $handler->display->display_options['fields']['field_uib_event_type']['type'] = 'i18n_list_default';
  /* Sort criterion: Content: Slideshow (field_uib_profiled_article:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_uib_profiled_article';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_uib_profiled_article_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'area' => 'area',
  );
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
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
    'uib_article' => 'uib_article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: Content: Main media (field_uib_main_media:fid) */
  $handler->display->display_options['filters']['field_uib_main_media_fid']['id'] = 'field_uib_main_media_fid';
  $handler->display->display_options['filters']['field_uib_main_media_fid']['table'] = 'field_data_field_uib_main_media';
  $handler->display->display_options['filters']['field_uib_main_media_fid']['field'] = 'field_uib_main_media_fid';
  $handler->display->display_options['filters']['field_uib_main_media_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_uib_main_media_fid']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'uib_external_content' => 'uib_external_content',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 2;
  /* Filter criterion: Content: Photo (field_uib_media:fid) */
  $handler->display->display_options['filters']['field_uib_media_fid']['id'] = 'field_uib_media_fid';
  $handler->display->display_options['filters']['field_uib_media_fid']['table'] = 'field_data_field_uib_media';
  $handler->display->display_options['filters']['field_uib_media_fid']['field'] = 'field_uib_media_fid';
  $handler->display->display_options['filters']['field_uib_media_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_uib_media_fid']['group'] = 2;

  /* Display: Area slideshow block */
  $handler = $view->new_display('block', 'Area slideshow block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['area_slideshow'] = array(
    t('Master'),
    t('Area slideshow'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content referencing Content from field_uib_profiled_article'),
    t('[field_uib_teaser]'),
    t('[field_uib_media]'),
    t('<span class="ciclepager"></span>'),
    t('Location'),
    t('node/[nid_1]'),
    t('<div class="transparent">
<div class="slidecontent">
<h3>[title]</h3>
<p class="lead">[field_uib_lead]</p>
</div>
</div>'),
    t('<a href="[field_uib_links]">
<div class="transparent">
<div class="slidecontent">
<h3>[title]</h3>
<p class="lead">[field_uib_lead]</p>
</div>
</div>
</a>'),
    t('<div class="transparent">
<div class="slidecontent event">
<h3>[title]</h3>
<p class="lead">[field_uib_lead]</p>
</div>
<div class="eventdata">
<p>[field_uib_event_type]</p>
<p>[field_uib_date]</p>
<p>[field_uib_location]</p>
</div>
</div>'),
    t('[field_uib_article_type]'),
    t('All'),
    t('Area slideshow block'),
  );
  $export['area_slideshow'] = $view;

  $view = new view();
  $view->name = 'area_sync';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'area_sync';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Areas with staff synchronisation problems';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    176168899 => '176168899',
    74573517 => '74573517',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<a href="/node/[nid]/staff_status">[title]</a>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'area' => 'area',
  );
  /* Filter criterion: Content: Staff sync status (field_uib_staff_status) */
  $handler->display->display_options['filters']['field_uib_staff_status_value']['id'] = 'field_uib_staff_status_value';
  $handler->display->display_options['filters']['field_uib_staff_status_value']['table'] = 'field_data_field_uib_staff_status';
  $handler->display->display_options['filters']['field_uib_staff_status_value']['field'] = 'field_uib_staff_status_value';
  $handler->display->display_options['filters']['field_uib_staff_status_value']['operator'] = '!=';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'webdesk/area-sync-status';
  $translatables['area_sync'] = array(
    t('Master'),
    t('Areas with staff synchronisation problems'),
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
    t('<a href="/node/[nid]/staff_status">[title]</a>'),
    t('Page'),
  );
  $export['area_sync'] = $view;

  $view = new view();
  $view->name = 'areas';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Areas';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Areas';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uib_area_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_uib_area_type']['id'] = 'field_uib_area_type';
  $handler->display->display_options['fields']['field_uib_area_type']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['fields']['field_uib_area_type']['field'] = 'field_uib_area_type';
  $handler->display->display_options['fields']['field_uib_area_type']['label'] = '';
  $handler->display->display_options['fields']['field_uib_area_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_area_type']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['sorts']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['sorts']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['sorts']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'area' => 'area',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['field_language'] = 'und';
  $handler->display->display_options['path'] = 'areas';
  $translatables['areas'] = array(
    t('Master'),
    t('Areas'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Page'),
  );
  $export['areas'] = $view;

  $view = new view();
  $view->name = 'courses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Study';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Study programmes';
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
  /* Contextual filter: Content: Responsible (field_uib_ou) */
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

  /* Display: Courses */
  $handler = $view->new_display('page', 'Courses', 'courses');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Courses';
  $handler->display->display_options['display_description'] = 'Listing courses belonging to area';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: ID */
  $handler->display->display_options['fields']['field_uib_study_code']['id'] = 'field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['field'] = 'field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_code']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_uib_study_title']['id'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['field'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['text'] = '<a href="[path]">[field_uib_study_code] / [field_uib_study_title]</a>';
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['sorts']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['sorts']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['sorts']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
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
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'course' => 'course',
  );
  /* Filter criterion: Content: Title (field_uib_study_title:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['filters']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['filters']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_uib_study_code_value']['value'] = 'EKSTWEB100';
  $handler->display->display_options['path'] = 'node/%/courses';

  /* Display: Studyprogrammes */
  $handler = $view->new_display('page', 'Studyprogrammes', 'study_programmes');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Study programmes';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_uib_study_category',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_uib_study_category']['id'] = 'field_uib_study_category';
  $handler->display->display_options['fields']['field_uib_study_category']['table'] = 'field_data_field_uib_study_category';
  $handler->display->display_options['fields']['field_uib_study_category']['field'] = 'field_uib_study_category';
  $handler->display->display_options['fields']['field_uib_study_category']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_study_category']['type'] = 'i18n_list_default';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_uib_study_title']['id'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['field'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['text'] = '<a href="[path]">[field_uib_study_title]</a>';
  $handler->display->display_options['fields']['field_uib_study_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
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
  $handler->display->display_options['path'] = 'node/%/study-programmes';

  /* Display: Masterprogrammes */
  $handler = $view->new_display('page', 'Masterprogrammes', 'master_programmes');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Master programmes';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['filters']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['filters']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_uib_study_code_value']['value'] = 'MA';
  /* Filter criterion: Content: Title (field_uib_study_title:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'node/%/master-programmes';

  /* Display: Bachelorprogrammes */
  $handler = $view->new_display('page', 'Bachelorprogrammes', 'bachelor_programmes');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Bachelor programmes';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['filters']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['filters']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_uib_study_code_value']['value'] = 'BA';
  /* Filter criterion: Content: Title (field_uib_study_title:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'node/%/bachelor-programmes';

  /* Display: One-year programmes */
  $handler = $view->new_display('page', 'One-year programmes', 'one_year_programmes');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'One-year programmes';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
  /* Filter criterion: Content: Type (field_uib_study_type) */
  $handler->display->display_options['filters']['field_uib_study_type_value']['id'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['table'] = 'field_data_field_uib_study_type';
  $handler->display->display_options['filters']['field_uib_study_type_value']['field'] = 'field_uib_study_type_value';
  $handler->display->display_options['filters']['field_uib_study_type_value']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: ID (field_uib_study_code) */
  $handler->display->display_options['filters']['field_uib_study_code_value']['id'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['filters']['field_uib_study_code_value']['field'] = 'field_uib_study_code_value';
  $handler->display->display_options['filters']['field_uib_study_code_value']['operator'] = 'starts';
  $handler->display->display_options['filters']['field_uib_study_code_value']['value'] = 'Å';
  /* Filter criterion: Content: Title (field_uib_study_title:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'node/%/one-year-programmes';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_uib_study_code' => 'field_uib_study_code',
    'field_uib_study_title' => 'field_uib_study_title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: ID */
  $handler->display->display_options['fields']['field_uib_study_code']['id'] = 'field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['field'] = 'field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_code']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_uib_study_title']['id'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['table'] = 'field_data_field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['field'] = 'field_uib_study_title';
  $handler->display->display_options['fields']['field_uib_study_title']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_study_title']['alter']['text'] = '[field_uib_study_title] - [field_uib_study_code]';
  $handler->display->display_options['fields']['field_uib_study_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $translatables['courses'] = array(
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
    t('Courses'),
    t('Listing courses belonging to area'),
    t('<a href="[path]">[field_uib_study_code] / [field_uib_study_title]</a>'),
    t('Studyprogrammes'),
    t('Masterprogrammes'),
    t('Master programmes'),
    t('Bachelorprogrammes'),
    t('Bachelor programmes'),
    t('One-year programmes'),
    t('Entity Reference'),
    t('[field_uib_study_title] - [field_uib_study_code]'),
  );
  $export['courses'] = $view;

  $view = new view();
  $view->name = 'faculty_departments_kids';
  $view->description = 'This view is for facultys, and its lists all insitutes kids';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Faculty departments kids';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Departments';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Parents (field_uib_area_parents) */
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['id'] = 'field_uib_area_parents_target_id';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['table'] = 'field_data_field_uib_area_parents';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['field'] = 'field_uib_area_parents_target_id';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['validate_options']['types'] = array(
    'area' => 'area',
  );
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
    'area' => 'area',
  );
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'institute' => 'institute',
  );

  /* Display: Faculty deparments kids */
  $handler = $view->new_display('block', 'Faculty deparments kids', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['faculty_departments_kids'] = array(
    t('Master'),
    t('Departments'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Faculty deparments kids'),
  );
  $export['faculty_departments_kids'] = $view;

  $view = new view();
  $view->name = 'frontpage_profiled_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Frontpage profiled articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Frontpage profiled articles';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_uib_profiled_message_node']['id'] = 'reverse_field_uib_profiled_message_node';
  $handler->display->display_options['relationships']['reverse_field_uib_profiled_message_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_uib_profiled_message_node']['field'] = 'reverse_field_uib_profiled_message_node';
  $handler->display->display_options['relationships']['reverse_field_uib_profiled_message_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_uib_profiled_message_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'uib_article' => 'uib_article',
  );
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'news' => 'news',
  );
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['relationship'] = 'reverse_field_uib_profiled_message_node';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'frontpage' => 'frontpage',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
  );

  /* Display: Profiled news english */
  $handler = $view->new_display('block', 'Profiled news english', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'News';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'More news';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'news';

  /* Display: Profiled events english */
  $handler = $view->new_display('block', 'Profiled events english', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Calendar';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'See the entire calendar';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'http://www.uib.no/en/calendar';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'long',
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
    'format_type' => 'long',
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uib_article' => 'uib_article',
  );
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['relationship'] = 'reverse_field_uib_profiled_message_node';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'frontpage' => 'frontpage',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
  );

  /* Display: Profiled events norwegian */
  $handler = $view->new_display('block', 'Profiled events norwegian', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Kalender — Det&nbsp;skjer';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Se hele kalenderen';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'http://www.uib.no/kalender';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_uib_date']['id'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['field'] = 'field_uib_date';
  $handler->display->display_options['fields']['field_uib_date']['label'] = '';
  $handler->display->display_options['fields']['field_uib_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_date']['settings'] = array(
    'format_type' => 'long',
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
    'format_type' => 'long',
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uib_article' => 'uib_article',
  );
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'event' => 'event',
  );
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['relationship'] = 'reverse_field_uib_profiled_message_node';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'frontpage' => 'frontpage',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'nb' => 'nb',
  );

  /* Display: Profiled news norwegian */
  $handler = $view->new_display('block', 'Profiled news norwegian', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Nyheter';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Flere aktuelle saker';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'aktuelt';
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
    'uib_article' => 'uib_article',
  );
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'news' => 'news',
  );
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['relationship'] = 'reverse_field_uib_profiled_message_node';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'frontpage' => 'frontpage',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'nb' => 'nb',
  );

  /* Display: Profiled articles newspage */
  $handler = $view->new_display('block', 'Profiled articles newspage', 'newspage_one_chosen_item');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'clearfix full';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Main media */
  $handler->display->display_options['fields']['field_uib_main_media']['id'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['table'] = 'field_data_field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['field'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['label'] = '';
  $handler->display->display_options['fields']['field_uib_main_media']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_uib_main_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_main_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_uib_main_media']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_uib_main_media']['settings'] = array(
    'file_view_mode' => 'wide_thumbnail',
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'linked_field' => array(
      'linked' => 1,
      'destination' => '[node:url]',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_uib_main_media']['delta_offset'] = '0';
  /* Field: Content: Kicker */
  $handler->display->display_options['fields']['field_uib_kicker']['id'] = 'field_uib_kicker';
  $handler->display->display_options['fields']['field_uib_kicker']['table'] = 'field_data_field_uib_kicker';
  $handler->display->display_options['fields']['field_uib_kicker']['field'] = 'field_uib_kicker';
  $handler->display->display_options['fields']['field_uib_kicker']['label'] = '';
  $handler->display->display_options['fields']['field_uib_kicker']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_kicker']['empty'] = 'News';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Lead */
  $handler->display->display_options['fields']['field_uib_lead']['id'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['table'] = 'field_data_field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['field'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['label'] = '';
  $handler->display->display_options['fields']['field_uib_lead']['alter']['text'] = '<div class="media-content">
  [field_uib_kicker]
  [title]
  [field_uib_lead]
</div>';
  $handler->display->display_options['fields']['field_uib_lead']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Promoted articles (field_uib_profiled_message:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_uib_profiled_message';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
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
    'uib_article' => 'uib_article',
  );
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['relationship'] = 'reverse_field_uib_profiled_message_node';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'newspage' => 'newspage',
  );

  /* Display: Profiled articles newspage 2 items */
  $handler = $view->new_display('block', 'Profiled articles newspage 2 items', 'newspage_two_chosen_items');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'clearfix half';
  $handler->display->display_options['display_description'] = 'Showing the next 2 items';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Main media */
  $handler->display->display_options['fields']['field_uib_main_media']['id'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['table'] = 'field_data_field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['field'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['label'] = '';
  $handler->display->display_options['fields']['field_uib_main_media']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_uib_main_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_main_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_uib_main_media']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_uib_main_media']['settings'] = array(
    'file_view_mode' => 'wide_thumbnail',
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'linked_field' => array(
      'linked' => 1,
      'destination' => '[node:url]',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_uib_main_media']['delta_offset'] = '0';
  /* Field: Content: Kicker */
  $handler->display->display_options['fields']['field_uib_kicker']['id'] = 'field_uib_kicker';
  $handler->display->display_options['fields']['field_uib_kicker']['table'] = 'field_data_field_uib_kicker';
  $handler->display->display_options['fields']['field_uib_kicker']['field'] = 'field_uib_kicker';
  $handler->display->display_options['fields']['field_uib_kicker']['label'] = '';
  $handler->display->display_options['fields']['field_uib_kicker']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_kicker']['empty'] = 'News';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Lead */
  $handler->display->display_options['fields']['field_uib_lead']['id'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['table'] = 'field_data_field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['field'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['label'] = '';
  $handler->display->display_options['fields']['field_uib_lead']['alter']['text'] = '<div class="media-content">
  [field_uib_kicker]
  [title]
  [field_uib_lead]
</div>';
  $handler->display->display_options['fields']['field_uib_lead']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Promoted articles (field_uib_profiled_message:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_uib_profiled_message';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
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
    'uib_article' => 'uib_article',
  );
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['relationship'] = 'reverse_field_uib_profiled_message_node';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'newspage' => 'newspage',
  );

  /* Display: Profiled articles newspage last items */
  $handler = $view->new_display('block', 'Profiled articles newspage last items', 'newspage_last_chosen_items');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'clearfix half';
  $handler->display->display_options['display_description'] = 'Showing the last items';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '3';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Main media */
  $handler->display->display_options['fields']['field_uib_main_media']['id'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['table'] = 'field_data_field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['field'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['label'] = '';
  $handler->display->display_options['fields']['field_uib_main_media']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_uib_main_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_main_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_uib_main_media']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_uib_main_media']['settings'] = array(
    'file_view_mode' => 'wide_thumbnail',
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'linked_field' => array(
      'linked' => 1,
      'destination' => '[node:url]',
      'advanced' => array(
        'title' => '',
        'target' => '',
        'class' => '',
        'rel' => '',
        'text' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_uib_main_media']['delta_offset'] = '0';
  /* Field: Content: Kicker */
  $handler->display->display_options['fields']['field_uib_kicker']['id'] = 'field_uib_kicker';
  $handler->display->display_options['fields']['field_uib_kicker']['table'] = 'field_data_field_uib_kicker';
  $handler->display->display_options['fields']['field_uib_kicker']['field'] = 'field_uib_kicker';
  $handler->display->display_options['fields']['field_uib_kicker']['label'] = '';
  $handler->display->display_options['fields']['field_uib_kicker']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_kicker']['empty'] = 'News';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Lead */
  $handler->display->display_options['fields']['field_uib_lead']['id'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['table'] = 'field_data_field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['field'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['label'] = '';
  $handler->display->display_options['fields']['field_uib_lead']['alter']['text'] = '<div class="media-content">
  [field_uib_kicker]
  [title]
  [field_uib_lead]
</div>';
  $handler->display->display_options['fields']['field_uib_lead']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Promoted articles (field_uib_profiled_message:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_uib_profiled_message';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
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
    'uib_article' => 'uib_article',
  );
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['relationship'] = 'reverse_field_uib_profiled_message_node';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'newspage' => 'newspage',
  );
  $translatables['frontpage_profiled_articles'] = array(
    t('Master'),
    t('Frontpage profiled articles'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content referencing Content from field_uib_profiled_message'),
    t('All'),
    t('Profiled news english'),
    t('News'),
    t('More news'),
    t('Profiled events english'),
    t('Calendar'),
    t('See the entire calendar'),
    t('[field_uib_date] - [title] ([field_uib_event_type])'),
    t('Profiled events norwegian'),
    t('Kalender — Det&nbsp;skjer'),
    t('Se hele kalenderen'),
    t('Profiled news norwegian'),
    t('Nyheter'),
    t('Flere aktuelle saker'),
    t('Profiled articles newspage'),
    t('<div class="media-content">
  [field_uib_kicker]
  [title]
  [field_uib_lead]
</div>'),
    t('Profiled articles newspage 2 items'),
    t('Showing the next 2 items'),
    t('Profiled articles newspage last items'),
    t('Showing the last items'),
  );
  $export['frontpage_profiled_articles'] = $view;

  $view = new view();
  $view->name = 'newslist';
  $view->description = 'A view that is used by the newslist field on areas';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Newslist';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = '';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['status']['alter']['text'] = '([status])';
  $handler->display->display_options['fields']['status']['element_type'] = 'span';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: ID */
  $handler->display->display_options['fields']['field_uib_study_code']['id'] = 'field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['table'] = 'field_data_field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['field'] = 'field_uib_study_code';
  $handler->display->display_options['fields']['field_uib_study_code']['label'] = '';
  $handler->display->display_options['fields']['field_uib_study_code']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_study_code']['hide_empty'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Area */
  $handler->display->display_options['fields']['field_uib_area']['id'] = 'field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['field'] = 'field_uib_area';
  $handler->display->display_options['fields']['field_uib_area']['label'] = '';
  $handler->display->display_options['fields']['field_uib_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_area']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_uib_area']['settings'] = array(
    'link' => 0,
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
  );
  $handler->display->display_options['fields']['field_uib_area']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uib_article' => 'uib_article',
    'uib_content_list' => 'uib_content_list',
    'uib_testimonial' => 'uib_testimonial',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'uib_external_content' => 'uib_external_content',
    'uib_study' => 'uib_study',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 2;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_uib_study_code' => 'field_uib_study_code',
    'title' => 'title',
    'field_uib_area' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Content list autocomplete */
  $handler = $view->new_display('entityreference', 'Content list autocomplete', 'entityreference_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_uib_study_code' => 'field_uib_study_code',
    'title' => 'title',
    'status' => 0,
    'field_uib_area' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uib_article' => 'uib_article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'infopage' => 'infopage',
  );
  $translatables['newslist'] = array(
    t('Master'),
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
    t('([status])'),
    t('Entity Reference'),
    t('Content list autocomplete'),
  );
  $export['newslist'] = $view;

  $view = new view();
  $view->name = 'recent_news';
  $view->description = 'List the 5 most recent news';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recent news';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent news';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Area (field_uib_area) */
  $handler->display->display_options['arguments']['field_uib_area_target_id']['id'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['field'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary_options']['items_per_page'] = '25';
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
    'uib_article' => 'uib_article',
  );
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'news' => 'news',
  );

  /* Display: Area recent news block */
  $handler = $view->new_display('block', 'Area recent news block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'News archive';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_uib_area_target_id']['id'] = 'field_uib_area_target_id';
  $handler->display->display_options['relationships']['field_uib_area_target_id']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['relationships']['field_uib_area_target_id']['field'] = 'field_uib_area_target_id';
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
    'uib_article' => 'uib_article',
  );
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'news' => 'news',
  );
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['relationship'] = 'field_uib_area_target_id';
  $handler->display->display_options['filters']['field_uib_area_type_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'frontpage' => 'frontpage',
    'newspage' => 'newspage',
  );
  /* Filter criterion: Not too old */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['ui_name'] = 'Not too old';
  $handler->display->display_options['filters']['created']['operator'] = '>';
  $handler->display->display_options['filters']['created']['value']['value'] = '-16 weeks';
  $handler->display->display_options['filters']['created']['value']['type'] = 'offset';

  /* Display: News archive */
  $handler = $view->new_display('page', 'News archive', 'newsarchive');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'News archive';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'created',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'node';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created_1']['date_format'] = 'medium';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Main media */
  $handler->display->display_options['fields']['field_uib_main_media']['id'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['table'] = 'field_data_field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['field'] = 'field_uib_main_media';
  $handler->display->display_options['fields']['field_uib_main_media']['label'] = '';
  $handler->display->display_options['fields']['field_uib_main_media']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_uib_main_media']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_uib_main_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_main_media']['empty'] = '<img src="/sites/all/themes/uib/uib_zen/images/Recent_High.png">';
  $handler->display->display_options['fields']['field_uib_main_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_uib_main_media']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_uib_main_media']['settings'] = array(
    'file_view_mode' => 'wide_thumbnail',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] ([created_1])';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Lead */
  $handler->display->display_options['fields']['field_uib_lead']['id'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['table'] = 'field_data_field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['field'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['label'] = '';
  $handler->display->display_options['fields']['field_uib_lead']['alter']['max_length'] = '400';
  $handler->display->display_options['fields']['field_uib_lead']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['field_uib_lead']['alter']['more_link_text'] = 'Read more';
  $handler->display->display_options['fields']['field_uib_lead']['alter']['more_link_path'] = '[path]';
  $handler->display->display_options['fields']['field_uib_lead']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_uib_lead']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Area (field_uib_area) */
  $handler->display->display_options['arguments']['field_uib_area_target_id']['id'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['field'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_area_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['validate_options']['types'] = array(
    'area' => 'area',
  );
  /* Contextual filter: Content: Created year + month */
  $handler->display->display_options['arguments']['created_year_month']['id'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['table'] = 'node';
  $handler->display->display_options['arguments']['created_year_month']['field'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['created_year_month']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['created_year_month']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['created_year_month']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['created_year_month']['specify_validation'] = TRUE;
  $handler->display->display_options['path'] = 'node/%/news-archive';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Area (field_uib_area) */
  $handler->display->display_options['arguments']['field_uib_area_target_id']['id'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['field'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_uib_area_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['validate_options']['types'] = array(
    'area' => 'area',
  );
  $handler->display->display_options['path'] = 'node/%/rss.xml';

  /* Display: Date and year selector */
  $handler = $view->new_display('block', 'Date and year selector', 'block_date_selector');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Select news by month and year';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Area (field_uib_area) */
  $handler->display->display_options['arguments']['field_uib_area_target_id']['id'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['field'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Created year + month */
  $handler->display->display_options['arguments']['created_year_month']['id'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['table'] = 'node';
  $handler->display->display_options['arguments']['created_year_month']['field'] = 'created_year_month';
  $handler->display->display_options['arguments']['created_year_month']['default_action'] = 'summary';
  $handler->display->display_options['arguments']['created_year_month']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['created_year_month']['summary']['sort_order'] = 'desc';
  $handler->display->display_options['arguments']['created_year_month']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['created_year_month']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['created_year_month']['summary_options']['base_path'] = 'node/%/news-archive';
  $handler->display->display_options['arguments']['created_year_month']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['created_year_month']['specify_validation'] = TRUE;
  $translatables['recent_news'] = array(
    t('Master'),
    t('Recent news'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Area recent news block'),
    t('News archive'),
    t('Content entity referenced from field_uib_area'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Post date'),
    t('<img src="/sites/all/themes/uib/uib_zen/images/Recent_High.png">'),
    t('[title] ([created_1])'),
    t('Read more'),
    t('Feed'),
    t('Date and year selector'),
    t('Select news by month and year'),
  );
  $export['recent_news'] = $view;

  $view = new view();
  $view->name = 'recent_phds';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recent PhDs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent PhDs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'clearfix';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_uib_media']['id'] = 'field_uib_media';
  $handler->display->display_options['fields']['field_uib_media']['table'] = 'field_data_field_uib_media';
  $handler->display->display_options['fields']['field_uib_media']['field'] = 'field_uib_media';
  $handler->display->display_options['fields']['field_uib_media']['label'] = '';
  $handler->display->display_options['fields']['field_uib_media']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_uib_media']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_uib_media']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_uib_media']['settings'] = array(
    'file_view_mode' => 'area_bottom',
  );
  $handler->display->display_options['fields']['field_uib_media']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_uib_media']['delta_offset'] = '0';
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
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] ([field_uib_date])';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Lead */
  $handler->display->display_options['fields']['field_uib_lead']['id'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['table'] = 'field_data_field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['field'] = 'field_uib_lead';
  $handler->display->display_options['fields']['field_uib_lead']['label'] = '';
  $handler->display->display_options['fields']['field_uib_lead']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_uib_lead']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="phd-lead-title-wrapper">
<div class="phd-title">[title]</div>
<div class="phd-lead">[field_uib_lead]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_uib_date) */
  $handler->display->display_options['sorts']['field_uib_date_value']['id'] = 'field_uib_date_value';
  $handler->display->display_options['sorts']['field_uib_date_value']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['sorts']['field_uib_date_value']['field'] = 'field_uib_date_value';
  $handler->display->display_options['sorts']['field_uib_date_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_uib_date_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_uib_date_value']['expose']['label'] = 'Date';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Contextual filter: Content: Area (field_uib_area) */
  $handler->display->display_options['arguments']['field_uib_area_target_id']['id'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['table'] = 'field_data_field_uib_area';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['field'] = 'field_uib_area_target_id';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['exception']['title'] = 'Alle';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_area_target_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Date -  start date (field_uib_date) */
  $handler->display->display_options['arguments']['field_uib_date_value']['id'] = 'field_uib_date_value';
  $handler->display->display_options['arguments']['field_uib_date_value']['table'] = 'field_data_field_uib_date';
  $handler->display->display_options['arguments']['field_uib_date_value']['field'] = 'field_uib_date_value';
  $handler->display->display_options['arguments']['field_uib_date_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_date_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_uib_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_uib_date_value']['year_range'] = '2014:+1';
  $handler->display->display_options['arguments']['field_uib_date_value']['granularity'] = 'year';
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
    'uib_article' => 'uib_article',
  );
  /* Filter criterion: Content: Type (field_uib_article_type) */
  $handler->display->display_options['filters']['field_uib_article_type_value']['id'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['table'] = 'field_data_field_uib_article_type';
  $handler->display->display_options['filters']['field_uib_article_type_value']['field'] = 'field_uib_article_type_value';
  $handler->display->display_options['filters']['field_uib_article_type_value']['value'] = array(
    'phd_press_release' => 'phd_press_release',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/recent-phds';
  $translatables['recent_phds'] = array(
    t('Master'),
    t('Recent PhDs'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('[title] ([field_uib_date])'),
    t('<div class="phd-lead-title-wrapper">
<div class="phd-title">[title]</div>
<div class="phd-lead">[field_uib_lead]</div>
</div>'),
    t('Date'),
    t('Title'),
    t('Alle'),
    t('All'),
    t('Page'),
  );
  $export['recent_phds'] = $view;

  $view = new view();
  $view->name = 'relevant_links';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Relevant links';
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
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  /* Relationship: Field collection item: Entity with the Relevant links (field_uib_link_section) */
  $handler->display->display_options['relationships']['field_uib_link_section_node']['id'] = 'field_uib_link_section_node';
  $handler->display->display_options['relationships']['field_uib_link_section_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_uib_link_section_node']['field'] = 'field_uib_link_section_node';
  $handler->display->display_options['relationships']['field_uib_link_section_node']['required'] = TRUE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_uib_link_section_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'return uib_area__get_current_nid();';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['relationship'] = 'field_uib_link_section_node';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'newspage' => 'newspage',
  );

  /* Display: Relevant Links */
  $handler = $view->new_display('block', 'Relevant Links', 'relevant_links');
  $handler->display->display_options['display_description'] = 'Expose uib_link_section to a block ';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['relationship'] = 'field_uib_link_section_node';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'newspage' => 'newspage',
    'phdpresspage' => 'phdpresspage',
  );

  /* Display: Shortcut menu */
  $handler = $view->new_display('block', 'Shortcut menu', 'block_1');
  $handler->display->display_options['display_description'] = 'Shortcut menu for frontpage';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['relationship'] = 'field_uib_link_section_node';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'frontpage' => 'frontpage',
  );
  $translatables['relevant_links'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('field_uib_link_section'),
    t('Field collection item ID'),
    t('.'),
    t(','),
    t('All'),
    t('Relevant Links'),
    t('Expose uib_link_section to a block '),
    t('Shortcut menu'),
    t('Shortcut menu for frontpage'),
  );
  $export['relevant_links'] = $view;

  $view = new view();
  $view->name = 'research_groups';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Research groups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Research groups';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Parents (field_uib_area_parents) */
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['id'] = 'field_uib_area_parents_target_id';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['table'] = 'field_data_field_uib_area_parents';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['field'] = 'field_uib_area_parents_target_id';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['summary_options']['items_per_page'] = '25';
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
    'area' => 'area',
  );
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'research group' => 'research group',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Research groups */
  $handler = $view->new_display('page', 'Research groups', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'node/%/research-groups';

  /* Display: Research schools */
  $handler = $view->new_display('page', 'Research schools', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Research schools';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Parents (field_uib_area_parents) */
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['id'] = 'field_uib_area_parents_target_id';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['table'] = 'field_data_field_uib_area_parents';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['field'] = 'field_uib_area_parents_target_id';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['summary_options']['items_per_page'] = '25';
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
    'area' => 'area',
  );
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'research school' => 'research school',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'node/%/research-schools';

  /* Display: Disciplines */
  $handler = $view->new_display('page', 'Disciplines', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Disciplines';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Parents (field_uib_area_parents) */
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['id'] = 'field_uib_area_parents_target_id';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['table'] = 'field_data_field_uib_area_parents';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['field'] = 'field_uib_area_parents_target_id';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_uib_area_parents_target_id']['summary_options']['items_per_page'] = '25';
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
    'area' => 'area',
  );
  /* Filter criterion: Content: Type (field_uib_area_type) */
  $handler->display->display_options['filters']['field_uib_area_type_value']['id'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['table'] = 'field_data_field_uib_area_type';
  $handler->display->display_options['filters']['field_uib_area_type_value']['field'] = 'field_uib_area_type_value';
  $handler->display->display_options['filters']['field_uib_area_type_value']['value'] = array(
    'discipline' => 'discipline',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['path'] = 'node/%/disciplines';
  $translatables['research_groups'] = array(
    t('Master'),
    t('Research groups'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Research schools'),
    t('Disciplines'),
  );
  $export['research_groups'] = $view;

  return $export;
}
