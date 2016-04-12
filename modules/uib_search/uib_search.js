(function ($) {
  // Helper function to retrieve value or empty string
  $.getVal = function (obj, key){
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
  }

  // Make sure dom is loaded
  $(document).ready(function ($) {
    var url = $('form[name=lbform] input[name=url]').val();
    if(!url){
        $('.lightbox .topbar .form-type-checkbox').css('display', 'none');
    }
    var password = $('form[name=lbform] input[name=password]').val();
    var user = $('form[name=lbform] input[name=user]').val();
    var index = $('form[name=lbform] input[name=index]').val();
    url = url + "/" + index + "/user/_search";
    var lang = $('html').attr('lang');
    $('form[name=lbform] .search-field').keyup(function (e) {
      if (!$('#switch_type_button').is(':checked')) {
        return;
      }
      var v = $(e.target).val();

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
        size: 10,
      };

      // Matching title, mail, ou and position
      data.query.bool.should[0].match_phrase_prefix["generic.title_" + lang] =
        v;
      data.query.bool.should[1].match_phrase_prefix.mail = v;
      data.query.bool.should[2].match["generic.title_" + lang] = v;
      data.query.bool.should[3].match_phrase_prefix["ou_" + lang] = v;
      data.query.bool.should[4].match_phrase_prefix["position_" + lang] = v;

      // Highlighting matches
      data.highlight.fields['generic.title_' + lang] = {};
      data.highlight.fields['ou_' + lang] = {};
      data.highlight.fields['position_' + lang] = {};
      data.highlight.fields.mail = {};

      // Options for jquery ajax-call
      var options = {
        url: url,
        type: 'POST',
        dataType: 'json',
        beforeSend: function (xhr) {
          xhr.setRequestHeader (
            "Authorization", "Basic " + btoa(user + ":" + password)
          );
        },
        data: JSON.stringify(data),
        success: function (data, status, jqXHR) {
          var res = $('form[name=lbform] .results');
          if (data.hits.hits) {
            res.html('');
          }
          $.each(data.hits.hits, function (index, v) {

            // Retrieving variables from returned object
            var evenodd = index % 2 ? 'odd' : 'even';
            var lang = $('html').attr('lang');
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
              .appendTo(res);
          });
        },
      };
      $.ajax(options);
    });
  });
})(jQuery);
