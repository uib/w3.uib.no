jQuery(document).ready(function($) {

  /* utility functions */
  var recalculate_collapsed = function() {
    $('.calendar-date').each(function() {
      var v = $(this);
      v.toggleClass('collapsed', v.has('.event-entry:visible').length == 0);
    });
  };

  var query_state = function(date_override) {
    var q = [];
    var d = date_override || date;
    if (d) {
      q.push('d=' + d);
    }
    $('.event-types-filter input[type=checkbox]').each(function() {
      if (this.checked) {
        q.push($(this).data('type'));
      }
    });
    return q.join('&');
  };

  $('#show-filter').click(function() {
    $('.calendar-types').toggleClass('is-visible');
  });

  $('#close-filter').click(function() {
    $('.calendar-types').removeClass('is-visible');
  });

  /* click event-type checkbox */
  $('.calendar-types input').click(function(e) {
    var type = $(this).data('type');
    var checked = this.checked;
    var count_checked = 0;
    $('.calendar-types input').each(function() {
      if (this.checked) {
        count_checked++;
      }
    });
    if (!count_checked) {
      // make them all visible
      $('.event-entry').toggle(true);
      $('.calendar-date').removeClass('collapsed');
      history.replaceState({}, 'Show all', '?' + query_state());
      return;
    }
    if (checked && count_checked == 1) {
      // everyone was visible before
      $('.event-entry').toggle(false);
    }
    $('.event-entry-' + type).toggle(checked);
    history.replaceState({}, 'Click', '?' + query_state());
    recalculate_collapsed();
  });

  /* click show button */
  $('#show-events').click(function(e) {
    $('.event-entry').toggle(true);
    $('.calendar-date').removeClass('collapsed');
    $('.calendar-types input').each(function() {
      this.checked = false;
    });
    history.replaceState({}, 'Show all', '?' + query_state());
  });

  /* click date */
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

  /* parse query string */
  var date = null;
  var event_type_init = {};
  var q = document.URL.split('?')[1];
  if (q !== undefined) {
    q = q.split('&');
    for (var i=0; i < q.length; i++) {
      if (q[i].substr(0, 2) == 'd=') {
        date = q[i].substr(2);
        if (date.match(/^\d\d\d\d$/)) {
          date += '-01-01';
        }
        else if (date.match(/^\d\d\d\d-\d\d$/)) {
          date += '-01';
        }
        else if (date.match(/^\d\d\d\d-\d\d-\d\d$/)) {
          // ok
        }
        else {
          date = null;
        }
      }
      else {
        var m = q[i].match(/^(\w+)(?:=(0|1))?$/);
        if (m) {
          event_type_init[m[1]] = Number(m[2] || 1);
        }
      }
    }
  }

  if (Object.keys(event_type_init).length) {
    $('.event-entry').toggle(false);
    for (var e in event_type_init) {
      $('#check-' + e).attr('checked', true);
      $('.event-entry-' + e).toggle(true);
    }
    recalculate_collapsed();
  }

  $('#datepicker').datepicker({
    'onSelect': function(date, inst) {
      document.location.href = "?" + query_state(date);
    },
    'dateFormat': 'yy-mm-dd',
    'defaultDate': date,
  });
});
