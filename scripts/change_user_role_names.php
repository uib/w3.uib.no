<?php
  db_query("update role set name = 'superbruker', machine_name = 'superbruker' where machine_name = 'level_1'");
  db_query("update role set name = 'innholdsprodusent', machine_name = 'innholdsprodusent' where machine_name = 'level_2'");
