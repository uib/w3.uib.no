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
  if (in_array($variables['node']->type, array('uib_article'))) {
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
  }
  if (in_array($variables['node']->type, array('area'))) {
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
    $calendar_block = block_load('views', 'calendar-block_1');
    $variables['page']['content_bottom']['uib_area_calendar'] = _block_get_renderable_array(_block_render_blocks(array($calendar_block)));
    $exhibitions_block = block_load('views', 'calendar-block_4');
    $variables['page']['content_bottom']['uib_area_exibitions']['#prefix'] = '<div class="ex-and-news">';
    $variables['page']['content_bottom']['uib_area_exibitions'] = _block_get_renderable_array(_block_render_blocks(array($exhibitions_block)));
    $recent_news_block = block_load('views', 'recent_news-block');
    $variables['page']['content_bottom']['uib_area_newspage_recent_news'] = _block_get_renderable_array(_block_render_blocks(array($recent_news_block)));
    $variables['page']['content_bottom']['uib_area_newspage_recent_news']['#suffix'] = '</div>';
    $variables['page']['footer_top']['field_uib_link_section'] = field_view_field('node', $variables['node'], 'field_uib_link_section', array(
      'label' => 'hidden',
      'weight' => 10,
    ));
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
    $unset_vars = array(
      'field_uib_byline',
      'field_uib_kicker',
      'field_uib_lead',
      'field_uib_main_media',
      'field_uib_primary_media',
      'field_uib_primary_text',
      'field_uib_secondary_text',
      'field_uib_social_media',
    );
    foreach ($unset_vars as $var) {
      unset($variables['content'][$var]);
    }
    hide($variables['content']['field_uib_link_section']);
    hide($variables['content']['field_uib_profiled_testimonial']);
  }
}

/**
 * Function returning render array for article info
 */
function __uib_w3__article_info(&$node) {

  $author = '<span class="uib-news-byline">' . t('By') . ' <span class="uib-author">';
  $author .= __uib_w3__author($node->field_uib_byline['und'][0]['target_id']);
  $author .= '</span></span>';
  $date_info = '<span class="uib-date-info">' . t('Date') . ': ';
  $date_info .= date('d.m.Y', $node->created);
  $date_info .= ' (' . t('Last updated') . ': ' . date('d.m.Y' , $node->changed) . ')';
  $date_info .= '</span>';

  $article_info = array(
    '#type' => 'markup',
    '#markup' => '<div class="article-info">',
    '#weight' => '-40',
  );
  $article_info['#markup'] .= $author;
  $article_info['#markup'] .= $date_info;
  $article_info['#markup'] .= '</div>';
  return $article_info;
}

/**
 * Function returning markup for article author
 */
function __uib_w3__author($uid) {
  $user = user_load($uid);
  $author = $user->field_uib_first_name['und'][0]['safe_value'] . ' ' . $user->field_uib_last_name['und'][0]['safe_value'];
  return $author;
}
