<?php
/**
 * @file
 * uib_setup.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function uib_setup_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_webdesk:webdesk
  $menu_links['management_webdesk:webdesk'] = array(
    'menu_name' => 'management',
    'link_path' => 'webdesk',
    'router_path' => 'webdesk',
    'link_title' => 'Webdesk',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'management_webdesk:webdesk',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Webdesk');

  return $menu_links;
}
