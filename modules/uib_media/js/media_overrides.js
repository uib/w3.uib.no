(function ($) {
  Drupal.behaviors.mediaOverrides = {
    attach: function (context, settings) {
      $("#media-internet-add-upload label").text(Drupal.t("Video URL (YouTube or Vimeo)"));
      $("#media-internet-add-upload .description").remove();
      $("[value=default]").remove();
      $("[value=full_width_banner]").remove();
      $("[value=teaser]").remove();
      $("[value=preview]").remove();
      $("[value=wysiwyg]").remove();
      $("[value=full_width_image]").remove();
      $("[value=wide_thumbnail]").remove();
      $("[value=area_bottom]").remove();
      $("[value=content_sidebar]").remove();
      $("[value=content_main]").remove();
      $("[value=area_main]").remove();
      $("[value=feature_image]").remove();
      full_width = $("[value=feature_article_full_width]").detach();
      $("[value=feature_article_standard]").text(Drupal.t("Image or video (landscape orientation)"));
      $("[value=feature_image_portrait]").text(Drupal.t("Image (portrait orientation)"));

      if ($("body.feature-article", window.parent.document).html()) {
        $("[value=feature_article_standard]").text(Drupal.t("Feature article image or video (landscape orientation)"));
        $("[value=feature_image_portrait]").text(Drupal.t("Feature article image (portrait orientation)"));
        $("#edit-format").append(full_width);
        $("[value=feature_article_full_width]").text(Drupal.t("Feature article image or video (full width)"));
        // Firefox needs the form to be reset in order to show the options in the dropdown list in the correct order initially
        if (!$("#edit-format option[selected]").length) {
          $("[value=feature_article_standard]").attr("selected","selected");
          $('#media-wysiwyg-format-form').trigger("reset");
        }
      }
    }
  }
})(jQuery);