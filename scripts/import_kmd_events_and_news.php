<?php

/*******************************************************************************
* This script imports news articles and events from kmd.uib.no. Content is added
* to the area Fakultet for kunst, musikk og design, nid 102518.
*******************************************************************************/


$url = variable_get(
  'uib_area_kmd_rest_json_api_url',
  'https://kmd.uib.no/_/service/khib/uibfeed?start=0&count=1000000'
);

$options = array(
  'headers' => array(
    'Accept' => 'application/json',
  ),
  'method' => 'GET',
);

$result = drupal_http_request($url, $options);
if ($result->code == '200') {
  $hits = json_decode($result->data);
  foreach ($hits->hits as $item) {
    $wrapper = uib__build_entity($item);
    $wrapper->save();
  }
}

function uib__build_entity($item) {
  if (!isset($item->type)) {
    return NULL;
  }
  // check if item exists
  // Sanitize
  $id = preg_replace('[^0-9a-f-]', '', $item->id);
  $result = db_query(
    "select entity_id from field_data_field_uib_kmd_data where
    field_uib_kmd_data_value like :item_id",
    array(':item_id' => "%{$id}%")
  );
  $nid = $result->fetchField();
  if ($nid == null) {
    $val = array(
      'type' => 'uib_article',
      'status' => 1,
      'language' => ($item->lang == 'no' ? 'nb' : 'en'),
    );
    $entity = entity_create('node', $val);
    $w = entity_metadata_wrapper('node', $entity);
  }
  else {
    $w = entity_metadata_wrapper('node', $nid);
  }
  if ($w == NULL) {
    return $w;
  }

  // Mandatory fields
  // Set kmd as area, nid: 102518
  $w->field_uib_area->set(array(102518));
  // $wrapper->field_uib_main_media_display->set(0);

  // Set kmd_data with link and id:
  $kmd = json_encode(array('id' => $item->id, 'href' => $item->href));
  $w->field_uib_kmd_data->set($kmd);

  foreach ($item as $key => $value) {
    switch ($key) {
      case 'title':
        $w->title->set($value);
        break;
      case 'ingress':
        $ingress = $value;
        if (isset($item->ingress2)) {
          $ingress .= ' ' . html_entity_decode(strip_tags($item->ingress2), ENT_COMPAT, 'UTF-8');
        }
        $w->field_uib_lead->set($ingress);
        break;
      case 'location':
        $w->field_uib_location->set($value);
        break;
      case 'startsAt':
        $d = new DateTime($value);
        $d->setTimeZone(new DateTimeZone('UTC'));
        $date =array(
          'value' => $d->format('Y-m-d H:i:s')
        );
        if (isset($item->endsAt)) {
          $d = new DateTime($item->endsAt);
          $d->setTimeZone(new DateTimeZone('UTC'));
          $date['value2'] = $d->format('Y-m-d H:i:s');
        }
        $w->field_uib_date->set($date);
        break;
      case 'type':
        $w->field_uib_article_type->set($value);
        if ($value == 'event') {
          $w->field_uib_event_type->set('event');
          // Promote item to front page calendar
          $w->promote->set(1);
        }
        break;
      case 'createdAt':
        $w->created->set(strtotime($value));
        break;
      case 'images':
        $dir = 'public://kmd_imported_files';
        file_prepare_directory($dir, FILE_CREATE_DIRECTORY);
        $image = system_retrieve_file(
          @$value->{'768'},
          $dir,
          TRUE,
          FILE_EXISTS_REPLACE
        );
        if (!$image) {
          continue;
        }

        $file = entity_metadata_wrapper('file', $image->fid);
        $f = $file->value();
        $f->display = 1;
        $w->field_uib_main_media->set(array((array)$f));
        break;
    }
  }
  return $w;
}
