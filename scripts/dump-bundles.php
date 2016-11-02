<?php

# This script prints the definitions for the bundles that we have
# defined in some imaginary Drupal programming language in the C family.

$fields = field_info_fields();
$instance_info_map = field_info_instances();

$bundle = array(); # our output

foreach ($fields as $field_name => $field_info) {
  foreach ($field_info['bundles'] as $type => $bundles) {
    foreach ($bundles as $bundle_name) {
      $instance_info = $instance_info_map[$type][$bundle_name][$field_name];
      if (!isset($bundle[$bundle_name])) {
        $bundle[$bundle_name] = array(
          'type' => $type,
          'fields' => array(),
        );
      }
      $ftype = $field_info['type'];
      if ($field_info['cardinality'] == -1) {
        $ftype .= $instance_info['required'] ? "+" : "*";
      }
      elseif ($field_info['cardinality'] > 1) {
        $ftype .= '{';
        $ftype .= $instance_info['required'];
        $ftype .= ',';
        $ftype .= $field_info['cardinality'];
        $ftype .= '}';
      }
      elseif (!$instance_info['required']) {
          $ftype .= '?';
      }
      $bundle[$bundle_name]['fields'][] = array(
        'name' => preg_replace('/^field_uib_/', '_', $field_name),
        'type' => $ftype,
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
