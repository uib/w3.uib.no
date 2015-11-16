<?php
/**
 * @file
 * uib_setup.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function uib_setup_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'The <em>Management</em> menu contains links for administrative tasks.',
  );
  // Exported menu: menu-webdesk.
  $menus['menu-webdesk'] = array(
    'menu_name' => 'menu-webdesk',
    'title' => 'Webdesk',
    'description' => '',
  );
  // Exported menu: menu-webdesk-no.
  $menus['menu-webdesk-no'] = array(
    'menu_name' => 'menu-webdesk-no',
    'title' => 'Webdesk_no',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Management');
  t('The <em>Management</em> menu contains links for administrative tasks.');
  t('Webdesk');
  t('Webdesk_no');

  return $menus;
}
