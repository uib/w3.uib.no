<?php

# This script outputs SQL that should be executed against the SEBRA database
# in order to degrade user roles for those that don't use their privilege.
#
# See https://rts.uib.no/issues/15372

$limit_level3 = mktime(0, 0, 0, 10, 1, 2016);
$limit_level2 = mktime(0, 0, 0, 11, 1, 2016);

if (0) {
  # calculate relative limits
  $month = 365.25 / 12 * 24 * 60 * 60;

  $limit_level3 = time() - 3 * $month;
  $limit_level2 = time() - 2 * $month;
}

$rid_level1 = 74573517;
$rid_level2 = 170699807;
$rid_level3 = 64272948;

$result = db_query("SELECT DISTINCT name, login FROM {users} AS u JOIN users_roles AS r ON u.uid = r.uid JOIN field_data_field_uib_user_domain AS d ON u.uid = d.entity_id WHERE created < :lim AND login < :lim AND field_uib_user_domain_value = 'uib' AND rid IN ($rid_level2, $rid_level3) ORDER BY name", array(
  ':lim' => $limit_level3,
));

$delete_users = array();
foreach ($result as $user) {
  $seen[$user->name] = true;
  $delete_users[] = "'$user->name'";
}

if ($delete_users) {
  $count = count($delete_users);
  print "-- Innholdsprodusent ($count) that have not logged in since " . date("Y-m-d", $limit_level3) . "\n";
  print "DELETE FROM fd_omraade_rolle WHERE pseq IN (SELECT pseq FROM konto WHERE navn in (" . implode(', ', $delete_users) . "));\n";
}

$result = db_query("SELECT DISTINCT name, login FROM {users} AS u JOIN users_roles AS r ON u.uid = r.uid JOIN field_data_field_uib_user_domain AS d ON u.uid = d.entity_id WHERE created < :lim AND login < :lim AND field_uib_user_domain_value = 'uib' AND rid = $rid_level2 ORDER BY name", array(
  ':lim' => $limit_level2,
));

$downgrade_users = array();
foreach ($result as $user) {
  if ($seen[$user->name])
    continue;
  $downgrade_users[] = "'$user->name'";
}

if ($downgrade_users) {
  if ($delete_users)
    $count = count($downgrade_users);
    print "\n";
  print "-- Downgrade Redaktør ($count) that have not logged in since " . date("Y-m-d", $limit_level2) . "\n";
  print "UPDATE fd_omraade_rolle SET rolle = 'Innholdsprodusent' WHERE rolle = 'Redaktør' AND pseq IN (SELECT pseq FROM konto WHERE navn IN (" . implode(', ', $downgrade_users) . "));\n";

}
