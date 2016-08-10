<?php

/**
 * @file
 * Default view template to display a item in an RSS feed.
 *
 * @ingroup views_templates
 */
?>
  <item>
    <title><?php print $title; ?></title>
<?php
$hypertext = explode('href', $link);
$s = explode('%3E',$hypertext[1]);
$p = str_replace(array('%22','%26','%3D','%3A','%3F'),array('','&','',':','?'),$s[0]);
?>
    <link><?php print $p?></link>
    <description><?php print $description; ?></description>
    <?php print $item_elements; ?>
  </item>

