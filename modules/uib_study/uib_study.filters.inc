<?php

/**
 * Creates a filter pages for study listings
 */
function uib_study__studyprogrammes() {
  $page = array(
    'title' => uib_study__get_filter_title(),
    'list' => uib_study__get_studyprogrammes_by_cat(),
  );
  return $page;
}

function uib_study__get_filter_title() {
  $title['page_title_section'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => 'study-filter-header'),
    'children' => array(
      'title' => array(
        '#type' => 'html_tag',
        '#tag' => 'h1',
        '#value' => t('Hi! Here you can find all the studies we offer.'),
      ),
      #'link' => array(
      #  '#type' => 'html_tag',
      #  '#tag' => 'p',
      #  '#value' => t('Check out the alphbetical list of all studies.'),
      #),
    ),
  );
  return $title;
}

function uib_study__get_studyprogrammes_by_cat() {
  global $language;
  global $base_url;
  $l = $language->language;
  $output = array(
    '#type' => 'container',
    '#attributes' => array('class' => 'study-listing'),
  );
  $studyprogrammes = drupal_http_request($base_url . '/' . $l . '/uib-study-data/studieprogram');
  $studyprogrammes = drupal_json_decode($studyprogrammes->data);
  $studies_with_category = array();
  foreach($studyprogrammes['nodes'] as $sp) {
    if (!empty($sp['node']['field_uib_study_tag'])) {
      $study = $sp['node'];
      $categories = explode(',', $study['field_uib_study_tag']);
      foreach ($categories as $cat) {
        $studies_with_category[(int)$cat][t($study['field_uib_study_category'])][$study['field_uib_study_code']] = $study;
      }
    }
  }
  $study_tag_terms = taxonomy_get_tree(40);
  $study_category_order = array(
    'bachelorprogram',
    'integrertemasterpr-profesjonsst',
    'masterprogram',
    'arsstudium',
  );
  #foreach ($studies_with_category as $tid => $studycategories) {
  foreach ($study_tag_terms as $study_tag_term) {
    if (array_key_exists($study_tag_term->tid, $studies_with_category)) {
      $category = taxonomy_term_load($study_tag_term->tid);
      if (isset($category->field_uib_tax_study_category[$l])) {
        $study_tag = $category->field_uib_tax_study_category[$l][0]['safe_value'];
      }
      else {
        $study_tag = $category->name;
      }
      $output[$study_tag_term->tid] = array(
        'study_tag' => array(
          '#type' => 'html_tag',
          '#tag' => 'h2',
          '#value' => $study_tag,
          '#attributes' => array('class' => 'uib-term-' . $study_tag_term->tid),
        ),
      );
      $study_list = array();
      #foreach ($studies_with_category[$study_tag_term->tid] as $studycategory => $studies) {
      foreach ($study_category_order as $cat) {
        if (array_key_exists($cat, $studies_with_category[$study_tag_term->tid])) {
          $study_list[] = array(
            'data' => uib_study__get_category_heading($cat),
            'children' => uib_study__get_studies_in_category($studies_with_category[$study_tag_term->tid][$cat], $l),
          );
        }
      }
      $output[$study_tag_term->tid]['study_list'] = array(
        '#theme' => 'item_list',
        '#items' => $study_list,
        '#attributes' => array('class' => 'uib-term-items-' . $study_tag_term->tid),
      );
    }
  }
  return $output;
}

function uib_study__get_category_heading($cat) {
  $cats = array(
    'masterprogram' => array(
      'header' => t('Master'),
      'text' => t('2 year programme. Requires a bachelor\'s degree.'),
    ),
    'bachelorprogram' => array(
      'header' => t('Bachelor'),
      'text' => t('3 year programme. Requires secondary education.'),
    ),
    'arsstudium' => array(
      'header' => t('One-year studies'),
      'text' => t('1 year programme.'),
    ),
    'integrertemasterpr-profesjonsst' => array(
      'header' => t('Integrated Master’s degrees/Profession studies'),
      'text' => t('5-6 year programme.  Requires secondary education.'),
    ),
  );
  $output = '<h3>' . $cats[$cat]['header'] . '</h3>';
  $output .= '<p>' . $cats[$cat]['text'] . '</p>';
  return $output;
}

function uib_study__get_studies_in_category($studies, $lang) {
  global $base_url;
  $urlpart = $lang == 'nb' ? '/nb/studieprogram/' : '/en/studyprogramme/';
  $url = $base_url . $urlpart;
  $output = array();
  $sort_studies = array();
  foreach ($studies as $study) {
    $title = uib_study__clean_study_title($study['field_uib_study_title']);
    $sort_studies[$study['field_uib_study_code']] = $title;
  }
  asort($sort_studies);
  foreach ($sort_studies as $study_code => $title) {
    $output[] = l($title, $url . $study_code);
  }
  return $output;
}

function uib_study__clean_study_title($title) {
  $title_exceptions = array(
    'Kjønn, seksualitet og mangfald, årsstudium',
    'Klima, atmosfære- og havfysikk, bachelor, 3 år',
  );
  $title = explode(',', $title);
  if (in_array($title, $title_exceptions)) return $title[0] . ', ' . $title[1];
  return $title[0];
}
