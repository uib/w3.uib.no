<?php

/**
* Usage: bin/site-drush node-update-image-caption
*
* The script updates nodes creating imagecaption-field-collections of the
* image description given in an image file entity. The script selects 1000 nodes
* and updates a log file (default doc/nodes_updated_rel79.txt) with handled
* nodes, and another (default doc/nid_fid_not_updated_rel79.txt) with errors.
* You'll need to run the script many times to handle all nodes in w3, as the
* site contains 100000+ nodes. The script starts with the last handled node in
* the log file, and goes on from there.
*
*
* Options:
* -e / --errors=/path/to/errorfile
* -l / --log=/path/to/logfile
* -v / --verbose Display more output
*
*/

// Declaring global log files
global $log, $errors, $verbose;
$log = drush_get_option(array('log', 'l'), dirname(__DIR__) . '/doc/nodes_updated_rel79.txt');
$errors = drush_get_option(array('errors', 'e'), dirname(__DIR__) . '/doc/nid_fid_not_updated_rel79.txt');
$verbose = drush_get_option(array('verbose', 'v'));

$f = @file($GLOBALS['log']);
$last = 0;
if ($f !== FALSE) {
  $last = intval(end($f));
}

// Select 1000 nodes
$sql = "Select nid from node where nid >=$last order by nid asc limit 1000";

$result = db_query($sql);
$count = 0;

foreach ($result as $record) {
  $count += uib__update_image_caption($record->nid);
}
if ($GLOBALS['verbose'] && $count > 0) {
  uibx_log($count . ' media description(s) saved as field collection(s).', 'notice');
}

function uib__update_image_caption($nid) {
  $w = entity_metadata_wrapper('node', $nid);
  $count = 0;
  try {
    $count = uib__caption_for_media($w, 'field_uib_main_media', 'field_uib_imagecaptions');
    file_put_contents(
      $GLOBALS['log'],
      $w->getIdentifier() . "\n",
      FILE_APPEND
    );
  } catch (Exception $e) {
    uibx_log("Error with node " . $w->getIdentifier()
    . " field_uib_main_media or field_uib_imagecaptions" , 'warning');
    file_put_contents(
      $GLOBALS['errors'],
      $w->getIdentifier() . "\n",
      FILE_APPEND
    );
  }

  try {
    $count += uib__caption_for_media($w, 'field_uib_media', 'field_uib_imagecaptions2');
  } catch (Exception $e) {
    uibx_log("Error with node " . $w->getIdentifier()
    . " field_uib_media or field_uib_imagecaptions2" , 'warning');
    file_put_contents(
      $GLOBALS['errors'],
      $w->getIdentifier() . "\n",
      FILE_APPEND
    );
  }
  return $count;
}

function uib__caption_for_media(
  $wrapper,
  $mediafield = 'field_uib_main_media',
  $captionfield = 'field_uib_imagecaptions'
) {
  $count = 0;
  if (isset($wrapper->$mediafield)) {
    foreach ($wrapper->$mediafield as $k => $v) {
      $value = $v->value();
      try{
        $has = FALSE;
        if (isset($wrapper->$captionfield)) {
          foreach ($wrapper->$captionfield as $i => $caption) {
            if ($caption->field_uib_imageindex->value()-1 == $k) {
              $has = TRUE;
              continue;
            }
          }
        }
        if (!$has) {
          $count++;
            $file = entity_metadata_wrapper('file', $value['fid']);
            $collection = entity_create(
              'field_collection_item',
              array('field_name' => $captionfield));
            $collection->setHostEntity('node', $wrapper->value());
            $c = entity_metadata_wrapper('field_collection_item', $collection);
            $c->field_uib_imagecaption->set($file->field_uib_description->value());
            $c->field_uib_imageindex->set($k+1);
            $c->save();
        }
      } catch(Exception $e) {
        uibx_log("Error with node " . $wrapper->getIdentifier()
          . " file " . $value['fid'], 'warning');
        file_put_contents(
          $GLOBALS['errors'],
          $wrapper->getIdentifier() . "\t" . $value['fid'] . "\n",
          FILE_APPEND
        );
      }
    }
  }
  return $count;
}
