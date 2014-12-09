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
  // Exported menu link: menu-webdesk-no_finn-innhold:webdesk/all-content
  $menu_links['menu-webdesk-no_finn-innhold:webdesk/all-content'] = array(
    'menu_name' => 'menu-webdesk-no',
    'link_path' => 'webdesk/all-content',
    'router_path' => 'webdesk/all-content',
    'link_title' => 'Finn innhold',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-webdesk-no_finn-innhold:webdesk/all-content',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
  );
  // Exported menu link: menu-webdesk-no_legg-til-innhold:node/add/uib-article
  $menu_links['menu-webdesk-no_legg-til-innhold:node/add/uib-article'] = array(
    'menu_name' => 'menu-webdesk-no',
    'link_path' => 'node/add/uib-article',
    'router_path' => 'node/add/uib-article',
    'link_title' => 'Legg til innhold',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-webdesk-no_legg-til-innhold:node/add/uib-article',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-webdesk-no_legg-til-omrde:node/add/area
  $menu_links['menu-webdesk-no_legg-til-omrde:node/add/area'] = array(
    'menu_name' => 'menu-webdesk-no',
    'link_path' => 'node/add/area',
    'router_path' => 'node/add/area',
    'link_title' => 'Legg til område',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-webdesk-no_legg-til-omrde:node/add/area',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'customized' => 1,
  );
  // Exported menu link: menu-webdesk-no_legg-til-vitnesbyrd:node/add/uib-testimonial
  $menu_links['menu-webdesk-no_legg-til-vitnesbyrd:node/add/uib-testimonial'] = array(
    'menu_name' => 'menu-webdesk-no',
    'link_path' => 'node/add/uib-testimonial',
    'router_path' => 'node/add/uib-testimonial',
    'link_title' => 'Legg til vitnesbyrd',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-webdesk-no_legg-til-vitnesbyrd:node/add/uib-testimonial',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
  );
  // Exported menu link: menu-webdesk_add-area:node/add/area
  $menu_links['menu-webdesk_add-area:node/add/area'] = array(
    'menu_name' => 'menu-webdesk',
    'link_path' => 'node/add/area',
    'router_path' => 'node/add/area',
    'link_title' => 'Add area',
    'options' => array(
      'attributes' => array(
        'title' => 'This is where you add area',
      ),
      'identifier' => 'menu-webdesk_add-area:node/add/area',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 0,
  );
  // Exported menu link: menu-webdesk_add-content:node/add/uib-article
  $menu_links['menu-webdesk_add-content:node/add/uib-article'] = array(
    'menu_name' => 'menu-webdesk',
    'link_path' => 'node/add/uib-article',
    'router_path' => 'node/add/uib-article',
    'link_title' => 'Add content',
    'options' => array(
      'attributes' => array(
        'title' => 'This is where you add content',
      ),
      'identifier' => 'menu-webdesk_add-content:node/add/uib-article',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 0,
  );
  // Exported menu link: menu-webdesk_add-testimonial:node/add/uib-testimonial
  $menu_links['menu-webdesk_add-testimonial:node/add/uib-testimonial'] = array(
    'menu_name' => 'menu-webdesk',
    'link_path' => 'node/add/uib-testimonial',
    'router_path' => 'node/add/uib-testimonial',
    'link_title' => 'Add testimonial',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-webdesk_add-testimonial:node/add/uib-testimonial',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 0,
  );
  // Exported menu link: menu-webdesk_find-content:webdesk/all-content
  $menu_links['menu-webdesk_find-content:webdesk/all-content'] = array(
    'menu_name' => 'menu-webdesk',
    'link_path' => 'webdesk/all-content',
    'router_path' => 'webdesk/all-content',
    'link_title' => 'Find content',
    'options' => array(
      'attributes' => array(
        'title' => 'This is where you find all content',
      ),
      'identifier' => 'menu-webdesk_find-content:webdesk/all-content',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add area');
  t('Add content');
  t('Add testimonial');
  t('Find content');
  t('Finn innhold');
  t('Legg til innhold');
  t('Legg til område');
  t('Legg til vitnesbyrd');
  t('Webdesk');


  return $menu_links;
}
