<?php
/**
 * @file
 * Contains the theme's functions to manipulate Drupal's default markup.
 *
 * A QUICK OVERVIEW OF DRUPAL THEMING
 *
 *   The default HTML for all of Drupal's markup is specified by its modules.
 *   For example, the comment.module provides the default HTML markup and CSS
 *   styling that is wrapped around each comment. Fortunately, each piece of
 *   markup can optionally be overridden by the theme.
 *
 *   Drupal deals with each chunk of content using a "theme hook". The raw
 *   content is placed in PHP variables and passed through the theme hook, which
 *   can either be a template file (which you should already be familiary with)
 *   or a theme function. For example, the "comment" theme hook is implemented
 *   with a comment.tpl.php template file, but the "breadcrumb" theme hooks is
 *   implemented with a theme_breadcrumb() theme function. Regardless if the
 *   theme hook uses a template file or theme function, the template or function
 *   does the same kind of work; it takes the PHP variables passed to it and
 *   wraps the raw content with the desired HTML markup.
 *
 *   Most theme hooks are implemented with template files. Theme hooks that use
 *   theme functions do so for performance reasons - theme_field() is faster
 *   than a field.tpl.php - or for legacy reasons - theme_breadcrumb() has "been
 *   that way forever."
 *
 *   The variables used by theme functions or template files come from a handful
 *   of sources:
 *   - the contents of other theme hooks that have already been rendered into
 *     HTML. For example, the HTML from theme_breadcrumb() is put into the
 *     $breadcrumb variable of the page.tpl.php template file.
 *   - raw data provided directly by a module (often pulled from a database)
 *   - a "render element" provided directly by a module. A render element is a
 *     nested PHP array which contains both content and meta data with hints on
 *     how the content should be rendered. If a variable in a template file is a
 *     render element, it needs to be rendered with the render() function and
 *     then printed using:
 *       <?php print render($variable); ?>
 *
 * ABOUT THE TEMPLATE.PHP FILE
 *
 *   The template.php file is one of the most useful files when creating or
 *   modifying Drupal themes. With this file you can do three things:
 *   - Modify any theme hooks variables or add your own variables, using
 *     preprocess or process functions.
 *   - Override any theme function. That is, replace a module's default theme
 *     function with one you write.
 *   - Call hook_*_alter() functions which allow you to alter various parts of
 *     Drupal's internals, including the render elements in forms. The most
 *     useful of which include hook_form_alter(), hook_form_FORM_ID_alter(),
 *     and hook_page_alter(). See api.drupal.org for more information about
 *     _alter functions.
 *
 * OVERRIDING THEME FUNCTIONS
 *
 *   If a theme hook uses a theme function, Drupal will use the default theme
 *   function unless your theme overrides it. To override a theme function, you
 *   have to first find the theme function that generates the output. (The
 *   api.drupal.org website is a good place to find which file contains which
 *   function.) Then you can copy the original function in its entirety and
 *   paste it in this template.php file, changing the prefix from theme_ to
 *   uib_zen_. For example:
 *
 *     original, found in modules/field/field.module: theme_field()
 *     theme override, found in template.php: uib_zen_field()
 *
 *   where uib_zen is the name of your sub-theme. For example, the
 *   zen_classic theme would define a zen_classic_field() function.
 *
 *   Note that base themes can also override theme functions. And those
 *   overrides will be used by sub-themes unless the sub-theme chooses to
 *   override again.
 *
 *   Zen core only overrides one theme function. If you wish to override it, you
 *   should first look at how Zen core implements this function:
 *     theme_breadcrumbs()      in zen/template.php
 *
 *   For more information, please visit the Theme Developer's Guide on
 *   Drupal.org: http://drupal.org/node/173880
 *
 * CREATE OR MODIFY VARIABLES FOR YOUR THEME
 *
 *   Each tpl.php template file has several variables which hold various pieces
 *   of content. You can modify those variables (or add new ones) before they
 *   are used in the template files by using preprocess functions.
 *
 *   This makes THEME_preprocess_HOOK() functions the most powerful functions
 *   available to themers.
 *
 *   It works by having one preprocess function for each template file or its
 *   derivatives (called theme hook suggestions). For example:
 *     THEME_preprocess_page    alters the variables for page.tpl.php
 *     THEME_preprocess_node    alters the variables for node.tpl.php or
 *                              for node--forum.tpl.php
 *     THEME_preprocess_comment alters the variables for comment.tpl.php
 *     THEME_preprocess_block   alters the variables for block.tpl.php
 *
 *   For more information on preprocess functions and theme hook suggestions,
 *   please visit the Theme Developer's Guide on Drupal.org:
 *   http://drupal.org/node/223440 and http://drupal.org/node/1089656
 */


/**
 * Override or insert variables into the maintenance page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("maintenance_page" in this case.)
 */
/* -- Delete this line if you want to use this function
function uib_zen_preprocess_maintenance_page(&$variables, $hook) {
  // When a variable is manipulated or added in preprocess_html or
  // preprocess_page, that same work is probably needed for the maintenance page
  // as well, so we can just re-use those functions to do that work here.
  uib_zen_preprocess_html($variables, $hook);
  uib_zen_preprocess_page($variables, $hook);
}
// */

/**
 * Override or insert variables into the html templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
function uib_zen_preprocess_html(&$variables, $hook) {
  $title = __uib_title(current_path());
  if ($title) {
    $variables['head_title_array']['title'] = $title;
    $variables['head_title'] = implode(' | ', $variables['head_title_array']);
  }

  /**
   * Get area menu style.
   */
  $current_area = uib_area__get_current();
  if (!empty($current_area)) {
    $menu_style = field_get_items('node', $current_area, 'field_uib_menu_style');
    $variables['classes_array'][] = $menu_style[0]['value'];
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
function uib_zen_preprocess_page(&$variables, $hook) {
  global $user;
  $variables['uib_hide_title'] = FALSE;
  $page_menu_item = menu_get_item(current_path());
  if (isset($variables['node'])) {
    $not_translated_txt = t('This content has not been translated.');
    if ($variables['node']->type == 'uib_article') {
      if ($variables['node']->language != $variables['language']->language) {
        drupal_set_message($not_translated_txt, 'warning');
        drupal_set_breadcrumb(array());
      }
    }
    elseif ($variables['node']->type == 'uib_study') {
      $study_data = uib_study__fspres_get_node_json($variables['node']->nid, 'render.json', TRUE);
       if (empty($study_data)) {
        $study_data = uib_study__fspres_get_node_json($variables['node']->nid, 'render.json', FALSE);
        if (!empty($study_data)) {
          drupal_set_message($not_translated_txt, 'warning');
        }
      }
    }
  }
  $variables['page_title'] = $variables['site_name'];
  $variables['page_title_link'] = l($variables['site_name'], '<front>', array('attributes' => array('title' => $variables['site_name'] . " " . t('Home'))));
  $variables['uib_node_edit_mode'] = '';
  if (!empty($variables['node']->type) && $variables['node']->type == 'area') {
    $current_area = $variables['node'];
    // use the title of current area
    $variables['page_title'] = $current_area->title;
    $variables['page_title_link'] = l($current_area->title, 'node/' . $current_area->nid, array('attributes' => array('title' => $current_area->title . " " . t('Home'))));
  }
  else {
    $current_area = uib_area__get_current();
    if (!empty($current_area)) {
      // use the title of current area
      $variables['page_title'] = $current_area->title;
      $variables['page_title_link'] = l($current_area->title, 'node/' . $current_area->nid, array('attributes' => array('title' => $current_area->title . " " . t('Home'))));
    }
    unset($variables['page']['above_content']['uib_area_area_offices']);
  }
  if (!empty($current_area) && $current_area->field_uib_area_type['und'][0]['value'] == 'frontpage') {
    $variables['page_title_link'] = l($current_area->title, '', array('attributes' => array('title' => $current_area->title . " " . t('Home'))));
  }

  if (!is_int(strpos($page_menu_item['path'], 'node/add/'))) {
    if ($variables['language']->language == 'nb') {
      $variables['global_menu'] = menu_navigation_links('menu-global-menu-no');
    }
    else {
      $variables['global_menu'] = menu_navigation_links('menu-global-menu');
    }
  }

  if (isset($variables['page']['header']['locale_language'])) {
    $variables['extra_language'] = $variables['page']['header']['locale_language'];
    $variables['page']['header']['locale_language'] = '';
  }

  // Render areas custom logo.
  if (!empty($current_area)) {
    $output = field_view_field('node', $current_area, 'field_uib_logo',
      array(
        'type' => 'image',
        'label' => 'hidden',
        'settings' => array(
          'image_style' => 'custom_logo',
        )
      )
    );
  }
  $variables['custom_logo'] = render($output);

  $suggestions = theme_get_suggestions(arg(), 'page');
  if ($suggestions) {
    if (in_array('page__node__edit', $suggestions) || in_array('page__node__add', $suggestions)) {
      // Language switcher on edit or create node pages
      $variables['page']['content_top'][] = $variables['extra_language'];
      unset($variables['extra_language']);
    }
  }

  if (isset($variables['node'])) {
    // Create a variable that indicates whether we are in EDIT mode or not
    if ($suggestions) {
      if (in_array('page__node__edit', $suggestions)) {
        $variables['uib_node_edit_mode'] = 'edit';
      }
    }

    if ($variables['node']->type == 'area') {
      unset($variables['page']['content']['uib_area_node_children']);
    }
  }

  $variables['uib_long_page_title'] = FALSE;
  if (strlen($variables['page_title']) > 47 && !empty($variables['custom_logo'])) {
    $variables['uib_long_page_title'] = TRUE;
  }
  elseif (strlen($variables['page_title']) > 65 && empty($variables['custom_logo'])) {
    $variables['uib_long_page_title'] = TRUE;
  }

  $variables['mobile_menu_links'] = array(
    array('title' => t('Menu'), 'href' => '', 'attributes' => array('class' => array('mobile-show-menu'),),),
    array('title' => t('Search'), 'href' => '', 'attributes' => array('class' => array('mobile-show-search'),),),
  );

  if (empty($variables['node'])) {
    if (isset($page_menu_item['page_arguments'][0]) && $page_menu_item['page_arguments'][0] == 'uib_taxonomy_term') {
      // uib_nus taxonomy term view page
      $term = taxonomy_term_load($page_menu_item['map'][2]);
      if ($term->vocabulary_machine_name == 'uib_nus') {
        $title = __uib_title($page_menu_item['href']);
        // Set html title
        drupal_set_title($title);
        $variables['uib_hide_title'] = TRUE;
      }
    }
    // User profile page (and not login page)
    if (isset($page_menu_item['map'][0])
      && $page_menu_item['map'][0] == 'user'
      && count($page_menu_item['original_map']) > 1
      && is_numeric($page_menu_item['original_map'][1])) {

      // Target only the user profile page
      if (count($page_menu_item['original_map'] == 2)) {
        $variables['uib_hide_title'] = TRUE;

        // Move research groups block into field group
        if (isset($variables['page']['content']['uib_user_research_groups'])) {
          $variables['page']['content']['system_main']['uib_user_research_groups'] = $variables['page']['content']['uib_user_research_groups'];
          unset($variables['page']['content']['uib_user_research_groups']);
          $variables['page']['content']['system_main']['#group_children']['uib_user_research_groups'] = 'group_user_second';
        }

        // Move user feed block into field group
        if (isset($variables['page']['content']['uib_user_feed'])) {
          $variables['page']['content']['system_main']['uib_user_feed'] = $variables['page']['content']['uib_user_feed'];
          unset($variables['page']['content']['uib_user_feed']);
          $variables['page']['content']['system_main']['#group_children']['uib_user_feed'] = 'group_user_second';
        }

        // Move twitter block into field group
        if (isset($variables['page']['content']['uib_user_twitter'])) {
          $variables['page']['content']['system_main']['uib_user_twitter'] = $variables['page']['content']['uib_user_twitter'];
          unset($variables['page']['content']['uib_user_twitter']);
          $variables['page']['content']['system_main']['#group_children']['uib_user_twitter'] = 'group_user_second';
        }
      }
    }
    if (isset($page_menu_item['map'])) {
      if (($page_menu_item['map'][0] == 'emne' || $page_menu_item['map'][0] == 'course') && isset($page_menu_item['map'][2]) && $page_menu_item['map'][2] == 'description') {
        $variables['uib_hide_title'] = TRUE;
      }
      if ($page_menu_item['map'][0] == 'studieprogram' || $page_menu_item['map'][0] == 'studyprogramme') {
        if (isset($page_menu_item['map'][2]) && $page_menu_item['map'][2] == 'plan') {
          $variables['uib_hide_title'] = TRUE;
        }
      }
    }
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
function uib_zen_preprocess_node(&$variables, $hook) {
  /**
   * hook_preprocess that allways run on nodes.
   */
  global $language;
  $current_language = $language->language;
  $variables['is_employee'] = FALSE;

  if ($variables['type'] == 'uib_testimonial') {
    $variables['content']['title']['#markup'] = '<h1>' . $variables['title'] . '</h1>';
    $variables['content']['title']['#weight'] = -45;
    if ($variables['view_mode'] == 'teaser') {
      $variables['content']['title']['#markup'] = '<h1><a href="' . $variables['node_url'] . '">' . $variables['title'] . '</a></h1>';
      $variables['title'] = '';
      if (!empty($variables['field_uib_name'])){
        $variables['content']['field_uib_name'][0]['#markup'] = '– ' . $variables['content']['field_uib_name'][0]['#markup'];
    } }
  }

  // Add theme suggestion to nodes printed in view mode (newspage).
  if (($variables['type'] == 'uib_article') && ($variables['field_uib_article_type']['und'][0]['value'] == 'news')) {
    if ($variables['view_mode'] == 'teaser') {
      $variables['theme_hook_suggestions'][] = 'node__news__recent_news';
    }
  }

  if ($variables['view_mode'] == 'short_teaser') {
    if ($variables['type'] != 'uib_ou') {
      if ($variables['unpublished']) {
        $variables['title_attributes_array'] = array('class' => 'node-unpublished node__title node-title');
      }
      $variables['theme_hook_suggestions'][] = 'node__children';
      $variables['content']['title'] = array(
        '#theme' => 'link',
        '#text' => $variables['title'],
        '#path' => 'node/' . $variables['nid'],
        '#options' => array(
          'attributes' => array(),
          'html' => TRUE,
        ),
        '#weight' => 5,
      );
    }
    if ($variables['type'] == 'uib_article' && empty($variables['content']['field_uib_main_media'])) {
      // if possible, use first image of small images field in short teaser when main media is empty
      if (isset($variables['field_uib_media']['und'])) {
        $small_media = field_view_field('node', $variables['node'], 'field_uib_media', $variables['field_uib_media']['und'][0]);
        if (!empty($small_media)) {
          $variables['content']['field_uib_media'] = $small_media;
          if (isset($variables['content']['field_uib_media']['1'])) {
            $i = 1;
            while (isset($variables['content']['field_uib_media'][$i])) {
              unset($variables['content']['field_uib_media'][$i]);
              $i++;
            }
          }
        }
      }
    }
    if ($variables['type'] == 'uib_external_content') {
      $variables['content']['title']['#path'] = $variables['field_uib_links']['und'][0]['url'];
    }
    if ($variables['type'] == 'uib_content_list') {
      if ($variables['field_uib_display_style']['und'][0]['value'] == 'workflow') {
        $variables['node']->field_uib_main_media['und'][0] = array(
          'uri' => '/sites/all/themes/uib/uib_zen/images/workflow-placeholder.png',
        );
        $variables['content']['field_uib_main_media'] = field_view_field('node', $variables['node'], 'field_uib_main_media',array(
            'type' => 'image',
            'label' => 'hidden',
            'settings' => array(),
          )
        );
      }
    }
    $variables['title'] = '';
  }

  if (stripos($variables['node_url'], 'foransatte') !== FALSE OR stripos($variables['node_url'], 'foremployees') !== FALSE) {
    $variables['is_employee'] = TRUE;
  }

  if ($variables['type'] == 'uib_external_content' && $variables['view_mode'] == 'short_teaser') {
    $variables['is_employee'] = TRUE;
  }

  if ($variables['type'] == 'uib_study' && $variables['teaser']) {
    $variables['theme_hook_suggestions'][] = 'node__uib_study__teaser';
  }


  /**
   * Only run this when nodes are rendered on a page.
   */
  if ($variables['page']) {
    $metadata = entity_metadata_wrapper('node', $variables['nid']);

    if ($variables['type'] == 'area') {
      $area_type = $metadata->field_uib_area_type->value();
      $profiled_article = $metadata->field_uib_profiled_article->value();
      $show_staff = $metadata->field_uib_show_staff->value();
      $link_section = $metadata->field_uib_link_section->value();

      switch ($area_type) {
        case 'research group':
          $variables['classes_array'][] = 'research_g_node';
          break;
        case 'faculty':
          $variables['classes_array'][] = 'faculty_node';
          break;
        case 'institute':
          $variables['classes_array'][] = 'institute_node';
          break;
        case 'research school':
          $variables['classes_array'][] = 'research_s_node';
          break;
        case 'section':
          $variables['classes_array'][] = 'section_node';
          break;
        case 'unit':
          $variables['classes_array'][] = 'unit_node';
          break;
        case 'newspage':
          $variables['classes_array'][] = 'newspage_node';
          $profiled_message = $metadata->field_uib_profiled_message->value();
          hide($variables['content']['field_uib_link_section']);

          if ($profiled_message) {
            $newspage_one = views_embed_view('frontpage_profiled_articles', 'newspage_one_chosen_item', $variables['nid']);
            $newspage_two = views_embed_view('frontpage_profiled_articles', 'newspage_two_chosen_items', $variables['nid']);
            $newspage_last = views_embed_view('frontpage_profiled_articles', 'newspage_last_chosen_items', $variables['nid']);
            $weight = $variables['content']['field_uib_profiled_message']['#weight'];
            $message = array(
              '#weight' => $weight,
              array('#markup' => $newspage_two),
              array('#markup' => $newspage_one),
              array('#markup' => $newspage_last),
            );
            $variables['content']['field_uib_profiled_message'] = $message;
          }

          // Recent news block.
          $recent_news_block = module_invoke('uib_area', 'block_view', 'newspage_recent_news');
          if ($recent_news_block) {
            $variables['content']['field_uib_newspage_recent_news'] = $recent_news_block['content'];
            $variables['content']['field_uib_newspage_recent_news']['#weight'] = $weight + 1;
            $news_archive_link = l(t('News archive'), drupal_get_path_alias(current_path()) . '/news-archive');
            $variables['content']['field_uib_newspage_recent_news'][]['#markup'] = $news_archive_link;
          }
          break;
        case 'frontpage':
          $variables['classes_array'][] = 'frontpage_node';
          hide($variables['content']['field_uib_profiled_message']);
          hide($variables['content']['field_uib_link_section']);

          // Adding js to fix mobile menu on front page.
          drupal_add_js(drupal_get_path('theme', 'uib_zen') . '/js/mobile_menu_fix.js',
            array('group' => JS_THEME, )
          );
          break;
        case 'phdpresspage':
          $variables['classes_array'][] = 'phdpresspage_node';
          hide($variables['content']['field_uib_link_section']);
          $latest_phds = views_embed_view('recent_phds', 'page', $variables['nid']);
          $variables['content']['field_uib_recent_phds'] = array(
            '#weight' => 100,
             array('#markup' => $latest_phds),
          );
          break;
      }

      /**
       * Area nodes slideshow.
       */
      if ($profiled_article) {
        $weight = $variables['content']['field_uib_profiled_article']['#weight'];
        $slideshow = views_embed_view('area_slideshow', 'default', $variables['nid']);
        $variables['content']['field_uib_profiled_article'] = array(
          '#weight' => $weight,
          array('#markup' => $slideshow),
        );
      }

      /**
       * Include list of area emplyee.
       */
      if ($show_staff) {
        $variables['content']['field_uib_front_staff']['#markup'] = views_embed_view('ansatte', 'page_1', $variables['nid']);
        $variables['content']['field_uib_front_staff']['#weight'] = 12;
       }

      /**
       * Hide "relevant links section" if empty [RTS-1073]. Prevent empty div.
       */
      if ($link_section) {
        hide($variables['content']['group_two_column']['field_uib_link_section']);
      }

      if (!isset($variables['content']['field_uib_primary_text'])) {
        $variables['classes_array'][] = 'no-primary-text';
        $variables['content']['field_uib_primary_media'][0]['#view_mode'] = 'content_main';
        $variables['content']['field_uib_primary_media'][0]['file']['#style_name'] = 'content_main';
      }

      // Only run on emplyoee area pages.
      if ($variables['is_employee']) {
        drupal_add_js(drupal_get_path('theme', 'uib_zen') . '/js/hide_links.js', array('group' => JS_THEME, ));
      }
    }

    if ($variables['type'] == 'uib_article') {
      $article_type = $metadata->field_uib_article_type->value();
      $kicker = $metadata->field_uib_kicker->value(array('sanitize' => TRUE));
      $title = check_plain($metadata->label());
      $created = $metadata->created->value();
      $changed = $metadata->changed->value();
      $byline = $metadata->field_uib_byline->value();
      $external_author = $metadata->field_uib_external_author->value(array('sanitize' => TRUE));
      $uib_text = $metadata->field_uib_text->value();
      hide($variables['content']['field_uib_byline']);

      /**
       * Move node title into content.
       */
      $variables['content']['title'] = array(
        '#type' => 'html_tag',
        '#tag' => 'h1',
        '#value' => $title,
        '#weight' => -45,
      );

      /**
       * Content publish information as time, etc.
       */
      $article_info = array(
        '#prefix' => '<div class="article-info clearfix">',
        '#suffix' => '</div>',
        '#weight' => -20,
        'created' => array(
          '#prefix' => '<div class="uib-news-byline-created uib-publish-info">',
          '#markup' => t('Created') . ' ' . format_date($created, 'long'),
          '#suffix' => '</div>',
          '#weight' => 10,
        ),
        'changed' => array(
          '#prefix' => '<div class="uib-news-byline-last-updated uib-publish-info">',
          '#markup' => t('Last updated') . ' ' . format_date($changed, 'long'),
          '#suffix' => '</div>',
          '#weight' => 11,
        ),
      );

      /**
       * Slideshow thingy.
       */
      $slideshow = $metadata->field_uib_main_media[1]->value();
      if (!is_null($slideshow)) {
        $cycle_path = libraries_get_path('jquery.cycle');
        drupal_add_js($cycle_path . '/jquery.cycle.all.js');
        drupal_add_css(drupal_get_path('theme', 'uib_zen') . '/css/slideshow.css');
        drupal_add_js('jQuery(function($) {
          $( ".field-name-field-uib-main-media .field-items" ).cycle(
            {
              containerResize: 1,
              fit: 1,
              width: 708,
              height: 560,
              fx: "scrollHorz",
            }
          );
        }); ', 'inline');
      }

      if ($variables['is_employee']) {
        if (empty($variables['content']['group_article_sidebar']['#id'])) {
          $variables['content']['group_article_sidebar']['#id'] =  'node_uib_article_full_group_article_sidebar';
          $variables['content']['group_article_sidebar']['#prefix'] = '<div class="group-article-sidebar">';
          $variables['content']['group_article_sidebar']['#suffix'] = '</div>';
          $variables['content']['group_article_sidebar']['#weight'] = 4;
        }
      }
      else {
        $article_info['uib_service_links'] = __uib_render_service_links($variables['node'], 20);
      }

      if ($article_type == 'news') {
        $kicker_array = array(
          '#prefix' => '<div class="field-name-field-uib-kicker">',
          'title' => array(
            '#prefix' => '<div class="uib-kicker-text">',
            '#suffix' => '</div>',
          ),
          'date' => array(
            '#prefix' => '<div class="uib-kicker-date">',
            '#markup' => format_date($created, 'medium'),
            '#suffix' => '</div>',
          ),
          '#suffix' => '</div>',
          '#weight' => -50,
        );

        if ($kicker) {
          $kicker_array['title']['#markup'] = $kicker;
        }
        else {
          $kicker_array['title']['#markup'] = t('News');
        }
        $variables['content']['field_uib_kicker'] = $kicker_array;

        /**
         * Reformatting byline information.
         */
        $news_byline = array();
        if ($byline) {
          foreach ($byline as $key => $value) {
            $news_byline[] = $variables['content']['field_uib_byline'][$key]['#markup'];
          }
        }

        if ($external_author) {
          $news_byline[] = $external_author;
        }

        if ($news_byline) {
          $last_author = array_pop($news_byline);
          if ($news_byline) {
            $news_byline = t('By') . ' ' . implode(', ', $news_byline) . ' ' . t('and') . ' ' . $last_author;
          }
          else {
            $news_byline = t('By') . ' ' . $last_author;
          }

          $article_info['uib_news_byline'] = array(
            '#prefix' => '<div class="uib-news-byline">',
            '#markup' => $news_byline,
            '#suffix' => '</div>',
          );
        }
      }

      if ($article_type == 'event') {
        if (!$kicker) {
          $event_type_machine_name = $variables['node']->field_uib_event_type['und'][0]['value'];
          $event_type_info = field_info_field('field_uib_event_type');
          $event_type_default = $event_type_info['settings']['allowed_values'][$event_type_machine_name];
          $event_type = i18n_string_translate('field:field_uib_event_type:#allowed_values:' . $event_type_machine_name, $event_type_default);

          $variables['node']->field_uib_kicker['und'][0] = array(
            'value' => $event_type,
            'format' => NULL,
            'safe_value' => $event_type
          );
          $field_uib_kicker = field_view_field('node', $variables['node'], 'field_uib_kicker', array(
            'label' => 'hidden',
            'weight' => -50,
            ),
          $variables['language']);
          $variables['content']['field_uib_kicker'] = $field_uib_kicker;
        }
      }

      if ($article_type == 'phd_press_release') {
        // The the date is only used for sorting
        hide($variables['content']['field_uib_date']);
      }

      // Ensure that the labels of some fields, which are shown in the
      // main content sidebar, are not show when the fields contain no data
      if (empty($variables['node']->field_uib_location['und'][0]['value'])) {
        hide($variables['content']['group_article_sidebar']['field_uib_location']);
      }
      if (empty($variables['node']->field_uib_fact_box['und'][0]['value'])) {
        hide($variables['content']['group_article_sidebar']['field_uib_fact_box']);
      }
      if (empty($variables['field_uib_area']['und'][0]['entity'])) {
         hide($variables['content']['group_article_sidebar']['field_uib_area']);
      }
      if (empty($variables['node']->field_uib_media['und'][0]['uri'])) {
        hide($variables['content']['group_article_sidebar']['field_uib_media']);
      }
      elseif (empty($variables['node']->field_uib_media['und'][0]['field_uib_copyright']['und'][0]['value'])) {
        hide($variables['content']['group_article_sidebar']['field_uib_media'][0]['field_uib_copyright']);
      }
      elseif (empty($variables['node']->field_uib_media['und'][0]['field_uib_owner']['und'][0]['value'])) {
        hide($variables['content']['group_article_sidebar']['field_uib_media'][0]['field_uib_owner']);
      }

      if ($uib_text && strstr($uib_text['safe_value'], 'uib-tabs-container')) {
        drupal_add_library('system' , 'ui.tabs');
        drupal_add_js(drupal_get_path('theme', 'uib_zen') . '/js/tabs.js',
          array('group' => JS_THEME, )
        );
      }

      // Do not show related persons label if related persons field is empty
      if (empty($variables['content']['field_uib_related_persons'])) {
        $variables['content']['field_related_persons_label']['#access'] = FALSE;
      }

      $variables['content']['article_info'] = $article_info;
    }

    if ($variables['type'] == 'uib_study') {
      /**
       * Use title field as node title.
       */
      $variables['content']['title'] = array(
        '#type' => 'html_tag',
        '#tag' => 'h1',
        '#value' => $metadata->language($current_language)->field_uib_study_title->value(),
        '#weight' => -45,
      );
      hide($variables['content']['field_uib_study_category']);
      $uib_service_links = __uib_render_service_links($variables['node'], 10);
      $uib_study_image = '';
      if (isset($variables['content']['field_uib_study_image'])) {
        $uib_study_image = $variables['content']['field_uib_study_image'];
      }
      hide($variables['content']['field_uib_study_image']);

      $uib_study_links = '';
      if (isset($variables['content']['field_uib_link_section'])) {
        $uib_study_links = $variables['content']['field_uib_link_section'];
      }
      hide($variables['content']['field_uib_link_section']);

      $uib_study_feed = '';
      if (isset($variables['content']['field_uib_feed'])) {
        $uib_study_feed = $variables['content']['field_uib_feed'];
      }
      hide($variables['content']['field_uib_feed']);

      $uib_study_facts = __uib_render_block('uib_study', 'study_facts', 15);
      $uib_study_contact = __uib_render_block('uib_study', 'study_contact', 20);
      $uib_study_testimonial = __uib_render_block('uib_study', 'study_testimonial', 30);
      if ($variables['field_uib_study_type']['und'][0]['value'] == 'course') {
        $uib_study_toggle = __uib_render_block('uib_study', 'study_semester_toggle', 18);
        $uib_study_related = __uib_render_block('uib_study', 'study_related', 25);
      }
      if ($metadata->field_uib_study_category->value() == 'evu') {
        $uib_study_evu = __uib_render_block('uib_study', 'study_evu', 13);
      }

      $specializations = '';
      $view = views_get_view('uib_study_specialization');
      $view->preview('block', array($variables['node']->nid));
      if ($view->result) {
        $specializations = '<div class="block block-uib-study"><h3>' . t('Specialization') . '</h3>' . $view->render() . '</div>';
      }

      $variables['content']['uib_study_first_block'] = array(
        '#type' => 'html_tag',
        '#tag' => 'div',
        '#value' => render($uib_study_image) .
                    render($uib_study_facts) .
                    $specializations .
                    render($uib_study_evu) .
                    render($uib_study_contact),
        '#weight' => 1,
        '#attributes' => array('class' => array('uib-study-first-block')),
      );
      $variables['content']['uib_study_content'] = __uib_render_block('uib_study', 'study_content', 5);
      if (!empty($variables['field_uib_study_category']) && $variables['field_uib_study_category'][0]['value'] == 'evu') {
        // Hide course description for evu courses
        $variables['content']['uib_study_content']['uib_study_study_content']['fspres'][0]['em-emnebeskrivelse']['#access'] = FALSE;
      }
      $variables['content']['uib_study_second_block'] = array(
        '#type' => 'html_tag',
        '#tag' => 'div',
        '#value' => render($uib_study_toggle) .
                    render($uib_study_testimonial) .
                    render($uib_study_related) .
                    render($uib_study_links) .
                    render($uib_study_feed) .
                    render($uib_service_links),
        '#weight' => 10,
        '#attributes' => array('class' => array('uib-study-second-block')),
      );
      $study_type = $metadata->field_uib_study_type->value();
      if ($study_type == 'program' || $study_type == 'specialization' || $study_type == 'exchange') {
        $variables['content']['uib_study_content']['#prefix'] = '<div class="uib-tabs-container">';
        $variables['content']['uib_study_content']['#suffix'] = '</div>';
        drupal_add_library('system' , 'ui.tabs');
        drupal_add_js(drupal_get_path('theme', 'uib_zen') . '/js/tabs.js',
          array('group' => JS_THEME, )
        );
      }
    }
  }
}

function uib_zen_menu_link(array $variables) {
  global $user;
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  if ($element['#href'] == 'node/add/uib-article') {
    // prepopulate byline field
    $output = '<a href="' . url($element['#href'], array('query' => array('field_uib_byline' => $user->uid))) . '"';
    if (!empty($element['#localized_options']['attributes']['title'])) {
      $output .= ' title="' . t($element['#localized_options']['attributes']['title']) . '"';
    }
    $output .= '>' . t($element['#title']) . '</a>';
  }
  elseif (isset($variables['element']['#bid']) && ($variables['element']['#bid']['delta'] == 'top-area-menu') && ($element['#original_link']['depth'] == 2) && (!drupal_is_front_page()))
    $output = '<a href="#">' . $element["#title"] . '</a> ';
  else
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Override or insert variables into the comment templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("comment" in this case.)
 */
/* -- Delete this line if you want to use this function
function uib_zen_preprocess_comment(&$variables, $hook) {
  $variables['sample_variable'] = t('Lorem ipsum.');
}
// */

/**
 * Override or insert variables into the region templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
/* -- Delete this line if you want to use this function
function uib_zen_preprocess_region(&$variables, $hook) {
  // Don't use Zen's region--sidebar.tpl.php template for sidebars.
  if (strpos($variables['region'], 'sidebar_') === 0) {
    $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('region__sidebar'));
  }
}
// */

/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
/* -- Delete this line if you want to use this function
function uib_zen_preprocess_block(&$variables, $hook) {
  // Add a count to all the blocks in the region.
  $variables['classes_array'][] = 'count-' . $variables['block_id'];

  // By default, Zen will use the block--no-wrapper.tpl.php for the main
  // content. This optional bit of code undoes that:
  if ($variables['block_html_id'] == 'block-system-main') {
    $variables['theme_hook_suggestions'] = array_diff($variables['theme_hook_suggestions'], array('block__no_wrapper'));
  }
}
// */

/**
 * template_preprocess_region()
 * @param $variables
 *
 */
function uib_zen_preprocess_region(&$variables) {
  if (isset($variables['region']) == 'content_top') {
    $variables['classes_array'][] = 'clearfix';
  }
}

/**
 * Override or insert variables into the block template
 *
 * @param $variables
 *   An array of varibales to pass to the theme template
 * @param $hook
 *   The name of the template being rendered
 */
function uib_zen_preprocess_block(&$variables, $hook) {
  if ($variables['block_html_id'] == 'block-uib-area-colophon') {
    $variables['content'] = '<div class="block-wrapper">' . $variables['content'] . '</div>';
  }

  //arrays containg block_html_id of blocks where the title is getting colored squares
  $blue_block = array(
    'block-views-recent-news-block',
    'block-uib-area-area-parents',
    'block-views-faculties-block-1',
    'block-uib-area-jobbnorge',
    'block-views-79622ce408d27be255f959dc886a6751',
    'block-views-59c9268577c7dee7af4089857ed7ab4e',
    'block-uib-area-feed',
    'block-uib-dbh-dbh',
  );
  $orange_block = array(
    'block-views-calendar-block-1',
    'block-views-calendar-block-4',
    'block-views-e35933dcbeaec830701d3e48e98f0046',
    'block-views-87d291272c77934f60566c1a5bccebdf',
  );
  if (in_array ($variables['block_html_id'], $blue_block)) {
    if ($variables['block']->subject) {
      $variables['classes_array'][] = 'blue-block';
      $variables['classes_array'][] = 'clearfix';
      $variables['block']->subject = '<span></span>' . $variables['block']->subject;
    }
  }
  if (in_array ($variables['block_html_id'], $orange_block)) {
    $variables['classes_array'][] = 'orange-block';
    $variables['block']->subject = '<span></span>' . $variables['block']->subject;
  }
}

/**
 * Override or insert variables into the field template
 *
 * @param $variables
 *   A array of variables to pass to the theme template
 * @param $hook
 *   The name of the template being rendered
 */
function uib_zen_preprocess_field(&$variables, $hook) {
  static $blue_block_done = FALSE;
  //arrays containing field_name_css of blocks where the title is getting colored squares
  $blue_block = array(
    'field-uib-area',
    'field-uib-files',
    'field-uib-title',
  );
  if (in_array($variables['field_name_css'], $blue_block)) {
    // Deal separately with certain field collections
    if (empty($variables['label']) && $variables['field_name_css'] == 'field-uib-title' && $variables['element']['#object']->field_name == 'field_uib_link_section') {
      $variables['items'][0]['#markup'] = '<span></span>' . $variables['items'][0]['#markup'];
      if ($blue_block_done) {
        // Fix to make second "block" in field collection orange
        $variables['classes_array'][] = 'orange-block';
      }
      else {
        $variables['classes_array'][] = 'blue-block';
        $blue_block_done = TRUE;
      }
    }
    else {
      $variables['classes_array'][] = 'blue-block';
      $variables['label'] = '<span></span>' . $variables['label'];
    }
  }
  if ($variables['element']['#field_name'] == 'field_uib_relation') {
    $variables['classes_array'][] = 'block-uib-area';
  }
  if ($variables['element']['#field_name'] == 'field_uib_social_media' || $variables['element']['#field_name'] == 'field_uib_user_social_media' ) {
    $variables['classes_array'][] = 'uib-social-media';
  }

  // Aim to remove colon from certain user page fields
  if ($variables['element']['#entity_type'] == 'user' && $variables['element']['#view_mode'] == 'full') {
    $certain_fields = array(
      'field_uib_user_competence',
      'field_uib_user_projects',
      'field_uib_user_docs',
      );
    if (in_array($variables['element']['#field_name'], $certain_fields)) {
      $variables['theme_hook_suggestions'][] = 'field__user__label_colonfree';
    }
  }
}

/**
 *
 */
function __uib_render_block($module, $block_id, $weight) {
  $block = block_load($module, $block_id);
  $block_content = _block_render_blocks(array($block));
  $render = _block_get_renderable_array($block_content);
  $render['#weight'] = $weight;
  return $render;
}

/**
 *
 */
function __uib_render_service_links($node, $weight) {
  $ids = array('twitter', 'facebook', 'linkedin', 'google_plus_share');
  $options = array(
    'style' => SERVICE_LINKS_STYLE_TEXT,
  );
  $service_links = theme('item_list',
    array(
      'items' => service_links_render_some($ids, $node, FALSE, $options),
    )
  );
  $output = array(
    '#prefix' => '<div class="service-links">',
    '#markup' => $service_links,
    '#suffix' => '</div>',
    '#weight' => $weight,
  );
  return $output;
}

function __uib_media_content($vars) {
  $content .= $vars;
  return $content;
}

function uib_zen_field($variables) {
  $output = '';
  // List of fields that will be rendered with simplified markup
  $simple_markup = array(
    'field_uib_lead',
    );
  if (in_array($variables['element']['#field_name'], $simple_markup)) {
    // Simplified markup
     foreach ($variables['items'] as $delta => $item) {
      $output = '<p class="' . $variables['classes'] . '">' . $item['#markup'] . '</p>';
    }
  }
  else {
    // Standard markup with lots of divs

    // Render the label, if it's not hidden.
    if (!$variables['label_hidden']) {
      $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
    }

    if ($variables['element']['#field_name'] == 'field_uib_relation') {
      // Render this particular field as an unordered list
      // Render the items.
      $output .= '<ul class="field-items clearfix">';
      foreach ($variables['items'] as $delta => $item) {
        $nids = array_keys($item['node']);
        if ($item['node'][$nids[0]]['#bundle'] == 'uib_study') {
          $item['node'][$nids[0]]['#node']->title = __uib_title('node/' . $nids[0]);
        }
        $output .= drupal_render($item);
      }
      $output .= '</ul>';
    }
    else {

      // Render the items.
      $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
      foreach ($variables['items'] as $delta => $item) {
        $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
        $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
      }
      $output .= '</div>';
    }
    // Render the top-level DIV.
    $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';
  }
  return $output;
}

/**
 * __uib_entity Return entity object if it exist.
 * @param  string Path current page to get field title from.
 * @return string Current node/term field based title. Return FALSE if type is
 * not supported by function.
 */
function __uib_title($path) {
  $path = explode('/', $path);
  if (!array_key_exists(1, $path)) {
    return FALSE;
  }
  $type = $path[0];
  global $language;
  $current_language = $language->language;
  $id = FALSE;
  if ($type == 'taxonomy' and $path[1] == 'term' and is_numeric($path[2])) {
    $type = $type . '_term';
    $id = array($path[2]);
  }
  elseif ($type == 'node' and is_numeric($path[1])) {
    $id = array($path[1]);
  }
  if ($id) {
    $result = entity_load($type, $id);
  }
  if (!empty($result)) {
    foreach ($result as $key => $entity) {
      $metadata = entity_metadata_wrapper($type, $entity);
      $bundle = $metadata->getbundle();
      if ($bundle == 'uib_nus') {
        return $metadata->language($current_language)->field_uib_term_title->value();
      }
      if ($bundle == 'uib_study') {
        return $metadata->language($current_language)->field_uib_study_title->value();
      }
      else {
        return FALSE;
      }
    }
  }
  else {
    return FALSE;
  }
}

function uib_zen_views_post_render(&$view, &$output, &$cache) {
  global $language;
  $current_lang = $language->language;
  if (($view->name == 'calendar' || $view->name == 'global_calendar') && in_array($view->current_display, array('block_3', 'block_5')) && $current_lang == 'nb') {
    foreach ($view->result as $key => $result) {
      $event_type = i18n_string_translate('field:field_uib_event_type:#allowed_values:' . $view->result[$key]->field_data_field_uib_event_type_field_uib_event_type_value, $view->result[$key]->field_data_field_uib_event_type_field_uib_event_type_value);
      $output = str_replace('>' . $view->result[$key]->link . '<', '>'. drupal_ucfirst($event_type) . '<', $output);
    }
  }
  $view_current_display = array(
    'study_programmes_all_page',
    'study_courses_all_page',
  );
  if ($view->name == 'courses' && in_array($view->current_display, $view_current_display) && $current_lang == 'nb') {
    foreach ($view->filter['field_uib_study_category_value']->value_options as $key => $value) {
      $study_category = i18n_string_translate(
        'field:field_uib_study_category:#allowed_values:' . $key,
        $view->filter['field_uib_study_category_value']->value_options[$key]
        );
      $output = str_replace('>' . $view->filter['field_uib_study_category_value']->value_options[$key] . '</label>', '>'. drupal_ucfirst($study_category) . '</label>', $output);
    }
  }
}

function uib_zen_preprocess_views_view(&$variables) {
  if ($variables['name'] == 'courses') {
    if ($variables['display_id'] == 'study_courses_all_page' || $variables['display_id'] == 'study_programmes_all_page') {
      // Force education as current area
      uib_area__get_current(variable_get('uib_study_area_nid'));
    }
  }
  $forced_education_area_names = array(
    'uib_nus_overview',
    'special_study_listings',
  );
  if (in_array($variables['name'], $forced_education_area_names)) {
    // Force education as current area
    uib_area__get_current(variable_get('uib_study_area_nid'));
  }
  $language_challenged_views = array('my_content', 'user_areas', 'scheduled_content');
  if (in_array($variables['view']->name, $language_challenged_views)) {
    $view = $variables['view'];
    foreach ($view->result as $key => $item) {
      if ($item->node_language == 'nb') {
        $variables['rows'] = str_replace('en/node/' . $item->nid, 'nb/node/' . $item->nid, $variables['rows']);
      }
      if ($item->node_language == 'en') {
        $variables['rows'] = str_replace('nb/node/' . $item->nid, 'en/node/' . $item->nid, $variables['rows']);
      }
    }
  }
}

/**
 * Theme the calendar title
 * Overrides date_nav_title theming function from the date module
 */
function uib_zen_date_nav_title(&$params) {
  if ($params['view']->name == 'calendar' && $params['view']->current_display == 'page_4') {
    $params['format'] = 'd.F Y';
  }
  $granularity = $params['granularity'];
  $view = $params['view'];
  $date_info = $view->date_info;
  $link = !empty($params['link']) ? $params['link'] : FALSE;
  $format = !empty($params['format']) ? $params['format'] : NULL;
  switch ($granularity) {
    case 'year':
      $title = $date_info->year;
      $date_arg = $date_info->year;
      break;
    case 'month':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? 'F Y' : 'F');
      $title = date_format_date($date_info->min_date, 'custom', $format);
      $date_arg = $date_info->year . '-' . date_pad($date_info->month);
      break;
    case 'day':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? 'l, F j, Y' : 'l, F j');
      $title = date_format_date($date_info->min_date, 'custom', $format);
      $date_arg = $date_info->year . '-' . date_pad($date_info->month) . '-' . date_pad($date_info->day);
      break;
    case 'week':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? 'F j, Y' : 'F j');
      $title = t('Week of @date', array('@date' => date_format_date($date_info->min_date, 'custom', $format)));
      $date_arg = $date_info->year . '-W' . date_pad($date_info->week);
      break;
  }
  if (!empty($date_info->mini) || $link) {
    // Month navigation titles are used as links in the mini view.
    $attributes = array('title' => t('View full page month'));
    $url = date_pager_url($view, $granularity, $date_arg, TRUE);
    return l($title, $url, array('attributes' => $attributes));
  }
  else {
    return $title;
  }
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
function uib_zen_breadcrumb(&$vars) {
  $breadcrumb = $vars['breadcrumb'];
  $output = '<nav class="breadcrumb" role="navigation"><ol>';
  foreach ($breadcrumb as $key => $crumb) {
    if ($key == 2 && strpos($crumb, 'uib-remove-link')) $crumb = strip_tags($crumb);
    $output .= '<li>' . urldecode($crumb) . ' &gt; </li>';
  }
  $output .= '</ol></nav>';
  return $output;
}
