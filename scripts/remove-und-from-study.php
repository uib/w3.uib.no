<?php
  $query = 'SELECT pt.entity_id as nid, c.field_uib_study_code_value as code, pt.language FROM field_data_field_uib_publish_text as pt, field_data_field_uib_study_code as c WHERE c.entity_id = pt.entity_id AND field_uib_publish_text_value = 1 AND pt.entity_id IN (SELECT entity_id FROM field_data_field_uib_study_language WHERE language = :und) ORDER BY c.field_uib_study_code_value';
  $published_with_und = db_query($query, array(':und' => 'und'));
  global $base_url;
  foreach($published_with_und as $study) {
    $e = entity_load('node', array($study->nid));
    if (!isset($e[$study->nid]->field_uib_study_language[$study->language])) {
      $revisions = db_query('SELECT revision_id FROM field_data_field_uib_study_language WHERE entity_id = :nid', array(':nid' => $study->nid));
      $revision = $revisions->fetchObject();
      uibx_log('Study programme ' . $study->code . ' is published for language ' . $study->language . ', but study language does not exist in published lang.');
      $q = 'INSERT INTO field_data_field_uib_study_language VALUES (:et, :b, 0, :nid, :rev, :plang, 0, :lang)';
      db_query($q, array(
        ':et' => 'node',
        ':b' => 'uib_study',
        ':nid' => $study->nid,
        ':lang' => $e[$study->nid]->field_uib_study_language['und'][0]['value'],
        ':plang' => $study->language,
        ':rev' => $revision->revision_id,
      ));
      $url = drupal_get_path_alias('node/' . $study->nid, $study->language);
      uibx_log($base_url . '/' . $study->language . '/' . $url . ' updated');
    }
  }
  db_query('DELETE FROM field_data_field_uib_study_language WHERE language = :und', array(':und' => 'und'));
