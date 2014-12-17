<?php
/**
 * @file
 * Code for the webdesk/stats page
 */


/**
 * Generate the overview page.
 */
function uib_webdesk__stats_page() {
  $areas = array();
  $articles = array();

  # gather data
  $result = db_query("SELECT nid, language, status, title, created, changed FROM {node} WHERE type='area' ORDER BY nid");
  foreach ($result as $row) {
    $row->articles = array();
    $areas[$row->nid] = $row;
  }

  $result = db_query("SELECT nid, language, status, title, created, changed FROM {node} WHERE type='uib_article' ORDER BY nid");
  foreach ($result as $row) {
    $articles[$row->nid] = $row;
  }

  $result = db_query("SELECT * from {field_data_field_uib_article_type} WHERE bundle='uib_article' ORDER BY entity_id");
  foreach ($result as $row) {
    $articles[$row->entity_id]->type = $row->field_uib_article_type_value;
  }
  $result = db_query("SELECT * from {field_data_field_uib_event_type} WHERE bundle='uib_article' ORDER BY entity_id");
  foreach ($result as $row) {
    $articles[$row->entity_id]->type = 'event.' . $row->field_uib_event_type_value;
  }

  $result = db_query("SELECT * from {field_data_field_uib_area} WHERE bundle='uib_article' ORDER BY entity_id");
  foreach ($result as $row) {
    $area_nid = $row->field_uib_area_target_id;
    if (empty($areas[$area_nid])) {
      uibx_log("Article node/$row->entity_id references non-existing area $area_nid", 'error');
      continue;
    }
    $areas[$area_nid]->articles[$row->entity_id] = $articles[$row->entity_id];
  }

  # count stuff
  $recent_days = 14;
  $recent = time() - $recent_days*24*60*60;
  $year_ago = time() - 365*24*60*60;
  $counters = array(
    'area' => array(count($areas), 0, 0),
    'article' => array(count($articles), 0, 0),
  );
  foreach ($articles as $article) {
    if (!array_key_exists($article->type, $counters)) {
      $counters[$article->type] = array(0, 0, 0);
    }
    $counters[$article->type][0]++;
    if ($article->created > $recent) {
      $counters[$article->type][1]++;
      $counters['article'][1]++;
    }
    if ($article->created > $year_ago) {
      $counters[$article->type][2]++;
      $counters['article'][2]++;
    }
  }

  # most active
  $active = array();
  foreach ($areas as $area) {
    foreach ($area->articles as $article) {
      if ($article->changed > $recent) {
        @$active[$area->nid]++;
      }
    }
    if ($area->created > $recent) {
      $counters['area'][1]++;
    }
    if ($area->created > $year_ago) {
      $counters['area'][2]++;
    }
  }
  arsort($counters);
  arsort($active);

  # build page
  $page = array();
  $page['summary'] = array(
    '#caption' => 'Content summary',
    '#theme' => 'table',
    '#attributes' => array('class' => array('numeric')),
    '#header' => array('type', 'count', "last $recent_days days", "last year"),
    '#rows' => uib_webdesk__rows($counters),
  );
  $page['active'] = array(
    '#caption' => 'Most active recently',
    '#theme' => 'table',
    '#attributes' => array('class' => array('numeric')),
    '#header' => array('area', "last $recent_days days"),
    '#rows' => uib_webdesk__rows($active, 15, function ($row) use ($areas) {
      $row[0] = l($areas[$row[0]]->title, "node/$row[0]");
      return $row;
    }),
  );

  $last_node_rows = array();
  $result = db_query("SELECT nid, title, type, created from {node} ORDER BY created DESC LIMIT 25");
  foreach ($result as $row) {
    $last_node_rows[] = array(l(truncate_utf8($row->title, 50, TRUE, TRUE, 5), "node/$row->nid"), uib_webdesk__nice_node_type($row->type, $row->nid), format_interval((time() - $row->created) , 1) . ' ' . t('ago'));
  }
  $page['recent_nodes'] = array(
    '#caption' => t('Newest nodes'),
    '#theme' => 'table',
    '#header' => array('node', 'type', 'created'),
    '#rows' => $last_node_rows,
  );

  $page['footer'] = array(
    '#type' => 'container',
    '#attributes' => array(
      'style' => 'clear: both; margin-top: 2em; border-top: 1px dotted #bbb;',
    ),
  );

  $release = uibx_current_version();
  if ($release) {
    $page['footer']['release'] = array(
      '#markup' => '<div style="text-align: right; color: #aaa;"><a href="release-notes">' . check_plain("Release $release") . '</a></div>',
    );
  }

  drupal_add_css('
    table {
      float: left;
      margin: 1em;
    }
    table > caption {
      font-weight: bold;
      font-size: larger;
      margin-top: 2em;
    }
    tr {
    }
    th, td {
      padding: 2px 5px;
    }
    tr.even td {
      background: white;
    }
    table.numeric td:nth-child(n+2) {
      text-align: right;
    }
  ', array('type' => 'inline', 'group' => CSS_THEME));

  return $page;
}

function uib_webdesk__rows(&$array, $limit=0, $formatter=NULL) {
  foreach ($array as $key => $value) {
    if (is_array($value)) {
      array_unshift($value, $key);
    }
    else {
      $value = array($key, $value);
    }
    if ($formatter) {
      $value = $formatter($value);
    }
    $rows[] = $value;
    if ($limit > 0) {
      if (--$limit <= 0) {
        break;
      }
    }
  }
  return $rows;
}

function uib_webdesk__nice_node_type($type, $nid) {
  if (substr($type, 0, 4) == 'uib_')
    $type = substr($type, 4);
  if ($type == 'external_content')
    $type = 'external';
  if ($type == 'article') {
    $node = node_load($nid);
    $type = $node->field_uib_article_type['und'][0]['value'];
    if ($type == 'event')
      $type = $node->field_uib_event_type['und'][0]['value'];
    elseif ($type == 'phd_press_release')
      $type = 'phd';
  }
  return $type;
}
