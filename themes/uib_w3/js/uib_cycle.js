(function($){
  $(document).ready(function(){
    navTopOffset();
    slideShowHeight();
    $('.cycle-slideshow').on('cycle-after', function(e, opts) {
      slideShowHeight();
    });
  });
  $(window).on('resize', function(){
    navTopOffset();
  });

  function navTopOffset() {
    var pictureHeight = $('.uib-slideshow picture').css('height');
    if (pictureHeight == '0px') {
      pictureHeight = $('.uib-slideshow iframe').css('height');
    }
    var ownHeight = $('.uib-slideshow__nav--prev').css('height');
    var topOffset = (pictureHeight.slice(0, -2) / 2) - (ownHeight.slice(0, -2) / 2);
    $('.uib-slideshow__nav--prev').css('top', topOffset + 'px');
    $('.uib-slideshow__nav--next').css('top', topOffset + 'px');
  }

  function slideShowHeight() {
    var slideHeight = $('.cycle-slide-active').css('height');
    $('.cycle-slideshow').css('height', slideHeight.slice(0, -2));
  }
})(jQuery);
