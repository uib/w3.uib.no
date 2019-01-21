<?php

/**
 * @file
 * uib_user.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uib_user_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_profile';
  $context->description = 'Blocks displayed on the user profile page';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user/*' => 'user/*',
        '~user/*/*' => '~user/*/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'uib_user-research_groups' => array(
          'module' => 'uib_user',
          'delta' => 'research_groups',
          'region' => 'content',
          'weight' => '9',
        ),
        'uib_user-feed' => array(
          'module' => 'uib_user',
          'delta' => 'feed',
          'region' => 'content',
          'weight' => '15',
        ),
        'uib_user-twitter' => array(
          'module' => 'uib_user',
          'delta' => 'twitter',
          'region' => 'content',
          'weight' => '14',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Blocks displayed on the user profile page');
  t('block');
  $export['user_profile'] = $context;

  return $export;
}
