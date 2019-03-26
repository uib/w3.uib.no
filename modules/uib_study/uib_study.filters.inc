<?php

/**
 * Creates a filter pages for study listings
 */
function uib_study__studyprogrammes() {
  $page = array(
    'title' => uib_study__get_filter_title('cat'),
    'list' => uib_study__get_studyprogrammes_by_cat(),
  );
  return $page;
}

/**
 * Creates a filter page with an alphabetical index of study programmes
 */
function uib_study__studyprogrammes__alphabetical() {
  $page = array(
    'title' => uib_study__get_filter_title('alpha'),
    'filter' => uib_study__get_filter(),
    'list' => uib_study__get_studyprogrammes_by_alpha(),
    'to-the-top' => uib_study__get_to_the_top(),
  );
  return $page;
}

function uib_study__get_filter_title($list_style) {
  global $language;
  $l = $language->language;
  $content = array(
    'alpha' => array(
      'title' => t('This is an alphabetical index of all the studies we offer.'),
      'linktext' => t('Check out the grouped index of all studies.'),
      'url' => array('nb' => 'studier', 'en' => 'studies'),
    ),
    'cat' => array(
      'title' => t('Here you can find all the studies we offer.'),
      'linktext' => t('Check out the alphabetical list of all studies.'),
      'url' => array('nb' => 'studier/alfabetisk', 'en' => 'studies/alphabetical'),
    ),
  );
  $title['page_title_section'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => 'study-filter-header'),
    'children' => array(
      'title' => array(
        '#type' => 'html_tag',
        '#tag' => 'h1',
        '#value' => $content[$list_style]['title'],
      ),
      'link' => array(
        '#type' => 'html_tag',
        '#tag' => 'p',
        '#value' => l($content[$list_style]['linktext'], $content[$list_style]['url'][$l]),
      ),
    ),
  );
  return $title;
}

function uib_study__get_filter() {
  $filter['page_fitler_section'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('study-filter-form')),
    'children' => array(
      'filter' => array(
        '#type' => 'container',
        '#attributes' => array('class' => array('study-filter-form-form')),
        'children' => array(
          'filtertitle' => array(
            '#type' => 'html_tag',
            '#tag' => 'h2',
            '#value' => t('Filter by study category'),
          ),
          'filter' => uib_study__get_form(),
        ),
      ),
    ),
  );
  return $filter;
}

function uib_study__get_form() {
  $state = array('method' => 'get');
  $form = drupal_build_form('uib_study__filter_form', $state);
  unset($form['form_build_id']);
  return $form;
}

function uib_study__filter_form() {
  $selected = uib_study__get_filter_selected();
  $form['all-categories'] = array(
    '#type' => 'checkbox',
    '#title' => t('All study categories'),
    '#default_value' => count($selected) == 0 ? 1 : 0,
    '#attributes' => array('class' => array('study-checkbox', 'study--all-categories')),
  );
  $form['group_title_1'] = array(
    '#type' => 'item',
    '#markup' => '<h3>' . t('Requires secondary education') . '</h3>',
  );
  $form['bachelorprogram'] = array(
    '#type' => 'checkbox',
    '#title' => t('Bachelor’s'),
    '#default_value' => in_array('bachelorprogram', $selected),
    '#attributes' => array('class' => array('study-checkbox', 'study--bachelorprogram')),
  );
  $form['integrertemasterpr-profesjonsst'] = array(
    '#type' => 'checkbox',
    '#title' => t('Integrated master’s/profession'),
    '#default_value' => in_array('integrertemasterpr-profesjonsst', $selected),
    '#attributes' => array('class' => array('study-checkbox', 'study--integrertemasterpr-profesjonsst')),
  );
  $form['arsstudium'] = array(
    '#type' => 'checkbox',
    '#title' => t('One-year'),
    '#default_value' => in_array('arsstudium', $selected),
    '#attributes' => array('class' => array('study-checkbox', 'study--arsstudium')),
  );
  $form['group_title_2'] = array(
    '#type' => 'item',
    '#markup' => '<h3>' . t('Requires a bachelor’s degree') . '</h3>',
  );
  $form['masterprogram'] = array(
    '#type' => 'checkbox',
    '#title' => t('Master’s'),
    '#default_value' => in_array('masterprogram', $selected),
    '#attributes' => array('class' => array('study-checkbox', 'study--masterprogram')),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Finished'),
  );
  $form['#method'] = 'post';
  global $user;
  if ($user->uid > 0) $form['#token'] = FALSE;
  return $form;
}

function uib_study__get_studyprogrammes_by_cat() {
  global $language;
  global $base_url;
  $l = $language->language;
  $output = array(
    '#type' => 'container',
    '#attributes' => array('class' => 'study-listing'),
  );
  $attilatest_urls = array(
    'https://w3-staging.test.uib.no',
    'https://w3-kurs.test.uib.no',
    'https://w3-prestaging.test.uib.no',
  );
  if (in_array($base_url, $attilatest_urls)) {
    $options['context'] = stream_context_create(array('ssl' => ['verify_peer' => FALSE, 'verify_peer_name' => FALSE]));
    $studyprogrammes = drupal_http_request($base_url . '/' . $l . '/uib-study-data/studieprogram', $options);
  }
  else {
    $studyprogrammes = drupal_http_request($base_url . '/' . $l . '/uib-study-data/studieprogram');
  }
  $studyprogrammes = drupal_json_decode($studyprogrammes->data);
  $studies_with_category = array();
  foreach($studyprogrammes['nodes'] as $sp) {
    if (!empty($sp['node']['field_uib_study_tag'])) {
      $study = $sp['node'];
      if ($study['field_uib_study_code'] == 'BAHF-MUS') $study['field_uib_study_category'] = 'bachelorprogram4';
      $categories = explode(',', $study['field_uib_study_tag']);
      foreach ($categories as $cat) {
        $studies_with_category[(int)$cat][$study['field_uib_study_category']][$study['field_uib_study_code']] = $study;
      }
    }
  }
  $study_category_order = uib_study__get_study_category_order();
  $study_tag_terms = taxonomy_get_tree(40);
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
          '#value' => '<span>' . $study_tag . '</span>',
          '#attributes' => array('class' => 'uib-term-' . $study_tag_term->tid),
        ),
      );
      $study_list = array();
      foreach ($study_category_order as $cat) {
        if (array_key_exists($cat, $studies_with_category[$study_tag_term->tid])) {
          $study_list[] = array(
            'data' => uib_study__get_category_heading($cat),
            'children' => uib_study__get_studies_in_category($studies_with_category[$study_tag_term->tid][$cat], $l),
          );
        }
      }
      $output[$study_tag_term->tid]['study_list'] = array(
        '#type' => 'container',
        'data' => array(
          '#theme' => 'item_list',
          '#items' => $study_list,
          '#attributes' => array('class' => 'uib-term-items-' . $study_tag_term->tid),
        ),
      );
    }
  }
  return $output;
}

function uib_study__get_studyprogrammes_by_alpha() {
  global $language;
  $l = $language->language;
  global $base_url;
  $studyprogrammes = drupal_http_request($base_url . '/' . $l . '/uib-study-data/studieprogram');
  $studyprogrammes = drupal_json_decode($studyprogrammes->data);
  $alpha_groups = array();
  $selected = uib_study__get_filter_selected();
  foreach ($studyprogrammes['nodes'] as $study) {
    $first_letter = substr($study['node']['field_uib_study_title'], 0, 1);
    $study_code = $study['node']['field_uib_study_code'];
    $cat = $study['node']['field_uib_study_category'];
    $title = $study['node']['field_uib_study_title'];
    $alpha_groups[$cat][$first_letter][$study['node']['path']] = uib_study__clean_study_title($title);
  }
  $output = array(
    '#type' => 'container',
    '#attributes' => array('class' => 'study-index-alpha'),
  );
  $study_category_order = uib_study__get_study_category_order();
  foreach ($study_category_order as $cat) {
    if ((count($selected) == 0 || in_array($cat, $selected)) && isset($alpha_groups[$cat])) {
      $study_list = array();
      $study_list[] = array(
        'data' => uib_study__get_category_heading($cat),
        'children' => uib_study__get_studies_in_category_alpha($alpha_groups[$cat], $l),
      );
      $output[$cat] = array(
        '#type' => 'container',
        '#attributes' => array('class' => 'study-cat--' . $cat),
        'study_list' => array(
          '#theme' => 'item_list',
          '#items' => $study_list,
        )
      );
    }
  }
  return $output;
}

function uib_study__get_category_heading($cat) {
  $cats = array(
    'masterprogram' => array(
      'header' => t('Master’s'),
      'text' => t('2 year programme. Requires a bachelor’s degree.'),
    ),
    'bachelorprogram' => array(
      'header' => t('Bachelor’s'),
      'text' => t('3 year programme. Requires secondary education.'),
    ),
    'bachelorprogram4' => array(
      'header' => t('Bachelor’s'),
      'text' => t('4 year programme. Requires secondary education.'),
    ),
    'arsstudium' => array(
      'header' => t('One-year'),
      'text' => t('1 year programme.'),
    ),
    'integrertemasterpr-profesjonsst' => array(
      'header' => t('Integrated master’s/profession'),
      'text' => t('5-6 year programme.  Requires secondary education.'),
    ),
  );
  $output = '<h3>' . $cats[$cat]['header'] . '</h3>';
  $output .= '<p>' . $cats[$cat]['text'] . '</p>';
  return $output;
}

function uib_study__get_studies_in_category($studies, $lang) {
  global $base_url;
  $urlpart = $lang == 'nb' ? '/nb/studier/' : '/en/studies/';
  $url = $base_url . $urlpart;
  $output = array();
  $sort_studies = array();
  foreach ($studies as $study) {
    $title = uib_study__clean_study_title($study['field_uib_study_title']);
    $sort_studies[$study['path']] = $title;
  }
  asort($sort_studies);
  foreach ($sort_studies as $path => $title) {
    $output[] = l($title, $base_url . $path);
  }
  return $output;
}

function uib_study__get_studies_in_category_alpha($alpha_groups, $lang) {
  global $base_url;
  ksort($alpha_groups);
  $studies = array();
  foreach($alpha_groups as $key => $ag) {
    asort($ag);
    $study_list = array();
    foreach($ag as $path => $title) {
      $study_list[] = l($title, $base_url . $path);
    }
    $studies[] = array(
      'data' => '<h4>' . $key . '</h4>',
      'children' => $study_list,
    );
  }
  return $studies;
}

function uib_study__clean_study_title($title) {
  $title_exceptions = array(
    'Kjønn, seksualitet og mangfald, årsstudium',
    'Klima, atmosfære- og havfysikk, bachelor, 3 år',
  );
  $title_array = explode(',', $title);
  if (in_array($title, $title_exceptions)) return $title_array[0] . ', ' . $title_array[1];
  return $title_array[0];
}

function uib_study__get_study_category_order() {
  return $study_category_order = array(
    'bachelorprogram',
    'bachelorprogram4',
    'integrertemasterpr-profesjonsst',
    'masterprogram',
    'arsstudium',
  );
}

function uib_study__get_filter_selected() {
  global $_POST;
  $selected = array();
  foreach(uib_study__get_study_category_order() as $choice) {
    if (key_exists($choice, $_POST)) $selected[] = $choice;
  }
  return $selected;
}

function uib_study__get_to_the_top() {
  $link_text = t('Back to top');
  $link = l($link_text, '', array(
    'attributes' => array('class' => 'uib-study--to-the-top',),
    'fragment' => 'block-system-main',
    'external' => TRUE,
  ));
  $output = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('uib-study__wrapper--to-the-top'),),
    'data' => array(
      '#type' => 'html_tag',
      '#tag' => 'p',
      '#value' => $link,
    ),
  );
  return $output;
}
