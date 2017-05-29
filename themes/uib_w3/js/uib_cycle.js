(function($){
  $(document).ready(function(){
    navTopOffset();
  });
  $(window).on('resize', function(){
    navTopOffset();
  });

  function navTopOffset() {
    var pictureHeight = $('.uib-slideshow picture').css('height');
    var ownHeight = $('.uib-slideshow__nav--prev').css('height');
    var topOffset = (pictureHeight.slice(0, -2) / 2) - (ownHeight.slice(0, -2) / 2);
    $('.uib-slideshow__nav--prev').css('top', topOffset + 'px');
    $('.uib-slideshow__nav--next').css('top', topOffset + 'px');
  }
})(jQuery);
