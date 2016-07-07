<?php
  db_query("DELETE FROM menu_links WHERE menu_name LIKE 'menu-area-%' AND depth > 2");
  db_query("UPDATE menu_links SET has_children = 0 WHERE menu_name LIKE 'menu_area_%' AND has_children <> 0 AND depth = 2");
