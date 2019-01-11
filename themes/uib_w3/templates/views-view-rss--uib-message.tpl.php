<?php

/**
 * @file
 * Default template for feed displays that use the RSS style.
 *
 * @ingroup views_templates
 */
?>
<?php
$arr = explode(' ',$channel_elements);
$regex = '/https?\:\/\/[^\",]+/i';
preg_match_all($regex, $channel_elements, $match);
$channel_link = str_replace('.xml','',$match[0][0]);
?>
<?php print "<?xml"; ?> version="1.0" encoding="utf-8" <?php print "?>"; ?>
<rss version="2.0" xml:base="<?php print $channel_link; ?>"<?php print $namespaces; ?>>
  <channel>
    <title><?php print $title; ?></title>
    <link><?php print $channel_link; ?></link>
    <description><?php print $description; ?></description>
    <language><?php print $langcode; ?></language>
    <?php print $channel_elements; ?>
    <?php print $items; ?>
  </channel>
</rss>
