<?php

# This script lists users with roles that has not logged in since the given date.
# It's used to remove their access with a manual update of the FD_OMRAADE_ROLLE
# table in SEBRA.
#
# See https://rts.uib.no/issues/15372

$limit_2016 = mktime(0, 0, 0, 1, 1, 2016);

$rid_level1 = 74573517;
$rid_level2 = 170699807;
$rid_level3 = 64272948;

$result = db_query("SELECT DISTINCT name, login FROM {users} AS u JOIN users_roles AS r ON u.uid = r.uid JOIN field_data_field_uib_user_domain AS d ON u.uid = d.entity_id WHERE login < :lim AND field_uib_user_domain_value = 'uib' AND rid IN ($rid_level1, $rid_level2, $rid_level3) ORDER BY name", array(
  ':lim' => $limit_2016,
));
foreach ($result as $user) {
  $user->login = date("Y-m-d", $user->login);
  print "'$user->name', ";
}

print "\n";
