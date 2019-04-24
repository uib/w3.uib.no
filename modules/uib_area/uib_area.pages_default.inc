<?php

/**
 * @file
 * uib_area.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function uib_area_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'area' => 'area',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2f5e3c29-10e8-4adb-9834-b412255d5179';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ec8a5aac-9cdd-413a-a4a2-91ecfc490ce8';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_uib_text2';
  $pane->shown = TRUE;
  $pane->access = array(
    'logic' => 'and',
  );
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ec8a5aac-9cdd-413a-a4a2-91ecfc490ce8';
  $display->content['new-ec8a5aac-9cdd-413a-a4a2-91ecfc490ce8'] = $pane;
  $display->panels['left'][0] = 'new-ec8a5aac-9cdd-413a-a4a2-91ecfc490ce8';
  $pane = new stdClass();
  $pane->pid = 'new-bc57c045-a4ff-4da2-98c7-0c8a09b18715';
  $pane->panel = 'left';
  $pane->type = 'views';
  $pane->subtype = 'area_slideshow';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'context' => array(
      0 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'bc57c045-a4ff-4da2-98c7-0c8a09b18715';
  $display->content['new-bc57c045-a4ff-4da2-98c7-0c8a09b18715'] = $pane;
  $display->panels['left'][1] = 'new-bc57c045-a4ff-4da2-98c7-0c8a09b18715';
  $pane = new stdClass();
  $pane->pid = 'new-9de6a302-4260-43a5-9bde-73e54d72c89f';
  $pane->panel = 'right';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 1,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 1,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9de6a302-4260-43a5-9bde-73e54d72c89f';
  $display->content['new-9de6a302-4260-43a5-9bde-73e54d72c89f'] = $pane;
  $display->panels['right'][0] = 'new-9de6a302-4260-43a5-9bde-73e54d72c89f';
  $pane = new stdClass();
  $pane->pid = 'new-d90b8d8e-2d48-4367-b360-070242ebf2b1';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_uib_newslist';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'teaser',
    ),
    'context' => 'argument_entity_id:node_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'd90b8d8e-2d48-4367-b360-070242ebf2b1';
  $display->content['new-d90b8d8e-2d48-4367-b360-070242ebf2b1'] = $pane;
  $display->panels['right'][1] = 'new-d90b8d8e-2d48-4367-b360-070242ebf2b1';
  $pane = new stdClass();
  $pane->pid = 'new-b2271c17-0a62-4121-bc1f-739aa7f7d07f';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'views-recent_news-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'News',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'b2271c17-0a62-4121-bc1f-739aa7f7d07f';
  $display->content['new-b2271c17-0a62-4121-bc1f-739aa7f7d07f'] = $pane;
  $display->panels['right'][2] = 'new-b2271c17-0a62-4121-bc1f-739aa7f7d07f';
  $pane = new stdClass();
  $pane->pid = 'new-2779e8e8-bbdd-4ab5-ad07-7748e912bbad';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'uib_area-jobbnorge';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '2779e8e8-bbdd-4ab5-ad07-7748e912bbad';
  $display->content['new-2779e8e8-bbdd-4ab5-ad07-7748e912bbad'] = $pane;
  $display->panels['right'][3] = 'new-2779e8e8-bbdd-4ab5-ad07-7748e912bbad';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ec8a5aac-9cdd-413a-a4a2-91ecfc490ce8';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Area pages',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:taxonomy_term',
          'settings' => array(
            'type' => array(
              'area' => 'area',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7add51a1-996f-4b5e-9af4-8f46d023409b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'term_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f158b0a5-e74d-4166-845a-d113646f6c70';
  $pane->panel = 'left';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_uib_trans_text2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_term_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f158b0a5-e74d-4166-845a-d113646f6c70';
  $display->content['new-f158b0a5-e74d-4166-845a-d113646f6c70'] = $pane;
  $display->panels['left'][0] = 'new-f158b0a5-e74d-4166-845a-d113646f6c70';
  $pane = new stdClass();
  $pane->pid = 'new-a912a8a6-82dc-471b-b8bc-11b82a9f51a1';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views-area_kids-block_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a912a8a6-82dc-471b-b8bc-11b82a9f51a1';
  $display->content['new-a912a8a6-82dc-471b-b8bc-11b82a9f51a1'] = $pane;
  $display->panels['left'][1] = 'new-a912a8a6-82dc-471b-b8bc-11b82a9f51a1';
  $pane = new stdClass();
  $pane->pid = 'new-c7128b26-a63e-426f-87d8-25666f019a53';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_uib_main_media';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'file_rendered',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'media_original',
    ),
    'context' => 'argument_term_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c7128b26-a63e-426f-87d8-25666f019a53';
  $display->content['new-c7128b26-a63e-426f-87d8-25666f019a53'] = $pane;
  $display->panels['right'][0] = 'new-c7128b26-a63e-426f-87d8-25666f019a53';
  $pane = new stdClass();
  $pane->pid = 'new-a7a6b8c2-be16-4690-a6c3-3363e6c39ae7';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_uib_trans_text';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'argument_term_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a7a6b8c2-be16-4690-a6c3-3363e6c39ae7';
  $display->content['new-a7a6b8c2-be16-4690-a6c3-3363e6c39ae7'] = $pane;
  $display->panels['right'][1] = 'new-a7a6b8c2-be16-4690-a6c3-3363e6c39ae7';
  $pane = new stdClass();
  $pane->pid = 'new-c1c14ea6-ae24-4376-b12b-09bc3be6d050';
  $pane->panel = 'right';
  $pane->type = 'entity_field';
  $pane->subtype = 'taxonomy_term:field_uib_newslist';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'entityreference_entity_view',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'view_mode' => 'teaser',
    ),
    'context' => 'argument_term_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'c1c14ea6-ae24-4376-b12b-09bc3be6d050';
  $display->content['new-c1c14ea6-ae24-4376-b12b-09bc3be6d050'] = $pane;
  $display->panels['right'][2] = 'new-c1c14ea6-ae24-4376-b12b-09bc3be6d050';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a912a8a6-82dc-471b-b8bc-11b82a9f51a1';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  return $export;
}
