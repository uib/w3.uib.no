(function ($) {
  Drupal.behaviors.uibStudyBehavior = {
    attach: function (context, settings) {
      $('.study-listing').accordion({
        active: false,
        collapsible: true,
        heightStyle: 'content',
        icons: false
      });
    }
  };
})(jQuery);
