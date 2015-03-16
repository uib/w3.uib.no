<?php
/**
 * @file
 * uib_views.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uib_views_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create uib_views_page content'.
  $permissions['create uib_views_page content'] = array(
    'name' => 'create uib_views_page content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any uib_views_page content'.
  $permissions['delete any uib_views_page content'] = array(
    'name' => 'delete any uib_views_page content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own uib_views_page content'.
  $permissions['delete own uib_views_page content'] = array(
    'name' => 'delete own uib_views_page content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any uib_views_page content'.
  $permissions['edit any uib_views_page content'] = array(
    'name' => 'edit any uib_views_page content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own uib_views_page content'.
  $permissions['edit own uib_views_page content'] = array(
    'name' => 'edit own uib_views_page content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
    ),
    'module' => 'node',
  );

  // Exported permission: 'override uib_views_page published option'.
  $permissions['override uib_views_page published option'] = array(
    'name' => 'override uib_views_page published option',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'override_node_options',
  );

  return $permissions;
}
