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
      $path = 'node/' . $node->nid;
      $old_alias['nb'] = drupal_get_path_alias($path, 'nb');
      $old_alias['en'] = drupal_get_path_alias($path, 'en');
      $alias['nb'] = array(
        'source' => 'node/' . $node->nid,
        'alias' => str_replace('studieprogram', 'studier', $old_alias['nb']),
        'language' => 'nb',
      );
      $alias['en'] = array(
        'source' => 'node/' . $node->nid,
        'alias' => str_replace('studyprogramme', 'studies', $old_alias['en']),
        'language' => 'en',
      );
      foreach($alias as $l => $a) {
        if (!drupal_lookup_path('source', $a['alias'], $l)) {
          path_save($a);
          uibx_log('Path ' . $a['alias'] . ' saved for node ' . $node->nid);
        }
        else {
          uibx_log('Path ' . $a['alias'] . ' already exists and is not saved');
        }
        if (drupal_lookup_path('source', $old_alias[$l], $l)) {
          $redirect = new stdClass();
          $redirect->source = $old_alias[$l];
          $redirect->source_options = array();
          $redirect->redirect = $a['source'];
          $redirect->redirect_options = array();
          $redirect->status_code = 0;
          $redirect->type = 'redirect';
          $redirect->language = $l;
          redirect_hash($redirect);
          if (!$existing = redirect_load_by_hash($redirect->hash)) {
            redirect_save($redirect);
            uibx_log('Redirect for ' . $old_alias[$l] . ' saved');
          }
          else {
            uibx_log('Redirect ' . $old_alias[$l] . ' exists and is not saved');
          }
        }
      }
    }
  }
  else {
    uibx_log('I got nada...');
  }
