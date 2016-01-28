<?php
/**
 * @file
 * uib_setup.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uib_setup_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access service links'.
  $permissions['access service links'] = array(
    'name' => 'access service links',
    'roles' => array(
      'admin' => 'admin',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'service_links',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'system',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer content translations'.
  $permissions['administer content translations'] = array(
    'name' => 'administer content translations',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'i18n_node',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer entity translation'.
  $permissions['administer entity translation'] = array(
    'name' => 'administer entity translation',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'administer scheduler'.
  $permissions['administer scheduler'] = array(
    'name' => 'administer scheduler',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer uib area menus'.
  $permissions['administer uib area menus'] = array(
    'name' => 'administer uib area menus',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'uib_area',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: 'assign all roles'.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign level 1 role'.
  $permissions['assign level 1 role'] = array(
    'name' => 'assign level 1 role',
    'roles' => array(
      'level 1' => 'level 1',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign level 2 role'.
  $permissions['assign level 2 role'] = array(
    'name' => 'assign level 2 role',
    'roles' => array(
      'level 1' => 'level 1',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign level 3 role'.
  $permissions['assign level 3 role'] = array(
    'name' => 'assign level 3 role',
    'roles' => array(
      'level 1' => 'level 1',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'create area content'.
  $permissions['create area content'] = array(
    'name' => 'create area content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create uib_article content'.
  $permissions['create uib_article content'] = array(
    'name' => 'create uib_article content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create uib_content_list content'.
  $permissions['create uib_content_list content'] = array(
    'name' => 'create uib_content_list content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create uib_external_content content'.
  $permissions['create uib_external_content content'] = array(
    'name' => 'create uib_external_content content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create uib_ou content'.
  $permissions['create uib_ou content'] = array(
    'name' => 'create uib_ou content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create uib_study content'.
  $permissions['create uib_study content'] = array(
    'name' => 'create uib_study content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create uib_testimonial content'.
  $permissions['create uib_testimonial content'] = array(
    'name' => 'create uib_testimonial content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'path',
  );

  // Exported permission: 'delete any area content'.
  $permissions['delete any area content'] = array(
    'name' => 'delete any area content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any files'.
  $permissions['delete any files'] = array(
    'name' => 'delete any files',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any uib_article content'.
  $permissions['delete any uib_article content'] = array(
    'name' => 'delete any uib_article content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any uib_content_list content'.
  $permissions['delete any uib_content_list content'] = array(
    'name' => 'delete any uib_content_list content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any uib_external_content content'.
  $permissions['delete any uib_external_content content'] = array(
    'name' => 'delete any uib_external_content content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any uib_ou content'.
  $permissions['delete any uib_ou content'] = array(
    'name' => 'delete any uib_ou content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any uib_study content'.
  $permissions['delete any uib_study content'] = array(
    'name' => 'delete any uib_study content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any uib_testimonial content'.
  $permissions['delete any uib_testimonial content'] = array(
    'name' => 'delete any uib_testimonial content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own area content'.
  $permissions['delete own area content'] = array(
    'name' => 'delete own area content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own files'.
  $permissions['delete own files'] = array(
    'name' => 'delete own files',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own uib_article content'.
  $permissions['delete own uib_article content'] = array(
    'name' => 'delete own uib_article content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own uib_content_list content'.
  $permissions['delete own uib_content_list content'] = array(
    'name' => 'delete own uib_content_list content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own uib_external_content content'.
  $permissions['delete own uib_external_content content'] = array(
    'name' => 'delete own uib_external_content content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own uib_ou content'.
  $permissions['delete own uib_ou content'] = array(
    'name' => 'delete own uib_ou content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own uib_study content'.
  $permissions['delete own uib_study content'] = array(
    'name' => 'delete own uib_study content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own uib_testimonial content'.
  $permissions['delete own uib_testimonial content'] = array(
    'name' => 'delete own uib_testimonial content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in uib_organisation'.
  $permissions['delete terms in uib_organisation'] = array(
    'name' => 'delete terms in uib_organisation',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit any area content'.
  $permissions['edit any area content'] = array(
    'name' => 'edit any area content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any files'.
  $permissions['edit any files'] = array(
    'name' => 'edit any files',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any uib_article content'.
  $permissions['edit any uib_article content'] = array(
    'name' => 'edit any uib_article content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any uib_content_list content'.
  $permissions['edit any uib_content_list content'] = array(
    'name' => 'edit any uib_content_list content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any uib_external_content content'.
  $permissions['edit any uib_external_content content'] = array(
    'name' => 'edit any uib_external_content content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any uib_ou content'.
  $permissions['edit any uib_ou content'] = array(
    'name' => 'edit any uib_ou content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any uib_study content'.
  $permissions['edit any uib_study content'] = array(
    'name' => 'edit any uib_study content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any uib_testimonial content'.
  $permissions['edit any uib_testimonial content'] = array(
    'name' => 'edit any uib_testimonial content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own area content'.
  $permissions['edit own area content'] = array(
    'name' => 'edit own area content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own files'.
  $permissions['edit own files'] = array(
    'name' => 'edit own files',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own uib_article content'.
  $permissions['edit own uib_article content'] = array(
    'name' => 'edit own uib_article content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own uib_content_list content'.
  $permissions['edit own uib_content_list content'] = array(
    'name' => 'edit own uib_content_list content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own uib_external_content content'.
  $permissions['edit own uib_external_content content'] = array(
    'name' => 'edit own uib_external_content content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own uib_ou content'.
  $permissions['edit own uib_ou content'] = array(
    'name' => 'edit own uib_ou content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own uib_study content'.
  $permissions['edit own uib_study content'] = array(
    'name' => 'edit own uib_study content',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own uib_testimonial content'.
  $permissions['edit own uib_testimonial content'] = array(
    'name' => 'edit own uib_testimonial content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in uib_nus'.
  $permissions['edit terms in uib_nus'] = array(
    'name' => 'edit terms in uib_nus',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in uib_organisation'.
  $permissions['edit terms in uib_organisation'] = array(
    'name' => 'edit terms in uib_organisation',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'enter area revision log entry'.
  $permissions['enter area revision log entry'] = array(
    'name' => 'enter area revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter uib_article revision log entry'.
  $permissions['enter uib_article revision log entry'] = array(
    'name' => 'enter uib_article revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter uib_content_list revision log entry'.
  $permissions['enter uib_content_list revision log entry'] = array(
    'name' => 'enter uib_content_list revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter uib_ou revision log entry'.
  $permissions['enter uib_ou revision log entry'] = array(
    'name' => 'enter uib_ou revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter uib_study revision log entry'.
  $permissions['enter uib_study revision log entry'] = array(
    'name' => 'enter uib_study revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter uib_testimonial revision log entry'.
  $permissions['enter uib_testimonial revision log entry'] = array(
    'name' => 'enter uib_testimonial revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'geocoder_service_all_handlers'.
  $permissions['geocoder_service_all_handlers'] = array(
    'name' => 'geocoder_service_all_handlers',
    'roles' => array(),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_exif'.
  $permissions['geocoder_service_handler_exif'] = array(
    'name' => 'geocoder_service_handler_exif',
    'roles' => array(),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_google'.
  $permissions['geocoder_service_handler_google'] = array(
    'name' => 'geocoder_service_handler_google',
    'roles' => array(),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_gpx'.
  $permissions['geocoder_service_handler_gpx'] = array(
    'name' => 'geocoder_service_handler_gpx',
    'roles' => array(),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_json'.
  $permissions['geocoder_service_handler_json'] = array(
    'name' => 'geocoder_service_handler_json',
    'roles' => array(),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_kml'.
  $permissions['geocoder_service_handler_kml'] = array(
    'name' => 'geocoder_service_handler_kml',
    'roles' => array(),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_latlon'.
  $permissions['geocoder_service_handler_latlon'] = array(
    'name' => 'geocoder_service_handler_latlon',
    'roles' => array(),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_mapquest_nominatim'.
  $permissions['geocoder_service_handler_mapquest_nominatim'] = array(
    'name' => 'geocoder_service_handler_mapquest_nominatim',
    'roles' => array(),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_wkt'.
  $permissions['geocoder_service_handler_wkt'] = array(
    'name' => 'geocoder_service_handler_wkt',
    'roles' => array(),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_yahoo'.
  $permissions['geocoder_service_handler_yahoo'] = array(
    'name' => 'geocoder_service_handler_yahoo',
    'roles' => array(),
    'module' => 'geocoder',
  );

  // Exported permission: 'geocoder_service_handler_yandex'.
  $permissions['geocoder_service_handler_yandex'] = array(
    'name' => 'geocoder_service_handler_yandex',
    'roles' => array(),
    'module' => 'geocoder',
  );

  // Exported permission: 'import media'.
  $permissions['import media'] = array(
    'name' => 'import media',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'media',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: 'override area authored by option'.
  $permissions['override area authored by option'] = array(
    'name' => 'override area authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override area authored on option'.
  $permissions['override area authored on option'] = array(
    'name' => 'override area authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override area promote to front page option'.
  $permissions['override area promote to front page option'] = array(
    'name' => 'override area promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override area published option'.
  $permissions['override area published option'] = array(
    'name' => 'override area published option',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override area revision option'.
  $permissions['override area revision option'] = array(
    'name' => 'override area revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override area sticky option'.
  $permissions['override area sticky option'] = array(
    'name' => 'override area sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_article authored by option'.
  $permissions['override uib_article authored by option'] = array(
    'name' => 'override uib_article authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_article authored on option'.
  $permissions['override uib_article authored on option'] = array(
    'name' => 'override uib_article authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_article promote to front page option'.
  $permissions['override uib_article promote to front page option'] = array(
    'name' => 'override uib_article promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_article published option'.
  $permissions['override uib_article published option'] = array(
    'name' => 'override uib_article published option',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_article revision option'.
  $permissions['override uib_article revision option'] = array(
    'name' => 'override uib_article revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_article sticky option'.
  $permissions['override uib_article sticky option'] = array(
    'name' => 'override uib_article sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_content_list authored by option'.
  $permissions['override uib_content_list authored by option'] = array(
    'name' => 'override uib_content_list authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_content_list authored on option'.
  $permissions['override uib_content_list authored on option'] = array(
    'name' => 'override uib_content_list authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_content_list promote to front page option'.
  $permissions['override uib_content_list promote to front page option'] = array(
    'name' => 'override uib_content_list promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_content_list published option'.
  $permissions['override uib_content_list published option'] = array(
    'name' => 'override uib_content_list published option',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_content_list revision option'.
  $permissions['override uib_content_list revision option'] = array(
    'name' => 'override uib_content_list revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_content_list sticky option'.
  $permissions['override uib_content_list sticky option'] = array(
    'name' => 'override uib_content_list sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_external_content authored by option'.
  $permissions['override uib_external_content authored by option'] = array(
    'name' => 'override uib_external_content authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_external_content authored on option'.
  $permissions['override uib_external_content authored on option'] = array(
    'name' => 'override uib_external_content authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_external_content promote to front page option'.
  $permissions['override uib_external_content promote to front page option'] = array(
    'name' => 'override uib_external_content promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_external_content published option'.
  $permissions['override uib_external_content published option'] = array(
    'name' => 'override uib_external_content published option',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_external_content revision option'.
  $permissions['override uib_external_content revision option'] = array(
    'name' => 'override uib_external_content revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_external_content sticky option'.
  $permissions['override uib_external_content sticky option'] = array(
    'name' => 'override uib_external_content sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_ou authored by option'.
  $permissions['override uib_ou authored by option'] = array(
    'name' => 'override uib_ou authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_ou authored on option'.
  $permissions['override uib_ou authored on option'] = array(
    'name' => 'override uib_ou authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_ou promote to front page option'.
  $permissions['override uib_ou promote to front page option'] = array(
    'name' => 'override uib_ou promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_ou published option'.
  $permissions['override uib_ou published option'] = array(
    'name' => 'override uib_ou published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_ou revision option'.
  $permissions['override uib_ou revision option'] = array(
    'name' => 'override uib_ou revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_ou sticky option'.
  $permissions['override uib_ou sticky option'] = array(
    'name' => 'override uib_ou sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_study authored by option'.
  $permissions['override uib_study authored by option'] = array(
    'name' => 'override uib_study authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_study authored on option'.
  $permissions['override uib_study authored on option'] = array(
    'name' => 'override uib_study authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_study promote to front page option'.
  $permissions['override uib_study promote to front page option'] = array(
    'name' => 'override uib_study promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_study published option'.
  $permissions['override uib_study published option'] = array(
    'name' => 'override uib_study published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_study revision option'.
  $permissions['override uib_study revision option'] = array(
    'name' => 'override uib_study revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_study sticky option'.
  $permissions['override uib_study sticky option'] = array(
    'name' => 'override uib_study sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_testimonial authored by option'.
  $permissions['override uib_testimonial authored by option'] = array(
    'name' => 'override uib_testimonial authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_testimonial authored on option'.
  $permissions['override uib_testimonial authored on option'] = array(
    'name' => 'override uib_testimonial authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_testimonial promote to front page option'.
  $permissions['override uib_testimonial promote to front page option'] = array(
    'name' => 'override uib_testimonial promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_testimonial published option'.
  $permissions['override uib_testimonial published option'] = array(
    'name' => 'override uib_testimonial published option',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_testimonial revision option'.
  $permissions['override uib_testimonial revision option'] = array(
    'name' => 'override uib_testimonial revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uib_testimonial sticky option'.
  $permissions['override uib_testimonial sticky option'] = array(
    'name' => 'override uib_testimonial sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'schedule (un)publishing of nodes'.
  $permissions['schedule (un)publishing of nodes'] = array(
    'name' => 'schedule (un)publishing of nodes',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'show format selection for field_collection_item'.
  $permissions['show format selection for field_collection_item'] = array(
    'name' => 'show format selection for field_collection_item',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for file'.
  $permissions['show format selection for file'] = array(
    'name' => 'show format selection for file',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
      'level 1' => 'level 1',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'toggle field translatability'.
  $permissions['toggle field translatability'] = array(
    'name' => 'toggle field translatability',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate any entity'.
  $permissions['translate any entity'] = array(
    'name' => 'translate any entity',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate content'.
  $permissions['translate content'] = array(
    'name' => 'translate content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'translation',
  );

  // Exported permission: 'translate file entities'.
  $permissions['translate file entities'] = array(
    'name' => 'translate file entities',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate taxonomy_term entities'.
  $permissions['translate taxonomy_term entities'] = array(
    'name' => 'translate taxonomy_term entities',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'use PHP for service visibility'.
  $permissions['use PHP for service visibility'] = array(
    'name' => 'use PHP for service visibility',
    'roles' => array(),
    'module' => 'service_links',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use text format basic_html'.
  $permissions['use text format basic_html'] = array(
    'name' => 'use text format basic_html',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format restricted_html'.
  $permissions['use text format restricted_html'] = array(
    'name' => 'use text format restricted_html',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view any unpublished area content'.
  $permissions['view any unpublished area content'] = array(
    'name' => 'view any unpublished area content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished content'.
  $permissions['view any unpublished content'] = array(
    'name' => 'view any unpublished content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished uib_article content'.
  $permissions['view any unpublished uib_article content'] = array(
    'name' => 'view any unpublished uib_article content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished uib_content_list content'.
  $permissions['view any unpublished uib_content_list content'] = array(
    'name' => 'view any unpublished uib_content_list content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished uib_external_content content'.
  $permissions['view any unpublished uib_external_content content'] = array(
    'name' => 'view any unpublished uib_external_content content',
    'roles' => array(),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished uib_ou content'.
  $permissions['view any unpublished uib_ou content'] = array(
    'name' => 'view any unpublished uib_ou content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished uib_study content'.
  $permissions['view any unpublished uib_study content'] = array(
    'name' => 'view any unpublished uib_study content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished uib_testimonial content'.
  $permissions['view any unpublished uib_testimonial content'] = array(
    'name' => 'view any unpublished uib_testimonial content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'admin' => 'admin',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'admin' => 'admin',
      'authenticated user' => 'authenticated user',
      'level 1' => 'level 1',
      'level 2' => 'level 2',
      'level 3' => 'level 3',
    ),
    'module' => 'system',
  );

  return $permissions;
}
