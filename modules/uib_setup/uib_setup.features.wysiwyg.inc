<?php

/**
 * @file
 * uib_setup.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function uib_setup_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: basic_html.
  $profiles['basic_html'] = array(
    'format' => 'basic_html',
    'editor' => 'ckeditor',
    'settings' => array(
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'Strike' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Undo' => 1,
          'Redo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Anchor' => 1,
          'Superscript' => 1,
          'Subscript' => 1,
          'Blockquote' => 1,
          'Cut' => 1,
          'Copy' => 1,
          'PasteFromWord' => 1,
          'SpecialChar' => 1,
          'Format' => 1,
          'Styles' => 1,
          'Table' => 1,
          'Maximize' => 1,
          'Templates' => 1,
        ),
        'picture_ckeditor' => array(
          'picture_ckeditor' => 1,
        ),
        'eqneditor' => array(
          'EqnEditor' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'theme' => '',
      'language' => 'en',
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 0,
      'acf_mode' => 0,
      'acf_allowed_content' => '',
      'css_setting' => 'none',
      'css_theme' => 'adminimal',
      'css_path' => '',
      'stylesSet' => 'Call to action=a.study--call-to-action',
      'block_formats' => 'p,h2,h3,h4',
      'forcePasteAsPlainText' => 0,
      'pasteFromWordNumberedHeadingToList' => 0,
      'pasteFromWordPromptCleanup' => 0,
      'pasteFromWordRemoveFontStyles' => 1,
      'pasteFromWordRemoveStyles' => 1,
    ),
    'preferences' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 0,
      'add_to_summaries' => 1,
      'version' => '4.5.7.e98277f',
    ),
    'name' => 'formatbasic_html',
  );

  // Exported profile: feature_text_html.
  $profiles['feature_text_html'] = array(
    'format' => 'feature_text_html',
    'editor' => 'ckeditor',
    'settings' => array(
      'theme' => '',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'Strike' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Undo' => 1,
          'Redo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Anchor' => 1,
          'Superscript' => 1,
          'Subscript' => 1,
          'Blockquote' => 1,
          'Paste' => 1,
          'PasteFromWord' => 1,
          'ShowBlocks' => 1,
          'SpecialChar' => 1,
          'Format' => 1,
          'Table' => 1,
          'Maximize' => 1,
          'Templates' => 1,
        ),
        'picture_ckeditor' => array(
          'picture_ckeditor' => 1,
        ),
        'eqneditor' => array(
          'EqnEditor' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 0,
      'acf_mode' => 0,
      'acf_allowed_content' => '',
      'css_setting' => 'none',
      'css_path' => '',
      'stylesSet' => '',
      'block_formats' => 'h2,h3,h4',
      'advanced__active_tab' => 'edit-basic',
      'forcePasteAsPlainText' => 0,
    ),
    'preferences' => array(
      'add_to_summaries' => 1,
      'default' => 1,
      'show_toggle' => 1,
      'user_choose' => 0,
      'version' => '4.5.7.e98277f',
    ),
    'name' => 'formatfeature_text_html',
  );

  // Exported profile: restricted_html.
  $profiles['restricted_html'] = array(
    'format' => 'restricted_html',
    'editor' => 'ckeditor',
    'settings' => array(
      'theme' => '',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'Strike' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Undo' => 1,
          'Redo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Anchor' => 1,
          'Superscript' => 1,
          'Subscript' => 1,
          'Cut' => 1,
          'Copy' => 1,
          'PasteFromWord' => 1,
          'SpecialChar' => 1,
          'Format' => 1,
          'Maximize' => 1,
        ),
      ),
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 0,
      'acf_mode' => 0,
      'acf_allowed_content' => '',
      'css_setting' => 'none',
      'css_path' => '',
      'stylesSet' => '',
      'block_formats' => 'p,h3,h4',
      'advanced__active_tab' => 'edit-basic',
      'forcePasteAsPlainText' => 0,
    ),
    'preferences' => array(
      'add_to_summaries' => 1,
      'default' => 1,
      'show_toggle' => 0,
      'user_choose' => 0,
      'version' => '4.5.7.e98277f',
    ),
    'name' => 'formatrestricted_html',
  );

  // Exported profile: study_text_html.
  $profiles['study_text_html'] = array(
    'format' => 'study_text_html',
    'editor' => 'ckeditor',
    'settings' => array(
      'theme' => '',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'Strike' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Undo' => 1,
          'Redo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Anchor' => 1,
          'Superscript' => 1,
          'Subscript' => 1,
          'Blockquote' => 1,
          'Paste' => 1,
          'PasteFromWord' => 1,
          'ShowBlocks' => 1,
          'SpecialChar' => 1,
          'Format' => 1,
          'Styles' => 1,
          'Table' => 1,
          'Maximize' => 1,
          'Templates' => 1,
        ),
        'picture_ckeditor' => array(
          'picture_ckeditor' => 1,
        ),
        'eqneditor' => array(
          'EqnEditor' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 0,
      'acf_mode' => 0,
      'acf_allowed_content' => '',
      'css_setting' => 'none',
      'css_path' => '',
      'stylesSet' => 'Call to action=a.study--call-to-action',
      'block_formats' => 'p,h2,h3,h4',
      'advanced__active_tab' => 'edit-css',
      'forcePasteAsPlainText' => 0,
    ),
    'preferences' => array(
      'add_to_summaries' => 1,
      'default' => 1,
      'show_toggle' => 0,
      'user_choose' => 0,
      'version' => '4.5.7.e98277f',
    ),
    'name' => 'formatstudy_text_html',
  );

  return $profiles;
}
