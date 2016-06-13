<?php
  db_query("UPDATE {field_data_field_uib_text} SET field_uib_text_value = REPLACE(field_uib_text_value, 'filetopic_', '') ");
  db_query("UPDATE {field_data_field_uib_fact_box} SET field_uib_fact_box_value = REPLACE(field_uib_fact_box_value, 'filetopic_', '') ");
