<?php
  db_query('delete from taxonomy_term_data where vid=3 and tid not in (select field_uib_user_competence_tid from field_data_field_uib_user_competence)');
