<?php
/**
 * @file
 * uib_message.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uib_message_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create uib_message content'.
  $permissions['create uib_message content'] = array(
    'name' => 'create uib_message content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any uib_message content'.
  $permissions['delete any uib_message content'] = array(
    'name' => 'delete any uib_message content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own uib_message content'.
  $permissions['delete own uib_message content'] = array(
    'name' => 'delete own uib_message content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in uib_message_tag'.
  $permissions['delete terms in uib_message_tag'] = array(
    'name' => 'delete terms in uib_message_tag',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any uib_message content'.
  $permissions['edit any uib_message content'] = array(
    'name' => 'edit any uib_message content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own uib_message content'.
  $permissions['edit own uib_message content'] = array(
    'name' => 'edit own uib_message content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in uib_message_tag'.
  $permissions['edit terms in uib_message_tag'] = array(
    'name' => 'edit terms in uib_message_tag',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'enter uib_message revision log entry'.
  $permissions['enter uib_message revision log entry'] = array(
    'name' => 'enter uib_message revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_message authored by option'.
  $permissions['override uib_message authored by option'] = array(
    'name' => 'override uib_message authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_message authored on option'.
  $permissions['override uib_message authored on option'] = array(
    'name' => 'override uib_message authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_message promote to front page option'.
  $permissions['override uib_message promote to front page option'] = array(
    'name' => 'override uib_message promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_message published option'.
  $permissions['override uib_message published option'] = array(
    'name' => 'override uib_message published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_message revision option'.
  $permissions['override uib_message revision option'] = array(
    'name' => 'override uib_message revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_message sticky option'.
  $permissions['override uib_message sticky option'] = array(
    'name' => 'override uib_message sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'view any unpublished uib_message content'.
  $permissions['view any unpublished uib_message content'] = array(
    'name' => 'view any unpublished uib_message content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
