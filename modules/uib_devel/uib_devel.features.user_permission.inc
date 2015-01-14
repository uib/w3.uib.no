<?php
/**
 * @file
 * uib_devel.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uib_devel_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'admin' => 'admin',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'view style guides'.
  $permissions['view style guides'] = array(
    'name' => 'view style guides',
    'roles' => array(
      'admin' => 'admin',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'styleguide',
  );

  return $permissions;
}
