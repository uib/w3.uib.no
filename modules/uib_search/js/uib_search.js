(function ($) {

  // Simple date formatter
  $.fn.df = function(d, f) {
    if(!d instanceof Date || typeof f !== 'string') {
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
  $.fn.delay = (function() {
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
  $.fn.executeQuery = function (postdata, query){
    // Options for jquery ajax-call
    var options = {
      url: $.uib_search.fullurl,
      type: 'POST',
      dataType: 'json',
      beforeSend: function (xhr) {
        xhr.setRequestHeader (
          "Authorization", "Basic " + btoa($.uib_search.user + ":" + $.uib_search.password)
        );
      },
      data: JSON.stringify(postdata),
      success: $().createResults($.uib_search.resultsselector, query),
    };
    $.ajax(options);
  }
  // This function creates the elasticsearch query
  $.fn.createQuery = function (query) {
      if(!$.uib_search.url){
          $('.lightbox .topbar .form-type-checkbox').css('display', 'none');
      }
      var index = $.uib_search.index;
      var lang = $.uib_search.lang;
      var all = false;
      var should = [];
      var data = {
        query: {
          bool: {
            should: [],
            filter: {
              or: []
            },
            minimum_should_match: 1
          }
        },
        highlight: { fields: {}, },
        size: $.uib_search.size,
        from: $.uib_search.from,
      }
      if (
        $('#search-filter-checkboxes input[value=everything]').is(':checked')
      ) {
        all = true;
        // News
        data.query.bool.filter.or.push(
          {term: {'w3.article_type': { value: 'news'}}}
        );
        // Event
        data.query.bool.filter.or.push(
          {term: {'w3.article_type': { value: 'event'}}}
        );
        // Area
        data.query.bool.filter.or.push(
          {term: {'w3.type': { value: 'area'}}}
        );
        // External content or link to views etc
        data.query.bool.filter.or.push(
          {term: {'w3.type': { value: 'uib_external_content'}}}
        );
        // Study
        data.query.bool.filter.or.push({type: {value: 'study'}});
        // User
        data.query.bool.filter.or.push({type: {value: 'user'}});
      }
      if (
        all ||
        $('#search-filter-checkboxes input[value=user]').is(':checked') ||
        $('#switch_type_button').is(':checked')
      ) {

        if (!all) {
          // Document type must be user
          data.query.bool.filter.or.push({type: {value: 'user'}});
        }
        should_tmp = []
        should_tmp.push(
          {match_phrase_prefix: {first_name: { query: query, boost: 3}}},
          {match: {first_name: { query: query, boost: 3}}},
          {match_phrase_prefix: {last_name: { query: query, boost: 3}}},
          {match: {last_name: { query: query, boost: 3}}},
          {match_phrase_prefix: {mail: query}},
          {match: {mail: query}}
        );

        // NGrams
        tmp = {match: {}}
        tmp.match["first_name.ngrams"] = { query: query, boost: 3};
        should_tmp.push(tmp)

        tmp = {match: {}}
        tmp.match["last_name.ngrams"] = { query: query, boost: 3};
        should_tmp.push(tmp)

        tmp = {match: {}}
        tmp.match["ou_" + lang] = { query: query, boost: 2};
        should_tmp.push(tmp)

        tmp = {match_phrase_prefix: {}}
        tmp.match_phrase_prefix["ou_" + lang] = query;
        should_tmp.push(tmp)

        tmp = {match: {}}
        tmp.match["position_" + lang] = { query: query, boost: 3};
        should_tmp.push(tmp)

        tmp = {match_phrase_prefix: {}}
        tmp.match_phrase_prefix["position_" + lang] = { query: query, boost: 2};
        should_tmp.push(tmp)

        tmp = {match: {}}
        tmp.match["alt_position_" + lang] = {query: query, boost: 3};
        should_tmp.push(tmp)

        tmp = {match_phrase_prefix: {}}
        tmp.match_phrase_prefix["alt_position_" + lang] =
          {query: query, boost: 2};
        should_tmp.push(tmp)

        tmp = {match: {}}
        tmp.match["competence_" + lang] = {query: query, boost: 3};
        should_tmp.push(tmp)

        tmp = {match_phrase_prefix: {}}
        tmp.match_phrase_prefix["competence_" + lang] =
          {query: query, boost: 2};
        should_tmp.push(tmp)

        // Adding above searches to the toplevel should-array
        should.push({bool: {should: should_tmp}});

        // Highlighted fields
        data.highlight.fields.first_name = {};
        data.highlight.fields.last_name = {};
        data.highlight.fields['ou_' + lang] = {};
        data.highlight.fields['position_' + lang] = {};
        data.highlight.fields.mail = {};
        data.highlight.fields['alt_position_' + lang] = {};



      }
      if (all ||
        $('#search-filter-checkboxes input[value=news]').is(':checked') ||
        $('#search-filter-checkboxes input[value=study]').is(':checked') ||
        $('#search-filter-checkboxes input[value=event]').is(':checked')
      ) {

        if (!all &&
          $('#search-filter-checkboxes input[value=news]').is(':checked')
        ) {
          // Document type: node, and w3 article-type: news
          data.query.bool.filter.or.push(
            {and:[
              {type: {value: 'node'}},
              {term: {'w3.article_type': { value: 'news'}}}
            ]}
          );
        }

        if (!all &&
          $('#search-filter-checkboxes input[value=event]').is(':checked')
        ) {
          // Document type: node, and w3 article-type: event
          data.query.bool.filter.or.push(
            {and:[
              {type: {value: 'node'}},
              {term: {'w3.article_type': { value: 'event'}}}
            ]}
          );
        }

        if (!all &&
          $('#search-filter-checkboxes input[value=study]').is(':checked')
        ) {
          // Document type: study
          data.query.bool.filter.or.push({type: {value: 'study'}});

        }

        // Match direct hit on study code
        tmp = {match: {}}
        tmp.match["w3.study_code"] = {query: query, boost: 10};
        should.push(tmp)

        // Boost hits on content type area
        tmp = {match: {}}
        tmp.match["w3.type"] = {query: 'area', boost: 1.2};
        should.push(tmp)

        tmp = {match: {}}
        tmp.match["generic.title"] = {query: query, boost: 3};
        should.push(tmp)

        tmp = {match: {}}
        tmp.match["generic.title.ngrams"] = {query: query, boost: 3};
        should.push(tmp)

        tmp = {match: {}}
        tmp.match["generic.title.nb"] = {query: query, boost: 3};
        should.push(tmp)

        tmp = {match: {}}
        tmp.match["generic.title.en"] = {query: query, boost: 3};
        should.push(tmp)


        tmp = {match: {}}
        tmp.match["generic.excerpt"] = {query: query, boost: 2};
        should.push(tmp)

        tmp = {match: {}}
        tmp.match["generic.excerpt.nb"] = {query: query, boost: 2};
        should.push(tmp)

        tmp = {match: {}}
        tmp.match["generic.excerpt.en"] = {query: query, boost: 2};
        should.push(tmp)

        tmp = {match: {}}
        tmp.match["generic._searchable_text"] = {query: query, boost: 1};
        should.push(tmp)

        tmp = {match: {}}
        tmp.match["generic._searchable_text.nb"] = {query: query, boost: 1};
        should.push(tmp)

        tmp = {match: {}}
        tmp.match["generic._searchable_text.en"] = {query: query, boost: 1};
        should.push(tmp)

        // Highlighted fields
        data.highlight.fields['generic.title'] = {};
        data.highlight.fields['generic.excerpt'] = {};
      }
      data.query.bool.should = should;

      // Use manual boosting only if new search is enabled:
      if (!$('#switch_type_button').length) {
        data.query = {
          function_score: {
            query: data.query,
            field_value_factor: {
              field: "search_manual_boost",
              modifier: "log1p",
            }
          }
        }
      }

      return data;
  };
  $.fn.createResults = function (resultsselector, query) {

    return function (data, status, jqXHR) {
      var resultstag = $(resultsselector);
      if (data.hits.hits) {
        resultstag.html('');
      }
      var showhits = $('<div></div>')
        .addClass('showhits')
        .html(data.hits.total + Drupal.t(' hits for') + ' <em>"' + query + '"</em>');
      showhits.appendTo(resultstag);

      $.each(data.hits.hits, function (index, v) {
        var node = v._type == 'node' || v._type == 'study';
        var w3_type = v._source.w3 ? v._source.w3.type : '';
        var article_type = v._source.w3.article_type;

        var entitywrapper = $('<div></div>');
        entitywrapper.addClass('item');
        entitywrapper.addClass(v._type);

        // Retrieving variables from returned object
        var evenodd = index % 2 ? 'odd' : 'even';
        var lang = $.uib_search.lang;
        var user_url = $().getVal(v._source, 'link_' + lang);

        var link = $().getVal(v._source.generic, 'link');
        var study_code = $().getVal(v._source.w3, 'study_code') ?
        $().getVal(v._source.w3, 'study_code') + ' / ': '';
        var title = $().getVal(v.highlight, 'generic.title') ?
          $().getVal(v.highlight, 'generic.title') :
          $().getVal(v._source.generic, 'title');
        title = study_code + title;
        var excerpt = $().getVal(v.highlight, 'generic.excerpt') ?
          $().getVal(v.highlight, 'generic.excerpt') :
          $().getVal(v._source.generic, 'excerpt');
        var first_name = $().getVal(v.highlight, 'first_name') ?
          $().getVal(v.highlight, 'first_name') :
          $().getVal(v._source, 'first_name');
        var last_name = $().getVal(v.highlight, 'last_name') ?
            $().getVal(v.highlight, 'last_name') :
            $().getVal(v._source, 'last_name');
        if (article_type == 'event') {
          var event_from = new Date($().getVal(v._source.w3.date, 'value'));
          var event_to = new Date($().getVal(v._source.w3.date, 'value2'));
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

        var displaylink = $('<a></a>')
          .attr('href', user_url)
          .text(user_url);

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
            $('<div></div>').addClass('phone').text(phone)
          );

        // Rewrite markup if document type = node
        if (node) {
          entitywrapper.addClass('node');
          entitywrapper.addClass(v._source.w3.type);
          entitywrapper.addClass(v._source.w3.article_type);
          displaylink = $('<a></a>')
            .attr('href', link)
            .text(link);

          name = $('<a></a>').attr('href', link).html(title);
          lft = $('<div></div>').addClass('lft')
            .append(
              $('<div></div>').addClass('title').append(name)
            )
            .append(
              $('<div></div>').addClass('link').append(displaylink)
            );
          if (article_type == 'event') {
            var day = $('<span></span>').addClass('cal-date').text(
                $.fn.df(event_from, 'd.m.Y')
            );
            var time = $('<span></span>').addClass('cal-time').text(
                $.fn.df(event_from, 'H:i') +  '-' + $.fn.df(event_to, 'H:i')
            );
            lft.append(
              $('<div></div>').addClass('excerpt')
              .append($('<div></div>').addClass('datetime')
                .append(day)
                .append(time))
              .append($('<div></div>').addClass('location').html(location))
            );
          }
          else {
            lft.append(
              $('<div></div>').addClass('excerpt').html(excerpt)
            );
          }
        }
        // If level 1 user:
        if ($('input[name=boost]').val()==1 &&
            (
              v._type == 'user' ||
              (
                v._type == 'node' &&
                (
                  w3_type == 'area' ||
                  w3_type == 'uib_article'
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
          .attr('href', $.uib_search.fullurl)
          .text(Drupal.t('No more results for this query. Click to refine your search.'))
          .appendTo(resultstag);
        $('.no_more_results').click(function(event){
          event.preventDefault();
          $().scroll('form#uib-search-form .search-field').focus();
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
        var postdata = $().createQuery($.uib_search.currentquery);
        $().delay(function() {
          $().executeQuery(postdata, $.uib_search.currentquery);
        }, $.uib_search.delay );


      });

      if ($.uib_search.scroll) {
        $().scroll($.uib_search.scroll);
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

    };
  };

  /**
  * Scroll to top of selector, by default the search input box, and
  * optionally select the text
  **/
  $.fn.scroll = function (selector) {
    $('.lightbox').animate({
      scrollTop: $(selector).offset().top
    }, 300);
    return $(selector);
  }
  /*
*/

  // Make sure dom is loaded
  $(document).ready(function ($) {
    // Reusable variables
    $.uib_search = {
      from: 0,
      size: 10,
      password: Drupal.settings.uib_search.password,
      user: Drupal.settings.uib_search.user,
      index: Drupal.settings.uib_search.index,
      url: Drupal.settings.uib_search.url,
      resultsselector: 'form#uib-search-form .results',
      lang: $('html').attr('lang'),
      currentquery: '',
      scroll: '',
      focus: '',
      select: '',
    };
    $.uib_search.fullurl = $.uib_search.url + "/" + $.uib_search.index
      + "/_search";

    if(!$.uib_search.url){
      // Hide switch button if elastic url is not set
      $('.lightbox .topbar .form-type-checkbox').css('display', 'none');
    }
    else{
      $('form#uib-search-form .search-field').keyup(function (e) {
        // TODO: Remove if block when switching to new search
        if (
          $('#switch_type_button').length &&
          !$('#switch_type_button').is(':checked')
        ) {
          return;
        }
        $(".global-search").submit(function(e){
          return false;
        });
        var query = $(e.target).val().trim();
        if (query.length == 0) {
          $('.results').html('');
          return;
        }
        $.uib_search.currentquery = query;
        $.uib_search.from = 0;
        $.uib_search.delay = 300;
        $.uib_search.scroll = false;
        $.uib_search.focus = false;
        $.uib_search.select = false;
        var postdata = $().createQuery(query);
        $().delay(function() {
          $().executeQuery(postdata, query);
        }, $.uib_search.delay );

      });
    }
  });
})(jQuery);
