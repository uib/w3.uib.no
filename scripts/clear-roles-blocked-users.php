<?php

# This script will clear the roles for all blocked users

$rid_level1 = 74573517;
$rid_level2 = 170699807;
$rid_level3 = 64272948;

$result = db_query("SELECT DISTINCT u.uid, name FROM {users} AS u JOIN users_roles AS r ON u.uid = r.uid JOIN field_data_field_uib_user_domain AS d ON u.uid = d.entity_id WHERE status=0 AND field_uib_user_domain_value = 'uib' AND rid IN ($rid_level1, $rid_level2, $rid_level3) ORDER BY name");
foreach ($result as $row) {
  print "$row->name $row->uid\n";
  $account = user_load($row->uid);
  $roles = $account->roles;
  $roles = array_filter($roles, function($rid) use ($rid_level1, $rid_level2, $rid_level3) {
    return !in_array($rid, array($rid_level1, $rid_level2, $rid_level3));
  }, ARRAY_FILTER_USE_KEY);
  user_save($account, array('roles' => $roles));
}
