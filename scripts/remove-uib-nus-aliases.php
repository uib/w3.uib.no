<?php
  $tree = taxonomy_get_tree(1);
  $tids = array();
  $dels = 0;
  foreach ($tree as $t) {
    uibx_log('Found taxonomy term in uib_nus with term ID ' . $t->tid);
    $num_del = db_delete('url_alias')
      ->condition('source', 'taxonomy/term/' . $t->tid)
      ->execute();
    uibx_log('Delete ' . $num_del . ' alias for taxonomy/term/' . $t->tid);
    if ($num_del > 0) $dels += $num_del;
  }
  uibx_log('A total of ' . $dels . ' were deleted');
