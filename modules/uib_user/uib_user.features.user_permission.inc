<?php

/**
 * @file
 * uib_user.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uib_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'delete terms in uib_research_fields'.
  $permissions['delete terms in uib_research_fields'] = array(
    'name' => 'delete terms in uib_research_fields',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in uib_research_fields'.
  $permissions['edit terms in uib_research_fields'] = array(
    'name' => 'edit terms in uib_research_fields',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'translate user entities'.
  $permissions['translate user entities'] = array(
    'name' => 'translate user entities',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  return $permissions;
}
