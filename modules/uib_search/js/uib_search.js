(function ($) {

  // Simple date formatter
  $.fn.df = function(d, f) {
    if(d == null || !d instanceof Date || typeof f !== 'string') {
      return '';
    }
    var months = [
      Drupal.t('January'),
      Drupal.t('February'),
      Drupal.t('March'),
      Drupal.t('April'),
      Drupal.t('May'),
      Drupal.t('June'),
      Drupal.t('July'),
      Drupal.t('August'),
      Drupal.t('September'),
      Drupal.t('October'),
      Drupal.t('November'),
      Drupal.t('December'),
    ];
    // Formats like php
    var formats = {
      Y: "d.getFullYear()",
      n: "d.getMonth()+1",
      m: "('0'+(d.getMonth()+1)).slice(-2)",
      M: "months[d.getMonth()].slice(0,3)",
      F: "months[d.getMonth()]",
      d: "('0'+d.getDate()).slice(-2)",
      H: "('0'+d.getHours()).slice(-2)",
      i: "('0'+d.getMinutes()).slice(-2)",
      s: "('0'+d.getSeconds()).slice(-2)",
    };
    var output = '';
    for (var i=0, len=f.length; i<len; i++) {
      if (f[i] in formats) {
        output += eval(formats[f[i]])
      }
      else {
        output += f[i];
      }
    }
    return output;
  }

  // Helper function to delay befor executing search
  $.fn.searchDelay = (function() {
    var timer = 0;
    return function(callback, ms) {
      clearTimeout (timer);
      timer = setTimeout(callback, ms);
    };
  })();

  // Helper function to retrieve value or empty string
  $.fn.getVal = function (obj, key) {
    if (typeof obj === 'undefined' ) {
      return '';
    }
    if (key in obj) {
      if (
        typeof obj[key] === 'string'
        || typeof obj[key] === 'number'
        || typeof obj[key] === 'boolean'
      ) {
        return obj[key];
      }
      else if (obj[key] && typeof obj[key][0] === 'string') {
        return obj[key][0];
      }
      else {
        return '';
      }
    }
    else {
      return '';
    }
  };

  $.fn.encodeURIComponent = function (inputstring) {
    return encodeURIComponent(inputstring.replace(/[!~*'()/]+/g,'_'));
  };
  $.fn.executeQuery = function (query){
    // Starting timer for debugging
    if ($.uib_search.debug) {
      uib_timer = new Date().getTime();
    }
    // query filters:
    var filters = $('[name="uib_search_filters[]"]:checked').map(function(){
      return $(this).val();
    }).get();

    // Keep count of queries, and dont overwrite newer queries
    $.uib_search.querynum++;
    // Options for jquery ajax-call
    var options = {
      url: $.uib_search.url + "/" + $.fn.encodeURIComponent(query),
      method: 'POST',
      data: {
        filters: filters,
        size: $.uib_search.size,
        from: $.uib_search.from,
        lang: $.uib_search.lang,
        querynum: $.uib_search.querynum,
      },
      dataType: 'json',
      beforeSend: function (xhr) {
        if ($.uib_search.current_request) {
          $.uib_search.current_request.abort();
          $.uib_search.current_request = false;
        }
        $.uib_search.current_request = xhr;
      },
      success: $().createResults($.uib_search.resultsselector, query),
    };
    $.ajax(options);
  }
  $.fn.createResults = function (resultsselector, query) {

    return function (data, status, jqXHR) {
      // Don't process if a new query is underway
      if ($.uib_search.querynum > data.querynum) return;


      var resultstag = $(resultsselector);
      if ($.trim($('form#uib-search-form .search-field').val())=='') {
        resultstag.html('');
        return;
      }
      if (data.hits.hits) {
        resultstag.html('');
      }
      var showhits = $('<div></div>')
        .addClass('showhits')
        .html(Drupal.t(
          '@count hits for <em>@query</em>',
          {'@count': data.hits.total, '@query': query })
        );
      showhits.appendTo(resultstag);

      $.each(data.hits.hits, function (index, v) {
        var node = v._type == 'node' || v._type == 'study';
        var w3_type = v._source.w3 ? v._source.w3.type : '';
        var article_type = v._source.w3
        ? v._source.w3.article_type : '';

        var entitywrapper = $('<div></div>');
        entitywrapper.addClass('item');
        entitywrapper.addClass(v._type);

        // Retrieving variables from returned object
        var evenodd = index % 2 ? 'odd' : 'even';
        var lang = $.uib_search.lang;
        var user_url = $().getVal(v._source, 'link_' + lang);
        user_url = user_url.replace(/^https?:\/\/(?:w3|www)\.uib\.no/, window.location.protocol + "//" + window.location.host);
        user_url = user_url.replace('w3.d1.test', window.location.host);

        var link = $().getVal(v._source.generic, 'link_' + lang) ||
          $().getVal(v._source.generic, 'link');
        link = link.replace(/^https?:\/\/(?:w3|www)\.uib\.no/, window.location.protocol + "//" + window.location.host);
        link = link.replace('w3.d1.test', window.location.host);

        var study_code = '';
        if (v._type == 'study') {
          study_code = $().getVal(v.highlight, 'w3.study_code') ?
            $().getVal(v.highlight, 'w3.study_code') + ' / ' :
            $().getVal(v._source.w3, 'study_code') + ' / ';
        }

        // Display priority (same for excerpt):
        //  - highlights for correct language
        //  - highlights
        //  - title correct language
        //  - other title
        var title = $().getVal(v.highlight, 'generic.title_' + lang) ||
          $().getVal(v.highlight, 'generic.title.' + lang) ||
          $().getVal(v._source.generic, 'title_' + lang) ||
          $().getVal(v._source.generic, 'title');
        title = study_code + title;
        var excerpt = $().getVal(v.highlight, 'generic.excerpt_' + lang) ||
          $().getVal(v.highlight, 'generic.excerpt.' + lang) ||
          $().getVal(v._source.generic, 'excerpt_' + lang) ||
          $().getVal(v._source.generic, 'excerpt');
        var first_name = $().getVal(v.highlight, 'first_name') ?
          $().getVal(v.highlight, 'first_name') :
          $().getVal(v._source, 'first_name');
        var last_name = $().getVal(v.highlight, 'last_name') ?
            $().getVal(v.highlight, 'last_name') :
            $().getVal(v._source, 'last_name');
        var changed = $().getVal(v._source.w3, 'changed');
        var published_timestamp = $().getVal(v._source.w3, 'published_timestamp');
        if (article_type == 'event') {
          var t = $().getVal(v._source.w3.date, 'value');
          var event_from = null;
          if (t) {
            // Produce a local time date object
            event_from = new Date(
              +t.substr(0,4), // year
              +t.substr(5,2) - 1, // 0-based month
              +t.substr(8,2), // day
              +t.substr(11,2), // hour
              +t.substr(14,2), // min
              +t.substr(17,2) // sec
            );
          }
          t = $().getVal(v._source.w3.date, 'value2');
          var event_to = null;
          if (t) {
            // Produce a local time date object
            event_to = new Date(
              +t.substr(0,4), // year
              +t.substr(5,2) - 1, // 0-based month
              +t.substr(8,2), // day
              +t.substr(11,2), // hour
              +t.substr(14,2), // min
              +t.substr(17,2) // sec
            );
          }
          var location = $().getVal(v._source.w3, 'location');
        }


        var name = $('<a></a>').attr('href', user_url).html(first_name + ' '
          + last_name);

        var mail = $().getVal(v._source, 'mail');
        var display_mail = $().getVal(v.highlight, 'mail') ?
          $().getVal(v.highlight, 'mail') :
          mail;

        var position = $().getVal(v.highlight, 'position_' + lang) ?
          $().getVal(v.highlight, 'position_' + lang) :
          $().getVal(v._source, 'position_' + lang);

        var alt_position = $().getVal(v.highlight, 'alt_position_' + lang) ?
          $().getVal(v.highlight, 'alt_position_' + lang) :
          $().getVal(v._source, 'alt_position_' + lang);

          var ou = $().getVal(v.highlight, 'ou_' + lang) ?
          $().getVal(v.highlight, 'ou_' + lang) :
          $().getVal(v._source, 'ou_' + lang);

        var phone = $().getVal(v._source, 'phone');
        var phone = $().getVal(v.highlight, 'phone.nospace') ?
        $().getVal(v.highlight, 'phone.nospace') :
        $().getVal(v._source, 'phone');
        // Strip spaces and +47 from phone numbers for nice appearence on
        // narrow displays.
        var narrowphone = phone.replace(/\+47 ?/g, '').replace(/([^,]) /g, '$1');

        var displaylink = $('<a></a>')
          .attr('href', user_url)
          .text(decodeURIComponent(user_url).replace(/^https?:\/\//,''));

        // building markup
        var lft = $('<div></div>').addClass('lft')
          .append(
            $('<div></div>').addClass('name').append(name)
          )
          .append(
            $('<div></div>').addClass('link').append(displaylink)
          )
          .append(
            $('<div></div>').addClass('ou')
            .html(
              ou
            )
          )
          .append(
            $('<div></div>').addClass('mail').append(
              $('<a></a>').attr('href', 'mailto:' + mail).html(display_mail)
            )
          )
          .append(
            $('<div></div>').addClass('phone').html(
              [
                '<span class="wide">',
                phone,
                '</span>',
                '<span class="narrow">',
                narrowphone,
                '</span>',
              ].join("\n")
            )
          );

        // Rewrite markup if document type = node
        if (node) {
          entitywrapper.addClass('node');
          entitywrapper.addClass(v._source.w3.type);
          entitywrapper.addClass(v._source.w3.article_type);
          displaylink = $('<a></a>')
            .attr('href', link)
            .text(decodeURIComponent(link).replace(/^https?:\/\//,''));

          var updated = $.fn.df(new Date(changed*1000), 'd.m.Y');
          var published = $.fn.df(new Date(published_timestamp*1000), 'd.m.Y');
          if (updated != published) {
            var last_updated = Drupal.t('Updated') + ': ' + updated;
            var first_published = ' (' + Drupal.t('First published') + ': ' + published + ')';
          } else {
            var last_updated = '';
            var first_published = Drupal.t('Published') + ': ' + published;
          }
          var changedtag = $('<div/>')
            .text(last_updated + first_published)
            .addClass('published');
          name = $('<a></a>').attr('href', link).html(title);
          lft = $('<div></div>').addClass('lft')
            .append(
              $('<div></div>').addClass('title').append(name)
            );
            if (article_type != 'event') {
              lft.append(changedtag);
            }
            lft.append(
              $('<div></div>').addClass('link').append(displaylink)
            );
          if (article_type == 'event') {
            var from = $('<span></span>').addClass('cal-from').text(
                $.fn.df(event_from, 'd.m.Y H:i')
            );
            if ($.fn.df(event_from, 'd.m.Y') == $.fn.df(event_to, 'd.m.Y')) {
              var to = !isNaN(event_to) && event_to ? $('<span></span>').addClass('cal-to').text($.fn.df(event_to, 'H:i')) : '';
            } else {
              var to = !isNaN(event_to) && event_to ? $('<span></span>').addClass('cal-to').text($.fn.df(event_to, 'd.m.Y H:i')) : '';
            }
            var str_datetime = $('<div></div>').addClass('datetime');
            if (!isNaN(Number(new Date(event_from)))) {
              str_datetime.append(from);
            }
            if (!isNaN(event_to) && event_to) {
              str_datetime.append('&ndash;');
              str_datetime.append(to);
            }
            lft.append(
              $('<div></div>').addClass('excerpt')
                .append(str_datetime)
              .append($('<div></div>').addClass('location').html(location))
            );
          }
          else {
            trim = $.trim(excerpt);
            if (trim.length > $.uib_search.excerpt_length) {
              var trim = excerpt.substring(0, $.uib_search.excerpt_length);
              trim = trim.substr(0, Math.min(trim.length, trim.lastIndexOf(" ")));
              trim += ' ' + '&hellip;';
            }
            if (typeof v._source.w3 !== 'undefined' &&
                typeof v._source.w3.step_titles_array === 'object'
                && v._source.w3.step_titles_array.length > 0
            ) {
                trim += '<div class="steps">';
                trim += Drupal.t('Includes titles') + ': ';
                for (i = 0; i < v._source.w3.step_titles_array.length; i++) {
                  trim += $('<span></span>')
                    .attr('data-href', link + '?step=' + (i+1))
                    .addClass('step-link')
                    .text(v._source.w3.step_titles_array[i])
                    .prop('outerHTML') + ', ';
                }
                trim = trim.replace(/[ ,]*$/, '');
                trim += '</div>';
            }

            lft.append(
              $('<div></div>').addClass('excerpt').html(trim)
            );
          }
        }
        // If superbruker user:
        if ($('input[name=boost]').val()==1 &&
            (
              v._type == 'user' ||
              (
                v._type == 'node' &&
                (
                  w3_type == 'area'
                  || w3_type == 'uib_article'
                  || w3_type == 'uib_external_content'
                  || w3_type == 'uib_content_list'
                )
              )
            )
          ) {
          var up = $('<a></a>').addClass('up').text(Drupal.t('Up'))
          up.attr('href', '/searchboost/up/' + v._type + '/' + v._id);
          var down = $('<a></a>').addClass('down').text(Drupal.t('Down'))
          down.attr('href', '/searchboost/down/' + v._type + '/' + v._id);
          var boost_value = $('<span></span>')
            .addClass('boost_value')
            .text($().getVal(v._source, 'search_manual_boost'));

          var boost = $('<div></div>').addClass('boost').append(
            up
          ).append(
            down
          ).append(
            boost_value
          );
          lft.append(boost);
        }

        // Make whole item in result list clickable
        entitywrapper.click(function(event) {
          if(event.target.nodeName === 'A') return;
          console.log(event.target)
          console.log($(event.target))
          if ($(event.target).data('href')) {
            window.location.href =$(event.target).data('href');
            return true;
          }
          var link = $(this).find('a:not(.up,.down)').first();
          link.click();
          window.location.href = link.attr('href');
        });

        // Showing hits for
        entitywrapper
          .addClass(evenodd)
          .append(lft)
          .appendTo(resultstag);

      }); // each

      // create pagination
      var maxpages = 9;
      var countpages = Math.ceil(data.hits.total / $.uib_search.size);
      countpages = countpages > maxpages ? maxpages : countpages;
      if (countpages>1) {
        // wrapper
        var wrapper = $('<div></div>')
          .addClass('pagination-wrapper')
          .appendTo(resultstag);

        var prev = $('<a></a>')
          .addClass('prev')
          .attr('data-from', 'prev')
          .text(Drupal.t('Previous'));
        if ( $.uib_search.from == 0) {
          prev.addClass('disable');
        }
        prev.appendTo(wrapper);
        for (var i = 0; i < countpages; i++) {
          var from = i * $.uib_search.size;
          var link = $('<a></a>')
          .addClass('resultpage')
            .attr('data-from', from)
            .text(i + 1);
          if (from == $.uib_search.from) {
            link.addClass('current');
          }
          link.appendTo(wrapper);
        }
        var next = $('<a></a>')
          .addClass('next')
          .attr('data-from', 'next')
          .text(Drupal.t('Next'));
        if ( $.uib_search.from == $.uib_search.size * (countpages - 1)) {
          next.addClass('disable');
        }
        next.appendTo(wrapper);

      }
      else if(data.hits.total>7) {
        $('<a></a>')
          .addClass('no_more_results')
          .attr('href', '#')
          .text(Drupal.t('No more results for this query. Click to refine your search.'))
          .appendTo(resultstag);
        $('.no_more_results').click(function(event){
          event.preventDefault();
          $().uibScroll('form#uib-search-form .search-field').focus();
        })
      }


      $('.pagination-wrapper a').click(function(event){
        event.preventDefault();
        $.uib_search.scroll = 'form#uib-search-form .search-field';
        $.uib_search.select = true;
        $.uib_search.focus = true;
        if ($(this).hasClass('disable') || $(this).hasClass('current') ) {
          return;
        }
        switch ($(this).data('from')) {
          case 'prev':
            if($.uib_search.from > 0){
              $.uib_search.from -= $.uib_search.size;
              $.uib_search.scroll = '.results-bottom-anchor';
              $.uib_search.select = false;
            }
          break;
          case 'next':
            $.uib_search.from += $.uib_search.size;
          break;
          default:
            $.uib_search.from = $(this).data('from');
          break;
        }
        $().searchDelay(function() {
          $().executeQuery($.uib_search.currentquery);
        }, 1 );


      });

      if ($.uib_search.scroll) {
        $().uibScroll($.uib_search.scroll);
      }
      if ($.uib_search.select) {
        $('form#uib-search-form .search-field').select();
      }
      if ($.uib_search.focus) {
        $('form#uib-search-form .search-field').focus();
      }
      $('.boost a').click(function(event) {
        event.preventDefault();
        $.post('/en' + $(event.target).attr('href'), function(data) {
          var parent = $(event.target).parent();
          var up = parent.children('.up');
          var down = parent.children('.down');
          parent.children('a').removeClass('disabled');
          parent.children('.boost_value').text(data);

          // Disable boost links when max or min boost is reached
          if (data >= Drupal.settings.uib_search.uib_search_boost_max) {
            up.addClass('disabled');
          }
          else if (data <= Drupal.settings.uib_search.uib_search_boost_min) {
            down.addClass('disabled');
          }
        });
      });

      // Manipulate history when clicking links
      $('.global-search .results .item a:not(.up,.down)').click(function (event) {
        var checkboxes = {};
        $('#search-filter-checkboxes input.form-checkbox:checked').each(function (index, obj) {
            checkboxes[$(obj).val()] = 1;
        });
        var q = {
          id: 'uib-search',
          query: $.uib_search.currentquery,
          from: $.uib_search.from,
          checkboxes: checkboxes
        };
        history.replaceState(q, 'Search', window.location.href);

        // Prevent recursion
        event.stopPropagation();
      });

      if ($.uib_search.debug) {
        console.log('Returned data object: ');
        console.log(data);
        console.log("Metadata for hits:");
        for (i in data.hits.hits) {
          var changed =
            typeof data.hits.hits[i]._source.w3 == 'undefined' ?
              0 : data.hits.hits[i]._source.w3.changed;
          var matched = typeof data.hits.hits[i].matched_queries == 'undefined' ?
              '' : ' Queries: ' + data.hits.hits[i].matched_queries.join(', ');
          var thetype = typeof data.hits.hits[i]._source.w3 == 'undefined' ?
              data.hits.hits[i]._type : data.hits.hits[i]._source.w3.type;
          console.log('score treff ' + i + ': ' + data.hits.hits[i]._score
            + ' changed: ' + $.fn.df(new Date(changed*1000), 'd.m.Y')
            + ' w3.type: ' + thetype
            + matched
            );
        }
        console.log("Execution time: " +
          ((new Date().getTime() - uib_timer)/1000) + "sec"
        );
      }
    };
  };

  /**
  * Scroll to top of selector, by default the search input box, and
  * optionally select the text
  **/
  $.fn.uibScroll = function (selector) {
    $('.lightbox').animate({
      scrollTop: $(selector).offset().top
    }, 300);
    return $(selector);
  }
  /*
*/

  // Make sure dom is loaded
  $(document).ready(function ($) {
    // Unset search field, workaround for safari:
    if ($('#searchfield').val() == ' ') {
      $('#searchfield').val('');
    }

    // Reusable variables
    $.uib_search = {
      from: 0,
      size: 15,
      resultsselector: 'form#uib-search-form .results',
      lang: $('html').attr('lang'),
      currentquery: '',
      scroll: '',
      focus: '',
      select: '',
      excerpt_length: 350,
      current_request: null,
      querynum: 0,
      debug: 0,
      url: '/sites/all/modules/uib/uib_search/php/qs.php',
    };


      $(".global-search").submit(function(e){
        return false;
      });
      $('form#uib-search-form .search-field').keyup(function (e) {
        var query = $(e.target).val().trim();
        if (query.length == 0) {
          $('.results').html('');
          return;
        }
        if (query == $.uib_search.currentquery && e.which != 0) {
          return;
        }
        $.uib_search.currentquery = query;
        $.uib_search.from = 0;
        $.uib_search.delay = 300;
        $.uib_search.scroll = false;
        $.uib_search.focus = false;
        $.uib_search.select = false;
        $().searchDelay(function() {
          $().executeQuery(query);
        }, $.uib_search.delay );

      });

    // Prepopulate search
    if (history.state && history.state.id  == 'uib-search') {
      $.uib_search.currentquery = history.state.query;
      $.uib_search.from = history.state.from;
      $.fn.uibSearchOpen();
      $('#search-filter-checkboxes input.form-checkbox').each( function(index, obj) {
        if (history.state.checkboxes[$(obj).val()]) {
          $(obj).checked = true;
        }
      });
      $('form#uib-search-form .search-field').val($.uib_search.currentquery);

      $().searchDelay(function() {
        $().executeQuery($.uib_search.currentquery);
      }, 1 );
    }
  });

})(jQuery);
