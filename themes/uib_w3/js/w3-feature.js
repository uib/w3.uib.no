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
    if ($('.feature-image .content-top').length > 0) {
      var container = '.feature-image ';
      var imgContainer = container + '.field-name-field-uib-primary-media';
    }
    if ($('.feature-video .content-top').length > 0) {
      var container = '.feature-video ';
      var imgContainer = container + '.field-name-field-uib-feature-mobile-media';
    }
    var img = $(imgContainer + ' img');
    var imgNaturalHeight = img[0].naturalHeight;
    var imgNaturalWidth = img[0].naturalWidth;
    var imgFormat = imgNaturalWidth / imgNaturalHeight;
    var viewPortHeight = $(window).height();
    var mediaTop = $(container + '.content-top').position().top;
    var mediaHeight = viewPortHeight - mediaTop;
    var mediaWidth = $(window).width();
    var mediaFormat = mediaWidth / mediaHeight;
    var offset = img.offset();
    var imgX = 0;
    var imgY = mediaTop;
    if (mediaFormat < imgFormat) {
      var newImageHeight = mediaHeight;
      var newImageWidth = newImageHeight * imgFormat;
      imgX = (mediaWidth - newImageWidth) / 2;
    }
    else {
      var newImageWidth = mediaWidth;
      var newImageHeight = newImageWidth / imgFormat;
      imgY = imgY + (mediaHeight - newImageHeight) / 2;
    }
    $(imgContainer).height(mediaHeight);
    img.height(newImageHeight);
    img.width(newImageWidth);
    img.offset({top: imgY, left: imgX});
    img.css('max-width', newImageWidth);
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
