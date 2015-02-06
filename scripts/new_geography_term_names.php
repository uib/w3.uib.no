<?php
$vocab_name = 'uib_geography';
$vocab = taxonomy_vocabulary_machine_name_load($vocab_name);

// Get existing terms
$pre_existing = array();
$query = new EntityFieldQuery();
$result = $query->entityCondition('entity_type', 'taxonomy_term')
  ->propertyCondition('vid', $vocab->vid)
  ->execute();
if (!empty($result['taxonomy_term'])) {
  $terms = entity_load('taxonomy_term', array_keys($result['taxonomy_term']));
  foreach ($terms as $term) {
    $wrapper = entity_metadata_wrapper('taxonomy_term', $term);
    $new_name = $wrapper->language('nb')->field_uib_geographic_name->value() .
      ' / ' . $wrapper->language('en')->field_uib_geographic_name->value();
    $wrapper->name->set($new_name);
    $wrapper->save();
  }
}
