<?php

# This script prints the definitions for the bundles that we have
# defined in some imaginary Drupal programming language in the C family.

$fields = field_info_field_map();

$bundle = array();

foreach ($fields as $field => $info) {
  foreach ($info['bundles'] as $type => $bundles) {
    foreach ($bundles as $bundle_name) {
      if (!isset($bundle[$bundle_name])) {
        $bundle[$bundle_name] = array(
          'type' => $type,
          'fields' => array(),
        );
      }
      $field_short = preg_replace('/^field_uib_/', '_', $field);
      $bundle[$bundle_name]['fields'][] = array(
        'name' => $field_short,
        'type' => $info['type'],
      );
    }
  }
}

ksort($bundle);
foreach ($bundle as $name => $info) {
  print "bundle $name : $info[type] {\n";
  usort($info['fields'], function ($a, $b) {
    return strcmp($a['name'], $b['name']);
  });

  foreach ($info['fields'] as $field) {
    print "    $field[name]: $field[type],\n";
  }
  print "}\n\n";
}
