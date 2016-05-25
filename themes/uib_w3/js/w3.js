(function ($) {
  var lightbox = '';
  $(document).ready(function($){
    $('.block-uib-search form[name=noscriptform] .search-button').click(function(event){
      event.preventDefault();
      $('body,html').css('overflow', 'hidden');
      if (lightbox.length > 0) {
        $(lightbox).appendTo('body');
      } else {
        if($('#uib-search-lightbox-bottom').length==0){
          $('.block-uib-search form[name=lbform]').appendTo(
            $('<div id="uib-search-lightbox-bottom" class="block-uib-search"/>').appendTo('body')
          );
        }
        $('.block-uib-search .lightbox').css('display','block');
        $('.block-uib-search .lightbox .search-field').focus();
        $('.block-uib-search .lightbox').animate({
          'opacity': 1
        }, 300);
      }
    });
    $('.closeme').click(function(event){
      event.preventDefault();
      $('body,html').css('overflow', 'visible');
      uibSearchClose();
    })
    $('#switch_type_button').click(function () {
      var placeholder = $('form[name=lbform] .search-field')
        .attr('placeholder');
      $('form[name=lbform] .search-field').attr('placeholder',
        $('form[name=lbform] .search-field').attr('data-placeholder'));
      $('form[name=lbform] .search-field').attr('data-placeholder',
        placeholder);
      if ($(this).is(':checked')) {
        $(this).siblings('label').html($(this).attr('data-toggle-title'));
        $('form[name=lbform] .results').css('display', 'block');
        $('form[name=lbform] .search-field').keyup();
      } else {
        $(this).siblings('label').html($(this).attr('data-title'));
        $('form[name=lbform] .results').css('display', 'none');
      }
      $('.block-uib-search .lightbox .search-field').focus();
    });
    $(document).keyup(function(e) {
      if (e.which == 27) {
        if($('#uib-search-lightbox-bottom').length==1 &&
          $('.block-uib-search .lightbox').css('display')!='none'){
          uibSearchClose();
        }
      }
    });
    if(!$('.uib-area-expanded-menu').length) {
      if(!$('#main-menu .menu .menu__item').hasClass('jstransition')){
        $('#main-menu .menu .menu__item').addClass('jstransition');
      }
      $('#main-menu .menu .menu__item.jstransition').hover(
        function(e){
          $(this).children('ul').first().clearQueue();
          $(this).children('ul').first().stop().delay(200).animate(
            {
              height: $(this).children('ul').first().get(0).scrollHeight+80,
              minHeight: '23.5rem',
              paddingTop: '1.875rem',
              paddingRight: '1.875rem',
              paddingBottom: '1.875rem',
            }, 400 );
      }, function(e){
        $(this).children('ul').first().clearQueue();
        $(this).children('ul').first().stop().animate(
          {
            height: 0,
            minHeight: 0,
            paddingTop: 0,
            paddingRight: 0,
            paddingBottom: 0,
          }, 300 );
      });
    }
  uibDisableCheckboxes();
  });
  function uibSearchClose(){
    lightbox = $('#uib-search-lightbox-bottom').detach();
  }
  $(document).ajaxSuccess(function(){
    uibDisableCheckboxes();
  });
  // Function for disabling other faculty checkboxes when UIB is checked
  function uibDisableCheckboxes(){
    var uib=".view-exchange-agreements #edit-term-node-tid-depth-1-2271";
    if($(uib).is(':checked')){
      $(uib).parents('.bef-checkboxes').find('input:not(' + uib + ')')
        .attr('disabled', 'disabled');
    }
    $(uib).click(function(){
      if($(this).is(':checked')){
        $(this).parents('.bef-checkboxes').find('input:not(' + uib + ')')
          .attr('disabled', 'disabled');
      }
      else{
        $(this).parents('.bef-checkboxes').find('input').removeAttr('disabled');
      }
    });
  }
})(jQuery);
