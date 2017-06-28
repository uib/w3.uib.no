<?php
require_once drupal_get_path('module', 'entityreference') .
  '/plugins/selection/EntityReference_SelectionHandler_Generic.class.php';

class EntityReference_SelectionHandler_Byline
  extends EntityReference_SelectionHandler_Generic {

  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    $field['settings']['handler_settings']['autocomplete_items_limit'] = 40;
    $target_entity_type = $field['settings']['target_type'];

    // Check if the entity type does exist and has a base table.
    $entity_info = entity_get_info($target_entity_type);

    if (empty($entity_info['base table'])) {
      return EntityReference_SelectionHandler_Broken::getInstance($field, $instance);
    }
    if (class_exists($class_name = 'EntityReference_SelectionHandler_Byline_' . ucfirst($target_entity_type))) {
      return new $class_name($field, $instance, $entity_type, $entity);
    }

    return parent::getInstance($field, $instance, $entity_type, $entity);
  }
}

class EntityReference_SelectionHandler_Byline_User extends EntityReference_SelectionHandler_Byline {
  public function buildEntityFieldQuery($match = NULL, $match_operator = 'CONTAINS') {
    $query = parent::buildEntityFieldQuery($match, $match_operator);
    if (isset($match)) {
      // Add tag to alter query using hook_query_TAG_alter
      $query->addTag('autocompleteuser');
      $query->addMetaData('match', $match);
    }
    if (count($query->fields)) {
      $query->addTag('field_data_field_uib_sort_name');
    }
    // Adding the 'user_access' tag is sadly insufficient for users: core
    // requires us to also know about the concept of 'blocked' and
    // 'active'.
    if (!user_access('administer users')) {
      $query->propertyCondition('status', 1);
    }
    return $query;
  }
}
