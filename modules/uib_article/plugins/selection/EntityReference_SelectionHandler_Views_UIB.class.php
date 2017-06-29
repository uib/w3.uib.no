<?php

require_once drupal_get_path('module', 'entityreference') .
  '/plugins/selection/EntityReference_SelectionHandler_Views.class.php';

/**
 * Extending the views handler plugin to change autocomplete items limit
 */
class EntityReference_SelectionHandler_Views_UIB extends EntityReference_SelectionHandler_Views {
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    $field['settings']['handler_settings']['autocomplete_items_limit'] = 40;
    return parent::getInstance($field, $instance);
  }
}
