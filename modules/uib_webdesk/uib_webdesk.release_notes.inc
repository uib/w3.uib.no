<?php

function uib_webdesk__release_notes_page() {

  $notes_md = file_get_contents('../doc/release-notes.md');
  if (!$notes_md)
    return MENU_NOT_FOUND;

  $page = array();

  $heading = 'Release notes';
  $version = uibx_current_version();
  if ($version) {
    $heading .= " for w3.uib.no versjon $version";
  }

  $page['heading'] = array('#markup' => '<h1>' . check_plain($heading) . '</h1>');


  if (module_load_include('inc.php', 'markdown', 'includes/MarkdownExtra')) {
    $notes_md = preg_replace('/^\#/m', '##', $notes_md);  // start headings at h2
    $notes_html = \Michelf\MarkdownExtra::defaultTransform($notes_md);
    $notes_html = preg_replace_callback('/#(\d+)/', function ($matches) {
      return '<a href="https://rts.uib.no/issues/' . $matches[1] . '">' . $matches[0] . '</a>';
    }, $notes_html);
    $page['text']['#markup'] = $notes_html;
  }
  else {
    $page['raw']['#markup'] = '<pre>' . check_plain($notes_md) . '</pre>';
  }

  drupal_add_css('
    .page-webdesk-release-notes h2 { margin-top: 2.5em; margin-bottom: 1.5em; }
    h2 em { font-size: 60%; font-style: normal; color: #cf3c3a; font-weight: normal; display: block; margin-top: -3em; }
  ', array('type' => 'inline', 'group' => CSS_THEME));

  return $page;
}
