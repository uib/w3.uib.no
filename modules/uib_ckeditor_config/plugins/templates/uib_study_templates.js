 CKEDITOR.addTemplates('uib_study_templates',{
   imagesPath: '/sites/all/modules/uib/uib_ckeditor_config/plugins/templates/images/',
   templates:[{
     title: 'Practical information',
     image: 'FAKTABOKS.svg',
     description: 'Practical information about this study prgramme',
     html: '(* studyinfo *)',
   },{
    title: 'Testimonial',
    image: 'SITAT_MED_NAVN.svg',
    description: 'Relevant testimonial for this study',
    html: '(* testimonial *)'
   },{
    title: 'Portrait image with text',
    image: 'PORTRETTFOTO_MED_BILDETEKST.svg',
    description: 'This inserts a portrait image with text to the right',
    html: '<div class="uib-study__portrait-image"><img src=" " width="100px" height="100px"><div class="uib-study__media-info"><p>Bilde tekst kommer her.</p></div></div>'
   },{
    title: 'Normal image with text',
    image: 'NORMALBREDDEBILDE_MED_BILDETEKST.svg',
    description: 'This inserts a image with text below',
    html: '<div class="uib-study__image"><img src=" " width="100px" height="100px"><div class="uib-study__media-info"><p>Bilde tekst kommer her.</p></div></div>'
   },{
    title: 'Full width image with text',
    image: 'FULLBREDDEBILDE_MED_BILDETEKST.svg',
    description: 'This inserts a full width image with text below',
    html: '<div class="uib-study__full-width-image"><img src=" " width="100px" height="100px"><div class="uib-study__media-info"><p>Bilde tekst kommer her.</p></div></div>'
   }
  ]
});
