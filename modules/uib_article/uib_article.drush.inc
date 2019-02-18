<?php
  function uib_article_drush_command() {
    $items['uib-sync-phd'] = array(
      'description' => 'Syncronise with phd-portal',
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
      'arguments' => array(),
    );
    $items['uib-add-phd-content-managers'] = array(
      'description' => 'Add content managers for testing',
      'aliases' => array('uapcm'),
      'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
      'arguments' => array(
        'arg1' => 'Area',
        'arg2' => 'Comma separated users',
      ),
    );
    return $items;
  }

  function drush_uib_article_uib_add_phd_content_managers($arg1 = NULL) {
    if ($arg1) {
      $areas = uib_article__get_phd_event_areas();
      $users = explode(',', $arg1);
      foreach($areas as $area) {
        $area = node_load($area);
        foreach($users as $uid) {
          $area->field_uib_content_manager['und'][]['target_id'] = $uid;
          $user = user_load($uid);
          if (!in_array('innholdsprodusent', $user->roles)) {
            $user->roles[] = 'innholdsprodusent';
            user_save($user);
          }
        }
        node_save($area);
      }
    }
  }

  function drush_uib_article_uib_sync_phd() {
    global $base_url;
    $byoth_url = variable_get('uib_sync_phd_url', 'https://avhandling.uib.no/api/press-releases');
    $byoth_token = variable_get('uib_sync_phd_token', FALSE);
    if (!$byoth_url || !$byoth_token) {
      die();
    }
    $imported_phds = uib_article__get_imported_phds();
    $options['headers'] = array(
      'Authorization' => 'Bearer ' . $byoth_token,
    );
    $options['context'] = stream_context_create(array(
      'ssl' => array(
        'verify_peer' => FALSE,
        'verify_peer_name' => FALSE,
        'allow_self_signed'=> TRUE,
      ),
    ));
    $press_releases = drupal_http_request($byoth_url, $options);
    if (isset($press_releases->code) && $press_releases->code != 200) {
      die('Exit with HTTP status code ' . $press_releases->code);
    }
    $press_releases = drupal_json_decode($press_releases->data);
    if (!empty($press_releases)) {
      foreach ($press_releases as $press_release) {
        uibx_log('Processing press release with ID ' . $press_release);
        if (in_array($press_release, $imported_phds)) {
          uibx_log('Press release already processed. Continue.');
          continue;
        }
        $pr = drupal_http_request($byoth_url . '/' . $press_release, $options);
        $pr = drupal_json_decode($pr->data);
        if (!empty($pr)) {
          $node = new stdClass();
          $node->title = $pr['pressRelease']['title']['nb'];
          $node->type = 'uib_article';
          node_object_prepare($node);
          $node->language = 'nb';
          $node->uid = 0;
          $node->status = 0;
          $node->field_uib_byoth_id['und'][]['value'] = $press_release;
          $node->field_uib_area['und'][]['target_id'] = 50541;
          $node->field_uib_article_type['und'][]['value'] = 'phd_press_release';
          $node->field_uib_kicker['und'][]['value'] = 'Ny doktorgrad';
          $node->field_uib_lead['und'][]['value'] = uib_article__generate_pressrelease_lead($pr);
          $candidate_description = uib_article__generate_candidate_description($pr['candidate']);
          $node->field_uib_text['und'][] = array(
            'value' => _filter_markdown($pr['pressRelease']['content']['nb'], 'basic_html') . $candidate_description,
            'format' => 'basic_html',
          );
          $node->field_uib_fact_box['und'][] = array(
            'value' => uib_article__generate_factbox($pr['defense'], $pr['trialLecture'], $pr['candidate']),
            'format' => 'restricted_html',
          );
          $node->field_uib_date['und'][] = array(
            'value' => $pr['defense']['start'],
            'value2' => $pr['defense']['end'],
          );
          if (isset($pr['candidate']['image']) && !empty($pr['candidate']['image'])) {
            $node->field_uib_media['und'][] = uib_article__get_phd_image($pr['candidate'], $press_release, $byoth_url, $options);
          }
          $node = node_submit($node);
          $defense = uib_article__generate_phd_event('defense', $pr, $node->field_uib_media);
          if ($defense) {
            $defense->field_uib_byoth_id['und'][]['value'] = $press_release;
            $defense = node_submit($defense);
            node_save($node);
            uibx_log('Phd press release with nid ' . $node->nid . ' saved!');
            $defense->field_uib_relation['und'][]['target_id'] = $node->nid;
            node_save($defense);
            uibx_log('Disputation with nid ' . $defense->nid . ' saved!');
            if (isset($pr['trialLecture']) && !empty($pr['trialLecture']['title'])) {
              $trial = uib_article__generate_phd_event('trialLecture', $pr, $node->field_uib_media);
              $trial->field_uib_byoth_id['und'][]['value'] = $press_release;
              $trial = node_submit($trial);
              $trial->field_uib_relation['und'][]['target_id'] = $node->nid;
              node_save($trial);
              uibx_log('Trial lecture with nid ' . $trial->nid . ' saved!');
            }
          }
          else {
            uibx_log('Invalid area for disputation. Abort.');
          }
        }
      }
    }
  }

  function uib_article__get_phd_image($candidate, $id, $byoth_url, $options) {
    $dir = 'public://media';
    $image_url = $byoth_url . '/' . $id . '/photo';
    $image_file = uib_article__retrieve_restricted_file($image_url, $dir, TRUE, FILE_EXISTS_RENAME, $options, $candidate['image']);
    $image = file_load($image_file->fid);
    $image->field_file_image_alt_text['und'][0] = array(
      'value' => $candidate['givenName'] . ' ' . $candidate['familyName'],
      'format' => NULL,
      'safe_value' => $candidate['givenName'] . ' ' . $candidate['familyName'],
    );
    $image->field_uib_owner['und'][0] = array(
      'value' => $candidate['image']['creatorName'],
      'format' => NULL,
      'safe_value' => $candidate['image']['creatorName'],
    );
    $image->display = '1';
    file_save($image);
    return (array)$image;
  }
  function uib_article__get_imported_phds() {
    $result = db_query('select field_uib_byoth_id_value from field_data_field_uib_byoth_id');
    $ids = $result->fetchAll();
    if (!empty($ids)) {
      $phd_ids = array();
      foreach ($ids as $id) {
        $phd_ids[] = $id->field_uib_byoth_id_value;
      }
      return $phd_ids;
    }
    else {
      return $ids;
    }
  }

  function uib_article__retrieve_restricted_file($url, $destination = NULL, $managed = TRUE, $replace = FILE_EXISTS_RENAME, $options = array(), $phd_image) {
    $parsed_url = parse_url($url);
    if (isset($phd_image['filename'])) {
      $parsed_url['path'] = $phd_image['filename'];
    }
    if (!isset($destination)) {
      $path = file_build_uri(drupal_basename($parsed_url['path']));
    }
    else {
      if (is_dir(drupal_realpath($destination))) {
        // Prevent URIs with triple slashes when glueing parts together.
        $path = str_replace('///', '//', "{$destination}/") . drupal_basename($parsed_url['path']);
      }
      else {
        $path = $destination;
      }
    }
    $result = drupal_http_request($url, $options);
    if ($result->code != 200) {
      drupal_set_message(t('HTTP error @errorcode occurred when trying to fetch @remote.', array(
        '@errorcode' => $result->code,
        '@remote' => $url,
      )), 'error');
      return FALSE;
    }
    $local = $managed ? file_save_data($result->data, $path, $replace) : file_unmanaged_save_data($result->data, $path, $replace);
    if (!$local) {
      drupal_set_message(t('@remote could not be saved to @path.', array(
        '@remote' => $url,
        '@path' => $path,
      )), 'error');
    }
    return $local;
  }

  function uib_article__get_phd_event_areas() {
    $result = db_query('select distinct field_uib_area_target_id from field_data_field_uib_area where entity_id in (select entity_id from field_data_field_uib_byoth_id where field_uib_byoth_id_value is not null)');
    $areas = array('50541',);
    $res_ids = $result->fetchAll();
    foreach($res_ids as $id) {
      $areas[] = $id->field_uib_area_target_id;
    }
    return $areas;
  }

  function uib_article__get_phd_event_area($code, $type = 'department') {
    $result = db_query('select at.entity_id from field_data_field_uib_ou as ou, field_data_field_uib_area_type as at where field_uib_ou_target_id IN (select entity_id from field_data_field_uib_ou_id where field_uib_ou_id_value = :code) and ou.entity_id = at.entity_id and at.field_uib_area_type_value in (:area_types)', array(':area_types' => array('institute', 'faculty'), ':code' => $code));
    $ids = $result->fetchAll();
    if (!empty($ids)) {
      $res_ids = array();
      foreach ($ids as $id) {
        $node = entity_load('node', array($id->entity_id));
        $node = reset($node);
        $res_ids[$node->language] = $id->entity_id;
      }
      return $res_ids['nb'];
    }
    else {
      if ($type == 'department') {
        uibx_log('No node ID found for departmentID ' . $code . ', trying facultyID.');
      }
      else {
        uibx_log('No node ID found for facultyID ' . $code);
      }
      return FALSE;
    }
  }

  function uib_article__generate_pressrelease_lead($data) {
    $lead = $data['candidate']['givenName'] . ' ' . $data['candidate']['familyName'];
    $lead .= ' disputerer ' . date('j.n.Y', strtotime($data['defense']['start']));
    $lead .= ' for ph.d.-graden ved Universitetet i Bergen med avhandlingen "' . $data['thesis']['title'] . '"';
    return $lead;
  }

  function uib_article__generate_factbox($defense, $trial, $candidate) {
    if (!empty($trial['title'])) {
      $factbox = '<h3>Prøveforelesning</h3>';
      $factbox .= '<p><span class="uib-phd-time__prefix">Tid: </span><span class="uib-phd-time__time">' . date('j.n.y G:i' ,strtotime($trial['start'])) . ' - ' . date('G:i', strtotime($trial['end'])) . '</span></p>';
      $factbox .= '<p><span class="uib-phd-place__prefix">Sted: </span><span class="uib-phd-place__place">' . $trial['location']['name'] . '</span></p>';
    }
    $factbox .= '<h3>Disputas</h3>';
    $factbox .= '<p><span class="uib-phd-time__prefix">Tid: </span><span class="uib-phd-time__time">' . date('j.n.y G:i' ,strtotime($defense['start'])) . ' - ' . date('G:i', strtotime($defense['end'])) . '</span></p>';
    $factbox .= '<p><span class="uib-phd-place__prefix">Sted: </span><span class="uib-phd-place__place">' . $defense['location']['name'] . '</span></p>';
    $factbox .= '<h3>Kontakt</h3>';
    $factbox .= '<p>' . $candidate['givenName'] . ' ' . $candidate['familyName'] . '</p>';
    $factbox .= '<p>E-post: ' . $candidate['email'] . '</p>';
    if (isset($candidate['telephone']) && !empty($candidate['telephone'])) {
      $factbox .= '<p>Telefon: ' . $candidate['telephone'] . '</p>';
    }
    return $factbox;
  }

  function uib_article__generate_phd_event($type, $data, $media) {
    $types = array(
      'defense' => array('disputation' => 'Disputas'),
      'trialLecture' => array('trial_lecture' => 'Prøveforelesning'),
    );
    $node = new stdClass();
    $node->title = $types[$type][key($types[$type])] . ' : ' . $data['candidate']['givenName'] . ' ' . $data['candidate']['familyName'];
    $node->type = 'uib_article';
    node_object_prepare($node);
    $node->language = 'nb';
    $node->uid = 0;
    $node->status = 0;
    $dep_nid = FALSE;
    $dep_id = isset($data['department']['departmentId']) ? $data['department']['departmentId'] : FALSE;
    if ($dep_id) $dep_nid = uib_article__get_phd_event_area($dep_id);
    if (!$dep_nid) {
      $fac_id = isset($data['department']['facultyId']) ? $data['department']['facultyId'] : FALSE;
      if ($fac_id) $dep_nid = uib_article__get_phd_event_area($fac_id, FALSE);
    }
    if (!empty($dep_nid)) {
      $node->field_uib_area['und'][]['target_id'] = $dep_nid;
    }
    else {
      return FALSE;
    }
    $node->field_uib_article_type['und'][]['value'] = 'event';
    $node->field_uib_event_type['und'][]['value'] = key($types[$type]);
    $node->field_uib_text['und'][] = array(
      'value' => uib_article__generate_phd_event_text($type, $data),
      'format' => 'basic_html',
    );
    $node->field_uib_date['und'][] = array(
      'value' => $data[$type]['start'],
      'value2' => $data[$type]['end'],
    );
    $node->field_uib_location['und'][]['value'] = $data[$type]['location']['name'];
    $node->field_uib_media = $media;
    return $node;
  }

  function uib_article__generate_phd_event_text($type, $data) {
    $texts = array(
      'defense' => uib_article_generate_defense_text($data),
      'trialLecture' => uib_article_generate_trial_text($data),
    );
    return $texts[$type];
  }

  function uib_article_generate_defense_text($data) {
    $text = '<h3>Avhandlingens tittel</h3><p>"' . $data['thesis']['title'] . '"</p>';
    if (isset($data['defense']['opponents'])) {
      $text .= '<h3>Opponenter:</h3><ol>';
      foreach ($data['defense']['opponents'] as $key => $o) {
        $opponent = isset($o['homepage']) ? l($o['name'], $o['homepage']) : $o['name'];
        $opponent = isset($o['affiliation']['name']) ? $opponent . ', ' . $o['affiliation']['name'] : $opponent;
        $opponent = isset($o['title']) ? $o['title'] . ' ' . $opponent : $opponent;
        $text .= '<li>' . $opponent . '</li>';
      }
      $text .= '</ol>';
    }
    if (isset($data['defense']['committeeLeader'])) {
      $cl = $data['defense']['committeeLeader'];
      $comitee_leader = isset($cl['homepage']) ? l($cl['name'], $cl['homepage']) : $cl['name'];
      $comitee_leader = isset($cl['affiliation']) ? $comitee_leader . ', ' . $cl['affiliation'] : $comitee_leader;
      $comitee_leader = isset($cl['title']) ? $cl['title'] . ' ' . $comitee_leader : $comitee_leader;
      $text .= '<h3>Leder av komiteen</h3><p>' . $comitee_leader . '</p>';
    }
    if (isset($data['defense']['masterOfCeremonies'])) {
      $moc = $data['defense']['masterOfCeremonies'];
      $master_of_ceremony = isset($moc['homepage']) ? l($moc['name'], $moc['homepage']) : $moc['name'];
      $master_of_ceremony = isset($moc['affiliation']) ? $master_of_ceremony . ', ' . $moc['affiliation'] : $master_of_ceremony;
      $master_of_ceremony = isset($moc['title']) ? $moc['title'] . ' ' . $master_of_ceremony : $master_of_ceremony;
      $text .= '<h3>Disputasleder</h3><p>' . $master_of_ceremony . '</p>';
    }
    $text .= '<p>Åpent for alle interesserte.</p>';
    return $text;
  }

  function uib_article_generate_trial_text($data) {
    $text = '<h3>Oppgitt emne</h3><p>"' . $data['trialLecture']['title'] . '"</p>';
    return $text;
  }

  function uib_article__generate_candidate_description($candidate) {
    return '<h3>Personalia</h3><p>' . $candidate['description'] . '</p>';
  }