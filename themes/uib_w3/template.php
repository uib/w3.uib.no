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
  if (isset($variables['theme_hook_suggestions'][0]) && $variables['theme_hook_suggestions'][0] == 'html__hybridauth') {
    if (isset($variables['page']['#children'])
        && ($variables['page']['#children'] == 'Closing...') || $variables['page']['#children'] == 'Logger inn ...') {
      drupal_add_css(drupal_get_path('module','uib_admin').'/css/hybridauth.css');
      $variables['page']['#children'] = '<div class="html__hybridauth__container"><h3 class="html__hybridauth__closing">'
                                        .t('Logging into uib.no')
                                        .'</h3><div class="loader"></div></div>';
    }
  }
  // setting te browser title to reflect the page and parent area
  if (isset($variables['theme_hook_suggestions'][3]) || $variables['theme_hook_suggestions'][0] == 'html__calendar') {
    $variables['head_title'] = uib_w3__get_theme_suggested_title($variables);
  }
  if (!$variables['logged_in']) {
    drupal_add_js("(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':new Date().getTime(), event:'gtm.js'}); var f=d.getElementsByTagName(s)[0], j=d.createElement(s), dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src='https://www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);})(window, document, 'script', 'dataLayer', 'GTM-KLPBXPW');", array('type' => 'inline', 'scope' => 'header', 'weight' => -99));
  }
  drupal_add_js('//use.typekit.net/yfr2tzw.js', 'external');
  drupal_add_js('try{Typekit.load();}catch(e){}', 'inline');
  drupal_add_js("(function() {
var sz = document.createElement('script'); sz.type = 'text/javascript'; sz.async = true;
sz.src = '//siteimproveanalytics.com/js/siteanalyze_6000122.js';
var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(sz, s);
})();", array('type' => 'inline', 'scope' => 'footer'));
  if ($variables['language']->language == 'en') {
    drupal_add_js('(function(a,b,c,d,e,f,g,h,i){i=/(|;)\s*_tmc=([;]+)/.exec(a[c]),i=i?i2:"",("done"!==i|| /[?&]_tmcf?(=|&|$)/.test(e))&&(g=a.getElementsByTagName(b)[0],h=a.createElement(b),h[d]("src",f+ "?r="+i+"&l=en&"+1*new Date),h[d]("type","text/javascript"),h.async=!0,g.parentNode.insertBefore(h,g)) })(document,"script","cookie","setAttribute",location.search,"//in.taskanalytics.com/00081/tm.js");', array('type' => 'inline', 'scope' => 'footer'));
  } else {
    drupal_add_js('(function(a,b,c,d,e,f,g,h,i){i=/(^|;)\s*_tmc=([^;]+)/.exec(a[c]),i=i?i[2]:"",("done"!==i|| /[?&]_tmcf?(=|&|$)/.test(e))&&(g=a.getElementsByTagName(b)[0],h=a.createElement(b),h[d]("src",f+ "?r="+i+"&"+1*new Date),h[d]("type","text/javascript"),h.async=!0,g.parentNode.insertBefore(h,g)) })(document,"script","cookie","setAttribute",location.search,"//in.taskanalytics.com/00081/tm.js");', array('type' => 'inline', 'scope' => 'footer'));
  }
  if ($node = menu_get_object()) {
    if ($node->type == 'uib_article') {
      $variables['classes_array'][] = $node->field_uib_feature_article['und'][0]['value'] === '1' ? 'uib-article__feature_article' : 'uib-article__' . $node->field_uib_article_type['und'][0]['value'];
      if ($node->field_uib_feature_article['und'][0]['value'] == 1) {
        if (!empty($node->field_uib_feature_heading_style)) {
          $variables['classes_array'][] = 'feature-article-style-' . $node->field_uib_feature_heading_style['und'][0]['value'];
        }
        else {
          $variables['classes_array'][] = 'feature-article-style-w';
        }
        if (!empty($node->field_uib_main_media) && $node->field_uib_main_media['und'][0]['type'] == 'video') {
          $variables['classes_array'][] = 'feature-article-video';
        }
        else {
          $variables['classes_array'][] = 'feature-article-image';
        }
      }
    }
    if ($node->type == 'area') {
      if ($node->field_uib_area_type['und'][0]['value'] == 'frontpage') {
        $variables['classes_array'][] = 'banner-image';
      }
      if ($node->field_uib_area_type['und'][0]['value'] == 'feature area') {
        $variables['classes_array'][] = 'feature-area';
        if (!empty($node->field_uib_feature_heading_style)) {
          $variables['classes_array'][] = 'feature-area-style-' . $node->field_uib_feature_heading_style['und'][0]['value'];
        }
        else {
          $variables['classes_array'][] = 'feature-area-style-w';
        }
        if (!empty($node->field_uib_primary_media) && $node->field_uib_primary_media['und'][0]['type'] == 'video') {
          $variables['classes_array'][] = 'feature-video';
        }
        else {
          $variables['classes_array'][] = 'feature-image';
        }
      }
      if (empty($node->field_uib_show_twitter_feed)) {
        $variables['classes_array'][] = 'no-twitter';
      }
      if (empty($node->field_uib_profiled_testimonial)) {
        $variables['classes_array'][] = 'no-testimonial';
      }
    }
    if ($node->type == 'uib_study') {
      if(uib_study__programme_use_w3_data($node->field_uib_study_type['und'][0]['value'])) {
        $variables['classes_array'][] = 'uib-study__program--new';
      }
      else $variables['classes_array'][] = 'uib-study__' . $node->field_uib_study_type['und'][0]['value'];
      if (uib_study__use_tabs($node->field_uib_study_type['und'][0]['value'])) {
        $variables['classes_array'][] = 'study-tabs';
      }
    }
  }
  if ($current_area = uib_area__get_current()) {
    if ($current_area->field_uib_menu_style['und'][0]['value'] == 'expanded') {
      $variables['classes_array'][] = 'uib-area-expanded-menu';
    }
  }
  // Adding meta element for last modified to head section
  if ($node && isset($node->revision_timestamp)) {
    $meta_last_modified = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'Last-Modified',
        'content' =>  date('Y-m-d\TH:i:s\Z', $node->revision_timestamp)
      )
    );
    drupal_add_html_head($meta_last_modified, 'meta_last_modified');
  }
  if (in_array('html__studier', $variables['theme_hook_suggestions']) || in_array('html__studies', $variables['theme_hook_suggestions'])) {
    $meta_description = array(
      '#type' => 'html_tag',
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'description',
        'content' => t(' We offer various studies taught in English within different fields. Choose your area of interest to find the perfect match for you.'),
      ),
    );
    drupal_add_html_head($meta_description, 'meta_description');
    if (!in_array('html__studies__alphabetical', $variables['theme_hook_suggestions']) && count($variables['theme_hook_suggestions']) > 1) {
      $key = array_search('page-studies', $variables['classes_array']);
      if ($key) unset($variables['classes_array'][$key]);
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
  drupal_add_js('sites/all/themes/uib/uib_w3/js/sortable.js');
  $page_menu_item = menu_get_item(current_path());
  if (!is_int(strpos($page_menu_item['path'], 'node/add/'))) {
    $global_menu_lang = $variables['language']->language == 'nb' ? '-no' : '';
    $global_menu = __uib_w3__get_renderable_menu('menu-global-menu' . $global_menu_lang . '-2');
    $variables['page']['header']['global_menu'] = $global_menu;
    $variables['page']['header']['global_menu']['#prefix'] = '<nav class="global-menu">';
    $variables['page']['header']['global_menu']['#suffix'] = '</nav>';
    $variables['page']['header']['global_menu']['#weight'] = -10;
    $variables['page']['header']['mobile_menu'] = array(
      '#type' => 'html_tag',
      '#tag' => 'div',
      '#attributes' => array('class' => 'menu-button'),
      '#value' => t('Menu'),
    );
    $variables['page']['header']['mobile_menu']['#prefix'] = '<nav class="mobile-menu">';
    $variables['page']['header']['mobile_menu']['#suffix'] = '</nav>';
    $variables['page']['header']['mobile_menu']['#weight'] = -11;
  }
  $current_area = uib_area__get_current();
  $is_view_page = false;
  $view_pages = array(
    'page__node__news_archive',
    'page__node__calendar',
    'page__node__persons',
    'page__node__persons__faculty',
    'page__node__persons__staff',
  );
  foreach($view_pages as $view_page) {
    $is_view_page = in_array($view_page, $variables['theme_hook_suggestions']);
    if ($is_view_page) break;
  }
  $is_feature_front = $current_area && $current_area->field_uib_area_type['und'][0]['value'] == 'feature area' && uib_area__get_node_type() == 'area' && !$is_view_page ? true : false;
  $is_feature_article = isset($variables['node']) && $variables['node']->type == 'uib_article' && $variables['node']->field_uib_feature_article['und'][0]['value'] === '1' ? true : false;
  $is_study_programme = isset($variables['node']) && $variables['node']->type == 'uib_study' && $variables['node']->field_uib_study_type['und'][0]['value'] == 'program' ? true : false;
  if ($area_menu_name = uib_area__get_current_menu()) {
    $area_menu = __uib_w3__get_renderable_menu($area_menu_name);
    if (!empty($area_menu)) {
      if (!$variables['is_front'] && !$is_feature_front && !$is_feature_article && !$is_study_programme) {
        $variables['area_menu'] = $area_menu;
      }
      $variables['area_menu_footer'] = $area_menu;
    }
  }
  if (!is_int(strpos($page_menu_item['path'], 'node/add/'))) {
    if ($variables['language']->language == 'nb') {
      $variables['mobile']['global_mobile_menu'] = __uib_w3__get_renderable_menu('menu-global-menu-no-2');
    }
    else {
      $variables['mobile']['global_mobile_menu'] = __uib_w3__get_renderable_menu('menu-global-menu-2');
    }
    $variables['mobile']['global_mobile_menu']['#prefix'] = '<nav class="global-mobile-menu">';
    $variables['mobile']['global_mobile_menu']['#suffix'] = '</nav>';
    $variables['mobile']['global_mobile_menu']['#weight'] = 5;
  }
  if ($current_area && !$variables['is_front'] && ($current_area->field_uib_area_type['und'][0]['value'] != 'feature area' || (uib_area__get_node_type() != 'area' || $is_view_page)) && !$is_feature_article && !$is_study_programme) {
    global $base_path;
    $variables['page']['subheader']['area'] = array(
      '#type' => 'link',
      '#prefix' => '<h2>',
      '#suffix' => '</h2>',
      '#title' => $current_area->title,
      '#href' => $base_path . drupal_get_path_alias("node/{$current_area->nid}",
        $variables['language']->language ),
    );
    if ($area_menu_name = uib_area__get_current_menu()) {
      $variables['page']['subheader']['area_menu']['#prefix'] = '<nav class="mobile_area mobile_dropdown">';
      $variblaes['page']['subheader']['area_menu']['#suffix'] = '</nav>';
      $variables['page']['subheader']['area_menu']['expandable'] = __uib_w3__get_renderable_menu($area_menu_name);
      $variables['page']['subheader']['area_menu']['expandable']['#prefix'] = '<nav class="area-mobile-menu">';
      $variables['page']['subheader']['area_menu']['expandable']['#suffix'] = '</nav>';
      $variables['page']['subheader']['area_menu']['expandable']['#weight'] = 2;
    }
  }
  if ($current_area && $is_feature_front) {
    if (empty($current_area->field_uib_feature_heading_style['und'][0]['value']) || $current_area->field_uib_feature_heading_style['und'][0]['value'] != 'h') {
      $variables['page']['content_top']['area'] = array(
        '#type' => 'html_tag',
        '#tag' => 'h2',
        '#attributes' => array(),
        '#value' => $current_area->title,
        '#weight' => -27,
        '#prefix' => '<div class="uib-feature-area__title">',
        '#suffix' => '</div>',
      );
    }
    if (isset($area_menu)) {
      $variables['page']['content_top']['area_menu'] = $area_menu;
      $variables['page']['content_top']['area_menu']['#prefix'] = '<nav class="uib-feature-area-menu">';
      $variables['page']['content_top']['area_menu']['#suffix'] = '</nav>';
    }
    if (!empty($variables['node']->field_uib_primary_media) || !empty($variables['node']->field_uib_main_media)) {
      if ($variables['node']->field_uib_primary_media['und'][0]['filemime'] == 'video/vimeo' || $variables['node']->field_uib_main_media['und'][0]['filemime'] == 'video/vimeo') {
        drupal_add_js('https://player.vimeo.com/api/player.js');
      }
      if ($variables['node']->field_uib_primary_media['und'][0]['filemime'] == 'video/youtube' || $variables['node']->field_uib_main_media['und'][0]['filemime'] == 'video/youtube') {
        drupal_add_js('https://www.youtube.com/iframe_api');
        drupal_add_js(drupal_get_path('theme', 'uib_w3') . '/js/yt.js', array('type' => 'file', 'scope' => 'footer',));
      }
    }
    drupal_add_js('sites/all/themes/uib/uib_w3/js/w3-feature.js');
  }
  $variables['page']['header']['search'] =
    __uib_w3__render_block('uib_search', 'global-searchform', -5);
  $variables['page']['footer']['uib_area_colophon'] = __uib_w3__render_block('uib_area','colophon_2',15);
  if ($current_area) {
    $variables['page']['footer']['social_media'] = field_view_field('node', $current_area, 'field_uib_social_media', array(
      'type' => 'socialmedia_formatter',
      'settings' => array('link' => TRUE),
      'weight' => '20',
    ));
  }
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

  if(isset($variables['theme_hook_suggestions'][3]) && $variables['theme_hook_suggestions'][3] != 'page__front' && $variables['theme_hook_suggestions'][3] != 'page__node__calendar' && isset($variables['theme_hook_suggestions'][3])) {
    $variables['page']['content_top']['title'] = array(
      '#type' => 'html_tag',
      '#tag' => 'h1',
      '#value' => uib_w3__get_theme_suggested_title($variables,false),
      '#weight' => -45,
    );
  }

  switch (true) {
    case in_array('page__studier', $variables['theme_hook_suggestions']) || in_array('page__studies', $variables['theme_hook_suggestions']);
      drupal_add_library('system' , 'ui.accordion');
      drupal_add_js(drupal_get_path('module', 'uib_study') . '/js/expand.js');
      break;
    case in_array('page__foremployees__market', $variables['theme_hook_suggestions']):
      $variables['page']['content_top']['title'] = array(
        '#type' => 'html_tag',
        '#tag' => 'h1',
        '#value' => t('Internal market'),
        '#weight' => -45,
      );
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
              li.click(function(){$(this).toggleClass('open')});
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
    case isset($variables['node']) && $variables['node']->type == 'uib_market':
      $variables['page']['content']['category'] = field_view_field('node',$variables['node'],'field_uib_market_category', array(
        'label' => 'hidden',
        'weight' => -46,
      ), $variables['language']->language);
      $variables['page']['content']['title'] = array(
        '#type' => 'html_tag',
        '#tag' => 'h3',
        '#value' => $variables['node']->title,
        '#weight' => -45,
        '#attributes' => array('class' => 'uib_market_title'),
      );
    break;
    case isset($variables['node']) && $variables['node']->type == 'uib_content_list':
      drupal_add_library('system' , 'ui.accordion');
      // set menu to appear as tabs
      $jq = uib_w3__accordion_script();
      drupal_add_js($jq, 'inline');
      break;
    case isset($variables['node']) && $variables['node']->type == 'uib_article':
      $not_trans = t('There has not been added a translated version of this content. You can either try <a href="@search" class="not-translated-search">searching</a> or go to the <a href="@area">"area"</a> home page to see if you can find the information there', array(
        '@search' => url('search'),
        '@area' => url('node/' . $current_area->nid),
      ));
      if ($variables['node']->language != $variables['language']->language) {
        drupal_set_message($not_trans, 'warning');
      }
      drupal_add_library('system' , 'ui.accordion');
      // set menu to appear as tabs
      $jq = uib_w3__accordion_script();
      drupal_add_js($jq, 'inline');
      $is_feature_article = $variables['node']->field_uib_feature_article['und'][0]['value'] === '1' ? TRUE : FALSE;
      if (!$is_feature_article) {
        $variables['page']['content_top']['kicker'] = field_view_field('node', $variables['node'], 'field_uib_kicker', array(
          'label' => 'hidden',
          'weight' => -50,
        ));
      }
      $variables['page']['content_top']['title'] = array(
        '#type' => 'html_tag',
        '#tag' => 'h1',
        '#value' => $variables['node']->title,
        '#weight' => -45,
      );
      $variables['page']['content_top']['field_uib_lead'] = field_view_field('node', $variables['node'], 'field_uib_lead', array(
        'label' => 'hidden',
        'weight' => -35,
      ));
      $feature_view_mode = count($variables['node']->field_uib_main_media['und']) > 1 ? 'feature_article_full_width' : 'feature_image';
      $file_view_mode = $is_feature_article ? $feature_view_mode : 'content_main';
      $image_weight = $is_feature_article ? -60 : -30;
      $variables['page']['content_top']['field_uib_main_media'] = field_view_field('node', $variables['node'], 'field_uib_main_media', array(
        'type' => 'file_rendered',
        'settings' => array('file_view_mode' => $file_view_mode),
        'label' => 'hidden',
        'weight' => $image_weight,
      ));
      if (isset($variables['page']['content_top']['field_uib_main_media']) && isset($variables['page']['content_top']['field_uib_main_media'][1])) {
        $cycle_path = libraries_get_path('jquery.cycle2');
        drupal_add_js($cycle_path . '/jquery.cycle2.min.js');
        drupal_add_js($cycle_path . '/jquery.cycle2.swipe.min.js');
        drupal_add_js(drupal_get_path('theme', 'uib_w3') . '/js/uib_cycle.js', 'file');
        $variables['page']['content_top']['field_uib_main_media']['#prefix'] = '<div class="uib-slideshow"><div class="uib-slideshow__nav--next">' . t('Next') . '</div>';
        $variables['page']['content_top']['field_uib_main_media']['#suffix'] = '<div class="uib-slideshow__nav--prev">' . t('Previous') . '</div></div>';
      }
      elseif (!empty($variables['page']['content_top']['field_uib_main_media']) && $variables['page']['content_top']['field_uib_main_media']['#items'][0]['type'] == 'video') {
        $variables['page']['content_top']['field_uib_feature_mobile_media'] = field_view_field('node', $variables['node'], 'field_uib_feature_mobile_media', array(
          'type' => 'file_rendered',
          'settings' => array('file_view_mode' => $file_view_mode),
          'label' => 'hidden',
          'weight' => $image_weight - 1,
        ));
        if (!empty($variables['page']['content_top']['field_uib_feature_mobile_media'])) {
          $variables['page']['content_top']['uib_play_video'] = array(
            '#type' => 'html_tag',
            '#tag' => 'div',
            '#attributes' => array('class' => array('uib-play-video')),
            '#value' => l('spill video', '#'),
            '#weight' => $image_weight - 2,
          );
        }
        $variables['page']['content_top']['field_uib_main_media']['#attached']['js'][] = array(
          'type' => 'external',
          'data' => 'https://player.vimeo.com/api/player.js',
          'scope' => 'footer',
          'group' => JS_THEME,
        );
        $variables['page']['content_top']['uib-play-video']['#attached']['js'][] = array(
          'type' => 'file',
          'data' => drupal_get_path('theme', 'uib_w3') . '/js/feature-play.js',
          'scope' => 'footer',
          'group' => JS_THEME,
        );
      }
      uib_w3__add_image_caption(
        $variables['page']['content_top']['field_uib_main_media'],
        $variables['node'],
        'field_uib_imagecaptions'
      );
      $variables['page']['content_bottom']['field_uib_links'] = field_view_field('node', $variables['node'], 'field_uib_links', array(
        'weight' => '25',
      ));
      $tmpVar3 = field_view_field('node',$variables['node'],'field_uib_links_label');
      $tmpVar4 = field_view_field('node',$variables['node'],'field_uib_links');
      if ($tmpVar3 && $tmpVar4) {
        $variables['page']['content_bottom']['field_uib_links']['#label_display'] = 'display';
        $variables['page']['content_bottom']['field_uib_links']['#title'] = $tmpVar3[0]['#markup'];
      }
      $variables['page']['content_bottom']['field_uib_relation'] = field_view_field('node', $variables['node'], 'field_uib_relation', array(
        'weight' => '30',
        'type' => 'entityreference_entity_view',
        'settings' => array('view_mode' => 'short_teaser'),
        'label' => 'hidden',
      ));
      $tmpVar = field_view_field('node',$variables['node'],'field_uib_related_content_label');
      $tmpVar2 = field_view_field('node',$variables['node'],'field_uib_relation');
      if ($tmpVar && $tmpVar2) {
        $variables['page']['content_bottom']['field_uib_relation']['#label_display'] = 'display';
        $variables['page']['content_bottom']['field_uib_relation']['#title'] = $tmpVar[0]['#markup'];
      }
      $variables['page']['content_bottom']['field_uib_related_persons'] = field_view_field('node', $variables['node'], 'field_uib_related_persons' , array(
        'weight' => '27',
        'type' => 'entityreference_entity_view',
        'settings' => array('view_mode' => 'uib_user_teaser'),
      ));
      $title=@$variables['node']->field_related_persons_label['und'][0]['value'];
      if($title &&
        @$variables['page']['content_bottom']['field_uib_related_persons']['#title']){
        $variables['page']['content_bottom']['field_uib_related_persons']['#title']=$title;
      }
      $variables['page']['content_bottom']['field_uib_files'] = field_view_field('node', $variables['node'], 'field_uib_files', array(
        'weight' => '26',
      ));
      $tmpVar5 = field_view_field('node',$variables['node'],'field_uib_documents_label');
      $tmpVar6 = field_view_field('node',$variables['node'],'field_uib_files');
      if ($tmpVar5 && $tmpVar6) {
        $variables['page']['content_bottom']['field_uib_files']['#label_display'] = 'display';
        $variables['page']['content_bottom']['field_uib_files']['#title'] = $tmpVar5[0]['#markup'];
      }

      // Article types with social media links
      $types = array('event', 'news', 'press_release', 'phd_press_release');
      if(in_array(@$variables['node']->field_uib_article_type['und'][0]['value'], $types) && !$is_feature_article){
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
          'field_uib_related_content_label',
          'field_related_persons_label',
          'field_uib_related_persons',
          'field_uib_main_media',
          'field_uib_kicker',
          'field_uib_lead',
          'field_uib_byline',
          'field_uib_links_label',
          'field_uib_links',
          'links',
          'language',
          'field_uib_documents_label',
        );
        $empty = TRUE;
        foreach($variables['page']['content']['system_main']['nodes'][$variables['node']->nid] as $key => $value) {
          if (!in_array($key, $stubborn_bastards) && !(substr($key, 0, 1) == '#')) {
            $empty = FALSE;
          }
        }
        if ($empty) {
          $article_info = __uib_w3__article_info($variables['node']);
          $variables['page']['content_top']['article_info'] = $article_info;
          $variables['page']['content'] = array();
        }
      }
      break;

    case isset($variables['node']) && $variables['node']->type == 'area':
      if (in_array($variables['node']->field_uib_area_type['und'][0]['value'], array('frontpage'))) {
        $view_mode = 'full_width_banner';
      }
      elseif (in_array($variables['node']->field_uib_area_type['und'][0]['value'], array('feature area'))) {
        $view_mode = 'feature_image';
        if ($variables['node']->field_uib_primary_media['und'][0]['type'] == 'video') {
          $variables['page']['content_top']['field_uib_feature_mobile_media'] = field_view_field('node', $variables['node'], 'field_uib_feature_mobile_media', array(
            'type' => 'file_rendered',
            'settings' => array('file_view_mode' => $view_mode),
            'label' => 'hidden',
            'weight' => -30,
          ));
          $variables['page']['content_top']['uib_play_video'] = array(
            '#type' => 'html_tag',
            '#tag' => 'div',
            '#attributes' => array('class' => array('uib-play-video')),
            '#value' => l('spill video', '#'),
            '#weight' => -20,
          );
        }
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

      $variables['page']['content_top']['field_uib_important_message'] = field_view_field('node', $variables['node'], 'field_uib_important_message', array(
        'label' => 'hidden',
        'weight' => -40,
      ));

      // Adding link to rss-newsfeed to header
      $link_attributes = array(
        'rel' => 'alternate',
        'type' => 'application/rss+xml',
        'href' => '/' . request_path() . '/rss.xml',
      );
      drupal_add_html_head_link($link_attributes, TRUE);

      // Adding link to calendar rss-feed to header
      $link_attributes = array(
        'rel' => 'alternate',
        'type' => 'application/rss+xml',
        'href' => '/' . request_path() . '/calrss.xml',
      );
      drupal_add_html_head_link($link_attributes, TRUE);

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

      if (!$is_feature_front || (empty($variables['node']->field_uib_feature_heading_style) || $variables['node']->field_uib_feature_heading_style['und'][0]['value'] != 'h')) {
        $variables['page']['content_top']['field_uib_secondary_text'] = field_view_field('node', $variables['node'], 'field_uib_secondary_text', array(
          'label' => 'hidden',
          'weight' => -20,
        ));
      }
      $nid = $variables['node']->nid;
      if ($variables['node']->field_uib_area_type['und'][0]['value'] != 'phdpresspage') {
        $variables['page']['content']['system_main']['nodes'][$nid]['news_and_calendar'] = __uib_w3__render_block('uib_area', 'news_and_calendar', 6);
      }
      if ($variables['node']->field_uib_area_type['und'][0]['value'] != 'frontpage') {
        if (($nid == 1 || $nid == 2) && variable_get('uib_display_employee_messages_block', 0)) {
          $variables['page']['content']['uib_messages'] = __uib_w3__render_block('uib_message', 'uib_message_block', -30);
        }
        $variables['page']['content']['system_main']['nodes'][$nid]['uib_area_calendar'] = __uib_w3__render_block('uib_calendar3', 'calendar3', 5);
        $variables['page']['content_bottom']['uib_area_twitter'] = __uib_w3__render_block('uib_area', 'area_twitter', 0);
        $variables['page']['content_bottom']['uib_area_testimonial'] = field_view_field('node', $variables['node'], 'field_uib_profiled_testimonial', array(
          'weight' => 5,
          'type' => 'entityreference_entity_view',
          'settings' => array('view_mode' => 'quote'),
          'label' => 'hidden',
        ));
        $variables['page']['content_bottom']['uib_area_exhibitions'] = __uib_w3__render_block('uib_calendar3', 'exhibitions3', 10);
        $variables['page']['content_bottom']['uib_area_newspage_recent_news'] = __uib_w3__render_block('views', 'recent_news-block', 15);
        $variables['page']['content_bottom']['field_uib_link_section'] = field_view_field('node', $variables['node'], 'field_uib_link_section', array(
          'label' => 'hidden',
          'weight' => 20,
        ));
        if (!empty($variables['page']['content_bottom']['field_uib_link_section'])) {
          $link_sections = array();
          $render_array = array();
          foreach($variables['page']['content_bottom']['field_uib_link_section'] as $key => $value) {
            if (is_numeric($key)) $link_sections[] = $value;
            else $render_array[$key] = $value;
          }
          if (count($link_sections) > 1) {
            $variables['page']['content_bottom']['field_uib_link_section'] = NULL;
            foreach ($link_sections as $key => $ls) {
              $variables['page']['content_bottom']['field_uib_link_section'][$key] = $render_array;
              $variables['page']['content_bottom']['field_uib_link_section']['#weight'] = 20;
              $variables['page']['content_bottom']['field_uib_link_section'][$key]['#weight'] = $key;
              $variables['page']['content_bottom']['field_uib_link_section'][$key][0] = $ls;
            }
          }
        }
      }
      /**
       * Include list of area employee.
       */
      $show_staff = @$variables['node']->field_uib_show_staff['und'][0]['value'];
      if ($show_staff) {
        $view = views_get_view('ansatte');
        $markup = "<h2>".$view->get_title() . " " . t('at') . " "
          . $variables['node']->title . "</h2>";
        $markup .= $view->preview('page_3', array( $variables['node']->nid));
        $variables['page']['footer_top']['field_uib_front_staff']['#markup']
          = "<div class=\"staff-view\">" . $markup . "</div>";
        $variables['page']['footer_top']['field_uib_front_staff']['#weight'] = 1200;
      }
      $variables['page']['content_bottom']['uib_area_jobbnorge'] = __uib_w3__render_block('uib_area','jobbnorge', 25);
      $variables['page']['content_bottom']['field_uib_feed'] = __uib_w3__render_block('uib_area', 'feed', 30);
      if (!empty($variables['page']['content_bottom']['field_uib_feed'])) {
         $variables['page']['content_bottom']['field_uib_feed'] = uib_w3__break_up_collection($variables['page']['content_bottom']['field_uib_feed'], 'uib_area_feed');
      }
      $variables['page']['footer']['social_media'] = field_view_field('node', $variables['node'], 'field_uib_social_media', array(
        'type' => 'socialmedia_formatter',
        'settings' => array('link' => TRUE),
        'weight' => '200',
      ));

      switch ($variables['node']->field_uib_area_type['und'][0]['value']) {
        case 'newspage':
          $variables['page']['content_top']['field_uib_profiled_article'] = field_view_field('node', $variables['node'], 'field_uib_profiled_article', array(
            'settings' => array('view_mode' => 'teaser'),
            'weight' => 40,
            'type' => 'entityreference_entity_view',
            'settings' => array('view_mode' => 'teaser'),
            'label' => 'hidden',
          ));
          break;
        case 'frontpage':
          if (!empty($variables['page']['content_top']['field_uib_primary_media'])) {
            if ($variables['language']->language == 'en') {
              $find_studies = __uib_w3__get_renderable_menu('menu-uib-find-studies-en');
              $prefix_text = variable_get('uib_find_studies_en');
              if (!$prefix_text) $prefix_text = 'Study at UiB?';
            }
            else {
              $find_studies = __uib_w3__get_renderable_menu('menu-uib-find-studies');
              $prefix_text = variable_get('uib_find_studies_nb');
              if (!$prefix_text) $prefix_text = 'Hva vil du studere ved UiB?';
            }
          }

          // Move everything in [content_top] to [content_top][top_banner]
          $top = $variables['page']['content_top'];
          $variables['page']['content_top'] = array(
            'top_banner' => array(
              '#type' => 'container',
              '#attributes' => array(
                'class' => array('top-banner'),
              ),
            ),
          );
          $variables['page']['content_top']['top_banner'] += $top;
          $variables['page']['content_top']['top_nav'] = array(
            '#type' => 'container',
            '#attributes' => array(
              'class' => array('top-nav'),
            ),
          );
          $variables['page']['content_top']['top_nav']['find_studies'] = array(
            '#type' => 'html_tag',
            '#value' => '<h3>' . $prefix_text . '</h3>' . render($find_studies),
            '#weight' => 200,
            '#attributes' => array('class' => array('uib-find-studies')),
            '#tag' => 'nav',
          );

          $variables['page']['content_top']['top_nav']['field_uib_profiled_message'] = field_view_field('node', $variables['node'], 'field_uib_profiled_message', array(
            'weight' => 400,
            'type' => 'entityreference_entity_view',
            'settings' => array('view_mode' => 'front_page_icons'),
            'label' => 'hidden',
          ));

          break;
      }
      break;

    case isset($variables['node']) && $variables['node']->type == 'uib_study':
      global $language;
      $study_type = $variables['node']->field_uib_study_type['und'][0]['value'];
      $variables['page']['content_bottom']['field_uib_study_relation'] =
        field_view_field(
          'node',
          $variables['node'],
          'field_uib_study_relation', array(
            'weight' => '30',
            'type' => 'entityreference_entity_view',
            'settings' => array('view_mode' => 'short_teaser', 'hide_admin_links' => TRUE),
          )
        );

      $tmpVar = field_view_field('node',$variables['node'],'field_uib_related_content_label');
      if (!empty($tmpVar)) {
        $variables['page']['content_bottom']['field_uib_study_relation']['#label_display'] = 'display';
        $variables['page']['content_bottom']['field_uib_study_relation']['#title'] = $tmpVar[0]['#markup'];
      }

      if (!empty($variables['page']['content_bottom']['field_uib_study_relation']['#items'])) {
        foreach ($variables['page']['content_bottom']['field_uib_study_relation']['#items'] as $k => $e) {
          if (
            $e['entity']->language != 'und' &&
            $e['entity']->language != $variables['language']->language
          ) {
            unset($variables['page']['content_bottom']['field_uib_study_relation']['#items'][$k]);
          }
        }
      }

      unset($variables['page']['content']['system_main']['nodes']
        [$variables['node']->nid]['field_uib_main_media'][0]['#contextual_links']);

      if (uib_study__use_tabs($study_type)) {
        drupal_add_library('system' , 'ui.tabs');
        // set menu to appear as tabs
        $jq = uib_w3__tabsScript();
        drupal_add_js($jq, 'inline');

        // Script to enable dropdown instead of tabs on mobile phones
        $js = <<<SCRIPT
(function ($) {
  $(document).ready(function ($) {
    var hash = $('.ui-tabs li.ui-tabs-active > a').attr('href').substr(1);
    $('#tabs-dropdown-menu-id').val(hash);
    $('#tabs-dropdown-menu-id').change(function (event){
      var id = $(this).find('option:selected').val();
      var index = $('.ui-tabs-nav a[href="#' + id + '"]').parent().index();
      $('.ui-tabs').tabs('option', 'active', index);
    });
  });
})(jQuery);
SCRIPT;
        drupal_add_js($js, 'inline');
      }
      if (!uib_study__programme_use_w3_data($study_type)) {
        if ($variables['node']->field_uib_study_type['und'][0]['value'] == 'specialization') {
          $variables['node']->field_uib_study_category['und'][0]['value'] = 'studieretning';
        }
        $variables['page']['content_top']['field_uib_study_type'] =
          field_view_field('node', $variables['node'], 'field_uib_study_category',
            array(
          'label' => 'hidden',
          'weight' => -50,
        ));
        $category = $variables['node']->field_uib_study_category['und'][0]['value'];
        $name = "field:field_uib_study_category:#allowed_values:" . $category;
        $variables['page']['content_top']['field_uib_study_type'][0]['#markup'] =
        uib_study__get_study_kicker($category, $name);
      }
      $lang = $language->language;
      $o_lang = $lang == 'nb' ? 'en' : 'nb';
      $study_title = '';
      if (isset($variables['node']->field_uib_study_title[$lang])) $study_title = $variables['node']->field_uib_study_title[$lang][0]['safe_value'];
      elseif (isset($variables['node']->field_uib_study_title[$o_lang])) $study_title = $variables['node']->field_uib_study_title[$o_lang][0]['safe_value'];
      elseif (isset($variables['node']->field_uib_study_title['und'])) $study_title = $variables['node']->field_uib_study_title[$lang][0]['safe_value'];
      $variables['page']['content_top']['title'] = array(
        '#type' => 'html_tag',
        '#tag' => 'h1',
        '#value' => $study_title,
        '#weight' => -45,
      );
      if (uib_study__programme_use_w3_data($study_type)) {
        $variables['page']['content_top']['study_lead'] = field_view_field('node', $variables['node'], 'field_uib_study_lead', array(
          'label' => 'hidden',
          'weight' => '30',
        ));
      }
      if (uib_study__programme_use_w3_data($study_type)) {
        $variables['page']['content_top']['study_facts'] = __uib_w3__render_block('uib_study', 'study_facts', 40);
      }
      else {
        $variables['page']['content_top']['study_facts'] = __uib_w3__render_block('uib_study', 'study_facts_2', 40);
        $variables['page']['content']['study_content'] = __uib_w3__render_block('uib_study', 'study_content', 0);
      }
      unset($variables['page']['content']['study_content']['uib_study_study_content']['#contextual_links']);

      if ($variables['node']->field_uib_study_type['und'][0]['value'] == 'exchange' && (!in_array($variables['node']->field_uib_study_category['und'][0]['value'], array('mou', 'forskningsavtale')))) {
        $variables['page']['content']['study_facts_exchange'] = __uib_w3__render_block('uib_study', 'study_facts_exchange', 15);
      }
      if ($variables['node']->field_uib_study_type['und'][0]['value'] != 'exchange') {
        $variables['page']['content_bottom']['study_related'] = __uib_w3__render_block('uib_study', 'study_related', 15);
      }
      if ($variables['node']->field_uib_study_category['und'][0]['value'] == 'evu') {
        $variables['page']['content']['study_evu_available'] = __uib_w3__render_block('uib_study', 'study_evu', 10);
      }
      if ($variables['node']->field_uib_study_type['und'][0]['value'] == 'course') {
        $variables['page']['content']['study_contact'] = __uib_w3__render_block('uib_study', 'study_contact', 5);
        global $language;
        $belongs_to = uib_study__area($variables['node'], $language->language);
        if ($belongs_to) {
          $variables['page']['content']['study_belongs_to'] = array(
            '#type' => 'html_tag',
            '#tag' => 'div',
            '#value' => $belongs_to,
            '#weight' => 20,
            '#attributes' => array('class' => array('uib-study-belongs-to')),
          );
        }

        $variables['page']['content']['study_toggle'] = __uib_w3__render_block('uib_study', 'study_semester_toggle', 10);
        if ($variables['node']->field_uib_study_category['und'][0]['value'] == 'phdkurs') {
          $variables['page']['content']['study_period'] = __uib_w3__render_block('uib_study', 'study_period_phd', 25);
        }
        $variables['page']['content']['study_reading_lists'] = __uib_w3__render_block('uib_study', 'study_reading_lists', 50);
        if (variable_get('uib_show_exam_info')) {
          $variables['page']['content']['study_exam_info'] = __uib_w3__render_block('uib_study', 'study_exam_info', 8);
        }
      }
      if (in_array($variables['node']->field_uib_study_type['und'][0]['value'], array('program', 'specialization'))) {
        if (!uib_study__programme_use_w3_data($variables['node']->field_uib_study_type['und'][0]['value'])) {
          $variables['page']['content']['study_image'] = field_view_field('node', $variables['node'], 'field_uib_study_image', array(
            'type' => 'file_rendered',
            'settings' => array('file_view_mode' => 'content_sidebar'),
            'label' => 'hidden',
            'weight' => 3,
          ));
          $variables['page']['content']['promocode'] = __uib_w3__render_block('uib_study', 'study_email_offers', 4);
          $variables['page']['content']['study_more_information'] = __uib_w3__render_block('uib_study', 'study_more_information', 6);
        }
        $link_section = $language->language == 'en' ? '_2' : '';
        $variables['page']['content_bottom']['field_uib_link_section'] = field_view_field('node', $variables['node'], 'field_uib_link_section' . $link_section, array(
          'label' => 'hidden',
          'weight' => 0,
        ));
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
        if (!in_array($variables['node']->field_uib_study_category['und'][0]['value'], array('mou', 'forskningsavtale'))) {
          $variables['page']['content_bottom']['study_static_links'] = __uib_w3__render_block('uib_study', 'study_static_links', 0);
        }
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
      drupal_add_library('system' , 'ui.tabs');
      // set menu to appear as tabs
      $jq = uib_w3__tabsScript();
      drupal_add_js($jq, 'inline');
      if (isset($variables['page']['content']['system_main']['user_vcard_link'])) {
        $user_vcard = $variables['page']['content']['system_main']['user_vcard_link']['#markup'];
        $user_login = '';
        if (isset($variables['page']['content']['system_main']['user_login_incard_link']))$user_login = $variables['page']['content']['system_main']['user_login_incard_link']['#markup'];
        $variables['page']['content_top']['vcard_and_login'] = array(
          '#type' => 'html_tag',
          '#tag' => 'div',
          '#value' => $user_vcard . ' | ' . $user_login,
          '#weight' => -50,
          '#attributes' => array('class' => array('vcard-and-login')),
        );
      }
      $variables['page']['content_top']['user_picture'] = $variables['page']['content']['system_main']['user_picture'];
      $variables['page']['content_top']['user_picture']['#weight'] = -40;
      $variables['page']['content_top']['user_picture']['#prefix'] = '<div class="user-media">';
      $first_name = $variables['page']['content']['system_main']['field_uib_first_name'][0]['#markup'];
      $last_name = $variables['page']['content']['system_main']['field_uib_last_name'][0]['#markup'];
      $variables['page']['content_top']['user_name'] = array(
        '#type' => 'html_tag',
        '#tag' => 'h1',
        '#value' => $first_name . ' ' . $last_name,
        '#weight' => -30,
      );
      $variables['page']['content_top']['user_name']['#prefix'] = '<div class="user-media-content">';
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
      if (isset($variables['page']['content']['system_main']['field_uib_user_url'])) {
        $variables['page']['content_top']['user_homepage'] = $variables['page']['content']['system_main']['field_uib_user_url'];
        $variables['page']['content_top']['user_homepage']['#weight'] = 0;
      }
      if (isset($variables['page']['content']['system_main']['field_uib_user_cv'])) {
        $variables['page']['content_top']['user_cv'] = $variables['page']['content']['system_main']['field_uib_user_cv'];
        $variables['page']['content_top']['user_cv']['#prefix'] = '<div class="field field-name-field-uib-user-cv field-type-file field-label-hidden"><div class="field-items"><div class="field-item even">';
        $variables['page']['content_top']['user_cv']['#suffix'] = '</div></div></div>';
        $variables['page']['content_top']['user_cv']['#weight'] = 5;
      }
      if (isset($variables['page']['content']['system_main']['field_uib_user_social_media'])) {
        $variables['page']['content_top']['social_media'] = $variables['page']['content']['system_main']['field_uib_user_social_media'];
        $variables['page']['content_top']['social_media']['#weight'] = 10;
      }
      $items = array();
      $account = $variables['page']['content']['system_main']['#account'];
      if (!empty($account->mail)) {
        $email = '<span class="user-contact__label">' . t('E-mail') . '</span>';
        $email .= '<span class="user-contact__value"><a href="mailto:' . $account->mail . '">' . $account->mail . '</a></span>';
        $items[] = $email;
      }
      $numbers = array();
      if (!empty($account->field_uib_phone)) {
        foreach ($account->field_uib_phone['und'] as $number) {
          $numbers[] = $number['value'];
        }
        if (!empty($numbers)) {
          $numbers = '<span class="phone-number">' . implode('</span><span class="phone-number">', $numbers) . '</span>';
          $phone = '<span class="user-contact__label">' . t('Phone') . '</span>';
          $phone .= '<span class="user-contact__value">' . $numbers . '</span>';
          $items[] = $phone;
        }
      }
      $variables['page']['content']['system_main']['visit_address']['#label_display'] = 'hidden';
      $visit_address = '<span class="user-contact__label">' . t('Visitor Address') . '</span>';
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
        '#attributes' => array(),
      );
      $variables['page']['content_top']['user_contact_info']['#prefix'] = '</div></div><div class="user-contact-info">';
      $variables['page']['content_top']['user_contact_info']['#suffix'] = '</div>';
      if (isset($variables['page']['content']['system_main']['field_uib_user_competence'])) {
        $variables['page']['content']['field_uib_user_competence'] = $variables['page']['content']['system_main']['field_uib_user_competence'];
      }
      $variables['page']['content_bottom']['user_twitter'] = __uib_w3__render_block('uib_user', 'twitter', 10);
      $variables['page']['content_bottom']['user_feed'] = __uib_w3__render_block('uib_user', 'feed', 20);
      if (isset($variables['page']['content']['system_main']['field_uib_user_docs'])) {
        $variables['page']['content_bottom']['field_uib_user_docs'] = $variables['page']['content']['system_main']['field_uib_user_docs'];
      }

      if (isset($variables['page']['content']['system_main']['field_uib_user_relation'])
        && $variables['language']->language == $variables['page']['content']['system_main']['field_uib_user_relation']['#language']) {
          $variables['page']['content_bottom']['field_uib_user_relation'] = $variables['page']['content']['system_main']['field_uib_user_relation'];
          $variables['page']['content_bottom']['field_uib_user_relation']['#weight'] = '11';
      }
      $unset_variables = array(
        'user_vcard_link',
        'user_login_incard_link',
        'user_picture',
        'field_uib_first_name',
        'field_uib_last_name',
        'field_uib_position',
        'field_uib_user_ou',
        'field_uib_user_url',
        'field_uib_user_cv',
        'field_uib_user_social_media',
        'field_uib_user_feed',
        'field_uib_phone',
        'user_email',
        'field_uib_user_competence',
        'field_uib_user_docs',
        'field_uib_user_relation',
        'selected_publications',
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
    case (isset($variables['node']) && $variables['node']->type == 'uib_views_page'):
      $title = current((array)field_get_items('node', $variables['node'],
          'field_uib_node_title'));
      if (isset($title['value'])) {
        $title = $title['value'];
        drupal_set_title($title);
      }
      break;
  }
  if(isset($variables['node']) && ($variables['node']->nid == '73684' || $variables['node']->nid == '73685')) {
    $variables['page']['content_top']['field_uib_profiled_message'] = field_view_field('node', $variables['node'], 'field_uib_profiled_message', array(
      'settings' => array('view_mode' => 'teaser'),
      'weight' => 4,
      'type' => 'entityreference_entity_view',
      'settings' => array('view_mode' => 'teaser'),
      'label' => 'hidden',
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
    'uib_study_study_related',
    'uib_study_study_facts',
    'uib_study_study_facts_2',
    'uib_study_study_plan',
    'uib_study_study_contact',
    'uib_study_study_semester_toggle',
    'uib_study_study_testimonial',
    'uib_study_study_evu',
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
  if (__uib_w3__empty_region($variables['page']['content_bottom'])) $variables['page']['content_bottom'] = array();
  if (__uib_w3__empty_region($variables['page']['footer_top'])) $variables['page']['footer_top'] = array();

  if(variable_get('uib_hubro_chatbot') && isset($variables['node'])){
    if ($variables['node']->nid == 17507 || (isset($variables['node']->field_uib_area['und'][0]['target_id']) && $variables['node']->field_uib_area['und'][0]['target_id'] == 17507)) {
      drupal_add_js('http' . (isset($_SERVER['HTTPS']) ? 's' : '').'://'. $_SERVER['HTTP_HOST'] . '/watsonbot/public/js/addchatbot.js');
    }
  }
}

/**
 * Implements hook_page_alter().
 */
function uib_w3_page_alter(&$page) {
  global $user;
  if (in_array('anonymous user', $user->roles)) {
    $page['#post_render'][] = 'uib_w3_gt_callback';
  }
}

/**
 * Implements callback_post_render()
 */
function uib_w3_gt_callback(&$children, $elements) {
  $gt = '<!-- Google Tag Manager (noscript) -->
<noscript><iframe src="https://www.googletagmanager.com/ns.html?id=GTM-KLPBXPW"
height="0" width="0" style="display:none;visibility:hidden"></iframe></noscript>
<!-- End Google Tag Manager (noscript) -->';
  $children = preg_replace('@<body[^>]*>@', '$0' . $gt, $children, 1);
  return $children;
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
    uib_w3__add_image_caption(
      $variables['content']['field_uib_media'],
      $variables['node'],
      'field_uib_imagecaptions2'
    );
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
      if ($variables['field_uib_area_type']['und'][0]['value'] != 'newspage') {
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
      if (isset($variables['content']['field_uib_date'][0]['#markup'])) {
        $variables['content']['field_uib_date'][0]['#markup'] =
          str_replace(
            array(' to ', ' til '),
            '–',
            $variables['content']['field_uib_date'][0]['#markup']
          );
      }
      if (isset($variables['content']['field_uib_feature_text'])) {
        $variables['content']['field_uib_feature_text']['#attached']['js'][] = array(
          'type' => 'file',
          'data' => drupal_get_path('theme', 'uib_w3') . '/js/feature-text.js',
          'scope' => 'footer',
          'group' => JS_THEME,
        );
        $variables['content']['field_uib_feature_text']['#attached']['js'][] = array(
          'type' => 'external',
          'data' => 'https://platform.twitter.com/widgets.js',
          'scope' => 'footer',
          'group' => JS_THEME,
        );
      }
      $variables['content']['field_uib_registration_link']['#label_display'] = 'hidden';
      $variables['content']['field_uib_location']['#label_display'] = 'hidden';
      $variables['content']['field_uib_event_type']['#label_display'] = 'hidden';
      $variables['content']['field_uib_contacts']['#label_display'] = 'hidden';
      $article_info = __uib_w3__article_info($variables['node']);
      if (isset($variables['content']['field_uib_text'])) {
        $variables['content']['field_uib_text'][0]['#markup'] = __uib_w3__add_table_wrapper($variables['content']['field_uib_text'][0]['#markup']);
        if ($variables['field_uib_article_type']['und'][0]['value'] == 'event' || $variables['field_uib_article_type']['und'][0]['value'] == 'infopage') {
          $variables['content']['field_uib_text'][0]['#markup'] = $variables['content']['field_uib_text'][0]['#markup'] . render($article_info);
        } else {
          $variables['content']['field_uib_text'][0]['#markup'] =  render($article_info) . $variables['content']['field_uib_text'][0]['#markup'];
        }
      }
      else {
        $variables['content']['article_info'] = $article_info;
      }
      if ($variables['field_uib_article_type']['und'][0]['value'] == 'phd_press_release') {
        $media_link = __uib_w3__download_image_link($variables['content']['field_uib_media'][0]['#file']);
        $media_markup = render($variables['content']['field_uib_media']);
        $media_markup = substr($media_markup, 0, -18);
        $media_markup .= $media_link . '</div></div></div>';
        $variables['content']['field_uib_media'] = array(
          '#weight' => 28,
          '#markup' => $media_markup,
        );
      }
      if ($variables['field_uib_article_type']['und'][0]['value'] == 'infopage') {
        $variables['content']['field_uib_article_twitter'] = __uib_w3__render_block('uib_article','twitter',0);
      }
    }
    if ($variables['type'] == 'uib_study') {
      $study_type = $variables['field_uib_study_type']['und'][0]['value'];
      if (uib_study__programme_use_w3_data($study_type)) {
        $variables['content']['study_content'] = __uib_w3__render_block('uib_study', 'study_content_w3', 0);
      }
    }
    $hide_vars = array(
      'field_uib_byline',
      'field_uib_kicker',
      'field_uib_lead',
      'field_uib_main_media',
      'field_uib_main_media_en',
      'field_uib_primary_media',
      'field_uib_primary_text',
      'field_uib_secondary_text',
      'field_uib_social_media',
      'field_uib_relation',
      'field_uib_link_section',
      'field_uib_profiled_testimonial',
      'field_uib_links',
      'field_uib_links_label',
      'field_uib_related_persons',
      'field_related_persons_label',
      'field_uib_related_content_label',
      'field_uib_files',
      'field_uib_study_category',
      'field_uib_study_image',
      'field_uib_study_relation',
      'field_uib_important_message',
      'field_uib_visitor_info',
      'field_uib_contact_info',
      'field_uib_documents_label',
      'field_uib_study_text',
      'field_uib_new_student',
      'field_uib_study_lead',
    );
    foreach ($hide_vars as $var) {
      hide($variables['content'][$var]);
    }
  }
  else {
    // Add class no-kicker to related content without a kicker
    if (!isset($variables['field_uib_kicker']) || empty($variables['field_uib_kicker'][0]['value'])) $variables['classes_array'][] = 'no-kicker';
    if ($variables['type'] == 'uib_article' && $variables['view_mode'] == 'full') {
      uib_w3__add_image_caption(
        $variables['content']['field_uib_media'],
        $variables['node'],
        'field_uib_imagecaptions2'
      );
    }
    if ($variables['type'] == 'uib_testimonial' && $variables['view_mode'] == 'teaser') {
      if (count($variables['field_uib_media']) > 1) {
        $variables['content']['field_uib_media'] = __uib_w3__keep_first_main_media($variables['content']['field_uib_media']);
      }
      $variables['theme_hook_suggestions'][] = 'node__testimonial__teaser';
    }
    if ($variables['type'] == 'uib_testimonial' && $variables['view_mode'] == 'quote') {
      if (count($variables['field_uib_media']) > 1) {
        $variables['content']['field_uib_media'] = __uib_w3__keep_first_main_media($variables['content']['field_uib_media']);
      }
      $variables['theme_hook_suggestions'][] = 'node__testimonial__quote';
    }
    if ($variables['type'] == 'uib_article' && $variables['view_mode'] == 'teaser') {
      if (isset($variables['content']['field_uib_lead'][0]['#markup'])) {
        $variables['content']['field_uib_lead'][0]['#markup'] =
        truncate_utf8($variables['content']['field_uib_lead'][0]['#markup'], 303, TRUE, TRUE);
      }
      if (empty($variables['field_uib_main_media']) && !empty($variables['field_uib_media'])) {
        $variables['theme_hook_suggestions'][] = 'node__article__small_image_teaser';
        $uib_media = field_view_field('node', $variables['node'], 'field_uib_media', array(
          'type' => 'file_rendered',
          'settings' => array('file_view_mode' => 'wide_thumbnail'),
          'label' => 'hidden',
          'weight' => 3,
        ));
        $uib_media['#field_name'] = 'field_uib_main_media';
        $variables['content']['field_uib_main_media'] = $uib_media;
        $variables['content']['field_uib_main_media'][0] = array();
        $variables['content']['field_uib_main_media'][0]['#markup'] = render($uib_media[0]);
        unset($variables['content']['field_uib_main_media'][0]['field_uib_copyright']);
        unset($variables['content']['field_uib_main_media'][0]['field_uib_owner']);
        unset($variables['content']['field_uib_main_media'][0]['field_uib_description']);
      } else {
        $variables['theme_hook_suggestions'][] = 'node__article__teaser';
      }
      if (count($variables['content']['field_uib_main_media']) > 1) {
        $variables['content']['field_uib_main_media'] = __uib_w3__keep_first_main_media($variables['content']['field_uib_main_media']);
      }
      if( count($variables['field_uib_event_type']) &&
        isset($variables['field_uib_date']['und'][0]['value'])){
        $variables['content']['field_uib_main_media'][0]['#markup'].=
          uib_calendar3__get_calendar_card_render_array(
          $variables['field_uib_date']['und'][0]['value'] . 'Z');
      }
      if (!empty($variables['field_uib_main_media_teaser'])) {
        $uib_media = field_view_field('node', $variables['node'], 'field_uib_main_media_teaser', array(
          'type' => 'file_rendered',
          'settings' => array('file_view_mode' => 'wide_thumbnail'),
          'label' => 'hidden',
          'weight' => 3,
        ));
        $uib_media['#field_name'] = 'field_uib_main_media';
        $variables['content']['field_uib_main_media'] = $uib_media;
        $variables['content']['field_uib_main_media'][0] = array();
        $variables['content']['field_uib_main_media'][0]['#markup'] = render($uib_media[0]);
      }
    }
    if ($variables['type'] == 'uib_article' && $variables['view_mode'] == 'short_teaser') {
      if (isset($variables['content']['field_uib_lead'][0]['#markup'])) {
        $variables['content']['field_uib_lead'][0]['#markup'] =
          truncate_utf8($variables['content']['field_uib_lead'][0]['#markup'], 303, TRUE, TRUE);
      }
      if (empty($variables['field_uib_main_media']) && !empty($variables['field_uib_media'])) {
        $uib_media = field_view_field('node', $variables['node'], 'field_uib_media', array(
          'type' => 'file_rendered',
          'settings' => array('file_view_mode' => 'wide_thumbnail'),
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
      if (!empty($variables['field_uib_main_media_teaser'])) {
        $uib_media = field_view_field('node', $variables['node'], 'field_uib_main_media_teaser', array(
          'type' => 'file_rendered',
          'settings' => array('file_view_mode' => 'wide_thumbnail'),
          'label' => 'hidden',
          'weight' => 3,
        ));
        $uib_media['#field_name'] = 'field_uib_main_media';
        $variables['content']['field_uib_main_media'] = $uib_media;
        $variables['content']['field_uib_main_media'][0] = array();
        $variables['content']['field_uib_main_media'][0]['#markup'] = render($uib_media[0]);
      }
      $variables['theme_hook_suggestions'][] = 'node__article__short_teaser';
    }
    if ($variables['type'] == 'uib_external_content' && $variables['view_mode'] == 'teaser') {
      $variables['theme_hook_suggestions'][] = 'node__external_content__teaser';
      $variables['title'] =
        isset($variables['field_uib_links']['und'][0]['title']) ?
          $variables['field_uib_links']['und'][0]['title'] :
          $variables['title'];
      $variables['content']['field_uib_main_media'] = field_view_field('node', $variables['node'], 'field_uib_media', array(
        'type' => 'file_rendered',
        'settings' => array('file_view_mode' => 'wide_thumbnail'),
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
      $variables['content']['field_uib_lead'][0]['#markup'] = truncate_utf8($variables['content']['field_uib_lead'][0]['#markup'], 303, TRUE, TRUE);
    }
    if ($variables['type'] == 'uib_external_content' && $variables['view_mode'] == 'short_teaser') {
      if (isset($variables['content']['field_uib_teaser'][0]['#markup'])) {
        $variables['content']['field_uib_teaser'][0]['#markup'] = truncate_utf8($variables['content']['field_uib_teaser'][0]['#markup'], 303, TRUE, TRUE);
      }
      $variables['theme_hook_suggestions'][] = 'node__external_content__short_teaser';

    }
    if ($variables['type'] == 'uib_external_content' && $variables['view_mode'] == 'front_page_icons') {
      $variables['theme_hook_suggestions'][] = 'node__external_content__front_page_icons';
      $variables['title'] =
        isset($variables['field_uib_links'][0]['title']) ?
          $variables['field_uib_links'][0]['title'] :
          $variables['title'];

      $variables['content']['field_uib_media'] = field_view_field(
        'node',
        $variables['node'],
        'field_uib_media',
        'default'
      );
    }
    if ($variables['type'] == 'uib_testimonial' && $variables['view_mode'] == 'short_teaser') {
      $variables['theme_hook_suggestions'][] = 'node__testimonial__short_teaser';
    }
    if ($variables['type'] == 'uib_study' && $variables['view_mode'] == 'short_teaser') {
      $variables['theme_hook_suggestions'][] = 'node__uib_study__short_teaser';
    }
    if ($variables['type'] == 'uib_content_list' && $variables['view_mode'] == 'short_teaser') {
      $image = array(
        'path' => drupal_get_path('theme', 'uib_w3') . '/images/contentlist-icon.png',
        'alt' => t('Content list'),
      );
      $variables['content']['field_uib_main_media'][0]['#markup'] = theme('image', $image);
      $variables['content']['field_uib_main_media']['#prefix'] = '<div class="field-name-field-uib-media">';
      $variables['content']['field_uib_main_media']['#suffix'] = '</div>';
      $variables['theme_hook_suggestions'][] = 'node__content_list__short_teaser';
    }
    if ($variables['type'] == 'area' && $variables['view_mode'] == 'short_teaser') {
      hide($variables['content']['language']);
      $variables['content']['field_uib_media'] = field_view_field('node', $variables['node'], 'field_uib_primary_media', array(
        'label' => 'hidden',
        'type' => 'file_rendered',
        'settings' => array('file_view_mode' => 'wide_thumbnail'),
        'weight' => 3,
      ));
      $variables['content']['field_uib_teaser'] = field_view_field('node', $variables['node'], 'field_uib_search_description', array(
        'label' => 'hidden',
        'weight' => 5,
      ));
      if (!empty($variables['content']['field_uib_teaser'])) {
        $variables['content']['field_uib_teaser'][0]['#markup'] = truncate_utf8($variables['content']['field_uib_teaser'][0]['#markup'], 303, TRUE, TRUE);
      }
      $variables['theme_hook_suggestions'][] = 'node__area__short_teaser';
    }
    /**
     * Replace teaser URL for kmd to external URL given in kmd import
     **/
    if (isset($variables['field_uib_kmd_data']['und'][0]['value'])) {
      global $base_url;
      global $language;
      $kmd_href = json_decode($variables['field_uib_kmd_data']['und'][0]['value'])->href;
      $variables['node_url'] = $kmd_href;
      $title = urlencode(strtolower(preg_replace(array('/[^a-zA-Z0-9 æøå\/]/', '/[ -]+/', '/^-|-$/','/-in-/','/-for-/'),array('', '-', '','-','-'), html_entity_decode($variables['title'], ENT_QUOTES))));
      $ref_url = $base_url .'/'. $language->language .'/kmd/'. $variables['nid'] . '/' . $title;
      if(isset($variables['content']['field_uib_main_media'][0]['#markup'])) {
        $variables['content']['field_uib_main_media'][0]['#markup'] = str_replace($ref_url, $kmd_href, $variables['content']['field_uib_main_media'][0]['#markup']);
      }
    }
  }
  if($variables['view_mode']=='short_teaser'){
    unset($variables['content']['links']);
    unset($variables['content']['field_uib_main_media']['#items'][0]['field_file_image_title_text']);
    unset($variables['content']['field_uib_main_media'][0]['#contextual_links']);
    unset($variables['content']['field_uib_main_media'][0]['links']);
    unset($variables['content']['field_uib_media']['#items'][0]['field_file_image_title_text']);
    unset($variables['content']['field_uib_media'][0]['#contextual_links']);
    unset($variables['content']['field_uib_media'][0]['links']);
  }
}
/**
 * Implementing theme_field()
 */
function uib_w3_field($variables) {
  $output = '';
  if (!$variables['label_hidden']) {
    $output .= '<div ' . $variables['title_attributes'] . '>' . $variables['label'] . '&nbsp;</div>';
  }
  $output .= '<div ' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $output .= '<div ' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';
  return $output;
}
/**
 * Implementing hook_preprocess_field()
 */
function uib_w3_preprocess_field(&$vars) {
  $name = $vars['element']['#field_name'];
  $bundle = $vars['element']['#bundle'];
  $elements_bundle = &$vars['element'][0]['#bundle'];
  $mode = $vars['element']['#view_mode'];
  $elements_mode = &$vars['element'][0]['#view_mode'];
  $classes = &$vars['classes_array'];
  $title_classes = &$vars['title_attributes_array']['class'];
  $content_classes = &$vars['content_attributes_array']['class'];
  $item_classes = array();

  $classes[] = 'field-wrapper';
  $title_classes[] = 'field-label';
  $content_classes[] = 'field-items';
  $item_classes[] = 'field-item';

  switch($name) {
    case 'field_uib_main_media':
      if (in_array($elements_mode, array('content_main', 'feature_article_full_width')) && in_array($elements_bundle, array('image', 'video'))) {
        if (count($vars['items']) > 1) {
          $auto_height = '16:10';
          foreach ($vars['items'] as $item) {
            if ($item['#bundle'] != 'video') $auto_height = 'false';
          }
          $content_classes[] = 'cycle-slideshow';
          $vars['content_attributes_array']['data-cycle-slides'] = '> div';
          $vars['content_attributes_array']['data-cycle-fx'] = 'scrollHorz';
          $vars['content_attributes_array']['data-cycle-swipe'] = 'true';
          $vars['content_attributes_array']['data-cycle-swipe-fx'] = 'scrollHorz';
          $vars['content_attributes_array']['data-cycle-timeout'] = '0';
          $vars['content_attributes_array']['data-cycle-prev'] = '.uib-slideshow__nav--prev';
          $vars['content_attributes_array']['data-cycle-next'] = '.uib-slideshow__nav--next';
          $vars['content_attributes_array']['data-cycle-auto-height'] = $auto_height;
          $vars['content_attributes_array']['data-cycle-log'] = 'false';
        }
        elseif (!empty($vars['items'][0]['field_uib_description']) && in_array($elements_bundle, array('image', 'video'))) {
          $classes[] = 'description';
        }
      }
      break;
    case 'field_uib_user_relation':
      $vars['classes_array'][] = 'field-name-field-uib-relation';
      break;
  }

  foreach ($vars['items'] as $delta => $item) {
    $vars['item_attributes_array'][$delta]['class'] = $item_classes;
    $vars['item_attributes_array'][$delta]['class'][] = $delta % 2 ? 'even' : 'odd';
    if ($name == 'field_uib_main_media' && count($vars['items']) > 1) {
      $imagecounter = array(
        '#type' => 'html_tag',
        '#tag' => 'div',
        '#attributes' => array('class' => 'uib-slideshow__info--counter'),
        '#value' => $delta + 1 . '/' . count($vars['items']),
        '#weight' => 50,
      );
      $vars['items'][$delta]['imagecounter'] = $imagecounter;
      $vars['items'][$delta]['#group_children']['imagecounter'] = 'group_media_info';
    }
  }
}

/**
 * Implementing hook_preprocess_block()
 */
function uib_w3_preprocess_block(&$vars) {
  if (in_array('block__uib_area__feed', $vars['theme_hook_suggestions'])) {
    if (empty($vars['elements']['#children'])) {
      $vars['theme_hook_suggestions'][] = 'block__uib_area__feed__empty';
    }
  }
}

/**
 * Implements hook_language_switch_links_alter
 */
function uib_w3_language_switch_links_alter(array &$links, $type, $path) {
  foreach ($links as $langcode => &$link) {
    unset($links[$langcode]['attributes']['xml:lang']);
    $link['attributes']['lang'] = $langcode;
  }
}

/**
 * Function returning render array for article info
 */
function __uib_w3__article_info(&$node) {
  $date_info = '<span class="uib-date-info">';
  $updated_date = date('d.m.Y' , $node->changed);
  if ($node->status == 1) {
    $published = $node->created;
    $t = field_get_items('node', $node, 'field_uib_published_timestamp');
    if ($t) {
      $published = $t[0]['value'];
    }
    $published_date = date('d.m.Y', $published);
    if ($published_date == $updated_date) {
      $date_info .= t('Published') . ': ' . $published_date;
    }
    else {
      $date_info .= t('Updated') . ': ' . $updated_date;
      $date_info .= ' (' . t('First published') . ': ' . $published_date . ')';
    }
  }
  else {
    $date_info .= '<span style="color:#cf3c3a;">' . t('Unpublished') . '</span>';
    $date_info .= ' (' . t('Last updated') . ': ' . $updated_date . ')';
  }
  $date_info .= '</span>';

  $article_info = array(
    '#type' => 'markup',
    '#markup' => '<div class="article-info">',
    '#weight' => '0',
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
  $authorarray = array_merge((array)@$node->field_uib_byline['und'], (array)@$node->field_uib_external_author['und']);
  if (count($authorarray)) {
    $tmp = array();
    foreach ($authorarray as $key => $b) {
      if(@$b['target_id']){
        $user = $b['entity'];
        $name = $user->field_uib_first_name['und'][0]['safe_value'] . ' ' . $user->field_uib_last_name['und'][0]['safe_value'];
        if ($b['access']) {
          $url = drupal_get_path_alias('user/' . $b['target_id']);
          $tmp[] = l($name, $url);
        }
        else {
          $tmp[] = $name;
        }
      }
      else{
        $ext_author = isset($b['safe_value']) ? $b['safe_value'] : $b['value'];
        $tmp[] = '<span class="ext_auth">' . $ext_author . '</span>';
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
  if (empty($block_content)) return array();
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
  if (count($breadcrumb) < 2) return FALSE;
  $output = '<nav class="breadcrumb" role="navigation"><ol>';
  foreach ($breadcrumb as $key => $crumb) {
    if (strpos($crumb, 'http:#') || ($key == count($breadcrumb)-1 && count($breadcrumb) != 1)) $crumb = strip_tags($crumb);
    if (!strstr($crumb, 'node/all')) {
      $output .= '<li>' . urldecode($crumb) . ' </li>';
    }
  }
  $output .= '</ol></nav>';
  return $output;
}
/**
 * Verify empty regions
 *
 * @param $region
 *
 * @return boolean
 */
function __uib_w3__empty_region($region) {
  foreach ($region as $r) {
    if (!empty($r)) return FALSE;
  }
  return TRUE;
}

/**
 * Overrides theme_menu_link
 *
 * @param $variables
 *   An array containing a menu link
 *
 * @return
 *   the overriden markup
 */
function uib_w3_menu_link($variables) {
  global $user;
  $level_user = in_array('superbruker', $user->roles) || in_array('innholdsprodusent', $user->roles) || in_array('level 3', $user->roles) ? true : false;
  if (strstr($variables['theme_hook_original'], 'menu_link__menu_area_')) {
    if ((!empty($variables['element']['#below']) || $variables['element']['#href'] != 'http:#') || $level_user) {
      $link = str_replace('http:#', '#', theme_menu_link($variables));
      return $link;
    }
  }
  elseif (strstr($variables['theme_hook_original'], 'menu_link__menu_global_menu_2')
    || strstr($variables['theme_hook_original'], 'menu_link__menu_global_menu_no_2')) {
    if ($variables['element']['#href'] == 'http:#') {
      return str_replace('http:#', '#', theme_menu_link($variables));
    }
    else {
      return theme_menu_link($variables);
    }
  }
  else {
    return theme_menu_link($variables);
  }
}

function __uib_w3__download_image_link($file) {
  $uri = file_entity_download_uri($file);
  $link_text = t('Download press photo');
  $image_link = l($link_text, $uri['path'], $uri['options']);
  $output = '<div class="image--download-original clearfix">' . $image_link . '</div>';
  return $output;
}

function __uib_w3__add_table_wrapper($text) {
  $text = str_replace(array('<table', '</table>'), array('<div class="uib-table-wrapper"><table', '</table></div>'), $text);
  return $text;
}

function uib_w3__get_image_caption_array($obj, $fieldname) {
  $static =  &drupal_static(__FUNCTION__);
  if (isset($static[$fieldname])) {
    return $static[$fieldname];
  }

  $retval = array();
  for (
    $i = 0;
    isset($obj->{$fieldname})
      && ($i < $obj->{$fieldname}->count());
    $i++) {
    $index = $obj->{$fieldname}[$i]->field_uib_imageindex->value();
    $caption = $obj->{$fieldname}[$i]->field_uib_imagecaption->value();
    $caption = trim($caption);
    if ($caption == '' || $index == '') continue;
    $retval[$index-1] = $caption == '0' ? '' : $caption;
  }
  $static[$fieldname] = $retval;
  return $retval;
}

function uib_w3__add_image_caption(
  &$imagefield,
  $node,
  $captionfieldname
) {

  $wrapped_node = entity_metadata_wrapper('node', $node);
  $other_media_captions = uib_w3__get_image_caption_array(
    $wrapped_node, $captionfieldname
  );

  foreach ((array)$other_media_captions as $key => $value) {
    if (!isset($imagefield[$key]) || !$imagefield[$key]) {
      // Field is not set
      continue;
    }
    if (isset($imagefield[$key]['field_uib_description'][0]['#markup'])) {
      $imagefield[$key]['field_uib_description'][0] =
        array(
          '#markup' => $value,
        );
    }
    else {
      $imagefield[$key]['field_uib_description'] =
        array(
          '#type' => 'container',
          '#weight' => 1,
          '#attributes' => array(
            'class' => array('field-name-field-uib-description', 'field'),
          ),
          'fields' => array(
            '#type' => 'container',
            '#attributes' => array(
              'class' => array('field-items'),
            ),
            'field-item' => array(
              '#type' => 'container',
              '#attributes' => array(
                'class' => array('field-item even'),
              ),
              'item' => array('#markup' => $value),
            ),
          ),
        );
    }
  }

}

function uib_w3__break_up_collection($collection, $field) {
  $sections = array();
  $render_array = array();
  foreach ($collection[$field] as $key => $value) {
    if (is_numeric($key)) $sections[] = $value;
    else $render_array[$key] = $value;
  }
  if (count($sections) > 1) {
    $collection[$field] = NULL;
    foreach ($sections as $key => $section) {
      $collection[$field][$key] = $render_array;
      $collection[$field][$key]['#weight'] = $key;
      $collection[$field][$key][0] = $section;
    }
  }
  return $collection;
}

function uib_w3__get_theme_suggested_title($variables,$with_name = true) {
  $current_area = uib_area__get_current();
  $hook_type = $variables['theme_hook_original'];
  $title = $current_area->title;
  $automatic_pages = array(
    $hook_type.'__node__persons',
    $hook_type.'__node__persons__faculty',
    $hook_type.'__node__persons__staff',
    $hook_type.'__node__courses',
    $hook_type.'__node__study_programmes',
    $hook_type.'__node__bachelor_programmes',
    $hook_type.'__node__master_programmes',
    $hook_type.'__node__one_year_programmes',
    $hook_type.'__node__research_groups',
    $hook_type.'__node__research_schools',
    $hook_type.'__node__disciplines',
    $hook_type.'__node__map',
    $hook_type.'__node__news_archive',
    $hook_type.'__node__calendar',
    $hook_type.'__calendar',
  );
  $suggestions = array_intersect($automatic_pages, $variables['theme_hook_suggestions']);
  if (count($suggestions) > 0) {
    if (in_array($hook_type.'__node__persons', $suggestions)) {
      if (in_array($hook_type.'__node__persons__faculty', $suggestions)) {
        $title_prefix = t('Faculty at');
      }
      elseif (in_array($hook_type.'__node__persons__staff', $suggestions)) {
        $title_prefix = t('Administrative and technical staff at');
      }
      else {
        $title_prefix = t('Staff at');
      }
    }
    if (in_array($hook_type.'__node__courses', $suggestions)) {
      $title_prefix = t('Courses at');
    }
    if (in_array($hook_type.'__node__study_programmes', $suggestions)) {
      $title_prefix = t('Study programmes at');
    }
    if (in_array($hook_type.'__node__bachelor_programmes', $suggestions)) {
      $title_prefix = t('Bachelor programmes at');
    }
    if (in_array($hook_type.'__node__master_programmes', $suggestions)) {
      $title_prefix = t('Master programmes at');
    }
    if (in_array($hook_type.'__node__one_year_programmes', $suggestions)) {
      $title_prefix = t('One year programmes at');
    }
    if (in_array($hook_type.'__node__research_groups', $suggestions)) {
      $title_prefix = t('Research groups at');
    }
    if (in_array($hook_type.'__node__research_schools', $suggestions)) {
      $title_prefix = t('Research schools at');
    }
    if (in_array($hook_type.'__node__disciplines', $suggestions)) {
      $title_prefix = t('Disciplines at');
    }
    if (in_array($hook_type.'__node__map', $suggestions)) {
      $title_prefix = t('Map for');
    }
    if (in_array($hook_type.'__node__news_archive', $suggestions)) {
      $title_prefix = t('News archive for');
    }
    if (in_array($hook_type.'__node__calendar', $suggestions)) {
      $title_prefix = t('Upcoming events for');
    }
    if (in_array($hook_type.'__calendar', $suggestions)) {
      $title_prefix = t('Upcoming events');
    }
    $title = $title_prefix . ' ' . $title;
    if($with_name) $title .= ' | ' . $variables['head_title_array']['name'];
  }
  return $title;
}
