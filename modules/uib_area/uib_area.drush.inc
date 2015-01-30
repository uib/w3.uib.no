<?php
/**
 * @file
 * uib_area.drush.inc
 */
function uib_area_drush_command() {
  $items['uib-area-connect-ou'] = array(
    'description' => 'Traversal of areas to connect missing organisational units',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  $items['uib-area-split-menu'] = array(
    'description' => 'Splits the big area menu into separate menus for each area',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  $items['uib-area-menu-to-relation'] = array(
    'description' => 'Removes area menu levels above 2 into entity relation structure',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  $items['uib-area-menu-chk'] = array(
    'description' => 'Reads area menu trees and checks that menu link pointers are consistent',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
  $items['uib-area-area-cleanup'] = array(
    'description' => 'Remove an area and all traces',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(
      'area' => 'The node id of the area',
    ),
  );
  $items['uib-area-sync-organisation'] = array(
    'description' => 'Synchronise uib_organisation taxonomy',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );

  return $items;
}

/**
 * Update area nodes that lack OU indication
 * with a relevant parental OU.
 *
 * It is possible to set an option --dry-run
 * If dry-run is set, nodes are checked and some output is given,
 * but nothing is changed. Note that you may want to combine the
 * dry-run option with --strict=0 --verbose.
 */
function drush_uib_area_connect_ou() {
  $dry_run = FALSE;
  if (drush_get_option('dry-run')) {
    $dry_run = TRUE;
  }
  // Find area nodes that lack OU.
  // Done in two steps as EntityFieldQuery lacks NotExists in D7.

  // Find all area nodes in which OU is set.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'area')
    ->fieldCondition('field_uib_ou', 'target_id', 0, '>');
  $result = $query->execute();
  $with_ou = array();
  if ($result) {
    foreach($result['node'] as $node) {
      $with_ou[] = $node->nid;
    }
    // Get all the other area nodes, i.e. those that lack OU
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'area')
      ->entityCondition('entity_id', $with_ou, 'NOT IN');
    $result2 = $query->execute();
    if ($result2) {
      $nodes = entity_load('node', array_keys($result2['node']));
      foreach($nodes as $node) {
        if ($dry_run) {
          uibx_log("Checking OU of node $node->nid ...", 'notice');
        }
        $ou_nid = uib_area__get_ou_nid($node);
        if (!empty($ou_nid)) {
          $node->field_uib_ou['und'][]['target_id'] = $ou_nid;
          if ($dry_run) {
            uibx_log("-- would update node=$node->nid with ou=$ou_nid", 'notice');
          }
          else {
            field_attach_update('node', $node);
          }
        }
        else {
          if ($dry_run) {
            uibx_log("** found no OU for node $node->nid **", 'warning');
          }
        }
      }
    }
  }
}

/**
 * Break apart the menu called "area" into one separate menu for each area
 *
 * The new menus get machine names in the form 'menu-area-' + nid. where nid is
 * the node id for the area.
 * The menu title is set to 'area_' + url node alias.
 * The menu description uses the node title.
 *
 * Intended to be executed only once, but it will avoìd trying to create menus that already exist
 */
function drush_uib_area_split_menu() {
  // Find all area nodes
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'area');
  $result = $query->execute();
  if ($result) {
    $nodes = entity_load('node', array_keys($result['node']));
    $added_menus = array();
    foreach($nodes as $node) {
      if (uib_area_menu_is_allowed($node)) {
        if (substr($node->title, 0, 13) !== 'Area stub for') {
          $menu_machine_name = 'menu-area-' . $node->nid;
          $menu_title = 'area_' . str_replace('/', '_', drupal_get_path_alias("node/$node->nid", $node->language));
          if ($node->language == 'en') {
            // Set suffix for English menus since nb and en aliases for different nodes may be the same
            $menu_title .= '_en';
          }
          $menu_description = 'Menu for ' . $node->title;

          if (!menu_load($menu_machine_name)) {
            // Create new menu
            $menu = array(
              'menu_name' => $menu_machine_name,
              'title' => $menu_title,
              'description' => $menu_description,
              );
            menu_save($menu);
            $added_menus[] = $menu_machine_name;
            uibx_log('Created ' . $menu_machine_name . ' for "' . $node->title . '"', 'notice');

            // Get menu link id for the area
            $node_mlink = menu_link_get_preferred('node/' . $node->nid, 'area');
            if (!empty($node_mlink)) {
              // Move the first level children
              $result = db_select('menu_links', 'n')
                ->fields('n', array('mlid'))
                ->condition('plid', $node_mlink['mlid'])
                ->condition('menu_name', 'area')
                ->execute()
                ->fetchCol();
              foreach ($result as $item) {
                $child = menu_link_load($item);
                $new_child = array (
                  'link_path' => 'http:#',
                  'link_title' => $child['link_title'],
                  'menu_name' => $menu_machine_name,
                  'expanded' => 1,
                  'mlid' => $child['mlid'],
                  'weight' => $child['weight'],
                  'has_children' => $child['has_children'],
                  'hidden' => $child['hidden'],
                  );
                menu_link_save($new_child);
                $orphan_nid = intval(substr($child['link_path'], (strrpos($child['link_path'], '/') + 1)));
                if ($orphan_nid > 0) {
                  $orphan = node_load($orphan_nid);
                  if (!$orphan) {
                    uibx_log('Tried to set ' . $child['link_path'] . ' to sticky, but was unable to load node.', 'notice');
                  }
                  else {
                    $orphan->sticky = 1;
                    node_save($orphan);
                    uibx_log('Orphanized and set ' . $child['link_path'] . ' ["' . $child['link_title'] . '"] to sticky.', 'notice');
                    if ($orphan->status == 0 && $child['hidden'] == 0) {
                      uibx_log('Found an unpublished node [' . $child['link_path'] . ' "' . $child['link_title'] . '", mlid=' . $child['mlid'] . '] at first level of menu ' . $menu_machine_name, 'warning');
                    }
                  }
                }
                else {
                    uibx_log('Did not set ' . $child['link_path'] . ' to sticky: no nid where expected.', 'notice');
                }
              }
              // Then fix second level menu children for this menu
              //   they were automatically moved here when moving the first level
              //   menu children.
              $result = db_select('menu_links', 'n')
                ->fields('n', array('mlid'))
                ->condition('depth', 2)
                ->condition('menu_name', $menu_machine_name)
                ->execute()
                ->fetchCol();
              foreach ($result as $item) {
                $child = menu_link_load($item);
                $new_child = array (
                  'link_path' => $child['link_path'],
                  'link_title' => $child['link_title'],
                  'menu_name' => $menu_machine_name,
                  'expanded' => 0,
                  'mlid' => $child['mlid'],
                  'plid' => $child['plid'],
                  'weight' => $child['weight'],
                  'has_children' => $child['has_children'],
                  'hidden' => $child['hidden'],
                  );
                menu_link_save($new_child);
              }
            }
            else {
              uibx_log('Did not find preferred menu link for node/' . $node->nid, 'warning');
            }
          }
        }
        else {
          uibx_log('Skipped "' . $node->title . '"', 'warning');
        }
      }
      else {
        uibx_log('Skipped area node of type ' . $node->field_uib_area_type['und'][0]['value'] . ': "' . $node->title . '"', 'notice');
      }
    }
  }
}

/**
 * Remove all menu levels above 2 from area menus and add them into
 * an entity relation structure of articles
 */
function drush_uib_area_menu_to_relation() {
  // Find all area nodes
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'area');
  $result = $query->execute();
  if ($result) {
    $nodes = entity_load('node', array_keys($result['node']));
    foreach($nodes as $node) {
      // menu name
      $menu_machine_name = 'menu-area-' . $node->nid;
      if ($menu = menu_load($menu_machine_name)) {
        $menu_title = $menu['title'];
        $menu_tree = menu_tree_all_data($menu_machine_name);
        uib_area__unroll_menu_recursive($menu_tree);
        uibx_log('Completed relationalization of menu "' . $menu_title . '" = ' . $menu_machine_name, 'notice');
      }
    }
  }
}

function uib_area__unroll_menu_recursive($trunk, $visible = TRUE) {
  foreach ($trunk as $branch) {
    $nid = 0;
    if (!$visible || $branch['link']['hidden'] == 1) {
      $visible = FALSE;
    }
    if (url_is_external($branch['link']['link_path'])) {
      // create external content node
      if ($branch['link']['depth'] > 2 && $visible) {
        // create new uib_external_content
        $new_node = new stdClass();
        $new_node->is_new = TRUE;
        $new_node->title = $branch['link']['title'];
        $new_node->type = 'uib_external_content';
        $new_node->language = 'und';
        $new_node->field_uib_links['und'][0]['url'] = $branch['link']['link_path'];
        $new_node->field_uib_links['und'][0]['title'] = $branch['link']['title'];
        node_save($new_node);
        if (!empty($new_node->nid)) {
          $nid = $new_node->nid;
          uibx_log('Created external link node ' . $nid . ' for "' . $branch['link']['link_path'] . '" mlid=' . $branch['link']['mlid'], 'notice');
        }
        else {
          uibx_log('Unable to create external link node for "' . $branch['link']['link_path'] . '" mlid=' . $branch['link']['mlid'], 'error');
        }
      }
    }
    else {
      // get node id from url
      $nid = uib_area__extract_nid_from_path($branch['link']['link_path']);
      if (empty($nid) && $branch['link']['depth'] > 2) {
        uibx_log('Unable to extract nid from url for "' . $branch['link']['link_path'] . '" mlid=' . $branch['link']['mlid'], 'error');
      }
    }
    if (!empty($branch['below'])) {
      uib_area__unroll_menu_recursive($branch['below'], $visible);
    }
    // Add to entity relation and nuke this menu link
    if ($branch['link']['depth'] > 2) {
      // Only add the relation if the menu link was enabled and it has no disabled parents
      if ($visible) {
        $parent_menu_link = menu_link_load($branch['link']['plid']);
        $parent_nid = uib_area__extract_nid_from_path($parent_menu_link['link_path']);
        if (empty($parent_nid)) {
          uibx_log('Unable to extract parent nid from url for "' . $parent_menu_link['link_path'] . '" mlid=' . $branch['link']['mlid'], 'error');
        }
        else {
          $parent_node = node_load($parent_nid);
          $already_set = FALSE;
          if (isset($parent_node->field_uib_relation['und'][0])) {
            foreach ($parent_node->field_uib_relation['und'] as $exists) {
              if ($exists['target_id'] == $nid) {
                $already_set = TRUE;
                break;
              }
            }
          }
          if (!$already_set) {
            $parent_node->field_uib_relation['und'][]['target_id'] = $nid;
            node_save($parent_node);
            uibx_log('Added entity relation to ' . $nid . ' for [parent] node ' . $parent_nid, 'notice');
          }
        }
      }
      else {
        uibx_log('Ignored hidden link "' . $branch['link']['link_path'] . '" mlid=' . $branch['link']['mlid'], 'notice');
      }
      menu_link_delete($branch['link']['mlid']);
    }
  }
}

function uib_area__extract_nid_from_path($path) {
  $nid = 0;
  if (!empty($path)) {
    $nid = substr($path, (strpos($path, 'node/') + 5));
    $p = strpos($nid, '/');
    if ($p !== FALSE) {
      $nid = substr($nid, 0, $p);
    }
    $nid = intval($nid);
  }
  return $nid;
}

/**
 * Check (and correct) menu for inconsistencies regarding parents
 *   Inconsistencies may be found by comparing the menu tree built
 *   by menu_tree_all_data() with what is found in the menu link record.
 *
 *   The option --check-all will force check of all menus, not only the
 *   old style Area menu.
 */
function drush_uib_area_menu_chk() {
  // Try old-style area menu
  $parent_trail = array();
  $menu_tree = menu_tree_all_data('area');
  if (!empty($menu_tree)) {
    uibx_log('Checking old-style "area" menu', 'notice');
    $parent_trail = array();
    if (!uib_area__chk_menu_recursive($menu_tree, NULL, $parent_trail)) {
      return FALSE;
    }
  }
  else {
    uibx_log('Old-style "area" menu was empty', 'notice');
  }

  if (drush_get_option('check-all')) {
    // Find all area nodes
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'area');
    $result = $query->execute();
    if ($result) {
      $nodes = entity_load('node', array_keys($result['node']));
      foreach($nodes as $node) {
        // menu name
        $menu_machine_name = 'menu-area-' . $node->nid;
        if ($menu = menu_load($menu_machine_name)) {
          $menu_title = $menu['title'];
          uibx_log('Checking menu "' . $menu_title . '" = ' . $menu_machine_name, 'notice');
          $menu_tree = menu_tree_all_data($menu_machine_name);
          $parent_trail = array();
          if (!uib_area__chk_menu_recursive($menu_tree, NULL, $parent_trail)) {
            return FALSE;
          }
        }
        else {
          if (uib_area_menu_is_allowed($node) && stripos($node->title, "Area stub") === FALSE) {
            uibx_log('The area "' . $node->title . '" unexpectedly lacked menu (' . $menu_machine_name . ')', 'warning');
          }
        }
      }
    }
  }
}

function uib_area__chk_menu_recursive($trunk, $parent_mlid, &$ptrail) {
  foreach ($trunk as $branch) {
    $nid = 0;
    array_push($ptrail, $branch['link']['mlid']);
    if (url_is_external($branch['link']['link_path'])) {
      if (!empty($branch['below']) && $branch['link']['link_path'] != 'http:#') {
        uibx_log('External link "' . $branch['link']['link_path'] . '" mlid=' . $branch['link']['mlid'] . ' has children', 'notice');
      }
    }
    else {
      // get node id from url
      $nid = uib_area__extract_nid_from_path($branch['link']['link_path']);
      if (empty($nid)) {
        uibx_log('Unable to extract nid from url for "' . $branch['link']['link_path'] . '" mlid=' . $branch['link']['mlid'] . ' external=' . $branch['link']['external'], 'warning');
        return FALSE;
      }
      else {
        // Check that node exists
        if (!node_load($nid)) {
          uibx_log('Cannot load node ' . $nid . ' path="' . $branch['link']['link_path'] . '" mlid=' . $branch['link']['mlid'], 'warning');
        }
      }
    }
    // Check menu parent link consistency
    if ($parent_mlid != NULL) {
       if ($parent_mlid != $branch['link']['plid']) {
        $current = menu_link_load($branch['link']['mlid']);
        $current['plid'] = $parent_mlid;
        menu_link_save($current);
        uibx_log('Fixed menu parent mismatch [mlid=' . $branch['link']['mlid'] . ']. Found plid=' . $branch['link']['plid'] . ', was corrected to ' . $parent_mlid, 'notice');
        // amend working branch with newly save data
        $current = menu_link_load($branch['link']['mlid']);
        for ($i = 1; $i <= 9; $i++) {
          $branch['link']["p$i"] = $current["p$i"];
        }
      }
    }
    // Check parent trail
    for ($i = 0; $i < count($ptrail); $i++) {
      $j = $i + 1;
      if ($ptrail[$i] != $branch['link']["p$j"]) {
        $current = menu_link_load($branch['link']['mlid']);
        $current['plid'] = $parent_mlid;
        menu_link_save($current);
        uibx_log('Fixed menu parent trail mismatch [mlid=' . $branch['link']['mlid'] . ']. Found ' . "p$j: " . $branch['link']["p$j"] . ' when expecting ' . $ptrail[$i] , 'notice');
      }
    }
    if (!empty($branch['below'])) {
      if (!uib_area__chk_menu_recursive($branch['below'], $branch['link']['mlid'], $ptrail)) {
        return FALSE;
      }
    }
    array_pop($ptrail);
  }
  return TRUE;
}

/**
 * Cleanup when an area has been or is to be deleted, and no traces should remain.
 *
 * Removes the area node and its menu if it exists
 * Removes any menu links pointing to the area node
 * Removes any aliases pointing to the node
 * Removes any redirects pointing to the node
 * Removes nodes that were connected to the deleted area if they were owned by the area
 * Removes any connections to nodes ("bobling")
*
 * @param integer $area
 *   Node id of the area node that was deleted
 *
 * @return FALSE if anything went wrong, else TRUE.
 */
function drush_uib_area_area_cleanup($area) {
  if (empty($area) || !is_numeric($area)) {
    return FALSE;
  }
  $area = intval($area);
  $area_path = 'node/' . $area;

  node_delete($area);

  if ($area_menu = menu_load('menu-area-' . $area)) {
    uibx_log('Removing menu ' . $area_menu['menu_name']);
    menu_delete($area_menu);
  }

  while ($menu_link = menu_link_get_preferred($area_path)) {
    uibx_log('Removing menu link ' . $menu_link['title']);
    menu_link_delete($menu_link['mlid']);
  }

  path_delete(array('source' => $area_path,));

  redirect_delete_by_path($area_path);

  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->fieldCondition('field_uib_area', 'target_id', $area)
    ->execute();
  $related_nodes = entity_load('node', array_keys($result['node']));
  foreach ($related_nodes as $rnid => $rnode) {
    if ($rnode->field_uib_area['und'][0]['target_id'] == $area) {
      // Remove articles owned by the area
      uibx_log("Removing node $rnid ($rnode->title)");
      node_delete($rnid);
   }
    else {
      $nrof_areas = count($rnode->field_uib_area['und']);
      for ($i = (count($rnode->field_uib_area['und']) - 1); $i >= 0; $i--) {
        if ($rnode->field_uib_area['und'][$i]['target_id'] == $area) {
          unset($rnode->field_uib_area['und'][$i]);
        }
      }
      node_save($rnode);
      uibx_log("Disconnected node $rnid ($rnode->title) from area $area");
    }
  }
}

/**
 * Synchronise the uib_organisation taxonomy
 */
function drush_uib_area_sync_organisation() {
  $vocab_name = 'uib_organisation';
  $vocab = taxonomy_vocabulary_machine_name_load($vocab_name);
  $seen_terms = array();

  // Get all existing terms
  $existing = array();
  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', 'taxonomy_term')
    ->propertyCondition('vid', $vocab->vid)
    ->execute();
  if (!empty($result['taxonomy_term'])) {
    $existing = array_flip(array_keys($result['taxonomy_term']));
  }

  // Get data for all organisational units
  // Ordered by ou id to ensure parents will be created before children
  $query = 'SELECT n.nid, f.field_uib_ou_id_value
    FROM node n, field_data_field_uib_ou_id f
    WHERE n.status = :act AND n.type = :nty AND n.nid = f.entity_id
    ORDER BY f.field_uib_ou_id_value';
  $result = db_query($query, array(':act' => 1, ':nty' => 'uib_ou'));
  foreach ($result as $record) {
    $ou_nid = $record->nid;
    $ou_id = $record->field_uib_ou_id_value;
    $org_type = uib_area__org_type($ou_id);

    $parent_id = uib_area__inferred_ou_parent($seen_terms, $org_type, $ou_id);
    if ($parent_id === FALSE) {
      // This avoids adding any orgs lower than intitute/unit to the vocab
      continue;
    }

    // Get corresponding area and names
    $areas = uib_area__ou_area($ou_nid);
    $area_nid = NULL;
    $area_name = array();
    if ($areas) {
      foreach($areas as $area) {
        if ($area->nid == $area->tnid) {
          $area_nid = $area->nid;
        }
        $area_name[$area->language] = $area->title;
        if ($area->field_uib_area_type['und'][0]['value'] != $org_type) {
          uibx_log('Expected area type ' . $org_type . ' but found ' .
            $area->field_uib_area_type['und'][0]['value'] . " for ou $ou_nid [id $ou_id] (using)", 'notice');
          $org_type = $area->field_uib_area_type['und'][0]['value'];
        }
      }
    }
    else {
      uibx_log("No area found for ou $ou_nid [id $ou_id]. Using ou name as fallback.", 'notice');
      // Special handling of the area-less University of Bergen ou
      if ($org_type == 'university') {
        $area_name['nb'] = 'Universitetet i Bergen';
        $area_name['en'] = 'University of Bergen';
      }
      else {
        $ou = node_load($ou_nid);
        foreach ($ou->field_uib_ou_title as $lang => $outitle) {
          $area_name[$lang] = $outitle[0]['value'];
        }
      }
    }

    // create taxonomy term if it does not exist
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'taxonomy_term')
      ->propertyCondition('vid', $vocab->vid)
      ->fieldCondition('field_uib_org_ou', 'target_id', $ou_nid)
      ->execute();
    if (empty($result['taxonomy_term'])) {
      $tmp_name = (empty($area_name['nb'])) ? $area_name['en'] : $area_name['nb'];
      if ($parent_id) {
        $term = entity_create('taxonomy_term', array(
          'vid' => $vocab->vid,
          'name' => $tmp_name,
          'parent' => $seen_terms[$parent_id],
          'vocabulary_machine_name' => $vocab_name,
          )
        );
      }
      else {
        $term = entity_create('taxonomy_term', array(
          'vid' => $vocab->vid,
          'name' => $tmp_name,
          'vocabulary_machine_name' => $vocab_name,
          )
        );
      }
      if ($area_nid) {
        $term->field_uib_org_area['und'][0]['target_id'] = $area_nid;
      }
      $term->field_uib_org_ou['und'][0]['target_id'] = $ou_nid;
      $term->field_uib_org_type['und'][0]['value'] = $org_type;
      foreach ($area_name as $lang => $tname) {
        $term->field_uib_org_name[$lang][0]['value'] = $tname;
      }
      // Initiate entity translation
      $trans_handler = entity_translation_get_handler('taxonomy_term', $term);
      $translation = array(
        'status' => 1,
        'language' => 'nb',
      );
      $trans_handler->setTranslation($translation);
      $translation = array(
        'status' => 1,
        'language' => 'en',
        'source' => 'nb',
      );
      $trans_handler->setTranslation($translation);
      taxonomy_term_save($term);
      $tid = $term->tid;
      uibx_log("Created new uib_organisation term: $term->name");
    }
    else {
      $tid = current(array_keys($result['taxonomy_term']));
      $term = taxonomy_term_load($tid);
      $wrapped_term = entity_metadata_wrapper('taxonomy_term', $term);
      $edited = array();
      if ($wrapped_term->name->value() != $area_name['nb']) {
        $wrapped_term->name->set($area_name['nb']);
        $edited[] = 'term name';
      }
      $existing_area_nid = $wrapped_term->field_uib_org_area->raw();
      if (current($existing_area_nid) != $area_nid) {
        $wrapped_term->field_uib_org_area->set(array($area_nid));
        $edited[] = 'area';
      }
       if ($wrapped_term->field_uib_org_type->value() != $org_type) {
        $wrapped_term->field_uib_org_type->set($org_type);
        $edited[] = 'type';
      }
      foreach ($area_name as $lang => $tname) {
        if ($wrapped_term->language($lang)->field_uib_org_name->value() != $tname) {
          $wrapped_term->language($lang)->field_uib_org_name->set($tname);
          $edited[] = "translated name ($lang)";
        }
      }
      if ($edited) {
        $wrapped_term->save();
        uibx_log("Updated uib_organisation term $term->name: " . implode(', ', $edited));
      }
    }
    $seen_terms[$ou_id] = $tid;
    if (isset($existing[$tid])){
      unset($existing[$tid]);
    }
  }

  // Remove any surplus terms (ou may have been inactivated)
  if ($existing) {
    $existing = array_flip($existing);
    print_r($existing);
    uibx_log('Preexisting terms existed that were not treated', 'warning');

    // foreach ($existing as $tid) {
    //   taxonomy_term_delete($tid);
    // }
  }
}
