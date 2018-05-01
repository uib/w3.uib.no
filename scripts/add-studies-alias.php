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
