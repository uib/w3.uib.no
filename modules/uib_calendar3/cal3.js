jQuery(document).ready(function($) {
  $('.calendar-types input').click(function() {
    var $type = $(this).data('type');
    var $checked = this.checked;
    var $count_checked = 0;
    $('.calendar-types input').each(function() {
      if (this.checked) {
        $count_checked++;
      }
    });
    if (!$count_checked) {
      // make them all visible
      $('.event-entry').toggle(true);
      $('.calendar-date').removeClass('collapsed');
      return;
    }
    if ($checked && $count_checked == 1) {
      // everyone was visible before
      $('.event-entry').toggle(false);
    }
    $('.event-entry-' + $type).toggle($checked);

    // XXX recalculate collapsed state
    $('.calendar-date').each(function() {
      var v = $(this);
      v.toggleClass('collapsed', v.has('.event-entry:visible').length == 0);
    });
  });
  $('#hide-events').click(function() {
    $('.event-entry').toggle(false);
    $('.calendar-date').addClass('collapsed');
    $('.calendar-types input').each(function() {
      this.checked = false;
    });
  });
  $('.calendar-date h3').click(function() {
    var container = $(this).parent();
    var hide = container.toggleClass('collapsed').hasClass('collapsed');
    container.children('.event-entry').each(function() {
      if (hide) {
        $(this).slideUp();
      }
      else {
        $(this).slideDown();
      }
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
