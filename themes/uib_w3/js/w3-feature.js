(function ($) {
  $(document).ready(function() {
    alterMediaHeight();
    if ($('.field-name-field-uib-primary-media .file-video-vimeo').length > 0) {
      var primaryMedia = $('.field-name-field-uib-primary-media iframe');
      var player = new Vimeo.Player(primaryMedia);
      w3VideoAutoPlay(player);
      $('.uib-play-video a').click(function(e) {
        w3VideoPlay(e, player);
      });
      player.on('pause', function(e) {
        $('.field-name-field-uib-primary-media').removeClass('focus');
      });
    }
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
    if ($('.feature-image .content-top').length > 0) {
      var container = '.feature-image ';
      var imgResize = '.field-name-name-field-uib-primary-media';
    }
    if ($('.feature-video .content-top').length > 0) {
      var container = '.feature-video ';
      var imgResize = '.field-name-field-uib-feature-mobile-media';
    }
    var mediaTop = $(container + '.content-top').position().top;
    var mediaHeight = viewHeight - mediaTop;
    var mediaWidth = $(window).width();
    $(container + imgResize).height(mediaHeight);
    var imgHeight = $(container + imgResize + ' img').height();
    var imgWidth = $(container + imgResize + ' img').width();
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
    $(container + imgResize + ' img').height(imgHeight);
    $(container + imgResize + ' img').width(imgWidth);
  }
  function w3VideoAutoPlay(player) {
    var deviceHeight = $(window).height();
    var deviceWidth = $(window).width();
    if ((deviceHeight > 736 && deviceWidth > 414) || (deviceWidth > 736 && deviceHeight > 414)) {
      player.play();
    }
  }
  function w3VideoPlay(e, player) {
    e.preventDefault();
    $('.field-name-field-uib-primary-media').addClass('focus');
    player.play();
  }
}(jQuery));
