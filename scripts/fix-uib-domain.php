<?php

$result = db_query("SELECT DISTINCT uid, name, field_uib_user_domain_value AS domain, status, created, login FROM {users} AS u JOIN field_data_field_uib_user_domain AS d ON u.uid = d.entity_id WHERE field_uib_user_domain_value != 'uib' and name not like 'User stub%' and uid != 1 ORDER BY name");

$ignored = array();
foreach ($result as $user) {
  if (!looks_like_uib_username($user->name)) {
    $ignored[] = "$user->name@$user->domain";
    continue;
  }
  printf("%-7s %s %s %s %s\n", $user->name, $user->status, $user->domain, date('Y-m-d', $user->created), date('Y-m-d', $user->login));

  $u = user_load($user->uid);
  $edit = array();
  $edit['field_uib_user_domain']['und'][0]['value'] = 'uib';
  user_save($u, $edit);
}

if ($ignored) {
  print "Ignored:\n";
  foreach ($ignored as $u) {
    print "  $u\n";
  }
}

function looks_like_uib_username($uname) {
  return preg_match('/^([a-z]{3}\d{3}|st\d{5})$/', $uname);
}
