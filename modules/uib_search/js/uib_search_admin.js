(function ($) {

$.fn.uib_search__test_setup = function(event) {
  event.preventDefault();
  var options = {
    url: "/compare_search",
    method: 'POST',
    data: $('#uib-search-boosting-admin-form').serialize(),
    beforeSend: function() {
      uib_search_wait_anim = setInterval(function() {
        $('.test-results').html($('.test-results').html() == '&nbsp;|' ? '&mdash;' : '&nbsp;|');
      }, 500);
    },
    success: function(data) {
      clearInterval(uib_search_wait_anim);
      $('.test-results').html(data);
    },
  };
  $.ajax(options).fail(function(obj, status){console.log('something failed'); console.log(status)});
}

})(jQuery);
