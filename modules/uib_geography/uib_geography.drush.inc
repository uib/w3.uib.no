<?php

function uib_geography_drush_command() {
  $items['uib-fs-geo-sync'] = array(
    'description' => 'Synchronise countries in FS with the Drupal taxonomy',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );

 return $items;
}

function drush_uib_geography_uib_fs_geo_sync() {
  uib_geography_sync();
}
