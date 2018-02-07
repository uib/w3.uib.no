<?php
/**
 * @file
 * uib_redirect.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uib_redirect_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer redirects'.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      'admin' => 'admin',
      'superbruker' => 'superbruker',
    ),
    'module' => 'redirect',
  );

  return $permissions;
}
