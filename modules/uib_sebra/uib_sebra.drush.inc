<?php

function uib_sebra_drush_command() {
  $items['uib-sebra-places'] = array(
    'description' => 'Syncronize places in Sebra with the Drupal database',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(
      'limit' => 'Only process this many places before terminating',
    ),
  );
  $items['uib-dump-place'] = array(
    'description' => 'Get a place object from Sebra and dump its attributes',
    'arguments' => array(
      'place-id' => 'The 6-digit place code of the place to dump',
    ),
    'required-arguments' => TRUE,
  );
  $items['uib-sebra-areas'] = array(
    'description' => 'Syncronize areas in Sebra with the Drupal database',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
  );
  $items['uib-sebra-users'] = array(
    'description' => 'Syncronize users in Sebra with the Drupal database',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(
      'limit' => 'Only process this many users before terminating',
      'no-block' => 'Do not block users that are not present in Sebra',
    ),
  );
  $items['uib-sebra-user'] = array(
    'description' => 'Syncronize the given user from Sebra with the Drupal database',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(
      'user' => 'The username',
    ),
    'required-arguments' => TRUE,
    'options' => array(
      'dry-run' => 'Don\'t actually update the database',
    ),
  );
  $items['uib-sebra-areadiff'] = array(
    'description' => 'Show a list of areas in sebra are not in the Drupal database, and which are',
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(),
    'options' => array(),
  );
 return $items;
}

function drush_uib_sebra_places() {
  $limit = (int)drush_get_option('limit', 0);
  uib_sebra__sync_places($limit);
  drush_uib_area_sync_organisation();
}

function drush_uib_sebra_uib_dump_place($place_id) {
  $place = new SebraPlace($place_id);
  print_r($place);
}

function drush_uib_sebra_areas() {
  // we need to execute this admin for node translations sync to
  // be able to update unpublished areas.
  global $user;
  $user = user_load(1);

  uib_sebra__sync_areas();
}

function drush_uib_sebra_user($user) {
  uib_sebra__sync_user($user, drush_get_option('dry-run'));
}

function drush_uib_sebra_users() {
  $limit = intval(drush_get_option('limit', 5));
  $no_block = drush_get_option('no-block', FALSE);
  uib_sebra__sync_users($limit, $no_block);
}

function drush_uib_sebra_areadiff() {
  uib_sebra__area_diff();
}
