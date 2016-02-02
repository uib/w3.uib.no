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
    if ($node->type == 'area' && $node->field_uib_area_type['und'][0]['value'] == 'frontpage') {
      $variables['classes_array'][] = 'banner-image';
    }
    if ($node->type == 'uib_study') {
      $variables['classes_array'][] = 'uib-study__' . $node->field_uib_study_type['und'][0]['value'];
      if ($node->field_uib_study_type['und'][0]['value'] != 'course') {
        $variables['classes_array'][] = 'study-tabs';
      }
    }
  }
  if ($current_area = uib_area__get_current()) {
    if ($current_area->field_uib_menu_style['und'][0]['value'] == 'expanded') {
      $variables['classes_array'][] = 'uib-area-expanded-menu';
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
  drupal_add_js('sites/all/themes/uib/uib_w3/js/mobile_menu.js');
  drupal_add_js(drupal_get_path('theme', 'uib_w3') . '/js/survey.js',
    array('group' => JS_THEME,)
  );
  $page_menu_item = menu_get_item(current_path());
  if (!is_int(strpos($page_menu_item['path'], 'node/add/'))) {
    $global_menu_lang = $variables['language']->language == 'nb' ? '-no' : '';
    $global_menu = __uib_w3__get_renderable_menu('menu-global-menu' . $global_menu_lang . '-2');
    $variables['page']['header']['global_menu'] = $global_menu;
    $variables['page']['header']['global_menu']['#prefix'] = '<nav class="global-menu">';
    $variables['page']['header']['global_menu']['#suffix'] = '</nav>';
    $variables['page']['header']['global_menu']['#weight'] = -10;
  }

  $current_area = uib_area__get_current();
  $frontpage = $current_area && $current_area->field_uib_area_type['und'][0]['value'] == 'frontpage' ? true : false;
  if ($area_menu_name = uib_area__get_current_menu()) {
    $area_menu = __uib_w3__get_renderable_menu($area_menu_name);
    if (!$frontpage) {
      $variables['area_menu'] = $area_menu;
    }
    $variables['area_menu_footer'] = $area_menu;
  }
  if (!is_int(strpos($page_menu_item['path'], 'node/add/'))) {
    if ($area_menu_name = uib_area__get_current_menu()) {
      $variables['mobile']['area_menu'] = __uib_w3__get_renderable_menu($area_menu_name);
      $variables['mobile']['area_menu']['#prefix'] = '<nav class="area-mobile-menu">';
      $variables['mobile']['area_menu']['#suffix'] = '</nav>';
      $variables['mobile']['area_menu']['#weight'] = -15;
    }
    if ($variables['language']->language == 'nb') {
      $variables['mobile']['global_mobile_menu'] = __uib_w3__get_renderable_menu('menu-global-menu-no-2');
    }
    else {
      $variables['mobile']['global_mobile_menu'] = __uib_w3__get_renderable_menu('menu-global-menu-2');
    }
    $variables['mobile']['global_mobile_menu']['#prefix'] = '<nav class="global-mobile-menu">';
    $variables['mobile']['global_mobile_menu']['#suffix'] = '</nav>';
    $variables['mobile']['global_mobile_menu']['#weight'] = 5;
    $variables['mobile']['language'] = __uib_w3__render_block('locale','language',10);
    $variables['mobile']['#prefix'] = '<nav class="mobile">';
    $variables['mobile']['#suffix'] = '</nav>';
    $variables['mobile']['#weight'] = 0;
  }
  if ($current_area && !$variables['is_front']) {
    global $base_path;
    $variables['page']['subheader']['area'] = array(
      '#type' => 'link',
      '#prefix' => '<h2>',
      '#suffix' => '</h2>',
      '#title' => $current_area->title,
      '#href' => $base_path . drupal_get_path_alias("node/{$current_area->nid}",
        $variables['language']->language ),
    );
  }
  $variables['page']['header']['search'] =
    __uib_w3__render_block('uib_search', 'global-searchform', -5);
  $variables['page']['footer']['uib_area_colophon'] = __uib_w3__render_block('uib_area','colophon_2',15);
  drupal_add_js('sites/all/themes/uib/uib_w3/js/w3.js');

  $affected_suggestions = array('page__node__edit', 'page__node__translate', 'page__node__menu', 'page__node__revisions');
  $do = FALSE;
  foreach ($affected_suggestions as $s) {
    if(in_array($s, $variables['theme_hook_suggestions'])) $do = TRUE;
  }
  if($do) {
    unset($variables['node']);
    unset($variables['page']['subheader']);
    unset($variables['page']['header']);
    unset($variables['logo']);
    unset($variables['site_name']);
  }
  $variables['page']['footer_bottom']['bottom_links'] = __uib_w3__render_block('uib_area', 'bottom_links', 100);

  if(!empty($current_area->field_uib_area_banner)){
    $variables['page']['content_top']['uib_area_banner'] = field_view_field('node', $current_area, 'field_uib_area_banner', array(
      'label' => 'hidden',
      'weight' => -240,
    ));
  }

  switch (true) {
    case @$variables['page']['content']['system_main']['nodes']['87343']:
      if (isset($variables['page']['content']['system_main']['nodes'][87343]['uib_views_block']['views_study_blocks-courses_all_b1']['#markup'])) {
        $haystack = $variables['page']['content']['system_main']['nodes'][87343]['uib_views_block']['views_study_blocks-courses_all_b1']['#markup'];
        $filterWrapperOne = '<div id="edit-studypoints-rank-wrapper"';
        $filterWrapperOneReplace = '<div class="bef_uib_course_wrapper"><div id="edit-studypoints-rank-wrapper"';
        $haystack = str_replace($filterWrapperOne, $filterWrapperOneReplace, $haystack);
        $needleOne = '<div id="edit-tid-wrapper" class';
        $replaceOne = '</div><div class="bef_uib_course"><div id="edit-tid-wrapper" class';
        $haystack = str_replace($needleOne, $replaceOne, $haystack);
        $needleTwo = '<div class="views-exposed-widget views-submit-button">';
        $replaceTwo = '</div><div class="views-exposed-widget views-submit-button">';
        $variables['page']['content']['system_main']['nodes'][87343]['uib_views_block']['views_study_blocks-courses_all_b1']['#markup'] = str_replace($needleTwo, $replaceTwo, $haystack);
      }
    break;
    case @$variables['page']['content']['views_recent_news-block_date_selector']:
      $jq = <<<'EOD'
      (function($) {
        var current=null;
        $('.page-node-news-archive .content-main-wrapper #block-views-recent-news-block-date-selector ul.views-summary').ready(function(){
          var year=0;
          var open='open';
          $('.page-node-news-archive .content-main-wrapper #block-views-recent-news-block-date-selector ul.views-summary').children().each(function(){
            var text=$(this).text().replace(/\r?\n|\r/g,"");
            var y=text.match(/([^ ]+) ([0-9]{4})(.*)$/);
            var month=y[1];
            var numart=y[3];
            if(y[2] != year){
              year=y[2];
              var li=$('<li></li>').html('<span class="year">' + year + '</span>');
              li.addClass(open);
              open='';
              current=$('<ul></ul>');
              li.append(current);
              $(this).before(li);
            }
            $(this).children('a').first().text(month+' '+numart);
            var ali=$('<li></li>').append($(this).children('a').first());
            current.append(ali);
            $(this).remove();
          });
        });
      })(jQuery);
EOD;
      drupal_add_js($jq, 'inline');
      break;
    case isset($variables['node']) && $variables['node']->type == 'uib_article':
      drupal_add_library('system' , 'ui.tabs');
      // set menu to appear as tabs
      $jq = <<<'EOD'
        jQuery( document ).ready( function($){
          $(".uib-tabs-container,#block-uib-study-study-content>.content").tabs();
        });
EOD;
      drupal_add_js($jq, 'inline');
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
      if (!empty($variables['node']->fields_uib_links)) {
        $variables['page']['content_bottom']['field_uib_links'] = field_view_field('node', $variables['node'], 'field_uib_links', array(
          'weight' => '25',
        ));
      }
      if (!empty($variables['node']->field_uib_relation)) {
        $variables['page']['content_bottom']['field_uib_relation'] = field_view_field('node', $variables['node'], 'field_uib_relation', array(
          'weight' => '30',
          'type' => 'entityreference_entity_view',
          'settings' => array('view_mode' => 'short_teaser'),
          'label' => 'hidden',
        ));
      }
      if (!empty($variables['node']->field_uib_related_persons)) {
       $variables['page']['content_bottom']['field_uib_related_persons'] = field_view_field('node', $variables['node'], 'field_uib_related_persons' , array(
          'weight' => '27',
          'type' => 'entityreference_entity_view',
          'settings' => array('view_mode' => 'uib_user_teaser'),
        ));
      }
      if (!empty($variables['node']->field_uib_files)) {
        $variables['page']['content_bottom']['field_uib_files'] = field_view_field('node', $variables['node'], 'field_uib_files', array(
          'weight' => '26',
        ));
      }

      /**
       * Slideshow thingy.
       */
      $slideshow = @$variables['page']['content']['system_main']['nodes'][$variables['node']->nid]['field_uib_main_media'][1];
      if (!is_null($slideshow)) {
        $cycle_path = libraries_get_path('jquery.cycle');
        drupal_add_js($cycle_path . '/jquery.cycle.all.js');
        drupal_add_js('jQuery(function($) {
          $( ".field-name-field-uib-main-media .field-items" ).cycle(
            {
              containerResize: 1,
              fit: 1,
              fx: "scrollHorz",
            }
          );
        }); ', 'inline');
      }

      // Article types with social media links
      $types = array('event', 'news', 'press_release', 'phd_press_release');
      if(in_array(@$variables['node']->field_uib_article_type['und'][0]['value'], $types)){
        // Add social media links inside content uib_artcle
        $variables['page']['content']['system_main']['nodes']
          [$variables['node']->nid]['service_links_service_links'] =
          @__uib_w3__render_block('service_links', 'service_links', 1000, true);
      }

      $exceptions = array('page__node__translate', 'page__node__menu', 'page__node__revisions');
      $stop = FALSE;
      foreach ($exceptions as $e) {
        if(in_array($e, $variables['theme_hook_suggestions'])) $stop = TRUE;
      }
      if (!$stop) {
        $stubborn_bastards = array(
          'field_uib_relation',
          'field_related_persons_label',
          'field_uib_related_persons',
          'field_uib_main_media',
          'field_uib_kicker',
          'field_uib_lead',
          'field_uib_byline',
          'field_uib_links',
          'links',
          'language',
        );
        $empty = TRUE;
        foreach($variables['page']['content']['system_main']['nodes'][$variables['node']->nid] as $key => $value) {
          if (!in_array($key, $stubborn_bastards) && !(substr($key, 0, 1) == '#')) {
            $empty = FALSE;
          }
        }
        if ($empty) $variables['page']['content'] = array();
      }
      break;

    case isset($variables['node']) && $variables['node']->type == 'area':
      $variables['page']['content_top']['uib_area_offices'] = __uib_w3__render_block('uib_area', 'area_offices', -35);
      if ($variables['node']->field_uib_area_type['und'][0]['value'] == 'frontpage') {
        $view_mode = 'full_width_banner';
      }
      else {
        $view_mode = empty($variables['node']->field_uib_primary_text) ? 'content_main' : 'area_main';
      }
      $variables['page']['content_top']['field_uib_primary_media'] = field_view_field('node', $variables['node'], 'field_uib_primary_media', array(
        'type' => 'file_rendered',
        'settings' => array('file_view_mode' => $view_mode),
        'label' => 'hidden',
        'weight' => -30,
      ));
      if ($view_mode == 'content_main') {
        unset($variables['page']['content_top']['field_uib_primary_media'][0]['field_uib_copyright']);
        unset($variables['page']['content_top']['field_uib_primary_media'][0]['field_uib_owner']);
        unset($variables['page']['content_top']['field_uib_primary_media'][0]['field_uib_description']);
        $variables['page']['content_top']['field_uib_primary_media']['#prefix'] = '<div class="full-width">';
        $variables['page']['content_top']['field_uib_primary_media']['#suffix'] = '</div>';
      }
      $variables['page']['content_top']['field_uib_primary_text'] = field_view_field('node', $variables['node'], 'field_uib_primary_text', array(
        'label' => 'hidden',
        'weight' => -25,
      ));
      $variables['page']['content_top']['field_uib_secondary_text'] = field_view_field('node', $variables['node'], 'field_uib_secondary_text', array(
        'label' => 'hidden',
        'weight' => -20,
      ));
      $nid = $variables['node']->nid;
      if ($variables['node']->field_uib_area_type['und'][0]['value'] != 'phdpresspage') {
        $variables['page']['content']['system_main']['nodes'][$nid]['news_and_calendar'] = __uib_w3__render_block('uib_area', 'news_and_calendar', 5);
      }
      if ($variables['node']->field_uib_area_type['und'][0]['value'] != 'frontpage') {
        $variables['page']['content_bottom']['uib_area_calendar'] = __uib_w3__render_block('uib_calendar3', 'calendar3', 0);
        $variables['page']['content_bottom']['uib_area_exhibitions'] = __uib_w3__render_block('uib_calendar3', 'exhibitions3', 5);
        $variables['page']['content_bottom']['uib_area_newspage_recent_news'] = __uib_w3__render_block('views', 'recent_news-block', 10);
        $variables['page']['content_bottom']['uib_area_testimonial'] = field_view_field('node', $variables['node'], 'field_uib_profiled_testimonial', array(
          'weight' => 30,
          'type' => 'entityreference_entity_view',
          'settings' => array('view_mode' => 'teaser'),
          'label' => 'hidden',
        ));
        if (isset($variables['page']['content_bottom']['uib_area_exhibitions']['uib_calendar3_exhibitions3']) && isset($variables['page']['content_bottom']['uib_area_newspage_recent_news']['views_recent_news-block'])) {
          $variables['page']['content_bottom']['uib_area_exhibitions']['#prefix'] = '<div class="news-and-exhibitions">';
          $variables['page']['content_bottom']['uib_area_newspage_recent_news']['#suffix'] = '</div>';
        }
        $variables['page']['footer_top']['field_uib_link_section'] = field_view_field('node', $variables['node'], 'field_uib_link_section', array(
          'label' => 'hidden',
          'weight' => 10,
        ));
      }
      $variables['page']['footer_top']['uib_area_jobbnorge'] = __uib_w3__render_block('uib_area','jobbnorge',20);
      $variables['page']['footer_top']['field_uib_feed'] = __uib_w3__render_block('uib_area', 'feed', 15);
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
        case 'frontpage':
          $variables['page']['content_bottom']['frontpage_links'] = __uib_w3__render_block('uib_area', 'frontpage_links', 0);
          if (!empty($variables['page']['content_top']['field_uib_primary_media'])) {
            if ($variables['language']->language == 'en') {
              $find_studies = __uib_w3__get_renderable_menu('menu-uib-find-studies-en');
            }
            else {
              $find_studies = __uib_w3__get_renderable_menu('menu-uib-find-studies');
            }
            $variables['page']['content_top']['find_studies'] = array(
              '#type' => 'html_tag',
              '#value' => render($find_studies),
              '#weight' => 20,
              '#attributes' => array('class' => array('uib-find-studies')),
              '#tag' => 'nav',
            );
          }
          break;
      }
      break;

    case isset($variables['node']) && $variables['node']->type == 'uib_study':
      if ($variables['node']->field_uib_study_type['und'][0]['value'] != 'course') {
        drupal_add_library('system' , 'ui.tabs');
        // set menu to appear as tabs
        $jq = <<<'EOD'
          jQuery( document ).ready( function($){
            $(".uib-tabs-container,#block-uib-study-study-content>.content").tabs();
          });
EOD;
        drupal_add_js($jq, 'inline');
      }
      $variables['page']['content_top']['field_uib_study_type'] = field_view_field('node', $variables['node'], 'field_uib_study_category', array(
        'label' => 'hidden',
        'weight' => -50,
      ));
      $variables['page']['content_top']['title'] = array(
        '#type' => 'html_tag',
        '#tag' => 'h1',
        '#value' => $variables['node']->field_uib_study_title[$variables['language']->language][0]['safe_value'],
        '#weight' => -45,

      );
      $variables['page']['content_top']['study_facts'] = __uib_w3__render_block('uib_study', 'study_facts_2', 40);
      $variables['page']['content']['study_content'] = __uib_w3__render_block('uib_study', 'study_content', 0);
      unset($variables['page']['content']['study_content']['uib_study_study_content']['#contextual_links']);
      $variables['page']['content']['study_contact'] = __uib_w3__render_block('uib_study', 'study_contact', 5);
      if ($variables['node']->field_uib_study_type['und'][0]['value'] == 'exchange') {
        $variables['page']['content']['study_facts_exchange'] = __uib_w3__render_block('uib_study', 'study_facts_exchange', 15);
      }
      global $language;
      $belongs_to = uib_study__area($variables['node'], $language->language);
      $variables['page']['content']['study_belongs_to'] = array(
        '#type' => 'html_tag',
        '#tag' => 'div',
        '#value' => $belongs_to,
        '#weight' => 20,
        '#attributes' => array('class' => array('uib-study-belongs-to')),
      );
      if ($variables['node']->field_uib_study_type['und'][0]['value'] != 'exchange') {
        $variables['page']['content_bottom']['study_related'] = __uib_w3__render_block('uib_study', 'study_related', 15);
      }
      if ($variables['node']->field_uib_study_category['und'][0]['value'] == 'evu') {
        $variables['page']['content']['study_evu_available'] = __uib_w3__render_block('uib_study', 'study_evu', 10);
      }
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
        $variables['page']['content']['study_did_you_know'] = __uib_w3__render_block('uib_study', 'study_trivia', 7);
        $variables['page']['content']['study_testimonial'] = __uib_w3__render_block('uib_study', 'study_testimonial', 10, TRUE);
        $variables['page']['content_bottom']['study_plan'] = __uib_w3__render_block('uib_study', 'study_plan', 20);
        $variables['page']['content_bottom']['field_uib_link_section'] = field_view_field('node', $variables['node'], 'field_uib_link_section', array(
          'label' => 'hidden',
          'weight' => 0,
        ));
        $specializations = '';
        $view = views_get_view('uib_study_specialization');
        $view->preview('block', array($variables['node']->nid));
        if ($view->result) {
          $specializations = '<div class="block block-uib-study uib-study-specialization"><h3>' . t('Specialization') . '</h3>' . $view->render() . '</div>';
        }
        $variables['page']['content']['field_uib_study'] = array(
          '#type' => 'markup',
          '#markup' => $specializations,
          '#weight' => 8,
        );
        $variables['page']['content_bottom']['field_uib_feed'] = field_view_field('node', $variables['node'], 'field_uib_feed', array(
          'type' => 'uib_area_link_feed',
          'settings' => array('view_mode' => 'full'),
          'label' => 'hidden',
          'weight' => 40,
        ));
      }
      if ($variables['node']->field_uib_study_type['und'][0]['value'] == 'exchange') {
        $variables['page']['content']['study_image'] = field_view_field('node', $variables['node'], 'field_uib_study_image', array(
          'type' => 'file_rendered',
          'settings' => array('file_view_mode' => 'content_sidebar'),
          'label' => 'hidden',
          'weight' => 3,
        ));
        $variables['page']['content_bottom']['study_static_links'] = __uib_w3__render_block('uib_study', 'study_static_links', 0);
      }
      break;
    case (isset($variables['node']) && $variables['node']->type == 'uib_testimonial'):
      $variables['page']['content_top']['title'] = array(
        '#type' => 'html_tag',
        '#tag' => 'h1',
        '#value' => $variables['node']->title,
        '#weight' => -30,
      );
      $variables['page']['content_top']['field_uib_lead'] = field_view_field('node', $variables['node'], 'field_uib_lead', array(
        'label' => 'hidden',
        'weight' => -20,
      ));
      $variables['page']['content_bottom']['field_uib_relation'] = field_view_field('node', $variables['node'], 'field_uib_relation', array(
        'weight' => '30',
        'type' => 'entityreference_entity_view',
        'settings' => array('view_mode' => 'short_teaser'),
        'label' => 'hidden',
      ));
      break;
    case (!isset($variables['node']) && $variables['theme_hook_suggestions'][0] == 'page__user' && !in_array('page__user__edit', $variables['theme_hook_suggestions'])):
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
      if (isset($variables['page']['content']['system_main']['field_uib_user_alt_position'])) {
        $alt_position = $variables['page']['content']['system_main']['field_uib_user_alt_position'][0]['#markup'];
        $variables['page']['content_top']['position'][0]['#markup'] .= $alt_position;
        unset($variables['page']['content']['system_main']['field_uib_user_alt_position']);
      }
      $user_ou = $variables['page']['content']['system_main']['field_uib_user_ou']['#object']->field_uib_user_ou['und'][0]['target_id'];
      $variables['page']['content_top']['user_ou'] = $variables['page']['content']['system_main']['field_uib_user_ou'][0]['node'][$user_ou]['field_uib_ou_title'];
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
    'uib_study_study_evu',
    'uib_study_study_trivia',
    'uib_area_area_banner',
    'uib_area_area_offices',
    'uib_calendar3_calendar3',
    'uib_user_feed',
    'uib_user_twitter',
    'uib_user_research_groups',
    'uib_calendar3_exhibitions3',
    'uib_search_global-searchform',
    'uib_area_ouprosjektet_logo',
    'uib_study_study_static_links',
    'uib_study_study_facts_exchange',
    'uib_area_frontpage_links',
    'uib_area_news_and_calendar',
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
      if ($variables['field_uib_area_type']['und'][0]['value'] == 'frontpage') {
        hide($variables['content']['field_uib_profiled_message']);
      }
      if ($variables['field_uib_area_type']['und'][0]['value'] == 'phdpresspage') {
        $phds = views_embed_view('recent_phds', 'page', $variables['nid']);
        $variables['content']['field_uib_recent_phds'] = array(
          '#weight' => '50',
          '#markup' => $phds,
        );
      }
    }
    if ($variables['type'] == 'uib_article') {
      $variables['content']['field_uib_date']['#label_display'] = 'hidden';
      $variables['content']['field_uib_registration_link']['#label_display'] = 'hidden';
      $variables['content']['field_uib_location']['#label_display'] = 'hidden';
      $variables['content']['field_uib_event_type']['#label_display'] = 'hidden';
      $variables['content']['field_uib_contacts']['#label_display'] = 'hidden';
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
    if ($variables['type'] == 'uib_testimonial' && $variables['view_mode'] == 'teaser') {
      if (count($variables['field_uib_media']) > 1) {
        $variables['content']['field_uib_media'] = __uib_w3__keep_first_media($variables['content']['field_uib_media']);
      }
      $variables['theme_hook_suggestions'][] = 'node__testimonial__teaser';
    }
    if ($variables['type'] == 'uib_article' && $variables['view_mode'] == 'teaser') {
      if (count($variables['field_uib_main_media']) > 1) {
        $variables['content']['field_uib_main_media'] = __uib_w3__keep_first_main_media($variables['content']['field_uib_main_media']);
      }
      $variables['theme_hook_suggestions'][] = 'node__article__teaser';
      if( count($variables['field_uib_event_type']) &&
        isset($variables['field_uib_date']['und'][0]['value'])){
        $variables['content']['field_uib_main_media'][0]['#markup'].=
          uib_calendar3__get_calendar_card_render_array(
          $variables['field_uib_date']['und'][0]['value'] . 'Z');
      }

    }
    if ($variables['type'] == 'uib_article' && $variables['view_mode'] == 'short_teaser') {
      if (empty($variables['field_uib_main_media']) && !empty($variables['field_uib_media'])) {
        $uib_media = field_view_field('node', $variables['node'], 'field_uib_media', array(
          'type' => 'file_rendered',
          'settings' => array('view_mode' => 'wide_thumbnail'),
          'label' => 'hidden',
          'weight' => 3,
        ));
        $variables['content']['field_uib_main_media'] = $uib_media;
        unset($variables['content']['field_uib_main_media'][0]['field_uib_copyright']);
        unset($variables['content']['field_uib_main_media'][0]['field_uib_owner']);
        unset($variables['content']['field_uib_main_media'][0]['field_uib_description']);
      }
      if (count($variables['field_uib_main_media']) > 1) {
        $variables['content']['field_uib_main_media'] = __uib_w3__keep_first_main_media($variables['content']['field_uib_main_media']);
      }
      if (empty($variables['field_uib_main_media']) && !empty($variables['field_uib_media'])) {
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
      unset($variables['content']['field_uib_main_media'][0]['field_uib_owner']);
      unset($variables['content']['field_uib_main_media'][0]['field_uib_description']);
      $variables['content']['field_uib_lead'] = field_view_field('node', $variables['node'], 'field_uib_teaser', array(
        'label' => 'hidden',
        'weight' => 5,
      ));
    }
    if ($variables['type'] == 'uib_external_content' && $variables['view_mode'] == 'short_teaser') {
      $variables['theme_hook_suggestions'][] = 'node__external_content__short_teaser';
    }
    if ($variables['type'] == 'uib_testimonial' && $variables['view_mode'] == 'short_teaser') {
      $variables['theme_hook_suggestions'][] = 'node__testimonial__short_teaser';
    }
    if ($variables['type'] == 'uib_study' && $variables['view_mode'] == 'short_teaser') {
      $variables['theme_hook_suggestions'][] = 'node__uib_study__short_teaser';
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
  $authorarray = array_merge((array)@$node->field_uib_byline['und'],
    (array)@$node->field_uib_external_author['und']);
  if (count($authorarray)) {
    $byline = field_view_field('node', $node, 'field_uib_byline', array(
      'type' => 'entityreference_label',
      'label' => 'hidden',
      'settings' => array('link' => TRUE),
    ));
    $tmp = array();
    foreach ($authorarray as $key => $b) {
      if(@$b['target_id']){
        $tmp[] = $byline[$key]['#markup'];
      }
      else{
        $tmp[] = '<span class="ext_auth">' . $b['value'] . '</span>';
      }
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
function __uib_w3__render_block($module, $block_id, $weight, $no_label=FALSE) {
  $block = block_load($module, $block_id);
  $block_content = _block_render_blocks(array($block));
  if ($no_label) $block->subject = FALSE;
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

/**
 * Function for formatting an uib_menu the way we want
 */
function __uib_w3__get_renderable_menu($menu_name) {
  $menu = menu_tree_output(menu_tree_all_data($menu_name));
  foreach ($menu as $key => $value) {
    if (is_numeric($key)) $menu[$key]['#attributes']['class'][] = 'menu__item';
  }
  return $menu;
}
/**
 * Overrides theme_breadcrumb()
 *
 * @param $vars
 *  An array containing the breadcrumb links.
 *
 * @return
 *  markup for the overriden breadcrumb
 */
function uib_w3_breadcrumb(&$vars) {
  $breadcrumb = $vars['breadcrumb'];
  $output = '<nav class="breadcrumb" role="navigation"><ol>';
  foreach ($breadcrumb as $key => $crumb) {
    if ($key == 2 && strpos($crumb, 'uib-remove-link')) $crumb = strip_tags($crumb);
    $output .= '<li>' . urldecode($crumb) . ' </li>';
  }
  $output .= '</ol></nav>';
  return $output;
}
