<?php

function uib_study_drush_command() {
  $items['uib-sync-fs'] = array(
    'description' => 'Syncronise with fs-pres.app.uib.no',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
  );
  return $items;
}

function drush_uib_study_uib_sync_fs() {
  // Find out what study_codes are in use.
  $unused_codes = array();
  $study_status = array();
  $studies_all = array();
  $incomplete_refs = array();
  $query = 'SELECT n.status, c.entity_id, c.field_uib_study_code_value
    FROM node n, field_data_field_uib_study_code c
    WHERE n.nid = c.entity_id';
  $result = db_query($query);
  foreach ($result as $row) {
    $studies_all[$row->field_uib_study_code_value] = $row->entity_id;
    $study_status[$row->field_uib_study_code_value] = $row->status;
  }
  $unused_codes = $studies_all;

  // Find what Organization Units we have
  $ou_id = array();
  $query = 'SELECT o.entity_id, o.field_uib_ou_id_value
    FROM node n, field_data_field_uib_ou_id o
    WHERE n.nid = o.entity_id AND n.type = :bnd
    ORDER BY o.field_uib_ou_id_value';
  $result = db_query($query, array(':bnd' => 'uib_ou'));
  foreach ($result as $row) {
    $ou_id[$row->entity_id] = $row->field_uib_ou_id_value;
  }

  $exchange_agreement_categories = array(
    'ERASMUS',
    'BILATERAL',
    'NORDPLUS',
  );
$study_count = 0;

  // let's process these then
  foreach ($ou_id as $nid => $oid) {
    $o1 = substr($oid, 0, 2);
    $o2 = substr($oid, 2, 2);
    $o3 = substr($oid, 4, 2);
    if ($o1 >= '19') # optimize; no need to look at adm/misc places
      continue;
    if ($o3 != '00')
      continue;  # not an institute

    // look for fag belonging to this ou
    $fspres_oid = implode('.', array('184', (int)$o1, (int)$o2));
    if ($fspres_oid == '184.0.0')
      $fspres_oid = '184';
    $data = uib_study__fspres_get_json("sted/$fspres_oid/info.json");
    if (!empty($data)) {
      if (isset($data['emner_fag'])) {
        foreach ($data['emner_fag'] as $emne) {
          $study_count++;
          $missing_refs = uib_study__update_study('course', $emne, $nid, $studies_all);
          if ($missing_refs) {
            $incomplete_refs[$emne['id']] = $missing_refs;
          }
          unset($unused_codes[$emne['id']]);
        }
      }
      if (isset($data['studieprogrammer_fag'])) {
        foreach ($data['studieprogrammer_fag'] as $program) {
          $study_count++;
          $missing_refs = uib_study__update_study('program', $program, $nid, $studies_all);
          if ($missing_refs) {
            $incomplete_refs[$program['id']] = $missing_refs;
          }
          unset($unused_codes[$program['id']]);
          if (isset($program['specializations'])) {
            foreach ($program['specializations'] as $specialization) {
              unset($unused_codes[$specialization['id']]);
            }
          }
        }
      }
      if (!empty($data['utvekslingsavtaler'])) {
        foreach ($data['utvekslingsavtaler'] as $avtale) {
          if (in_array($avtale['category'], $exchange_agreement_categories) && in_array('STUDENT', $avtale['category_persons'])) {
            $study_count++;
            $missing_refs = uib_study__update_study('exchange', $avtale, $nid, $studies_all);
            if ($missing_refs) {
              $incomplete_refs[$avtale['id']] = $missing_refs;
            }
            unset($unused_codes[$avtale['id']]);
          }
        }
      }
    }
    elseif (is_null($data)) {
      uibx_log("Failed to fetch sted/$fspres_oid/info.json from fs-pres, aborting", "error");
      return;
    }
  }

  // if possible, fix any remaining incomplete program references
  if ($incomplete_refs) {
    foreach ($incomplete_refs as $study_code => $missing_refs) {
      $study_node = node_load($studies_all[$study_code]);
      $incomplete = entity_metadata_wrapper('node', $study_node);
      $delta = isset($study_node->field_uib_study_part_of['und']) ? count($study_node->field_uib_study_part_of['und']) : 0;
      $found = 0;
      foreach ($missing_refs as $missing) {
        if (!empty($studies_all[$missing])) {
          $incomplete->field_uib_study_part_of[$delta]->set($studies_all[$missing]);
          $delta++;
          $found++;
        }
        else {
          if ($study_code != 'NORUT' && substr($study_code, 0, 5) != 'INTL-') {
            uibx_log("Referenced program [from $study_code] $missing is missing", 'warning');
          }
        }
      }
      if ($found) {
        $incomplete->save();
        uibx_log("Study $study_code updated (again) to fix incomplete refs");
      }
    }
  }

  if ($study_count < 2200) {
    uibx_log("Found too few studies ($study_count) to unpublish anything", 'error');
  }
  else {
    foreach ($unused_codes as $study_code => $study_nid) {
      if ($study_status[$study_code]) {
        $unused = node_load($study_nid);
        $unused->status = 0;
        node_save($unused);
        if ($unused->field_uib_study_type['und'][0]['value'] == 'exchange') {
          uibx_log('Unpublished exchange agreement: ' . $study_code);
        }
        else {
          uibx_log('Unpublished study: ' . $study_code);
        }
      }
    }
  }
}

function uib_study__update_study($type, $study, $ou_nid, &$existing) {
  if ($type == 'course') {
    $no_path_prefix = 'emne';
    $en_path_prefix = 'course';
  }
  elseif ($type == 'program') {
    $no_path_prefix = 'studieprogram';
    $en_path_prefix = 'studyprogramme';
  }
  elseif ($type == 'exchange') {
    $no_path_prefix = 'utvekslingsavtale';
    $en_path_prefix = 'exchange-agreement';
  }

  $admin_user = &drupal_static(__FUNCTION__);
  if (!isset($admin_user)) {
    $admin_user = user_load(1);
  }

  static $uib_nus_list;
  if (!isset($uib_nus_list)) {
    $uib_nus_list = array();
    $uib_nus_vocab = taxonomy_vocabulary_machine_name_load('uib_nus');
    $query = new EntityFieldQuery;
    $tax_result = $query
      ->entityCondition('entity_type', 'taxonomy_term')
      ->propertyCondition('vid', $uib_nus_vocab->vid)
      ->execute();
    if ($tax_result) {
      $taxonomy_terms = taxonomy_term_load_multiple(array_keys($tax_result['taxonomy_term']));
      foreach($taxonomy_terms as $term) {
        $term_wrapper = entity_metadata_wrapper('taxonomy_term', $term);
        $uib_nus_list[$term_wrapper->field_uib_nus_id->value()] = $term_wrapper->getIdentifier();
      }
    }
  }

  $nusId = '';
  if (isset($study['nuskode'])) {
    $nusId_temp = str_split(substr($study['nuskode'], 1, 2));
    $nusId = $nusId_temp[0];
    if (isset($nusId_temp[1])) {
      $nusId .= '.' . $nusId_temp[1];
    }
  }

  $uib_study_labels = taxonomy_vocabulary_machine_name_load('uib_study_labels');
  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', 'taxonomy_term')
    ->propertyCondition('vid', $uib_study_labels->vid)
    ->execute();
  $labels = array();
  if (!empty($result)) {
    $ids = array_keys($result['taxonomy_term']);
    $label_terms = entity_load('taxonomy_term', $ids);
    foreach ($label_terms as $term) {
      $labels[$term->name] = $term->tid;
    }
  }

  static $uib_org_list;
  if (!isset($uib_org_list)) {
    $uib_org_vocab = taxonomy_vocabulary_machine_name_load('uib_organisation');
    $query = new EntityFieldQuery;
    $tax_result = $query
      ->entityCondition('entity_type', 'taxonomy_term')
      ->propertyCondition('vid', $uib_org_vocab->vid)
      ->execute();
    if ($tax_result) {
      $taxonomy_terms = taxonomy_term_load_multiple(array_keys($tax_result['taxonomy_term']));
      foreach($taxonomy_terms as $term) {
        $term_wrapper = entity_metadata_wrapper('taxonomy_term', $term);
        $uib_org_list[$term_wrapper->field_uib_org_ou->raw()] = $term_wrapper->getIdentifier();
      }
    }
  }

  $max_title_length = 250;
  $refs_incomplete = array();
  $studypoints_ranks = _uib_study__get_sp_ranks();

  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->fieldCondition('field_uib_study_type', 'value', $type)
    ->fieldCondition('field_uib_study_code', 'value', $study['id'])
    ->addMetaData('account', $admin_user)
    ->execute();

  if (empty($result)) {
    // Create a new one.
    $study_node = entity_create('node', array(
      'type' => 'uib_study',
      'uid' => 1,
      'status' => 1,
      'revision' => 0,
      )
    );
    $metadata = entity_metadata_wrapper('node', $study_node);
    $handler = entity_translation_get_handler('node', $study_node, TRUE);
    $translation = array(
      'translate' => 0,
      'status' => 1,
      'language' => 'en',
      'source' => 'nb',
    );
    $handler->setTranslation($translation, $study_node);

    // Node title
    if (empty($study['title_no']) && empty($study['title_en'])) {
      $metadata->title->set($study['id']);
    }
    else {
      $metadata->title->set(drupal_substr($study['title_no'] . ' / ' . $study['title_en'], 0, $max_title_length));
    }

    // Populate Norwegian version
    $metadata->language->set('nb');
    $metadata->language('nb')->field_uib_study_title->set(drupal_substr($study['title_no'], 0, $max_title_length));
    if (!$metadata->language('nb')->field_uib_study_title->value()) {
      $metadata->language('nb')->field_uib_study_title->set($study['id']);
    }
    $metadata->field_uib_study_code->set($study['id']);
    $metadata->field_uib_study_type->set($type);
    $metadata->field_uib_ou->set($ou_nid);
    if (isset($study['category'])) {
      $metadata->field_uib_study_category->set($study['category']);
    }

    // Populate English version
    $metadata->language('en')->field_uib_study_title->set(drupal_substr($study['title_en'], 0, $max_title_length));
    if (!$metadata->language('en')->field_uib_study_title->value()) {
      $metadata->language('en')->field_uib_study_title->set($study['id']);
    }

    // labels
    if (!empty($study['labels'])) {
      $new_labels = array();
      foreach ($study['labels'] as $sl) {
        if (!array_key_exists($sl, $labels)) {
          $new_term_tid = uib_study__create_taxonomy_term($sl, 'uib_study_labels');
          uibx_log('Created taxonomy_term "' . $sl . '" with tid ' . $new_term_tid);
          $labels[$new_term_tid] = $sl;
          $new_labels[] = $new_term_tid;
        }
        else {
          $new_labels[] = $labels[$sl];
        }
      }
      if (!empty($new_labels)) {
        $metadata->field_uib_study_label->set($new_labels);
      }
    }

    // program references
    if (!empty($study['ref_programs'])) {
      $delta = 0;
      foreach ($study['ref_programs'] as $ref_code) {
        if (!empty($existing[$ref_code])) {
          $metadata->field_uib_study_part_of[$delta]->set($existing[$ref_code]);
          $delta++;
        }
        else {
          $refs_incomplete[] = $ref_code;
        }
      }
    }

    // Study points rank
    if ($type == 'course') {
      $sp_rank = _uib_study__sp_rank($study['studiepoeng'], $studypoints_ranks);
      if ($sp_rank !== FALSE) {
        $metadata->field_uib_study_points_rank->set($sp_rank);
      }
    }

    // NUS code
    if (isset($uib_nus_list[$nusId])) {
      $metadata->field_uib_nus->set($uib_nus_list[$nusId]);
    }

    // Connection to uib_organisation taxonomy vocab
    if (isset($uib_org_list[$ou_nid])) {
      $metadata->field_uib_study_organisation->set($uib_org_list[$ou_nid]);
    }

    // Country references
    if (!empty($study['ref_countries'])) {
      $delta = 0;
      foreach ($study['ref_countries'] as $fs_country) {
        if ($tid = uib_geography_term($fs_country)) {
          $metadata->field_uib_study_country[$delta]->set($tid);
          $delta++;
        }
      }
    }

    $metadata->save();
    $existing[$study['id']] = $study_node->nid;

    // Define node path alias
    $path_suffix = $study['id'];
    if ($type == 'specialization') {
      $program_code = $study['ref_programs'][0];
      // If the specialization code share prefix with the study code use shorter URLs.
      // i.e. studieprogram/MAMN-INF/AG instead of studieprogram/MAMN-INF/MAMN-INFAG
      if (strlen($path_suffix) > strlen($program_code) &&
          substr($path_suffix, 0, strlen($program_code)) == $program_code)
      {
        $path_suffix = substr($path_suffix, strlen($program_code));
      }
      $path_suffix = "$program_code/$path_suffix";

      // Set up redirects from the w2 location
      foreach (array('nb', 'en') as $lang) {
        $redirect = new stdClass();
        redirect_object_prepare($redirect);
        $redirect->source = ($lang == 'nb' ? 'studieretning/' : 'programmeoption/') . $study['id'];
        $redirect->redirect = 'node/' . $metadata->nid->value();
        $redirect->language = $lang;
        redirect_save($redirect);
        uibx_log("Redirect created for $lang/" . $redirect->source . ' -> ' . $redirect->redirect);
      }
    }

    $path = array(
      'source' => 'node/' . $metadata->nid->value(),
      'alias' => "$no_path_prefix/$path_suffix",
      'language' => 'nb',
      );
    path_save($path);

    $path = array(
      'source' => 'node/' . $metadata->nid->value(),
      'alias' => "$en_path_prefix/$path_suffix",
      'language' => 'en',
      );
    path_save($path);

    uibx_log("Created $type " . $study['id']);
    return $refs_incomplete;
  }
  else {
    // Study exists
    $nodes = node_load_multiple(array_keys($result['node']));

    // handle specializations
    if (!empty($study['specializations'])) {
      foreach ($study['specializations'] as $spec) {
        $spec['nuskode'] = $study['nuskode'];
        $spec['ref_programs'] = array($study['id']);
        uib_study__update_study('specialization', $spec, $ou_nid, $existing);
      }
    }

    foreach ($nodes as $node) {
      $wrapper = entity_metadata_wrapper('node', $node);
      $edit = array();
      $severity = 'notice';

      if (isset($uib_nus_list[$nusId]) && $wrapper->field_uib_nus->raw() != $uib_nus_list[$nusId]) {
        $wrapper->field_uib_nus->set($uib_nus_list[$nusId]);
        $edit[] = 'nuscode';
      }

      // update uib_study_labels
      {
        $existing_labels = array();
        foreach ($wrapper->field_uib_study_label->getIterator() as $delta => $target) {
          $existing_labels[] = $target->raw();
        }
        $new_labels = array();
        if (isset($study['labels'])) {
          foreach ($study['labels'] as $sl) {
            if (!array_key_exists($sl, $labels)) {
              $new_term_tid = uib_study__create_taxonomy_term($sl, 'uib_study_labels');
              uibx_log('Created taxonomy_term "' . $sl . '" with tid ' . $new_term_tid);
              $labels[$new_term_tid] = $sl;
              $new_labels[] = $new_term_tid;
            }
            else {
              $new_labels[] = $labels[$sl];
            }
          }
        }
        sort($existing_labels);
        sort($new_labels);
        if ($existing_labels != $new_labels) {
          $wrapper->field_uib_study_label->set($new_labels);
          $edit[] = 'labels';
        }
      }

      if (!empty($study['unpublished'])) {
        // ensure unpublished
        if ($wrapper->status->value() != 0) {
          $wrapper->status->set(0);
          $edit[] = "status=0";
        }
      }
      else {
        // ensure published
        if ($wrapper->status->value() == 0) {
          $wrapper->status->set(1);
          $edit[] = "status=1";
        }
      }

      if (empty($study['title_no']) && empty($study['title_en'])) {
        $title = $study['id'];
      }
      else {
        $title = drupal_substr($study['title_no'] . ' / ' . $study['title_en'], 0, $max_title_length);
      }
      if ($wrapper->title->value() != $title) {
        $wrapper->title->set($title);
        $edit[] = 'node title';
      }

      if ($wrapper->language('nb')->field_uib_study_title->value() != drupal_substr($study['title_no'], 0, $max_title_length)) {
        $wrapper->language('nb')->field_uib_study_title->set(drupal_substr($study['title_no'], 0, $max_title_length));
        $edit[] = 'no title';
      }
      if ($wrapper->language('en')->field_uib_study_title->value() != drupal_substr($study['title_en'], 0, $max_title_length)) {
        $wrapper->language('en')->field_uib_study_title->set(drupal_substr($study['title_en'], 0, $max_title_length));
        $edit[] = 'en title';
      }

      if ($wrapper->field_uib_ou->raw() != $ou_nid) {
        $wrapper->field_uib_ou->set($ou_nid);
        $edit[] = 'ou';
      }

      if (isset($uib_org_list[$ou_nid])) {
        if ($wrapper->field_uib_study_organisation->raw() != $uib_org_list[$ou_nid]) {
          $wrapper->field_uib_study_organisation->set($uib_org_list[$ou_nid]);
          $edit[] = 'org';
        }
      }

      if (isset($study['category'])) {
        if ($wrapper->field_uib_study_category->value() != $study['category']) {
          $wrapper->field_uib_study_category->set($study['category']);
          $edit[] = 'category';
        }
      }
      elseif (!is_null($wrapper->field_uib_study_category->value())) {
        $wrapper->field_uib_study_category->set(NULL);
        $edit[] = 'removed category';
      }

      // Check if any change in referenced programs
      $prev_refs = array();
      foreach ($wrapper->field_uib_study_part_of->getIterator() as $delta => $term) {
        $prev_refs[] = $term->raw();
      }
      $new_refs = array();
      if (!empty($study['ref_programs'])) {
        foreach ($study['ref_programs'] as $ref_code) {
          if (!empty($existing[$ref_code])) {
            $new_refs[] = $existing[$ref_code];
          }
        }
      }
      sort($prev_refs);
      sort($new_refs);
      if ($prev_refs != $new_refs) {
        $wrapper->field_uib_study_part_of = array();
        $delta = 0;
        foreach ($study['ref_programs'] as $ref_code) {
          if (!empty($existing[$ref_code])) {
            $wrapper->field_uib_study_part_of[$delta]->set($existing[$ref_code]);
            $delta++;
          }
          else {
            $refs_incomplete[] = $ref_code;
          }
        }
        $edit[] = 'part_of';
      }

      // Country references changes
      $prev_refs = array();
      foreach ($wrapper->field_uib_study_country->getIterator() as $delta => $term) {
        $prev_refs[] = $term->raw();
      }
      $new_refs = array();
      if (!empty($study['ref_countries'])) {
        foreach ($study['ref_countries'] as $ref_code) {
          $new_refs[] = uib_geography_term($ref_code);
        }
      }
      sort($prev_refs);
      sort($new_refs);
      if ($prev_refs != $new_refs) {
        $prev_max = count($prev_refs) - 1;
        $delta = 0;
        foreach ($new_refs as $ref_tid) {
          $wrapper->field_uib_study_country[$delta]->set($ref_tid);
          $delta++;
        }
        while ($prev_max >= $delta) {
          $wrapper->field_uib_study_country[$delta]->set(NULL);
          $delta++;
        }
        $edit[] = 'countries';
      }

      // Study point rank
      if ($type == 'course') {
        $sp_rank = _uib_study__sp_rank($study['studiepoeng'], $studypoints_ranks);
        if ($sp_rank === FALSE) {
          $wrapper->field_uib_study_points_rank->set('');
          $edit[] = 'study points rank [empty]';
          $severity = 'warning';
        }
        elseif ($wrapper->field_uib_study_points_rank->value() != $sp_rank) {
          $wrapper->field_uib_study_points_rank->set($sp_rank);
          $edit[] = 'study points rank';
        }
      }

      if ($edit) {
        $wrapper->save();
        uibx_log(ucfirst($type) . ' ' . $study['id'] . " updated " . implode(', ', $edit), $severity);
      }
    }
  }
  return $refs_incomplete;
}

/**
 * Get study point ranks from field info
 */
function _uib_study__get_sp_ranks() {
  static $ranks;
  if (!isset($ranks)) {
    $ranks = array();
    $field_info = field_info_field('field_uib_study_points_rank');
    $allowed_values = $field_info['settings']['allowed_values'];
    $unreasonably_high_number = 1000;

    foreach ($allowed_values as $key => $range) {
      if (strpos($range, '–') !== FALSE) {
        // range
        $tmp = explode('–', $range);
        $ranks[$key] = array(
          'low' => trim($tmp[0]),
          'high' => trim($tmp[1]),
          );
        if (empty($ranks[$key]['high'])) {
          // unexpected open ended range
          $ranks[$key]['high'] = $unreasonably_high_number;
        }
      }
      elseif (strpos($range, '+') !== FALSE) {
        // open ended range
        $ranks[$key] = array(
          'low' => rtrim($range, '+'),
          'high' => $unreasonably_high_number,
          );
      }
      else {
        // single value
        $ranks[$key] = array(
          'low' => trim($range),
          'high' => trim($range),
          );
      }
    }
  }
  return $ranks;
}

/**
 * Determine to which study point rank a study point instance belongs
 */
function _uib_study__sp_rank($study_points, $list) {
  foreach ($list as $rank => $range) {
    if ($study_points >= $range['low'] && $study_points <= $range['high']) {
      return $rank;
    }
  }
  return FALSE;
}

function uib_study__create_taxonomy_term($term_name, $vocabular_machine_name) {
  $vocabular = taxonomy_vocabulary_machine_name_load($vocabular_machine_name);
  $term = new stdClass();
  $term->name = $term_name;
  $term->vid = $vocabular->vid;
  taxonomy_term_save($term);
  return $term->tid;
}
