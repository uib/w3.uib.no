CKEDITOR.editorConfig = function( config ) {
  // config.linkShowAdvancedTab = false;
  config.removeDialogTabs = 'link:advanced';
};

CKEDITOR.on( 'dialogDefinition', function( ev ) {
  var dialogName = ev.data.name;
  var dialogDefinition = ev.data.definition;

  if ( dialogName == 'link' ) {
    var targetTab = dialogDefinition.getContents( 'target' );
    var targetField = targetTab.get( 'linkTargetType' );
    targetField['items'] = [];
    targetField['items'][0] = ['<not set>', 'notSet'];
    targetField['items'][1] = ['New window (_blank)', '_blank'];
    targetField['items'][2] = ['Same window (_self)', '_self'];
  }
});
