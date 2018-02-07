<?php
/**
 * @file
 * Code for the webdesk/content_managers page
 */


/**
 * Generate the status page.
 */
function uib_webdesk__content_managers_page() {
  // collect data
  $role_id = db_query("SELECT name, rid FROM {role} WHERE name LIKE 'level%' ORDER BY name")->fetchAllKeyed();
  $count_nodes = array();
  $last_node_create = array();
  foreach (db_query("SELECT uid, count(*) AS count, max(created) AS last_create FROM {node} GROUP BY uid") as $row) {
    $count_nodes[$row->uid] = $row->count;
    $last_node_create[$row->uid] = $row->last_create;
  }
  $last_node_edit = db_query("SELECT uid, max(timestamp) FROM {node_revision} GROUP BY uid")->fetchAllKeyed();

  $area_nids = array();
  foreach (db_query("SELECT DISTINCT node.tnid AS area_nid, field_uib_content_manager_target_id AS uid FROM {field_data_field_uib_content_manager} JOIN {node} ON entity_id = node.nid") as $row) {
    $area_nids[$row->uid][] = $row->area_nid;
  }

  // generate page
  $page = array();
  $page['header'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h1',
    '#value' => t('W3 Content Mangers as of @date', array('@date' => date('Y-m-d'))),
  );
  $seen_users = array();

  // generate each section
  foreach (array_merge(array_keys($role_id), array('authors')) as $level) {

    // select what users go in this section
    if ($level != 'authors') {
      $users = db_query("SELECT DISTINCT uid FROM {users_roles} WHERE rid = :rid", array(':rid' => $role_id[$level]))->fetchCol();
      $users = array_diff($users, $seen_users);
    }
    else {
      $users = array_diff(array_keys($count_nodes), $seen_users);
    }
    $seen_users = array_merge($seen_users, $users);

    $users = user_load_multiple($users);
    usort($users, function($a, $b) {
      $cmp = $b->access - $a->access;
      if ($cmp == 0) {
        $cmp = $b->created - $a->created;
      }
      return $cmp;
    });

    // wrap section in container so we can make it collapsible
    $page[$level] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('ctools-collapsible-container'),
      ),
    );
    if ($level != 'superbruker') {
      $page[$level]['#attributes']['class'][] = 'ctools-collapsed';
    }

    $page[$level]['header'] = array(
      '#type' => 'html_tag',
      '#tag' => 'h2',
      '#attributes' => array(
        'class' => array('ctools-collapsible-handle'),
      ),
      '#value' => ucfirst($level) . " (" . count($users) . " users)",
    );

    $page[$level]['content'] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array('ctools-collapsible-content'),
      ),
    );

    $page[$level]['content']['users'] = array(
      '#theme' => 'table',
      #'#caption' => 'Users',
      '#header' => array(t('name'), t('# areas'), t('# nodes'), t('last create'), t('last edit'), t('last access')),
      '#rows' => array_map(
         function($user) use ($count_nodes, $last_node_create, $last_node_edit, $area_nids) {
            return array(
              l(uib_webdesk__user_short_fullname($user) . " ($user->name)", "user/$user->uid"),
              array_key_exists($user->uid, $area_nids) ? count($area_nids[$user->uid]) : 0,
              array_key_exists($user->uid, $count_nodes) ? $count_nodes[$user->uid] : 0,
              array_key_exists($user->uid, $last_node_create) ? date('Y-m-d', $last_node_create[$user->uid]) : t('n/a'),
              array_key_exists($user->uid, $last_node_edit) ? date('Y-m-d', $last_node_edit[$user->uid]) : t('n/a'),
              $user->access ? date('Y-m-d', $user->access)  . ' (' . format_interval(time() - $user->access, 1) . ' ' . t('ago') . ')':
                              t('n/a') . " (created " . date('Y-m-d', $user->created) . ")",
            );
         }, $users
      ),
    );
  }

  // required styling
  ctools_add_js('collapsible-div');
  ctools_add_css('collapsible-div');
  drupal_add_css('
    .content h2 {
      margin-top: 2em;
    }
  ', array('type' => 'inline', 'group' => CSS_THEME));

  return $page;
}

/**
 * Returns a name for the given account that doesn't end up being too long.
 */
function uib_webdesk__user_short_fullname($user) {
  $name = array_merge(
    explode(' ', @$user->field_uib_first_name['und'][0]['value']),
    explode(' ', @$user->field_uib_last_name['und'][0]['value'])
  );
  // shorten all middle names to a single letter
  for($i = 1; $i < count($name) - 1; $i++) {
    $name[$i] = mb_substr($name[$i], 0, 1);
  }
  $fullname = implode(' ', $name);
  if (mb_strlen($fullname) > 16) {
    // shorten first name as well
    $name[0] = mb_substr($name[0], 0, 1);
    $fullname = implode(' ', $name);
  }
  if (empty($fullname)) {
    $fullname = $user->name;
  }
  return $fullname;
}
