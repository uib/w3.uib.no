<?php
// Get all areas
$query = new EntityFieldQuery;
$result = $query
  ->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'area')
  ->propertyCondition('status', 1)
  ->execute();
foreach ($result['node'] as $area_nid => $node) {
  // Setup base area paths
  $area_path = 'node/' . $area_nid;
  $area_alias = uibx_path_load($area_path);
  $area_alias = $area_alias[0]->alias;
  $result = db_query('SELECT language FROM {node} WHERE nid = :nid', array(':nid' => $area_nid));
  foreach ($result as $record) {
    $language = $record->language;
    break;
  }
  // update area alias paths
  uib_area__create_area_aliases($area_nid, $area_alias, $language);
  uibx_log("Updated alias paths for $area_alias [nid=$area_nid, lang=$language]");
}
