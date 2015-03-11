<?php
/**
 * Convert certain study views into content "view page"
 */

$contype = 'uib_views_page';
$utdanning = array(node_load(48591));

// Exchange agreements

$new_node = entity_create('node', array(
  'type' => $contype,
  'uid' => 1,
  'status' => 1,
  'revision' => 0,
  )
);
$metadata = entity_metadata_wrapper('node', $new_node);
$handler = entity_translation_get_handler('node', $new_node, TRUE);
$translation = array(
  'translate' => 0,
  'status' => 1,
  'language' => 'en',
  'source' => 'nb',
);
$handler->setTranslation($translation, $new_node);
$metadata->title->set('utvekslingsavtale');
$metadata->field_uib_area->set($utdanning);
$metadata->language->set('nb');
$metadata->language('nb')->field_uib_node_title->set('Finn utvekslingsavtaler');
$metadata->language('en')->field_uib_node_title->set('Find exchange agreements');
$metadata->field_uib_view_block_name->set('exchange_agreements-b1');
$info = array(
  'format' => 'basic_html',
  'value' => 'På denne sida kan du finne fram til den utvekslingsavtalen som er den rette for deg:

- Under «Søk etter fakultet» kan du hake av for avtaleeigar, eller ‘Universitetet i Bergen’ (sentralt eigde utvekslingsavtalar som dei fleste studentar ved UiB kan søke seg ut gjennom).

- Bruk eventuelt land-filteret.

- Dersom du lar alt stå tomt får du opp heile UiB sin avtaleportefølje.
',
);
$metadata->language('nb')->field_uib_view_information->set($info);
$info['value'] = 'The University of Bergen has bilateral agreements, Erasmus agreements, and other network agreements with approximately 450 renowned universities around the world. This search page makes it easier for you to find the agreement most suitable for you. Search for faculty to obtain a list of exchange agreements that belong to your faculty. If you search for "University of Bergen" (university-wide agreements) you will get an overview of exchange agreements through which most UiB students may apply for exchange.';
$metadata->language('en')->field_uib_view_information->set($info);
$metadata->save();

$existing_alias = uibx_path_load('exchange-agreement');
path_delete($existing_alias[0]->pid);
$path = array(
  'source' => 'node/' . $new_node->nid,
  'alias' => 'exchange-agreement',
  'language' => 'en',
);
path_save($path);
$path = array(
  'source' => 'node/' . $new_node->nid,
  'alias' => 'utvekslingsavtale',
  'language' => 'nb',
);
path_save($path);

// Study programmes

$new_node = entity_create('node', array(
  'type' => $contype,
  'uid' => 1,
  'status' => 1,
  'revision' => 0,
  )
);
$metadata = entity_metadata_wrapper('node', $new_node);
$handler = entity_translation_get_handler('node', $new_node, TRUE);
$translation = array(
  'translate' => 0,
  'status' => 1,
  'language' => 'en',
  'source' => 'nb',
);
$handler->setTranslation($translation, $new_node);
$metadata->title->set('Search for study programmes');
$metadata->field_uib_area->set($utdanning);
$metadata->language->set('nb');
$metadata->language('nb')->field_uib_node_title->set('Søk i studieprogram');
$metadata->language('en')->field_uib_node_title->set('Search for study programmes');
$metadata->field_uib_view_block_name->set('study_blocks-studypr_all_b1');
$metadata->save();
$pre_aliases = array('studyprogramme');
$pre_langs = array('en');
$existing_alias = uibx_path_load('studyprogramme');
foreach ($existing_alias as $prev) {
  $pre_aliases[] = $prev->alias;
  $pre_langs[] = $prev->language;
  path_delete($prev->pid);
}
foreach ($pre_aliases as $delta => $alias) {
  $path = array(
    'source' => 'node/' . $new_node->nid,
    'alias' => $alias,
    'language' => $pre_langs[$delta],
  );
  path_save($path);
}

// Courses

$new_node = entity_create('node', array(
  'type' => $contype,
  'uid' => 1,
  'status' => 1,
  'revision' => 0,
  )
);
$metadata = entity_metadata_wrapper('node', $new_node);
$handler = entity_translation_get_handler('node', $new_node, TRUE);
$translation = array(
  'translate' => 0,
  'status' => 1,
  'language' => 'en',
  'source' => 'nb',
);
$handler->setTranslation($translation, $new_node);
$metadata->title->set('Search for courses');
$metadata->field_uib_area->set($utdanning);
$metadata->language->set('nb');
$metadata->language('nb')->field_uib_node_title->set('Søk i emner');
$metadata->language('en')->field_uib_node_title->set('Search for courses');
$metadata->field_uib_view_block_name->set('study_blocks-courses_all_b1');
$metadata->save();
$pre_aliases = array('course');
$pre_langs = array('en');
$existing_alias = uibx_path_load('course');
foreach ($existing_alias as $prev) {
  $pre_aliases[] = $prev->alias;
  $pre_langs[] = $prev->language;
  path_delete($prev->pid);
}
foreach ($pre_aliases as $delta => $alias) {
  $path = array(
    'source' => 'node/' . $new_node->nid,
    'alias' => $alias,
    'language' => $pre_langs[$delta],
  );
  path_save($path);
}

// Special study listing: exchange

$new_node = entity_create('node', array(
  'type' => $contype,
  'uid' => 1,
  'status' => 1,
  'revision' => 0,
  )
);
$metadata = entity_metadata_wrapper('node', $new_node);
$handler = entity_translation_get_handler('node', $new_node, TRUE);
$translation = array(
  'translate' => 0,
  'status' => 1,
  'language' => 'en',
  'source' => 'nb',
);
$handler->setTranslation($translation, $new_node);
$metadata->title->set('Courses for exchange students');
$metadata->field_uib_area->set($utdanning);
$metadata->language->set('nb');
$metadata->language('nb')->field_uib_node_title->set('Emner for utvekslingsstudenter');
$metadata->language('en')->field_uib_node_title->set('Courses for exchange students');
$metadata->field_uib_view_block_name->set('special_study_listings-b1');
$info = array(
  'format' => 'basic_html',
  'value' => '',
);
$metadata->language('nb')->field_uib_view_information->set($info);
$info = array(
  'format' => 'basic_html',
  'value' => 'You can filter the list of courses for <a href="http://www.uib.no/en/education/48741/admission-exchange-students">exchange students</a>
    below by faculty and semester (autumn/ spring).
    Read more about how to choose your courses <a href="http://www.uib.no/en/education/50052/courses-exchange-students">here</a>.',
);
$metadata->language('en')->field_uib_view_information->set($info);
$metadata->save();
$path = array(
  'source' => 'node/' . $new_node->nid,
  'alias' => 'education/exchange',
  'language' => 'en',
);
path_save($path);
