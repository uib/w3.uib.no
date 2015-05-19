jQuery(document).ready(function($) {
  $('.calendar-types input').click(function() {
    var $type = $(this).data('type');
    var $checked = this.checked;
    $('.event-entry-' + $type).toggle($checked);
    if ($type == 'course') {
      // toggle them all
      $('.calendar-types input').each(function() {
        var $t2 = $(this).data('type');
        if ($t2.substr(0, 7) == 'course_') {
          this.checked = $checked;
          $('.event-entry-' + $t2).toggle($checked);
        }
      });
    }
  });
  $('#hide-events').click(function() {
    $('.calendar-types input').each(function() {
      this.checked = false;
      var $type = $(this).data('type');
      $('.event-entry-' + $type).toggle(false);
    });
  });
  $('.calendar-date h3').click(function() {
    $(this).parent().children('div').each(function() {
      $(this).toggle(true);
    });
  });

  var date = null;
  var q = document.URL.split('?')[1];
  if (q !== undefined) {
    q = q.split('&');
    for (var i=0; i < q.length; i++) {
      if (q[i].substr(0, 2) == 'd=') {
        date = q[i].substr(2);
      }
    }
  }

  $('#datepicker').datepicker({
    'onSelect': function(date, inst) {
      document.location.href = "?d=" + date;
    },
    'dateFormat': 'yy-mm-dd',
    'defaultDate': date,
  });
});
