(function ($) {
  Drupal.behaviors.uib_tabs = {
    attach: function (context, settings) {
      $('.uib-tabs-container').tabs({
        show: function(event, ui) {
          if (ui.panel.id) {
            var initialScroll = $(window).scrollTop();
            window.location.hash = ui.panel.id;
            $(window).scrollTop(initialScroll);
            $('#page').scrollTop(0);
          }
          else {
            window.location.hash = "";
            $(window).scrollTop(0);
            $('#page').scrollTop(0);
            $('html, body').animate({ scrollTop: 0 }, 1);
          }
        }
      });
      $('.uib-tabs-nav-mobile').change(function() {
        var activeTab = $(this).find("option:selected").val();
        $('.offices.uib-tabs-container .ui-tabs-panel').addClass('ui-tabs-hide');
        $('#' + activeTab).removeClass('ui-tabs-hide');
        var initialScroll = $(window).scrollTop();
        window.location.hash = activeTab;
        $(window).scrollTop(initialScroll);
        $('#page').scrollTop(0);
      });
    }
  }
})(jQuery);
