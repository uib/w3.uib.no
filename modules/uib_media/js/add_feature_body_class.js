(function ($) {
  Drupal.behaviors.addFeatureBodyClass = {
    attach: function (context, settings) {
      if ($("#edit-field-uib-feature-article-und").attr("checked")) $("body").addClass("feature-article");
      $("#edit-field-uib-feature-article-und").click(function() {
        if ($( this ).prop("checked")) $("body").addClass("feature-article")
        else $("body").removeClass("feature-article")
      });
    }
  }
})(jQuery);