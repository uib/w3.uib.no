CKEDITOR.editorConfig = function( config ) {
  //config.removeDialogTabs = 'table:advanced;tableProperties:advanced';
  config.removeDialogTabs = 'table:advanced';
  config.contentsCss = '/sites/all/modules/uib/uib_ckeditor_config/ckeditor.css';
  config.extraPlugins = 'dialog,dialogui';
  config.pasteFilter = 'p; a[!href]; h2; h3; h4; strong; em; ul; ol; li; sup; sub';
  config.templates_replaceContent = false;
};

CKEDITOR.on( 'dialogDefinition', function( ev ) {
  var dialogName = ev.data.name;
  var dialogDefinition = ev.data.definition;

  if ( dialogName == 'link' ) {
    var advancedTab = dialogDefinition.getContents( 'advanced' );
    var toRemove = [ 'advId', 'advLangDir', 'advAccessKey', 'advName', 'advLangCode', 'advTabIndex', 'advContentType', 'advCSSClasses', 'advCharset', 'advRel', 'advStyles' ];
    for ( key in toRemove ) {
      advancedTab.remove( toRemove[key] );
    }
    var targetTab = dialogDefinition.getContents( 'target' );
    var targetField = targetTab.get( 'linkTargetType' );
    targetField['items'] = [];
    targetField['items'][0] = ['<not set>', 'notSet'];
    targetField['items'][1] = ['New window (_blank)', '_blank'];
    targetField['items'][2] = ['Same window (_self)', '_self'];
  }

  if ( dialogName == 'table' || dialogName == 'tableProperties' ) {
    var advancedTab = dialogDefinition.getContents( 'advanced' );
    var advRemove = ['advId','advLangDir','advStyles'];
    for ( key in advRemove ) {
      advancedTab.remove( advRemove[key] );
    }
    var tableCSS = advancedTab.get('advCSSClasses');
    var help_text = {
      type : 'html',
      html : '<p>Add stylesheet class "sortable" to make the table sortable</p>'
    }
    advancedTab.add(help_text);
    var info = dialogDefinition.getContents( 'info' );
    var toRemove = [ 'txtWidth', 'txtHeight', 'selHeaders', 'txtBorder', 'cmbAlign', 'txtCellSpace', 'txtCellPad', 'txtCaption', 'txtSummary' ];
    for ( key in toRemove ) {
      info.remove( toRemove[key] );
    }
  }

  if ( dialogName == 'cellProperties' ) {
    var info = dialogDefinition.getContents( 'info' );
    var toRemove = [ 'wordWrap', 'vAlign', 'hAlign', 'width', 'widthType', 'height', 'htmlHeightType', 'borderColor', 'borderColorChoose', 'bgColor', 'bgColorChoose' ];
    for ( key in toRemove ) {
      info.remove( toRemove[key] );
    }
    console.log(info);
  }

  if ( dialogName == 'image' ) {
    dialogDefinition.removeContents('Link');
    dialogDefinition.removeContents('advanced');
    var infoTab = dialogDefinition.getContents( 'info' );
    var toRemove = [ 'txtWidth', 'txtHeight', 'txtBorder', 'cmbAlign', 'txtHSpace', 'txtVSpace', 'ratioLock', 'htmlPreview' ];
    for ( key in toRemove ) {
      infoTab.remove( toRemove[key] );
    }
  }
});
