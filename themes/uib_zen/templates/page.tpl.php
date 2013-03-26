<?php
/**
 * @file
 * Zen theme's implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $secondary_menu_heading: The title of the menu used by the secondary links.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header']: Items for the header region.
 * - $page['navigation']: Items for the navigation region, below the main menu (if any).
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['footer']: Items for the footer region.
 * - $page['bottom']: Items to appear at the bottom of the page below the footer.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see zen_preprocess_page()
 * @see template_process()
 */
?>
<?php if ($variables['uib_node_edit_mode'] != 'edit'): ?>
  <div id="top-region-wrapper">
    <?php if (isset($global_menu)): ?>
      <div id="global-header">
        <nav id="global-menu">
          <?php print theme('links__menu-global-menu', array(
            'links' => $global_menu,
            'attributes' => array(
              'class' => array('links','global-menu'),
            ),
          ));
          ?>
        </nav>

        <div id="mobile-name-and-slogan">
          <?php if ($logo): ?>
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="logo"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
          <?php endif; ?>
          <?php
          /**
           * Modified to print name of area instead of site-name.
           * The varible 'page_title_link' is setup in template.php and contains
           * the area name in an url.
           */
          if ($site_name || $site_slogan || $page_title_link): ?>
            <hgroup id="name-and-slogan-mobile">
              <h1 class="site-name"><?php print $page_title_link; ?></h1>
              <?php if ($site_slogan): ?>
                <h2 id="mobile-site-slogan"><?php print $site_slogan; ?></h2>
              <?php endif; ?>
            </hgroup><!-- /#name-and-slogan -->
          <?php endif; ?>
        </div><!-- end #mobile-name-and-slogan -->

        <div id="menu-search-mobile-wrapper">
          <div id="global-searchform">
            <form method="get" action="http://www.uib.no/search">
              <div class="searchbox">
                <p><input type="text" id="searchField" name="q" value="" autocomplete="off"></p>
                <p><input alt="Submit" type="image" src="<?php print base_path() . drupal_get_path('theme', 'uib_zen'); ?>/images/submit.gif" value="Search"></p>
              </div>
            </form>
          </div>
          <div id ="mobile-menu">
            <ul>
              <li></li>
              <li></li>
              <li></li>
            </ul>
          </div>
        </div>

      </div>
    <?php endif; ?>
  </div>
<?php endif; ?>

<div id="page">
  <?php if ($variables['uib_node_edit_mode'] != 'edit'): ?>
    <header id="header" role="banner">
      <?php if ($logo): ?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="logo large-screens"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
      <?php endif; ?>

      <?php
      /**
      * Modified to print name of area instead of site-name.
      * The varible 'page_title_link' is setup in template.php and contains the
      * area name in an url.
      */
      if ($site_name || $site_slogan || $page_title_link): ?>
        <hgroup id="name-and-slogan">
          <h1 class="site-name"><?php print $page_title_link; ?></h1>
            <?php if ($site_slogan): ?>
              <h2 id="site-slogan"><?php print $site_slogan; ?></h2>
            <?php endif; ?>
        </hgroup><!-- /#name-and-slogan -->
      <?php endif; ?>

      <?php if ($secondary_menu): ?>
        <nav id="secondary-menu" role="navigation">
          <?php print theme('links__system_secondary_menu', array(
            'links' => $secondary_menu,
            'attributes' => array(
              'class' => array('links', 'inline', 'clearfix'),
            ),
            'heading' => array(
              'text' => $secondary_menu_heading,
              'level' => 'h2',
              'class' => array('element-invisible'),
            ),
          )); ?>
        </nav>
      <?php endif; ?>

      <?php print render($page['header']); ?>
    </header>

    <div id="navigation"<?php
      // Modified in order to pick upp class style for uib navigation menu, $uib_menu_style set in template.php
      if (!empty($uib_menu_style)): ?> class="<?php print $uib_menu_style; ?>"<?php endif; ?>>

      <?php if ($main_menu): ?>
        <nav id="main-menu" role="navigation">
          <?php
          /**
           * This code snippet is hard to modify. We recommend turning off the
           * "Main menu" on your sub-theme's settings form, deleting this PHP
           * code block, and, instead, using the "Menu block" module.
           *
           * @see http://drupal.org/project/menu_block
           */
          print theme('links__system_main_menu', array(
            'links' => $main_menu,
            'attributes' => array(
              'class' => array('links', 'inline', 'clearfix'),
            ),
            'heading' => array(
              'text' => t('Main menu'),
              'level' => 'h2',
              'class' => array('element-invisible'),
            ),
          )); ?>
        </nav>
      <?php endif; ?>

      <?php print render($page['navigation']); ?>
    </div><!-- /#navigation -->
  <?php endif; ?>

  <div id="desktop-tablet-language">
  <?php print render($extra_language); ?></div>

  <div id="main">
    <div id="content" class="column" role="main">
      <?php print render($page['highlighted']); ?>
      <?php print $breadcrumb; ?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <?php if ($title != $page_title):
          // Modified to print title only if different from area title
          ?>
          <h1 class="title" id="page-title"><?php print $title; ?></h1>
        <?php endif; ?>
      <?php endif; ?>
      <?php print render($page['content_top']); ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php if ($action_links): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div><!-- /#content -->

    <?php
      // Render the sidebars to see if there's anything in them.
      $sidebar_first  = render($page['sidebar_first']);
      $sidebar_second = render($page['sidebar_second']);
    ?>

    <?php if ($sidebar_first || $sidebar_second): ?>
      <aside class="sidebars">
        <?php print $sidebar_first; ?>
        <?php print $sidebar_second; ?>
      </aside><!-- /.sidebars -->
    <?php endif; ?>
  </div><!-- /#main -->

  <?php print render($page['footer']); ?>
</div><!-- /#page -->

<div id="bottom-region-wrapper" class="clearfix">
  <?php print render($page['bottom']); ?>
</div>
