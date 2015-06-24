<?php
/**
 * @file
 * uib_market.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uib_market_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create uib_market content'.
  $permissions['create uib_market content'] = array(
    'name' => 'create uib_market content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any uib_market content'.
  $permissions['delete any uib_market content'] = array(
    'name' => 'delete any uib_market content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own uib_market content'.
  $permissions['delete own uib_market content'] = array(
    'name' => 'delete own uib_market content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any uib_market content'.
  $permissions['edit any uib_market content'] = array(
    'name' => 'edit any uib_market content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own uib_market content'.
  $permissions['edit own uib_market content'] = array(
    'name' => 'edit own uib_market content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'enter uib_market revision log entry'.
  $permissions['enter uib_market revision log entry'] = array(
    'name' => 'enter uib_market revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_market authored by option'.
  $permissions['override uib_market authored by option'] = array(
    'name' => 'override uib_market authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_market authored on option'.
  $permissions['override uib_market authored on option'] = array(
    'name' => 'override uib_market authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_market promote to front page option'.
  $permissions['override uib_market promote to front page option'] = array(
    'name' => 'override uib_market promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_market published option'.
  $permissions['override uib_market published option'] = array(
    'name' => 'override uib_market published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_market revision option'.
  $permissions['override uib_market revision option'] = array(
    'name' => 'override uib_market revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_market sticky option'.
  $permissions['override uib_market sticky option'] = array(
    'name' => 'override uib_market sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'view any unpublished uib_market content'.
  $permissions['view any unpublished uib_market content'] = array(
    'name' => 'view any unpublished uib_market content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
