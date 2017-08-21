<?php
  $feature_areas = array(
    107138,
    107139,
    107143,
    107240,
    107140,
    107141,
  );
  $areas = entity_load('node', $feature_areas);
  foreach ($areas as $key => $area) {
    $area->field_uib_area_type['und'][0]['value'] = 'feature area';
    entity_save('node', $area);
    uibx_log($area->title . ' is now a feature area');
  }
