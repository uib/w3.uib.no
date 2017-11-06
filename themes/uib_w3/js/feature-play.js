(function ($) {
  Drupal.behaviors.featurePlay= {
    attach: function (context, settings) {
      if ($('.field-name-field-uib-main-media .file-video-vimeo').length > 0) {
        var primaryMedia = $('.field-name-field-uib-main-media iframe');
        var player = new Vimeo.Player(primaryMedia);
        $('.uib-play-video a').click(function(e) {
          w3VideoPlay(e, player);
        });
        player.on('pause', function(e) {
          $('.field-name-field-uib-main-media').removeClass('focus');
        });
        player.on('ended', function(e) {
          $('.field-name-field-uib-main-media').css('display', 'none');
        });
      }
      function w3VideoPlay(e, player) {
        e.preventDefault();
        $('.field-name-field-uib-main-media').addClass('focus');
        player.play();
      }
    }
  };
}(jQuery));
