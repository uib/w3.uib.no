 CKEDITOR.addTemplates('uib_templates',{
   imagesPath: '/sites/all/modules/uib/uib_ckeditor_config/plugins/templates/images/',
   templates:[{
     title: 'Fact box',
     image: 'FAKTABOKS.svg',
     description: 'Collapsible fact box',
     html: '<div class="uib-feature__fact-box"><h2>Faktaboks</h2><div class="uib-feature__fact-box--facts collapsed"><p>Fakta kommer her</p></div></div>'
   },{
    title: 'Quote with name',
    image: 'SITAT_MED_NAVN.svg',
    description: 'Blockquote with name',
    html: '<blockquote><p>Insert quote here</p><p class="uib-feature__quote-author">Insert author here</p></blockquote>'
   },{
    title: 'Portrait image with text',
    image: 'PORTRETTFOTO_MED_BILDETEKST.svg',
    description: 'This inserts a portrait image with text to the right',
    html: '<div class="uib-feature__portrait-image"><img src=" " width="100px" height="100px"><p>Bilde tekst kommer her.</p></div>'
   },{
    title: 'Normal image with text',
    image: 'NORMALBREDDEBILDE_MED_BILDETEKST.svg',
    description: 'This inserts a image with text below',
    html: '<div class="uib-feature__image"><img src=" " width="100px" height="100px"><p>Bilde tekst kommer her.</p></div>'
   },{
    title: 'Full width image with text',
    image: 'FULLBREDDEBILDE_MED_BILDETEKST.svg',
    description: 'This inserts a full width image with text below',
    html: '<div class="uib-feature__full-width-image"><img src=" " width="100px" height="100px"><p>Bilde tekst kommer her.</p></div>'
   }
  ]
});
