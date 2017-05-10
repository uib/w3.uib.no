<?php
  db_query("update field_data_field_uib_study_title set language = 'en' where language = 'und' and entity_id in (select entity_id from field_data_field_uib_study_title where language = 'und' and entity_id not in (select entity_id from field_data_field_uib_study_title where language = 'en'))");
  db_query("delete from field_data_field_uib_study_title where language = 'und'");
