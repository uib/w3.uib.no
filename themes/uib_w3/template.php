<?php
/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
function uib_w3_preprocess_html(&$variables) {
  drupal_add_js('//use.typekit.net/yfr2tzw.js', 'external');
  drupal_add_js('try{Typekit.load();}catch(e){}', 'inline');
  if ($node = menu_get_object()) {
    if ($node->type == 'uib_article') {
      $variables['classes_array'][] = 'uib-article__' . $node->field_uib_article_type['und'][0]['value'];
    }
  }
}

/**
 * Override or insert variables into the page templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function uib_w3_preprocess_page(&$variables, $hook) {
  global $user;
  $page_menu_item = menu_get_item(current_path());
  if (!is_int(strpos($page_menu_item['path'], 'node/add/'))) {
    if ($variables['language']->language == 'nb') {
      $variables['global_menu'] = menu_navigation_links('menu-global-menu-no');
    }
    else {
      $variables['global_menu'] = menu_navigation_links('menu-global-menu');
    }
  }
  $current_area = uib_area__get_current();
  if ($current_area && !$variables['is_front']) {
    $variables['page']['subheader']['area'] = array(
      '#type' => 'html_tag',
      '#tag' => 'h2',
      '#value' => $current_area->title,
    );
  }
  $variables['page']['header']['search'] =
    __uib_w3__render_block('uib_search', 'global-searchform', -5);

  switch (true) {
    case $variables['node']->type == 'uib_article':
      $variables['page']['content_top']['kicker'] = field_view_field('node', $variables['node'], 'field_uib_kicker', array(
        'label' => 'hidden',
        'weight' => -50,
      ));
      $variables['page']['content_top']['title'] = array(
        '#type' => 'html_tag',
        '#tag' => 'h1',
        '#value' => $variables['node']->title,
        '#weight' => -45,
      );
      $article_info = __uib_w3__article_info($variables['node']);
      $variables['page']['content_top']['article_info'] = $article_info;
      $variables['page']['content_top']['field_uib_lead'] = field_view_field('node', $variables['node'], 'field_uib_lead', array(
        'label' => 'hidden',
        'weight' => -35,
      ));
      $variables['page']['content_top']['field_uib_main_media'] = field_view_field('node', $variables['node'], 'field_uib_main_media', array(
        'type' => 'file_rendered',
        'settings' => array('file_view_mode' => 'content_main'),
        'label' => 'hidden',
        'weight' => -30,
      ));
      $variables['page']['content_bottom']['field_uib_links'] = field_view_field('node', $variables['node'], 'field_uib_links', array(
        'weight' => '25',
      ));
      $variables['page']['content_bottom']['field_uib_relation'] = field_view_field('node', $variables['node'], 'field_uib_relation', array(
        'weight' => '30',
        'type' => 'entityreference_entity_view',
        'settings' => array('view_mode' => 'short_teaser'),
      ));
      $variables['page']['content_bottom']['field_uib_related_persons'] = field_view_field('node', $variables['node'], 'field_uib_related_persons' , array(
        'weight' => '27',
        'type' => 'entityreference_entity_view',
        'settings' => array('view_mode' => 'uib_user_teaser'),
      ));
      $variables['page']['content_bottom']['field_uib_files'] = field_view_field('node', $variables['node'], 'field_uib_files', array(
        'weight' => '26',
      ));
      break;

    case $variables['node']->type == 'area':
      $variables['page']['content_top']['uib_area_banner'] = field_view_field('node', $variables['node'], 'field_uib_area_banner', array(
        'label' => 'hidden',
        'weight' => -40,
      ));
      $variables['page']['content_top']['uib_area_offices'] = __uib_w3__render_block('uib_area', 'area_offices', -35);
      $variables['page']['content_top']['field_uib_primary_media'] = field_view_field('node', $variables['node'], 'field_uib_primary_media', array(
        'type' => 'file_rendered',
        'settings' => array('file_view_mode' => 'area_main'),
        'label' => 'hidden',
        'weight' => -30,
      ));
      $variables['page']['content_top']['field_uib_primary_text'] = field_view_field('node', $variables['node'], 'field_uib_primary_text', array(
        'label' => 'hidden',
        'weight' => -25,
      ));
      $variables['page']['content_top']['field_uib_secondary_text'] = field_view_field('node', $variables['node'], 'field_uib_secondary_text', array(
        'label' => 'hidden',
        'weight' => -20,
      ));
      $variables['page']['content_bottom']['uib_area_calendar'] = __uib_w3__render_block('uib_calendar3', 'calendar3', 0);
      $variables['page']['content_bottom']['uib_area_exhibitions'] = __uib_w3__render_block('uib_calendar3', 'exhibitions3', 5);
      $variables['page']['content_bottom']['uib_area_newspage_recent_news'] = __uib_w3__render_block('views', 'recent_news-block', 10);
      $variables['page']['content_bottom']['uib_area_testimonial'] = field_view_field('node', $variables['node'], 'field_uib_profiled_testimonial', array(
        'weight' => 30,
        'type' => 'entityreference_entity_view',
        'settings' => array('view_mode' => 'teaser'),
      ));
      $variables['page']['footer_top']['field_uib_link_section'] = field_view_field('node', $variables['node'], 'field_uib_link_section', array(
        'label' => 'hidden',
        'weight' => 10,
      ));
      $variables['page']['footer_top']['uib_area_jobbnorge'] = __uib_w3__render_block('uib_area','jobbnorge',20);
      $variables['page']['footer_top']['field_uib_feed'] = __uib_w3__render_block('uib_area', 'feed', 15);
      $variables['page']['footer']['uib_area_colophon'] = __uib_w3__render_block('uib_area','colophon_2',15);
      $variables['page']['footer']['social_media'] = field_view_field('node', $variables['node'], 'field_uib_social_media', array(
        'type' => 'socialmedia_formatter',
        'label' => 'hidden',
        'settings' => array('link' => TRUE),
        'weight' => '20',
      ));

      switch ($variables['node']->field_uib_area_type['und'][0]['value']) {
        case 'newspage':
          $variables['page']['content_top']['field_uib_profiled_article'] = field_view_field('node', $variables['node'], 'field_uib_profiled_article', array(
            'settings' => array('view_mode' => 'teaser'),
            'weight' => 4,
            'type' => 'entityreference_entity_view',
            'settings' => array('view_mode' => 'teaser'),
            'label' => 'hidden',
          ));
          break;
        }
      break;

    case $variables['node']->type == 'uib_study':
      $variables['page']['content_top']['field_uib_study_type'] = field_view_field('node', $variables['node'], 'field_uib_study_type', array(
        'label' => 'hidden',
        'weight' => -50,
      ), $variables['node']->language);
      $variables['page']['content_top']['title'] = array(
        '#type' => 'html_tag',
        '#tag' => 'h1',
        '#value' => $variables['node']->field_uib_study_title[$variables['node']->language][0]['safe_value'],
        '#weight' => -45,

      );
      $variables['page']['content_top']['study_facts'] = __uib_w3__render_block('uib_study', 'study_facts_2', 40);
      $variables['page']['content']['study_content'] = __uib_w3__render_block('uib_study', 'study_content', 0);
      $variables['page']['content']['study_contact'] = __uib_w3__render_block('uib_study', 'study_contact', 5);
      global $language;
      $belongs_to = uib_study__area($variables['node'], $language->language);
      $variables['page']['content']['study_belongs_to'] = array(
        '#type' => 'html_tag',
        '#tag' => 'div',
        '#value' => $belongs_to,
        '#weight' => 20,
        '#attributes' => array('class' => array('uib-study-belongs-to')),
      );
      $variables['page']['content_bottom']['study_related'] = __uib_w3__render_block('uib_study', 'study_related', 15);
      if ($variables['node']->field_uib_study_type['und'][0]['value'] == 'course') {
        $variables['page']['content']['study_toggle'] = __uib_w3__render_block('uib_study', 'study_semester_toggle', 10);
      }
      if (in_array($variables['node']->field_uib_study_type['und'][0]['value'], array('program', 'specialization'))) {
        $variables['page']['content']['study_image'] = field_view_field('node', $variables['node'], 'field_uib_study_image', array(
          'type' => 'file_rendered',
          'settings' => array('file_view_mode' => 'content_sidebar'),
          'label' => 'hidden',
          'weight' => 3,
        ));
        $variables['page']['content']['study_testimonial'] = __uib_w3__render_block('uib_study', 'study_testimonial', 10);
        $variables['page']['content_bottom']['study_plan'] = __uib_w3__render_block('uib_study', 'study_plan', 20);
        $variables['page']['content_bottom']['field_uib_link_section'] = field_view_field('node', $variables['node'], 'field_uib_link_section', array(
          'label' => 'hidden',
          'weight' => 0,
        ));
        $specializations = '';
        $view = views_get_view('uib_study_specialization');
        $view->preview('block', array($variables['node']->nid));
        if ($view->result) {
          $specializations = '<div class="block block-uib-study"><h3>' . t('Specialization') . '</h3>' . $view->render() . '</div>';
        }
        $variables['page']['content_bottom']['field_uib_study'] = array(
          '#type' => 'markup',
          '#markup' => $specializations,
          '#weight' => 30,
        );
        $variables['page']['content_bottom']['field_uib_feed'] = field_view_field('node', $variables['node'], 'field_uib_feed', array(
          'type' => 'uib_area_link_feed',
          'settings' => array('view_mode' => 'full'),
          'label' => 'hidden',
          'weight' => 40,
        ));
      }

      break;
    case (!isset($variables['node']) && $variables['theme_hook_suggestions'][0] == 'page__user'):
      $user_vcard = $variables['page']['content']['system_main']['user_vcard_link']['#markup'];
      $user_login = $variables['page']['content']['system_main']['user_login_incard_link']['#markup'];
      $variables['page']['content_top']['vcard_and_login'] = array(
        '#type' => 'html_tag',
        '#tag' => 'div',
        '#value' => $user_vcard . ' | ' . $user_login,
        '#weight' => -50,
        '#attributes' => array('class' => array('vcard-and-login')),
      );
      $variables['page']['content_top']['user_picture'] = $variables['page']['content']['system_main']['user_picture'];
      $variables['page']['content_top']['user_picture']['#weight'] = -40;
      $first_name = $variables['page']['content']['system_main']['field_uib_first_name'][0]['#markup'];
      $last_name = $variables['page']['content']['system_main']['field_uib_last_name'][0]['#markup'];
      $variables['page']['content_top']['user_name'] = array(
        '#type' => 'html_tag',
        '#tag' => 'h1',
        '#value' => $first_name . ' ' . $last_name,
        '#weight' => -30,
      );
      $variables['page']['content_top']['position'] = $variables['page']['content']['system_main']['field_uib_position'];
      $variables['page']['content_top']['position']['#weight'] = -20;
      $variables['page']['content_top']['user_ou'] = $variables['page']['content']['system_main']['field_uib_user_ou'][0]['node'][29]['field_uib_ou_title'];
      $variables['page']['content_top']['user_ou']['#weight'] = -10;
      $variables['page']['content_top']['user_homepage'] = $variables['page']['content']['system_main']['field_uib_user_url'];
      $variables['page']['content_top']['user_homepage']['#weight'] = 0;
      $variables['page']['content_top']['social_media'] = $variables['page']['content']['system_main']['field_uib_user_social_media'];
      $variables['page']['content_top']['social_media']['#weight'] = 10;
      $items = array();
      $account = $variables['page']['content']['system_main']['#account'];
      $email = '<span class="user-contact__label">' . t('E-mail') . '</span>';
      $email .= '<span class="user-contact__value"><a href="mailto:' . $account->mail . '">' . $account->mail . '</a></span>';
      $items[] = $email;
      $numbers = array();
      foreach ($account->field_uib_phone['und'] as $number) {
        $numbers[] = $number['value'];
      }
      $numbers = '<span class="phone-number">' . implode('</span><span class="phone-number">', $numbers) . '</span>';
      $phone = '<span class="user-contact__label">' . t('Phone') . '</span>';
      $phone .= '<span class="user-contact__value">' . $numbers . '</span>';
      $items[] = $phone;
      $variables['page']['content']['system_main']['visit_address']['#label_display'] = 'hidden';
      $visit_address = '<span class="user-contact__label">' . $variables['page']['content']['system_main']['visit_address']['#title'] . '</span>';
      $visit_address .= '<span class="user-contact__value">' . render($variables['page']['content']['system_main']['visit_address']);
      if (!empty($variables['page']['content']['system_main']['field_uib_user_room'])) {
        $user_room = render($variables['page']['content']['system_main']['field_uib_user_room']);
        $visit_address .= $user_room;
      }
      $visit_address .= '</span>';
      $items[] = $visit_address;
      $variables['page']['content']['system_main']['postal_address']['#label_display'] = 'hidden';
      $postal_address = '<span class="user-contact__label">' . $variables['page']['content']['system_main']['postal_address']['#title'] . '</span>';
      $postal_address .= '<span class="user-contact__value">' . render($variables['page']['content']['system_main']['postal_address']);
      $items[] = $postal_address;
      $variables['page']['content_top']['user_contact_info'] = array(
        '#theme' => 'item_list',
        '#items' => $items,
        '#weight' => 20,
        '#attributes' => array('class' => array('user-contact-info')),
      );
      $variables['page']['content']['field_uib_user_competence'] = $variables['page']['content']['system_main']['field_uib_user_competence'];
      $variables['page']['content_bottom']['user_twitter'] = __uib_w3__render_block('uib_user', 'twitter', 10);
      $variables['page']['content_bottom']['user_feed'] = __uib_w3__render_block('uib_user', 'feed', 20);

      $unset_variables = array(
        'user_vcard_link',
        'user_login_incard_link',
        'user_picture',
        'field_uib_first_name',
        'field_uib_last_name',
        'field_uib_position',
        'field_uib_user_ou',
        'field_uib_user_url',
        'field_uib_user_social_media',
        'field_uib_user_projects',
        'field_uib_user_feed',
        'field_uib_phone',
        'user_email',
        'field_uib_user_competence',
      );
      foreach ($unset_variables as $unset) {
        unset($variables['page']['content']['system_main'][$unset]);
      }
      $unset_variables = array(
        'uib_user_twitter',
        'uib_user_feed',
      );
      foreach ($unset_variables as $unset) {
        unset($variables['page']['content'][$unset]);
      }
      break;
  }
  $unset_blocks = array(
    'uib_area_paahoyden_logo',
    'uib_area_colophon',
    'uib_area_feed',
    'uib_area_newspage_recent_news',
    'uib_dbh_dbh',
    'uib_study_study_content',
    'uib_area_jobbnorge',
    'uib_area_area_parents',
    'uib_area_colophon_logos',
    'uib_study_study_related',
    'uib_study_study_facts',
    'uib_study_study_facts_2',
    'uib_study_study_contact',
    'uib_study_study_plan',
    'uib_study_study_semester_toggle',
    'uib_study_study_testimonial',
    'uib_area_area_banner',
    'uib_area_area_offices',
    'uib_calendar3_calendar3',
    'uib_user_feed',
    'uib_user_twitter',
    'uib_user_research_groups',
    'uib_calendar3_exhibitions3',
  );
  foreach ($unset_blocks as $block) {
    unset($variables['page']['header'][$block]);
  }
}

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function uib_w3_preprocess_node(&$variables, $hook) {
  global $language;
  $current_language = $language->language;
  if ($variables['page'])  {
    if ($variables['type'] == 'area') {
      $variables['content']['field_uib_profiled_article'] = field_view_field('node', $variables['node'], 'field_uib_profiled_article', array(
        'settings' => array('view_mode' => 'teaser'),
        'weight' => 4,
        'type' => 'entityreference_entity_view',
        'settings' => array('view_mode' => 'teaser'),
        'label' => 'hidden',
      ));
      if ($variables['field_uib_area_type']['und'][0]['value'] == 'newspage') {
        $variables['content']['field_uib_profiled_message'] = field_view_field('node', $variables['node'], 'field_uib_profiled_message', array(
          'settings' => array('view_mode' => 'teaser'),
          'weight' => 4,
          'type' => 'entityreference_entity_view',
          'settings' => array('view_mode' => 'teaser'),
          'label' => 'hidden',
        ));
        hide($variables['content']['field_uib_profiled_article']);
      }
    }
    $hide_vars = array(
      'field_uib_byline',
      'field_uib_kicker',
      'field_uib_lead',
      'field_uib_main_media',
      'field_uib_primary_media',
      'field_uib_primary_text',
      'field_uib_secondary_text',
      'field_uib_social_media',
      'field_uib_relation',
      'field_uib_link_section',
      'field_uib_profiled_testimonial',
      'field_uib_links',
      'field_uib_related_persons',
      'field_related_persons_label',
      'field_uib_files',
      'field_uib_study_category',
      'field_uib_study_image',
    );
    foreach ($hide_vars as $var) {
      hide($variables['content'][$var]);
    }
  }
  else {
    if ($variables['type'] == 'uib_article' && $variables['view_mode'] == 'teaser') {
      if (count($variables['field_uib_main_media']) > 1) {
        $variables['content']['field_uib_main_media'] = __uib_w3__keep_first_main_media($variables['content']['field_uib_main_media']);
      }
      $variables['theme_hook_suggestions'][] = 'node__article__teaser';
    }
    if ($variables['type'] == 'uib_article' && $variables['view_mode'] == 'short_teaser') {
      if (count($variables['field_uib_main_media']) > 1) {
        $variables['content']['field_uib_main_media'] = __uib_w3__keep_first_main_media($variables['content']['field_uib_main_media']);
      }
      $variables['theme_hook_suggestions'][] = 'node__article__short_teaser';
    }
    if ($variables['type'] == 'uib_external_content' && $variables['view_mode'] == 'teaser') {
      $variables['theme_hook_suggestions'][] = 'node__external_content__teaser';
      $variables['content']['field_uib_main_media'] = field_view_field('node', $variables['node'], 'field_uib_media', array(
        'type' => 'file_rendered',
        'settings' => array('view_mode' => 'teaser'),
        'label' => 'hidden',
        'weight' => 3,
      ));
      unset($variables['content']['field_uib_main_media'][0]['field_uib_copyright']);
      $variables['content']['field_uib_lead'] = field_view_field('node', $variables['node'], 'field_uib_teaser', array(
        'label' => 'hidden',
        'weight' => 5,
      ));
    }
    if ($variables['type'] == 'uib_external_content' && $variables['view_mode'] == 'short_teaser') {
      $variables['theme_hook_suggestions'][] = 'node__external_content__short_teaser';
    }
  }
}

/**
 * Function returning render array for article info
 */
function __uib_w3__article_info(&$node) {
  $date_info = '<span class="uib-date-info">' . t('Date') . ': ';
  $date_info .= date('d.m.Y', $node->created);
  $date_info .= ' (' . t('Last updated') . ': ' . date('d.m.Y' , $node->changed) . ')';
  $date_info .= '</span>';

  $article_info = array(
    '#type' => 'markup',
    '#markup' => '<div class="article-info">',
    '#weight' => '-40',
  );
  if (!in_array($node->field_uib_article_type['und'][0]['value'], array('infopage', 'event'))) {
    $author = __uib_w3__author($node);
    if ($author) {
      $article_info['#markup'] .= '<span class="uib-news-byline">' . t('By') . ' <span class="uib-author">';
      $article_info['#markup'] .= $author;
      $article_info['#markup'] .= '</span></span>';
    }
  }
  $article_info['#markup'] .= $date_info;
  $article_info['#markup'] .= '</div>';
  return $article_info;
}

/**
 * Function returning markup for article author
 */
function __uib_w3__author(&$node) {
  $authors = FALSE;
  if (!empty($node->field_uib_byline)) {
    $byline = field_view_field('node', $node, 'field_uib_byline', array(
      'type' => 'entityreference_label',
      'label' => 'hidden',
      'settings' => array('link' => TRUE),
    ));
    $tmp = array();
    foreach ($node->field_uib_byline['und'] as $key => $b) {
      $tmp[] = $byline[$key]['#markup'];
    }
    if ($tmp) {
      $last_author = array_pop($tmp);
      if ($tmp) {
        $authors = implode(', ', $tmp) . ' ' . t('and') . ' ' . $last_author;
      }
      else {
        $authors = $last_author;
      }
    }
  }
  return $authors;
}

/**
 * Function for creating a renderable block
 */
function __uib_w3__render_block($module, $block_id, $weight) {
  $block = block_load($module, $block_id);
  $block_content = _block_render_blocks(array($block));
  $render = _block_get_renderable_array($block_content);
  $render['#weight'] = $weight;
  return $render;
}

/**
 * Function for keeping just the first main media in article teaser mode
 */
function __uib_w3__keep_first_main_media($variables) {
  $keep = $variables[0];
  foreach($variables as $key => $value) {
    if (is_numeric($key)) unset($variables[$key]);
  }
  $variables[0] = $keep;
  return $variables;
}
