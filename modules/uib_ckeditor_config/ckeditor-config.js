CKEDITOR.editorConfig = function( config ) {
  config.removeDialogTabs = 'table:advanced;tableProperties:advanced';
  config.contentsCss = 'sites/all/modules/uib/uib_ckeditor_config/ckeditor.css';
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
    var info = dialogDefinition.getContents( 'info' );
    var toRemove = [ 'txtWidth', 'txtHeight', 'selHeaders', 'txtBorder', 'cmbAlign', 'txtCellSpace', 'txtCellPad', 'txtCaption', 'txtSummary' ];
    for ( key in toRemove ) {
      info.remove( toRemove[key] );
    }
  }
});
