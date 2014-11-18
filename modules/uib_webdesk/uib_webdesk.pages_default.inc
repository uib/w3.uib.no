<?php
/**
 * @file
 * uib_webdesk.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function uib_webdesk_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'uib_webdesk';
  $page->task = 'page';
  $page->admin_title = 'UiB webdesk';
  $page->admin_description = '';
  $page->path = 'webdesk/all';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 64272948,
            1 => 170699807,
            2 => 74573517,
            3 => 176168899,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'php',
        'settings' => array(
          'description' => '',
          'php' => 'global $user;
          if ($user->uid == 1)
          return TRUE;
        ',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
  );
  $page->menu = array(
    'type' => 'default tab',
    'title' => 'Webdesk',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'normal',
      'title' => 'Webdesk',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_uib_webdesk_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'uib_webdesk';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'site_language',
          'settings' => array(
            'language' => array(
              'en' => 'en',
              'default' => 0,
              'nb' => 0,
            ),
          ),
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
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'UiB webdesk';
  $display->uuid = '002d1d29-220a-4599-b8b6-15f224cf2fb0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fd95a6c9-16c7-4079-a404-4ad1bd5532bf';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_block-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fd95a6c9-16c7-4079-a404-4ad1bd5532bf';
    $display->content['new-fd95a6c9-16c7-4079-a404-4ad1bd5532bf'] = $pane;
    $display->panels['left'][0] = 'new-fd95a6c9-16c7-4079-a404-4ad1bd5532bf';
    $pane = new stdClass();
    $pane->pid = 'new-a74bacc8-7902-40fb-8c3c-7ebb5f2a0448';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_areas-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a74bacc8-7902-40fb-8c3c-7ebb5f2a0448';
    $display->content['new-a74bacc8-7902-40fb-8c3c-7ebb5f2a0448'] = $pane;
    $display->panels['left'][1] = 'new-a74bacc8-7902-40fb-8c3c-7ebb5f2a0448';
    $pane = new stdClass();
    $pane->pid = 'new-4d0963bc-d2ab-482f-83c1-127bd65a5f73';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'locale-language';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4d0963bc-d2ab-482f-83c1-127bd65a5f73';
    $display->content['new-4d0963bc-d2ab-482f-83c1-127bd65a5f73'] = $pane;
    $display->panels['right'][0] = 'new-4d0963bc-d2ab-482f-83c1-127bd65a5f73';
    $pane = new stdClass();
    $pane->pid = 'new-312d272c-fa69-41ea-804d-fe3bf23cd583';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-webdesk';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '312d272c-fa69-41ea-804d-fe3bf23cd583';
    $display->content['new-312d272c-fa69-41ea-804d-fe3bf23cd583'] = $pane;
    $display->panels['right'][1] = 'new-312d272c-fa69-41ea-804d-fe3bf23cd583';
    $pane = new stdClass();
    $pane->pid = 'new-a6964d5f-fe9a-46fa-b311-4e7fbe7103a6';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_content-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'a6964d5f-fe9a-46fa-b311-4e7fbe7103a6';
    $display->content['new-a6964d5f-fe9a-46fa-b311-4e7fbe7103a6'] = $pane;
    $display->panels['right'][2] = 'new-a6964d5f-fe9a-46fa-b311-4e7fbe7103a6';
    $pane = new stdClass();
    $pane->pid = 'new-0193ae68-5fc1-4bbb-abf5-b026a37fbcf7';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'scheduled_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '1',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
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
    $pane->uuid = '0193ae68-5fc1-4bbb-abf5-b026a37fbcf7';
    $display->content['new-0193ae68-5fc1-4bbb-abf5-b026a37fbcf7'] = $pane;
    $display->panels['right'][3] = 'new-0193ae68-5fc1-4bbb-abf5-b026a37fbcf7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_uib_webdesk_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'uib_webdesk';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Norwegian webdesk',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'site_language',
          'settings' => array(
            'language' => array(
              'nb' => 'nb',
              'default' => 0,
              'en' => 0,
            ),
          ),
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
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'UiB webdesk';
  $display->uuid = '21a2c512-3c0a-4019-bdf3-e7e151da805f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e90ad83a-1963-4be7-bc4d-7497287a6c14';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_block-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e90ad83a-1963-4be7-bc4d-7497287a6c14';
    $display->content['new-e90ad83a-1963-4be7-bc4d-7497287a6c14'] = $pane;
    $display->panels['left'][0] = 'new-e90ad83a-1963-4be7-bc4d-7497287a6c14';
    $pane = new stdClass();
    $pane->pid = 'new-e9bcd3b4-9b8e-47e3-9e66-a48569e63d5f';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'user_areas-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e9bcd3b4-9b8e-47e3-9e66-a48569e63d5f';
    $display->content['new-e9bcd3b4-9b8e-47e3-9e66-a48569e63d5f'] = $pane;
    $display->panels['left'][1] = 'new-e9bcd3b4-9b8e-47e3-9e66-a48569e63d5f';
    $pane = new stdClass();
    $pane->pid = 'new-55d9c448-2c8f-4651-a0b3-59d753d01d10';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'locale-language';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '55d9c448-2c8f-4651-a0b3-59d753d01d10';
    $display->content['new-55d9c448-2c8f-4651-a0b3-59d753d01d10'] = $pane;
    $display->panels['right'][0] = 'new-55d9c448-2c8f-4651-a0b3-59d753d01d10';
    $pane = new stdClass();
    $pane->pid = 'new-ecc0db74-02df-4c37-aede-33386cd356ed';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-webdesk-no';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ecc0db74-02df-4c37-aede-33386cd356ed';
    $display->content['new-ecc0db74-02df-4c37-aede-33386cd356ed'] = $pane;
    $display->panels['right'][1] = 'new-ecc0db74-02df-4c37-aede-33386cd356ed';
    $pane = new stdClass();
    $pane->pid = 'new-abcbce76-b0a2-43e0-8d40-f5f57d6107b6';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'my_content-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'abcbce76-b0a2-43e0-8d40-f5f57d6107b6';
    $display->content['new-abcbce76-b0a2-43e0-8d40-f5f57d6107b6'] = $pane;
    $display->panels['right'][2] = 'new-abcbce76-b0a2-43e0-8d40-f5f57d6107b6';
    $pane = new stdClass();
    $pane->pid = 'new-fffe931a-1dd2-46f5-8deb-8b00460d3441';
    $pane->panel = 'right';
    $pane->type = 'views';
    $pane->subtype = 'scheduled_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '1',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
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
    $pane->uuid = 'fffe931a-1dd2-46f5-8deb-8b00460d3441';
    $display->content['new-fffe931a-1dd2-46f5-8deb-8b00460d3441'] = $pane;
    $display->panels['right'][3] = 'new-fffe931a-1dd2-46f5-8deb-8b00460d3441';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['uib_webdesk'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'uib_webdesk_user';
  $page->task = 'page';
  $page->admin_title = 'UiB webdesk user';
  $page->admin_description = '';
  $page->path = 'webdesk/my';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 5,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'php',
        'settings' => array(
          'description' => '',
          'php' => 'global $user;
            if ($user->uid == 1)
              return TRUE;',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'My content',
    'name' => 'navigation',
    'weight' => '10',
    'parent' => array(
      'type' => 'tab',
      'title' => 'Webdesk',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_uib_webdesk_user_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'uib_webdesk_user';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
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
  $display->title = 'UiB webdesk';
  $display->uuid = '84984cdc-9c70-408c-abfd-69e9618290f2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a425ba18-4b65-4202-847f-a8edd56d8d5f';
    $pane->panel = 'top';
    $pane->type = 'views_panes';
    $pane->subtype = 'uib_webdesk-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a425ba18-4b65-4202-847f-a8edd56d8d5f';
    $display->content['new-a425ba18-4b65-4202-847f-a8edd56d8d5f'] = $pane;
    $display->panels['top'][0] = 'new-a425ba18-4b65-4202-847f-a8edd56d8d5f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['uib_webdesk_user'] = $page;

  return $pages;

}
