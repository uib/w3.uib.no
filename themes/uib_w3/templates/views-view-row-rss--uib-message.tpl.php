<?php

/**
 * @file
 * Default view template to display a item in an RSS feed.
 *
 * @ingroup views_templates
 */
?>
  <item>
    <title><?php print htmlspecialchars_decode($title); ?></title>
    <?php if($link !== 'http:noresult') print('<link>' . $link . '</link>'); ?>
    <description><?php print $description; ?></description>
    <?php print $item_elements; ?>
  </item>
