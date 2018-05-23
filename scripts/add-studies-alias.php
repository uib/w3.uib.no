<?php
  $study_alias[0] = array(
    'source' => 'studies',
    'alias' => 'studier',
    'language' => 'nb',
  );
  $study_alias[1] = array(
    'source' => 'studies/alphabetical',
    'alias' => 'studier/alfabetisk',
    'language' => 'nb',
  );
  foreach ($study_alias as $sa) {
    if (!drupal_lookup_path('source', $sa['alias'], 'nb')) {
      path_save($sa);
      uibx_log('Path ' . $sa['alias'] . ' saved');
    }
    else {
      uibx_log('Path ' . $sa['alias'] . ' already exists and is not saved');
    }
  }
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_uib_study_type', 'value', array('program', 'specialization'), 'IN')
    ->addMetaData('account', user_load(1));
  $result = $query->execute();
  if(isset($result['node'])) {
    $nodes = entity_load('node', array_keys($result['node']));
    foreach($nodes as $node) {
      $study_code = $node->field_uib_study_code['und'][0]['value'];
      $alias['nb'] = array(
        'new' => array(
          'source' => 'node/' . $node->nid,
          'alias' => 'studier/' . $study_code,
          'language' => 'nb',
        ),
        'old' => 'studieprogram/' . $study_code,
      );
      $alias['en'] = array(
        'new' => array(
          'source' => 'node/' . $node->nid,
          'alias' => 'studies/' . $study_code,
          'language' => 'en',
        ),
        'old' => 'studyprogramme/' . $study_code,
      );
      foreach($alias as $l => $a) {
        if (!drupal_lookup_path('source', $a['new']['alias'], $l)) {
          path_save($a['new']);
          uibx_log('Path ' . $a['new']['alias'] . ' saved for node ' . $node->nid);
        }
        else {
          uibx_log('Path ' . $a['new']['alias'] . ' already exists and is not saved');
        }
        if (drupal_lookup_path('source', $a['old'], $l)) {
          $redirect = new stdClass();
          $redirect->source = $a['old'];
          $redirect->source_options = array();
          $redirect->redirect = $a['new']['source'];
          $redirect->redirect_options = array();
          $redirect->status_code = 0;
          $redirect->type = 'redirect';
          $redirect->language = $l;
          redirect_hash($redirect);
          if (!$existing = redirect_load_by_hash($redirect->hash)) {
            redirect_save($redirect);
            uibx_log('Redirect for ' . $a['old'] . ' saved');
          }
          else {
            uibx_log('Redirect ' . $a['old'] . ' exists and is not saved');
          }
        }
      }
    }
  }
  else {
    uibx_log('I got nada...');
  }
