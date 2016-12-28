(function ($) {
  var lightbox = '';
  $(document).ready(function($){
    $('.block-uib-search #uib-search-noscript-form .search-button,' +
      '.not-translated-search'
    ).click(function(event){
      event.preventDefault();
      $.fn.uibSearchOpen();
    });
    $('.closeme').click(function(event){
      event.preventDefault();
      $('body,html').css('overflow', 'visible');
      uibSearchClose();
    })
    $('#switch_type_button').click(function () {
      var placeholder = $('form#uib-search-form .search-field')
        .attr('placeholder');
      $('form#uib-search-form .search-field').attr('placeholder',
        $('form#uib-search-form .search-field').attr('data-placeholder'));
      $('form#uib-search-form .search-field').attr('data-placeholder',
        placeholder);
      if ($(this).is(':checked')) {
        $(this).siblings('label').html($(this).attr('data-toggle-title'));
        $('form#uib-search-form .results').css('display', 'block');
        $('form#uib-search-form .search-field').keyup();
      } else {
        $(this).siblings('label').html($(this).attr('data-title'));
        $('form#uib-search-form .results').css('display', 'none');
      }
      $('.block-uib-search .lightbox .search-field').focus();
    });
    $('#search-filter-checkboxes input').click(function() {
      var otherchecked =
        $('#search-filter-checkboxes input[value!=everything]')
          .is(':checked');
      if ($(this).attr('value') == 'everything') {
        $(this).prop('checked', true);
        $('#search-filter-checkboxes input[value!=everything]')
          .prop('checked', false);
      }
      else {
        if (otherchecked) {
          $('#search-filter-checkboxes input[value=everything]')
            .prop('checked', false)
        }
        else {
          $('#search-filter-checkboxes input[value=everything]')
            .prop('checked', true)
        }
      }
      $('form#uib-search-form .search-field').keyup();
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
    $('.global-search .form-item-filters>label').click(function(event) {
      if ($(this).css('background-image') !== 'none') {
        if(
          $(this).attr('data-toggle') == 'true'
        ){
          $(this).attr('data-toggle', 'false')
        }
        else {
          $(this).attr('data-toggle', 'true')
        }
      }
    });
  uibDisableCheckboxes();
  });
  function uibSearchClose(){
    lightbox = $('#uib-search-lightbox-bottom').detach();
  }
  $.fn.uibSearchOpen = function() {
    $('body,html').css('overflow', 'hidden');
    if (lightbox.length > 0) {
      $(lightbox).appendTo('body');
    } else {
      if($('#uib-search-lightbox-bottom').length==0){
        $('.block-uib-search form#uib-search-form').appendTo(
          $('<div id="uib-search-lightbox-bottom" class="block-uib-search"/>').appendTo('body')
        );
      }
      $('.block-uib-search .lightbox').css('display','block');
      $('.block-uib-search .lightbox .search-field').focus();
      $('.block-uib-search .lightbox').animate({
        'opacity': 1
      }, 300);
    }
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
