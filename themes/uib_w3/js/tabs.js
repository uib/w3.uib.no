(function ($) {
  Drupal.behaviors.uib_tabs = {
    attach: function (context, settings) {
      $('.uib-tabs-nav-mobile').change(function() {
        var activeTab = $(this).find("option:selected").val();
        $('.offices.uib-tabs-container .ui-tabs-panel').addClass('ui-tabs-hide').hide();
        $('#' + activeTab).removeClass('ui-tabs-hide').show();
        var initialScroll = $(window).scrollTop();
        window.location.hash = activeTab;
        $(window).scrollTop(initialScroll);
        $('#page').scrollTop(0);
      });
    }
  }
})(jQuery);
