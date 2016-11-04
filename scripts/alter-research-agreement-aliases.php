<?php
  $result = db_query("select entity_id from field_data_field_uib_study_category where field_uib_study_category_value = 'mou' or field_uib_study_category_value = 'forskningsavtale'");
  $replacements = 0;
  foreach ($result as $eid) {
    uibx_log('Found research agrement at node ' .$eid->entity_id);
    $r = db_query("select pid, alias, language from url_alias where source = 'node/" . $eid->entity_id ."' and (alias like 'forskningsavtale%' or alias like 'research-agreement')");
    foreach ($r as $alias) {
      list($to_be_replaced, $study_code) = explode('/', $alias->alias);
      if ($alias->language == 'en') {
        $new_alias = 'bilateral-agreement/' . $study_code;
      }
      else {
        $new_alias = 'samarbeidsavtale/' . $study_code;
      }
      db_query("update url_alias set alias = '" . $new_alias . "' where pid = " . $alias->pid);
      uibx_log('Replacing alias ' . $alias->alias . ' with ' . $new_alias);
      $replacements++;
    }
  }
  uibx_log($replacements . ' aliases were updated.');
