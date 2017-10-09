(function ($) {
  Drupal.behaviors.featureFactbox= {
    attach: function (context, settings) {
      $('.uib-feature__fact-box > h2').each(function(index, element) {
        $(this).toggleClass('collapsed');
        $(this).siblings().hide();
      });
      $('.uib-feature__fact-box > h2').click( function() {
        if ($(this).hasClass('collapsed')) {
          $(this).toggleClass('collapsed');
          $(this).siblings().show();
        }
        else {
          $(this).toggleClass('collapsed');
          $(this).siblings().hide();
        }
      });
      $('.uib-feature__portrait-image, .uib-feature__image, .uib-feature__full-width-image').each(function(index, element) {
        var uibCopyright = $(this).find('.field-name-field-uib-copyright').removeClass('field-label-inline clearfix');
        var uibOwner = $(this).find('.field-name-field-uib-owner').removeClass('field-label-inline clearfix');
        $(this).find('p:last-child').append(uibCopyright).append(uibOwner);
      });
      $('.uib-article__feature_article .content-top h1').each(function(index, element) {
        var uibBreadcrumb = $('.uib_breadcrumb');
        $(this).after(uibBreadcrumb);
      })
      if ($(document).width() < 600) {
        $('.uib-facebook-live__square').css('height', $('.uib-facebook-live__square').width());
        $('.uib-facebook-live__landscape').css('height', function(index, element) {
          return ($(this).height()*$(this).width()/560);
        });
      }
      if ($(document).width() < 355) {
        $('.uib-facebook-live__portrait').css('height', function(index, element) {
          return ($(this).height()*$(this).width()/315);
        });
      }
    }
  };
}(jQuery));
