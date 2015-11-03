<?php

// first some cleanup
node_delete(50546);  // area stub leftover



$query = new EntityFieldQuery;
$query = $query
  ->entityCondition('entity_type', 'node')
  ->propertyCondition('type', 'area')
  ->fieldOrderBy('field_uib_sebra_id', 'value')
  ;
$result = $query->execute();

$synced_fields = array(
  "field_uib_sebra_id",
  "field_uib_ou",
  "field_uib_content_manager",
  "field_uib_staff",
  "field_uib_staff_status",
);

foreach (array_keys($result['node']) as $nid) {
  $area = node_load($nid);
  if (!$area->tnid)
    continue;
  if ($area->tnid == $nid)
    continue;
  $src_area = node_load($area->tnid);
  if (!$src_area) {
    print "Can't load $area->tnid (referenced by $area->nid)\n";
    continue;
  }

  $sebra_id = $area->field_uib_sebra_id['und'][0]['value'];

  $diff = array();
  foreach ($synced_fields as $field) {
    if ($area->$field != $src_area->$field) {
      $diff[] = $field;
    }
  }

  if (!empty($diff)) {
    print "$sebra_id: $area->tnid /node/$area->nid /node/$src_area->nid differ in " . implode(", ", $diff) . "\n";

    // try to refresh sync
    node_save($src_area);
  }
}
