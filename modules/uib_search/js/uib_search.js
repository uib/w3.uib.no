(function ($) {

  // Helper function to retrieve value or empty string
  $.fn.getVal = function (obj, key) {
    if (typeof obj === 'undefined' ) {
      return '';
    }
    if (key in obj) {
      if (typeof obj[key] === 'string') {
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
  $.fn.executeQuery = function (postdata){
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
      success: function (data, status, jqXHR) {
        $().createResults(data, $.uib_search.resultsselector)
      },
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
        tmp.match["generic.excerpt"] = {query: query, boost: 2};
        should.push(tmp)

        tmp = {match: {}}
        tmp.match["generic._searchable_text"] = {query: query, boost: 1};
        should.push(tmp)

        // Highlighted fields
        data.highlight.fields['generic.title'] = {};
        data.highlight.fields['generic.excerpt'] = {};
      }
      data.query.bool.should = should;
      return data;
  };
  $.fn.createResults = function (data, resultsselector) {

    var resultstag = $(resultsselector);
    if (data.hits.hits) {
      resultstag.html('');
    }

    $.each(data.hits.hits, function (index, v) {
      var node = v._type == 'node' || v._type == 'study';
      // Retrieving variables from returned object
      var evenodd = index % 2 ? 'odd' : 'even';
      var lang = $.uib_search.lang;
      var user_url = $().getVal(v._source, 'link_' + lang);

      var link = $().getVal(v._source.generic, 'link');
      var title = $().getVal(v.highlight, 'generic.title') ?
        $().getVal(v.highlight, 'generic.title') :
        $().getVal(v._source.generic, 'title');
      var excerpt = $().getVal(v.highlight, 'generic.excerpt') ?
        $().getVal(v.highlight, 'generic.excerpt') :
        $().getVal(v._source.generic, 'excerpt');
      var first_name = $().getVal(v.highlight, 'first_name') ?
        $().getVal(v.highlight, 'first_name') :
        $().getVal(v._source, 'first_name');
      var last_name = $().getVal(v.highlight, 'last_name') ?
        $().getVal(v.highlight, 'last_name') :
        $().getVal(v._source, 'last_name');

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


      // building markup
      var lft = $('<div></div>').addClass('lft')
        .append(
          $('<div></div>').addClass('name').append(name)
        )
        .append(
          $('<div></div>').addClass('position')
          .html(
            position + (alt_position ? ', ' + alt_position : '')
          )
        )
        .append(
          $('<div></div>').addClass('ou')
          .html(
            ou
          )
        );
      var rgt = $('<div></div>').addClass('rgt')
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
        name = $('<a></a>').attr('href', link).html(title);
        lft = $('<div></div>').addClass('lft')
        .append(
          $('<div></div>').addClass('title').append(name)
        )
        .append(
          $('<div></div>').addClass('excerpt').html(excerpt)
        );
        rgt = '';
      }

      $('<div></div>').addClass('user_' + v._id + ' ' + evenodd)
        .append(lft)
        .append(rgt)
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
      $().executeQuery(postdata);

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
        var query = $(e.target).val().trim();
        if (query.length == 0) {
          $('.results').html('');
          return;
        }
        $.uib_search.currentquery = query;
        $.uib_search.from = 0;
        $.uib_search.scroll = false;
        $.uib_search.focus = false;
        $.uib_search.select = false;
        var postdata = $().createQuery(query);
        $().executeQuery(postdata);
      });
    }
  });
})(jQuery);
