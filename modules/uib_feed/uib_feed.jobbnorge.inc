<?php

/**
 * Generates the feed URL for available UiB positions at jobbnorge.
 */
function uib_feed__jobbnorge_url($jobbnorge_id=0 ,$lang=NULL) {
  $feed_url = 'https://www.jobbnorge.no/apps/joblist/joblistbuilder.ashx?id=';
  if ($jobbnorge_id == 'i') $feed_url .= '9724e7ab-ae43-4141-9f9e-d804895eeaa7';
  else $feed_url .= '821a69c9-7674-4e36-90f8-41e443b99064';
  if ($jobbnorge_id != 'i') {
    if ($jobbnorge_id) {
      $feed_url .= "&depid=$jobbnorge_id";
    }
    if (!$lang) {
      global $language;
      $lang = $language->language;
    }
    if ($lang == 'en') {
      $feed_url .= '&langid=2&trid=2';
    }
  }
  return $feed_url;
}

/**
 * Return render array presenting the jobbnorge positions in full view mode
 */
function uib_feed__jobbnorge_positions_full($jobbnorge_id=0) {
  return uib_feed__format(uib_feed__jobbnorge_url($jobbnorge_id), $title = '', $limit = 999, array('uib_feed__format_jobbnorge_pre_render'), array('uib_feed__format_jobbnorge_post_render'));
}

/**
 * Pre render formatting for jobbnorge posistions page in full view mode
 */
function uib_feed__format_jobbnorge_pre_render($element) {
  list($url, $title, $limit) = $element['#cache']['keys'];
  $content = uib_feed__get($url);
  if (!$content) {
    global $language;
    if ($language->language == 'en') {
      $external_url = 'https://www.jobbnorge.no/en/available-jobs/university-of-bergen';
    } else {
      $external_url = 'https://www.jobbnorge.no/ledige-stillinger/universitetet-i-bergen';
    }
    $elm['empty']['jobbnorge']['no_response'] = array(
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#value' => t('Open position entries cannot be retrieved at this moment. Please see the complete list at !jobbnorge_url.', array('!jobbnorge_url' => l('Jobbnorge',$external_url))),
      '#attributes' => array(
        'class' => 'uib-vacancies-no-response',
      ),
    );
    return $elm;
  }

  $content = str_replace('jn:', '', $content);  // make namespaced element regular elements
  $content = preg_replace('/\s*-\s*(?:Søknadsfrist|Deadline):\s*[\d\.]+/', '', $content);

  $xml = @simplexml_load_string($content);
  if ($xml === FALSE) {
    return $element;
  }
  if ($xml->channel->item) {
    $element['list'] = array(
      '#items' => array(),
      '#theme' => 'item_list',
      '#attributes' => array(
        'class' => 'uib-vacancies',
      ),
    );
    if ($title != '') {
      $element['list']['#title'] = $title;
    }
    foreach ($xml->channel->item as $item) {
      $place = '';
      $description = (string) $item->description;
      $item_title = $description;
      if (strpos($description, ' - ') !== FALSE) {
        $description = explode(' - ', $description);
        $place = trim(array_pop($description)) . ' - ';
        $item_title = implode(" - ",$description);
      }
      $entry = '<h2>' . l($item_title, $item->link) . '</h2>';
      $entry .= '<p>' . $place . t('Application deadline') . ': ' . $item->deadline . '</p>';

      $element['list']['#items'][] = $entry;
    }
  }
  return $element;
}

/**
 * Post render formatting for global positions page in full view mode
 */
function uib_feed__format_jobbnorge_post_render($markup) {
  $markup = str_replace(array('<h3>', '</h3>'), array('<h1>', '</h1>'), $markup);
  $markup = str_replace(array('<h2>', '</h2>'), array('<h3>', '</h3>'), $markup);
  return $markup;
}
