<?php

/**
 * This script imports data for study programmes from fs-pres. The content is added 
 * to existing study nodes.
 */

$ou_ids = array();
$query = 'SELECT o.entity_id, o.field_uib_ou_id_value
    FROM node n, field_data_field_uib_ou_id o
    WHERE n.nid = o.entity_id AND n.type = :bnd
    ORDER BY o.field_uib_ou_id_value';
$result = db_query($query, array(':bnd' => 'uib_ou'));
foreach ($result as $row) {
  $ou_ids[$row->entity_id] = $row->field_uib_ou_id_value;
}

$study_count = 0;
foreach ($ou_ids as $nid => $oid) {
  $o1 = substr($oid, 0, 2);
  $o2 = substr($oid, 2, 2);
  $o3 = substr($oid, 4, 2);
  if ($o1 >= '19')
    continue;
  if ($o3 != '00' && $oid != '12005')
    continue;
  $fspres_oid = implode('.', array('184', (int)$o1, (int)$o2));
  if ($o3 != '00')
    $fspres_oid .= '.' . (int)$o3;
  if ($fspres_oid == '184.0.0')
    $fspres_oid = '184';
  $data = uib_study__fspres_get_json('sted/' . $fspres_oid . '/info.json');
  if(!empty($data)) {
    if (isset($data['studieprogrammer_fag'])) {
      $admin_user = &drupal_static(__FUNCTION__);
      if (!isset($admin_user)) {
        $admin_user = user_load(1);
      }
      foreach ($data['studieprogrammer_fag'] as $programme) {
        $programme_render_data['nb'] = uib_study__fspres_get_json('nn/studieprogram/' . $programme['id'] . '/render.json');
        $programme_render_data['en'] = uib_study__fspres_get_json('en/studieprogram/' . $programme['id'] . '/render.json');
        $query = new EntityFieldQuery;
        $result = $query
          ->entityCondition('entity_type', 'node')
          ->fieldCondition('field_uib_study_code', 'value', $programme['id'])
          ->addMetaData('account', $admin_user)
          ->execute();
        if (!empty($result)) {
          $nodes = node_load_multiple(array_keys($result['node']));
          foreach ($nodes as $node) {
            $study = entity_metadata_wrapper('node', $node);
            $handler = entity_translation_get_handler('node', $node, TRUE);
            $translation = array(
              'translate' => 0,
              'status' => 1,
              'language' => 'nb',
              'source' => 'en',
            );
            $handler->setTranslation($translation, $study);
            $textvalue = '';
            foreach ($programme_render_data['nb'] as $infotypegruppe) {
              $textvalue .= '<h2>' . $infotypegruppe['#title'] . '<h2>';
              foreach ($infotypegruppe['#items'] as $infotype) {
                $textvalue .= '<h3>' . $infotype['#title'] . '</h3>';
                $textvalue .= $infotype['#text'];
              }
            }
            $study->language->set('nb');
            $study->language('nb')->field_uib_study_text = array(
              'value' => $textvalue,
              'format' => 'study_text_html'
            );
            $textvalue = '';
            foreach ($programme_render_data['en'] as $infotypegruppe) {
              $textvalue .= '<h2>' . $infotypegruppe['#title'] . '<h2>';
              foreach ($infotypegruppe['#items'] as $infotype) {
                $textvalue .= '<h3>' . $infotype['#title'] . '</h3>';
                $textvalue .= $infotype['#text'];
              }
            }
            $study->language->set('en');
            $study->language('en')->field_uib_study_text = array(
              'value' => $textvalue,
              'format' => 'restricted_html'
            );
            $study->save();
            $handler->saveTranslations();
            uibx_log('Saved text for node ' . $study->getIdentifier());
            $study_count++;
          }
        }
      }
    }
  }
  elseif (is_null($data)) {
    uibx_log("Failed to fetch sted/$fspres_oid/info.json from fs-pres, aborting", "error");
    return;
  }
}
uibx_log('Study count: ' . $study_count);