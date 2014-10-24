<?php
$usernames = array();
$tab_text = FALSE;
// fetch all roles for all areas
$all_area_roles = uib_sebra__sws_get('omraaderoller');
if (empty($all_area_roles)) {
  uibx_log('Sebra claims there are no area roles, aborting area sync', 'error');
  return;
}

$query = new EntityFieldQuery;
$query = $query
  ->entityCondition('entity_type', 'node')
  ->propertyCondition('type', 'area')
  ->fieldOrderBy('field_uib_sebra_id', 'value')
  ;
$result = $query->execute();
$areas = entity_load('node', array_keys($result['node']));
$seen_sebra_id = array();
$msgs = array();
foreach ($areas as $entity) {
  $area = entity_metadata_wrapper('node', $entity);
  $sebra_id = $area->field_uib_sebra_id->value();
  if (isset($seen_sebra_id[$sebra_id])) {
    // we can skip this one since all the fields we update are shared
    // between the translations.
    uibx_log('Skipping area "' . $area->title->value() . ' [Sebra id = ' . $sebra_id . ']', 'notice');
    continue;
  }
  $seen_sebra_id[$sebra_id] = TRUE;
  uibx_log('Checking area "' . $area->title->value() . ' [Sebra id = ' . $sebra_id . ']', 'notice');

  $area_doc = uib_sebra__sws_get("omraader?omraadekode=$sebra_id");
  if (empty($area_doc)) {
    uibx_log("Can't get area $sebra_id", 'error');
    continue;
  }

  if (isset($area_doc->omraade->visninger->uibid)) {
    foreach ((array)$area_doc->omraade->visninger->uibid as $uname) {
      // Check staff
      // Check if the user has an active account in Sebra
      if (! uib_sebra__sws_get("person?id=$uname")) {
        $msgs[] = array(
          $uname,
          __getUsersRealName($uname),
          '',
          '',
          'node/' . $area->getIdentifier(),
          $area->title->value(),
          'Staff',
          'no active account in Sebra',
        );
      }

      // Check if the user has a main account in Sebra
      if (!isset($usernames[$uname])) {
        $tmp = uib_sebra_get_main_user($uname);
        $usernames[$uname] = (string)$tmp;
      }
      $sebra_main = $usernames[$uname];
      if (empty($sebra_main)) {
        $msgs[] = array(
          $uname,
          __getUsersRealName($uname),
          '',
          '',
          'node/' . $area->getIdentifier(),
          $area->title->value(),
          'Staff',
          'no main account in Sebra',
        );
      }
      $sebra_main = (string)$sebra_main;

      // Check if this is the user's main account in Sebra
      if ($sebra_main != $uname) {
        $msgs[] = array(
          $uname,
          __getUsersRealName($uname),
          $sebra_main,
          __getUsersRealName($sebra_main),
          'node/' . $area->getIdentifier(),
          $area->title->value(),
          'Staff',
          'not main',
        );
      }
    }
  }

  // Check the same things for Content manager
  $area_roles = uib_sebra__get_area_roles($all_area_roles, $sebra_id);
  foreach ($area_roles as $uname) {
    if (! uib_sebra__sws_get("person?id=$uname")) {
      $msgs[] = array(
        $uname,
        __getUsersRealName($uname),
        '',
        '',
        'node/' . $area->getIdentifier(),
        $area->title->value(),
        'Content manager',
        'no active account in Sebra',
      );
    }
    if (!isset($usernames[$uname])) {
      $tmp = uib_sebra_get_main_user($uname);
      $usernames[$uname] = (string)$tmp;
    }
    $sebra_main = $usernames[$uname];
    if (empty($sebra_main)) {
      $msgs[] = array(
        $uname,
        __getUsersRealName($uname),
        '',
        '',
        'node/' . $area->getIdentifier(),
        $area->title->value(),
        'Content manager',
        'no main account in Sebra',
      );
    }
    if ($sebra_main != $uname) {
      $msgs[] = array(
        $uname,
        __getUsersRealName($uname),
        $sebra_main,
        __getUsersRealName($sebra_main),
        'node/' . $area->getIdentifier(),
        $area->title->value(),
        'Content manager',
        'not main',
      );
    }
  }
}

if ($msgs) {
  uibx_log(count($msgs) . ' stale users were found among area staff/content managers', 'warning');
  foreach ($msgs as $message) {
    if ($tab_text) {
      echo implode("\t", $message), PHP_EOL;
    }
    else {
      $message_text = $message[6] . ' ' . $message[7] . ': ';
      $message_text .= $message[0];
      if (!empty($message[1])) {
       $message_text .= ' (' . $message[1] . ')';
      }
      if (!empty($message[2])) {
        $message_text .= ' -> ' . $message[2] . ' (' . $message[3] . ')';
      }
      $message_text .= ' @ ' . $message[4] . ' (' . $message[5] . ')';
      uibx_log($message_text, 'warning');
    }
  }
}

function __getUsersRealName($username) {
  static $users = array();
  if (!isset($users[$username])) {
    if ($u = user_load_by_name($username)) {
      $users[$username] = $u->field_uib_first_name['und'][0]['value'] . ' ' . $u->field_uib_last_name['und'][0]['value'];
    }
  }
  return $users[$username];
}
