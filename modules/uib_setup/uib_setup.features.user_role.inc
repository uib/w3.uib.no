<?php
/**
 * @file
 * uib_setup.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function uib_setup_user_default_roles() {
  $roles = array();

  // Exported role: admin.
  $roles['admin'] = array(
    'name' => 'admin',
    'weight' => 5,
    'machine_name' => 'admin',
  );

  // Exported role: innholdsprodusent.
  $roles['innholdsprodusent'] = array(
    'name' => 'innholdsprodusent',
    'weight' => 3,
    'machine_name' => 'innholdsprodusent',
  );

  // Exported role: level 3.
  $roles['level 3'] = array(
    'name' => 'level 3',
    'weight' => 2,
    'machine_name' => 'level_3',
  );

  // Exported role: superbruker.
  $roles['superbruker'] = array(
    'name' => 'superbruker',
    'weight' => 4,
    'machine_name' => 'superbruker',
  );

  return $roles;
}
