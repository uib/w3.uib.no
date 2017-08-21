(function ($) {
  $(document).ready(function() {
    alterMediaHeight();
  });
  $(window).resize(function() {
    alterMediaHeight();
  })
  $(window).scroll(function() {
    if ($(window).scrollTop() !== 0) {
      $('.field-name-field-uib-primary-media').addClass('scrolling')
    }
    else {
      $('.field-name-field-uib-primary-media').removeClass('scrolling')
    }
  });
  function alterMediaHeight() {
    var imgOffsetY = 0;
    var imgOffsetX = 0;
    var viewHeight = $(window).height();
    var mediaTop = $('.feature-image .content-top').position().top;
    var mediaHeight = viewHeight - mediaTop;
    var mediaWidth = $(window).width();
    $('.feature-image .field-name-field-uib-primary-media').height(mediaHeight);
    var imgHeight = $('.feature-image .field-name-field-uib-primary-media img').height();
    var imgWidth = $('.feature-image .field-name-field-uib-primary-media img').width();
    if (imgHeight !== mediaHeight) {
      var factor1 = mediaHeight/imgHeight;
      imgHeight = imgHeight * factor1;
      imgWidth = imgWidth * factor1;
    }
    if (imgWidth < mediaWidth) {
      var factor2 = mediaWidth/imgWidth;
      imgHeight = imgHeight * factor2;
      imgWidth = imgWidth * factor2;
    }
    if (imgHeight > mediaHeight) {
      imgOffsetY = Math.round((imgHeight - mediaHeight) / 2);
    }
    if (imgWidth > mediaWidth) {
      imgOffsetX = Math.round((imgWidth - mediaWidth) / 2);
    }
    $('.feature-image .field-name-field-uib-primary-media img').height(imgHeight);
    $('.feature-image .field-name-field-uib-primary-media img').width(imgWidth);
  }
}(jQuery));
