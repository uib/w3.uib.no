(function ($) {

  // Helper function to retrieve value or empty string
  $.getVal = function (obj, key) {
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

  // This function creates the elasticsearch query
  $.createQuery = function (query) {
      var index = $.uib_search.index;
      var lang = $.uib_search.lang;

      // Building elastic query
      var data = {
        query: {
          bool: {
            should: [
              { match_phrase_prefix: {} },
              { match_phrase_prefix: {} },
              { match: {} },
              { match_phrase_prefix: {} },
              { match_phrase_prefix: {} },
            ],
          },
        },
        highlight: { fields: {}, },
        size: $.uib_search.size,
      };

      // Matching title, mail, ou and position
      data.query.bool.should[0].match_phrase_prefix["generic.title_" + lang] =
        query;
      data.query.bool.should[1].match_phrase_prefix.mail = query;
      data.query.bool.should[2].match["generic.title_" + lang] = query;
      data.query.bool.should[3].match_phrase_prefix["ou_" + lang] = query;
      data.query.bool.should[4].match_phrase_prefix["position_" + lang] = query;

      // Highlighting matches
      data.highlight.fields['generic.title_' + lang] = {};
      data.highlight.fields['ou_' + lang] = {};
      data.highlight.fields['position_' + lang] = {};
      data.highlight.fields.mail = {};
      return data;
  };
  // Function to create search result output
  $.createResults = function (data, resultsselector, clearlist) {
    var clearlist = typeof clearlist !== 'undefined' ? clearlist : true;
    var resultstag = $(resultsselector);
    if (clearlist) {
      $.uib_search.from = $.uib_search.size;
      if (data.hits.hits) {
        resultstag.html('');
      }
    }
    else {
      $.uib_search.from += $.uib_search.size;
    }

    $.each(data.hits.hits, function (index, v) {
      // Retrieving variables from returned object
      var evenodd = index % 2 ? 'odd' : 'even';
      var lang = $.uib_search.lang;
      var user_url = $.getVal(v._source, 'link_' + lang);

      var name = $.getVal(v.highlight, 'generic.title_' + lang) ?
        $.getVal(v.highlight, 'generic.title_' + lang) :
        $.getVal(v._source.generic, 'title_' + lang);
      name = $('<a></a>').attr('href', user_url).html(name);

      var mail = $.getVal(v._source, 'mail');
      var display_mail = $.getVal(v.highlight, 'mail') ?
        $.getVal(v.highlight, 'mail') :
        mail;

      var position = $.getVal(v.highlight, 'position_' + lang) ?
        $.getVal(v.highlight, 'position_' + lang) :
        $.getVal(v._source, 'position_' + lang);

      var ou = $.getVal(v.highlight, 'ou_' + lang) ?
        $.getVal(v.highlight, 'ou_' + lang) :
        $.getVal(v._source, 'ou_' + lang);

      var phone = $.getVal(v._source, 'phone');

      // building markup
      var lft = $('<div></div>').addClass('lft')
        .append(
          $('<div><div>').addClass('name').append(name)
        )
        .append(
          $('<div><div>').addClass('position')
          .html(
            position
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
  };
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
        var postdata = $.createQuery(query);
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
            $.createResults(data, $.uib_search.resultsselector,  true)
          },
        };
        $.ajax(options);

      });
    }
  });
})(jQuery);
