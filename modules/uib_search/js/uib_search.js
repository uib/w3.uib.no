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

      // Building elastic query
      var data = {
        query: {
          bool: {
            should: [
              { match_phrase_prefix: {} },
              { match_phrase_prefix: {} },
              { match_phrase_prefix: {} },
              { match_phrase_prefix: {} },
              { match_phrase_prefix: {} },
              { match_phrase_prefix: {} },
              { match: {} },
              { match: {} },
              { match: {} },
              { match: {} },
              { match: {} },
              { match: {} },
              { match_phrase_prefix: {} },
              { match: {} },
            ],
          },
        },
        highlight: { fields: {}, },
        size: $.uib_search.size,
        from: $.uib_search.from,
      };

      // Matching title, mail, ou and position
      data.query.bool.should[0].match_phrase_prefix.first_name
        = { query: query, boost: 3};
      data.query.bool.should[1].match_phrase_prefix.last_name
        = { query: query, boost: 3};
      data.query.bool.should[2].match_phrase_prefix.mail = query;
      data.query.bool.should[3].match_phrase_prefix["ou_" + lang ] = query;
      data.query.bool.should[4].match_phrase_prefix["position_" + lang]
        = { query: query, boost: 2};
      data.query.bool.should[5].match_phrase_prefix["alt_position_" + lang]
        = {query: query, boost: 2};
      data.query.bool.should[6].match.first_name
        = { query: query, boost: 4};
      data.query.bool.should[7].match.last_name
        = { query: query, boost: 4};
      data.query.bool.should[8].match.mail = { query: query, boost: 2};
      data.query.bool.should[9].match["ou_" + lang] = { query: query, boost: 2};
      data.query.bool.should[10].match["position_" + lang]
        = { query: query, boost: 3};
      data.query.bool.should[11].match["alt_position_" + lang]
        = {query: query, boost: 3};
      data.query.bool.should[12].match_phrase_prefix["competence_" + lang]
        = {query: query, boost: 2};
      data.query.bool.should[13].match["competence_" + lang]
        = {query: query, boost: 3};

      // Highlighting matches
      data.highlight.fields.first_name = {};
      data.highlight.fields.last_name = {};
      data.highlight.fields['ou_' + lang] = {};
      data.highlight.fields['position_' + lang] = {};
      data.highlight.fields.mail = {};
      data.highlight.fields['alt_position_' + lang] = {};
      return data;
  };
  $.fn.createResults = function (data, resultsselector) {

    var resultstag = $(resultsselector);
    if (data.hits.hits) {
      resultstag.html('');
    }

    $.each(data.hits.hits, function (index, v) {
      // Retrieving variables from returned object
      var evenodd = index % 2 ? 'odd' : 'even';
      var lang = $.uib_search.lang;
      var user_url = $().getVal(v._source, 'link_' + lang);

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
          $('<div><div>').addClass('name').append(name)
        )
        .append(
          $('<div><div>').addClass('position')
          .html(
            position + (alt_position ? ', ' + alt_position : '')
          )
        )
        .append(
          $('<div><div>').addClass('ou')
          .html(
            ou
          )
        );
      var rgt = $('<div></div>').addClass('rgt')
        .append(
          $('<div><div>').addClass('mail').append(
            $('<a></a>').attr('href', 'mailto:' + mail).html(display_mail)
          )
        )
        .append(
          $('<div><div>').addClass('phone').text(phone)
        );


      $('<div></div>').addClass('user_' + v._id + ' ' + evenodd)
        .append(lft)
        .append(rgt)
        .appendTo(resultstag);
    });

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
        $().scroll('form[name=lbform] .search-field').focus();
      })
    }


    $('.pagination-wrapper a').click(function(event){
      event.preventDefault();
      $.uib_search.scroll = 'form[name=lbform] .search-field';
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
      $('form[name=lbform] .search-field').select();
    }
    if ($.uib_search.focus) {
      $('form[name=lbform] .search-field').focus();
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
      password: $('form[name=lbform] input[name=password]').val(),
      user: $('form[name=lbform] input[name=user]').val(),
      index: $('form[name=lbform] input[name=index]').val(),
      url: $('form[name=lbform] input[name=url]').val(),
      resultsselector: 'form[name=lbform] .results',
      lang: $('html').attr('lang'),
      currentquery: '',
      scroll: '',
      focus: '',
      select: '',
    };
    $.uib_search.fullurl = $.uib_search.url + "/" + $.uib_search.index
      + "/user/_search";

    if(!$.uib_search.url){
      // Hide switch button if elastic url is not set
      $('.lightbox .topbar .form-type-checkbox').css('display', 'none');
    }
    else{
      $('form[name=lbform] .search-field').keyup(function (e) {
        if (!$('#switch_type_button').is(':checked')) {
          return;
        }
        var query = $(e.target).val().trim();
        if (query.length == 0 || query == $.uib_search.currentquery ) {
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
