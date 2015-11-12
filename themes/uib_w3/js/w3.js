jQuery(document).ready(function($){
  $('.block-uib-search form[name=noscriptform] .search-button').click(function(event){
    event.preventDefault();
    if($('#uib-search-lightbox-bottom').length==0){
      $('.block-uib-search form[name=lbform]').appendTo(
        $('<div id="uib-search-lightbox-bottom" class="block-uib-search"/>').appendTo('body')
      );
    }
    $('.block-uib-search .lightbox').css('display','block');
    $('.block-uib-search .lightbox .search-field').focus();
    $('.block-uib-search .lightbox').animate({
      'opacity': .8
    }, 300);
  });
  $('.closeme').click(function(event){
    event.preventDefault();
    $('.block-uib-search .lightbox').css('display','none');
    $('.block-uib-search .lightbox').css('opacity','0');
  })
});
