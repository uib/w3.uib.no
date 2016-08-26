<?php

/**
 * Generate the it-ops HTML snippet
 */
function uib_message__it_ops_recent() {
  $ITA_NID = 77318;  // IT-deparment
  $page = array();

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type','node');
  $query->entityCondition('bundle','uib_message');
  $query->propertyCondition('status', 1);
  $query->propertyCondition('created', time() - 5*24*60*60, '>=');
  $query->fieldCondition('field_uib_message_area', 'target_id', $ITA_NID);
  $query->fieldCondition('field_uib_message_tag', 'target_id', 5391); // Drift/Operations
  $query->propertyOrderBy('created', 'DESC');

  $result = $query->execute();
  $nids = array_keys($result['node']);
  $nodes = node_load_multiple($nids);
  foreach ($nodes as $nid => $node) {
    $msg = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => 'w3-message',
      ),
    );
    $msg['date'] = array(
      '#type' => 'html_tag',
      '#tag' => 'h2',
      '#value' => date('j.n.Y', $node->created) . ' kl ' . date('H:i', $node->created),
    );
    $msg['text_no'] = array(
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#value' => check_plain($node->field_uib_message_text_nb['und'][0]['value']),
    );
    if (!empty($node->field_uib_message_link_nb)) {
      $msg['text_no']['#value'] .= '<br><a href="' . check_plain($node->field_uib_message_link_nb['und'][0]['url']) . '">Les mer...</a>';
    }
    $msg['text_en'] = array(
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#value' => check_plain($node->field_uib_message_text_en['und'][0]['value']),
    );
    if (!empty($node->field_uib_message_link_en)) {
      $msg['text_en']['#value'] .= '<br><a href="' . check_plain($node->field_uib_message_link_nb['und'][0]['url']) . '">Read more...</a>';
    }

    $page['msg'][$nid] = $msg;
  }

  if (empty($page['msg'])) {
    $page['nomsg'] = array(
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#value' => 'Ingen meldinger...',
    );
  }

  $languages = language_list();

  $page['archive'] = array(
    '#type' => 'container',
    'link' => array(
      '#markup' => '<a href="' .
        url('node/' . $ITA_NID . '/messages', array(
          'query' => array('tag' => 'Drift'),
          'language' => $languages['nb'],
        )) .
        '">Arkiv</a>',
    ),
  );

  drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');
  echo render($page);
  return;
}
