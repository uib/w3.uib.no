<?php
// This script updates field_data_field_uib_hours_custom fields from
// the similar field field_data_field_uib_custom_hours. The field
// field_data_field_uib_custom_hours has the wrong type, and will be
// deleted in the next release. 

$sql = "select distinct n.nid from node n
  inner join field_data_field_uib_custom_hours h on (n.nid = h.entity_id)";

$list = db_query($sql)->fetchAll();
foreach ($list as $key => $value) {
  $n = node_load($value->nid);
  $n->field_uib_hours_custom = $n->field_uib_custom_hours;
  node_save($n);
}
