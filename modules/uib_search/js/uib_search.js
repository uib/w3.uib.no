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
      if ($.uib_search.debug) {
        uib_timer = new Date().getTime();
      }
      if(!$.uib_search.url){
          $('.lightbox .topbar .form-type-checkbox').css('display', 'none');
      }
      var index = $.uib_search.index;
      var lang = $.uib_search.lang;
      var all = false;
      var should = [];
      var tmp = {};
      var data = {
        query: {
          bool: {
            should: [],
            must: {},
            filter: {bool: {should: []}},
          }
        },
        highlight: { fields: {}, },
        size: $.uib_search.size,
        from: $.uib_search.from,
      }
      var boostquery = {bool: {should: [], _name: "Boost"}};
      var searchquery =
        {bool: {should: [], _name: "Search", minimum_should_match: 1}};

      /**************************************
       * Query matching
       *************************************/

      // Match NGrams in title. Ngrams are made up of word triplets
      // This matches for user and node
      tmp = {
        bool: {
          filter: { terms: { _type: ["user", "node"]}},
          must: {
            match: {}
          },
          _name: "NGram-search",
        }
      };
      tmp.bool.must.match["generic.title.ngrams"] = {
        query: query,
        minimum_should_match: "40%",
      };
      searchquery.bool.should.push(tmp);

      tmp = {
        bool: {
          filter: { terms: { _type: ["study"]}},
          should: [
            {
              match: {
                "generic.title_nb.ngrams": {
                  query: query,
                  minimum_should_match: "40%",
                }
              }
            },
            {
              match: {
                "generic.title_en.ngrams": {
                  query: query,
                  minimum_should_match: "40%",
                }
              }
            },
          ],
          minimum_should_match: 1,
          _name: "NGram-study",
        }
      };
      searchquery.bool.should.push(tmp);

      // Match full words in title
      tmp = {
          bool: {
            filter: { terms: { _type: ["user", "node"]}},
            must: {
              match: {}
            },
            _name: "Match-title",
          }
        };
      tmp.bool.must.match["generic.title." + lang] = {
        query: query,
      };
      searchquery.bool.should.push(tmp);

      tmp = {
        bool: {
          filter: { terms: { _type: ["study"]}},
          should: { match: {} },
          _name: "Match-title-study(" + lang + ")",
        }
      };
      tmp.bool.should.match["generic.title_" + lang] = {
        query: query,
      };
      searchquery.bool.should.push(tmp);

      // Match words in excerpt
      tmp = {
        bool: {
          filter: { terms: { _type: ["user", "node"]}},
          must: {
            match: {}
          },
          _name: "Match-excerpt",
        }
      };
      tmp.bool.must.match["generic.excerpt." + lang] = {
        query: query,
      };
      searchquery.bool.should.push(tmp);

      tmp = {
        bool: {
          filter: { terms: { _type: ["study"]}},
          should: { match: {} },
          _name: "Match-excerpt-study(" + lang + ")",
        }
      };
      tmp.bool.should.match["generic.excerpt_" + lang] = {
        query: query,
      };
      searchquery.bool.should.push(tmp);

      // Match keywords
      tmp = {match: {}}
      tmp.match["w3.search_keywords"] = {
        query: query,
        boost: 2,
        fuzziness: 'auto',
        _name: "Fuzzy-match-keywords",
      };
      searchquery.bool.should.push(tmp);

      //Match search description
      tmp = {match: {}}
      tmp.match["w3.search_description"] = {
        query: query,
        boost: 2,
        fuzziness: 'auto',
        _name: "Fuzzy-match-description",
      };
      searchquery.bool.should.push(tmp);

      //Match in _searchable text
      tmp = {match: {}}
      tmp.match["generic._searchable_text." + lang] = {
        query: query,
        _name: "Match-searchable-text",
      };
      searchquery.bool.should.push(tmp);

      // Phrase-matching on title
      tmp = {
        bool: {
          filter: { terms: { _type: ["user", "node"]}},
          must: {
            match_phrase_prefix: {}
          },
          _name: "Phrase-search(" + lang + ")",
        }
      };
      tmp.bool.must.match_phrase_prefix["generic.title." + lang] = {
        query: query,
      };
      searchquery.bool.should.push(tmp);

      tmp = {
        bool: {
          filter: { terms: { _type: ["study"]}},
          should: { match_phrase_prefix: {} },
          _name: "Phrase-search-study(" + lang + ")",
        }
      };
      tmp.bool.should.match_phrase_prefix["generic.title_" + lang] = {
        query: query,
      };
      searchquery.bool.should.push(tmp);


      // Prefix - matching on disipline
      tmp = {prefix: {"fs.dicipline_nb": query, _name: 'Dicipline(nb)'}};
      searchquery.bool.should.push(tmp);
      tmp = {prefix: {"fs.dicipline_en": query, _name: 'Dicipline(en)'}};
      searchquery.bool.should.push(tmp);

      // Match url elements on nodes
      tmp = {match: {}}
      tmp.match["w3.url_string." + lang] = {
        query: query,
        boost: 3,
        fuzziness: 'auto',
        prefix_length: 3,
        max_expansions: 50,
        _name: "Match-url",
      };
      searchquery.bool.should.push(tmp);

      // Match on custom fields for persons
      tmp = {
        bool: {
          should:[
            {match_phrase_prefix: {first_name: {query: query}}},
            {match: {first_name: {query: query, fuzziness: 1, prefix_length: 3, max_expansions: 50,}}},
            {match_phrase_prefix: {last_name: {query: query}}},
            {match: {last_name: {query: query, fuzziness: 1, prefix_length: 3, max_expansions: 50,}}},
            {match_phrase_prefix: {mail: {query: query}}},
            {match_phrase_prefix: {ou_nb: {query: query}}},
            {match_phrase_prefix: {ou_en: {query: query}}},
            {match_phrase_prefix: {position_nb: {query: query}}},
            {match_phrase_prefix: {position_en: {query: query}}},
            {match_phrase_prefix: {alt_position_nb: {query: query}}},
            {match_phrase_prefix: {alt_position_en: {query: query}}},
            {match_phrase_prefix: {competence_nb: {query: query}}},
            {match_phrase_prefix: {competence_en: {query: query}}},
            {multi_match: {query: query, fields: [
              "ou_nb",
              "ou_en",
              "position_nb",
              "position_en",
              "alt_position_nb",
              "alt_position_en",
              "competence_nb",
              "competence_en",
            ]}},
          ],
        _name: 'Person-search',
        }
      };
      searchquery.bool.should.push(tmp);

      // Add the searchquery to the must clause, as something here must match
      data.query.bool.must = searchquery;

      /**************************************
       * Highlighted fields
       *************************************/
      data.highlight.fields["generic.title." + lang] = {};
      data.highlight.fields["generic.title_" + lang] = {};
      data.highlight.fields["generic.excerpt." + lang] = {};
      data.highlight.fields["generic.excerpt_" + lang] = {};
      data.highlight.fields.first_name = {};
      data.highlight.fields.last_name = {};
      data.highlight.fields['ou_' + lang] = {};
      data.highlight.fields['position_' + lang] = {};
      data.highlight.fields.mail = {};
      data.highlight.fields['alt_position_' + lang] = {};

      /**************************************
       * Boosting relevance
       *************************************/
      // Importance levels are found in this doc https://goo.gl/yw9mzP
      // The boost levels associated with the importance levels are subject
      // to change.
      var importance_levels = {
        1:6, // Most important: Area pages etc
        2:5, // Less important: News from latest month etc
        3:4, // Even less important: News from last year?
        4:3, // ...etc
        5:2,
        6:1,
      };

      // Match direct hit on study code
      tmp = {
        constant_score: {
          filter: {
            term: {
              "w3.study_code": {
                value: query,
              }
            }
          },
          boost: importance_levels[1],
        }
      }
      boostquery.bool.should.push(tmp);

      // Boost study programs
      tmp = {
        constant_score: {
          filter: {
            term: {
              "fs.study_type": {
                value: 'program',
              }
            }
          },
          boost: importance_levels[1],
        }
      }
      boostquery.bool.should.push(tmp);

      // Boost study courses
      tmp = {
        constant_score: {
          filter: {
            term: {
              "fs.study_type": {
                value: 'course',
              }
            }
          },
          boost: importance_levels[2],
        }
      }
      boostquery.bool.should.push(tmp);

      // Boost exchange agreements
      tmp = {
        constant_score: {
          filter: {
            term: {
              "fs.study_type": {
                value: 'exchange',
              }
            }
          },
          boost: importance_levels[2],
        }
      }
      boostquery.bool.should.push(tmp);

      // Boost all hits in the study index
      // not boosted otherwise
      tmp = {
        constant_score: {
          filter: {
            bool: {
              must: {
                term: { "_type": { value: 'study' } },
              },
              must_not: [
                { term: { "fs.study_type": { value: 'course' } } },
                { term: { "fs.study_type": { value: 'program' } } },
                { term: { "fs.study_type": { value: 'exchange' } } },
              ],
            },
          },
          boost: importance_levels[3],
        }
      }
      boostquery.bool.should.push(tmp);

      // Boost hits on content type area
      tmp = {
        constant_score: {
          filter: {
            term: {
              "w3.type": {
                value: 'area'
              },
            },
          },
          boost: importance_levels[1],
        },
      };
      boostquery.bool.should.push(tmp);

      // Boost external content
      tmp = {
        constant_score: {
          filter: {
            term: {
              "w3.type": {
                value: 'uib_external_content'
              },
            },
          },
          boost: importance_levels[1],
        },
      };
      boostquery.bool.should.push(tmp);

      // Boost recent content
      tmp = {
        constant_score: {
          filter: {
            bool: {
              must: [
                 {
                   range: {
                     "w3.changed":{
                       gte: "now-1M"
                     },
                   },
                 },
                 {
                   term: {
                     "w3.article_type": {
                       value: 'news'
                     },
                   },
                 },
              ],
            },
          },
          boost: importance_levels[2],
        },
      };
      boostquery.bool.should.push(tmp);

      // Boost upcoming events
      tmp = {
        constant_score: {
          filter: {
            bool: {
              should: [
                {
                  range: {
                    "w3.date.value":{
                      gte: "now/d"
                    },
                  },
                },
                {
                  range: {
                    "w3.date.value2":{
                      gte: "now/d"
                    },
                  },
                },
              ],
              must: [
                 {
                   term: {
                     "w3.article_type": {
                       value: 'event'
                     },
                   },
                 },
              ],
              minimum_should_match: 1,
            },
          },
          boost: importance_levels[2],
        },
      };
      boostquery.bool.should.push(tmp);



      // Boost relevanskriteriene i forhold til søkekriteriene
      // for å få rett effekt av relevanskriteriene
      tmp = {bool: {should: boostquery, boost: 1}};

      // Adding relevance boost to should - clause. Some or none of these can
      // match.
      data.query.bool.should.push(tmp);

      /**************************************
       * Negative boosting
       *
       * Unboostqueries are added to the
       * main query at the very end.
       **************************************/
      var unboost_past_events = {bool: {should: [], _name: "Unboost"}};

      // Events where date.value2 is at least 1 month old
      tmp = {
        bool: {
          must: [
            {
              term: {
                "w3.article_type": {
                  value: 'event'
                },
              },
            },
            {
              range: {
                "w3.date.value2":{
                  lt: "now-1M/d",
                },
              },
            },
          ],
        }
      };
      unboost_past_events.bool.should.push(tmp);

      // Events where date.value2 does not exists and date.value is at least
      // 1 month old
      tmp = {
        bool: {
          must: [
            {
              term: {
                "w3.article_type": {
                  value: 'event'
                },
              },
            },
            {
              range: {
                "w3.date.value":{
                  lt: "now-1M/d",
                },
              },
            },
          ],
          must_not: [
            {
              exists: {
                field: "w3.date.value2",
              }
            },
          ],
        }
      };
      unboost_past_events.bool.should.push(tmp);

      /**************************************
       * Filtering
       * The filtering will not affect
       * relevance scores.
       *************************************/
      // Hide users on KHiB until jan 1. 2017
      if (new Date()<new Date(2017,0,1,0,0,0,0)) {
        data.query.bool.filter.bool.must_not =
          {bool:
            {must:
              [
                {match: {ou_nb: {
                  query: 'Fakultet for kunst, musikk og design',
                  operator: 'and'
                }}},
                {type: {value: 'user'}},
              ]
            }
          };
      }
      // All content
      if (
        $('#search-filter-checkboxes input[value=everything]').is(':checked')
      ) {
        all = true;
        // Study
        data.query.bool.filter.bool.should.push(
          {type: {value: 'study'}}
        );
        // User
        data.query.bool.filter.bool.should.push(
          {type: {value: 'user'}}
        );
        // Node
        data.query.bool.filter.bool.should.push(
          {type: {value: 'node'}}
        );
      }

      // Users
      if (
        all ||
        $('#search-filter-checkboxes input[value=user]').is(':checked') ||
        $('#switch_type_button').is(':checked')
      ) {

        if (!all) {
          // Document type must be user
          data.query.bool.filter.bool.should.push(
            {type: {value: 'user'}}
          );
        }

      }

      // News, study, events
      if (all ||
        $('#search-filter-checkboxes input[value=news]').is(':checked') ||
        $('#search-filter-checkboxes input[value=study]').is(':checked') ||
        $('#search-filter-checkboxes input[value=event]').is(':checked')
      ) {

        // News
        if (!all &&
          $('#search-filter-checkboxes input[value=news]').is(':checked')
        ) {
          // Document type: node, and w3 article-type: news
          data.query.bool.filter.bool.should.push({
            bool: {
              should: [
                {type: {value: 'node'}},
                {term: {'w3.article_type': { value: 'news'}}},
              ],
              minimum_should_match: 2,
            }
          });
        }

        // Events
        if (!all &&
          $('#search-filter-checkboxes input[value=event]').is(':checked')
        ) {
          // Document type: node, and w3 article-type: event
          data.query.bool.filter.bool.should.push({
            bool: {
              should: [
                {type: {value: 'node'}},
                {term: {'w3.article_type': { value: 'event'}}},
              ],
              minimum_should_match: 2,
            }
          });
        }

        // Study
        if (!all &&
          $('#search-filter-checkboxes input[value=study]').is(':checked')
        ) {
          // Document type: study
          data.query.bool.filter.bool.should.push(
            {type: {value: 'study'}}
          );
        }
      }
      // Use manual boosting only if new search is enabled. Affects
      // only the search part of the query (not other boosts)
      if (!$('#switch_type_button').length) {
        data.query.bool.must = {
          function_score: {
            query: data.query.bool.must,
            field_value_factor: {
              field: 'search_manual_boost',
              modifier: "square",
              factor: 1,
            },
          }
        }

        // Negative boost for past events
        data.query.bool.must = {
          boosting: {
            positive: data.query.bool.must,
            negative: unboost_past_events,
            negative_boost: 0.03,
          }
        };
      }
      if ($.uib_search.debug) {
        console.log("JSON search query:\n" + JSON.stringify(data))
      }
      return data;
  };
  $.fn.createResults = function (resultsselector, query) {

    return function (data, status, jqXHR) {
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
        .html(data.hits.total + Drupal.t(' hits for') + ' <em>"' + query + '"</em>');
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

        var link = $().getVal(v._source.generic, 'link_' + lang) ||
          $().getVal(v._source.generic, 'link');
        link = link.replace(/^https?:\/\/(?:w3|www)\.uib\.no/, window.location.protocol + "//" + window.location.host);

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
            var from = $('<span></span>').addClass('cal-from').text(
                $.fn.df(event_from, 'd.m.Y H:i')
            );
            if ($.fn.df(event_from, 'd.m.Y') == $.fn.df(event_to, 'd.m.Y')) {
              console.log('same day');
              var to = !isNaN(event_to) && event_to ? $('<span></span>').addClass('cal-to').text($.fn.df(event_to, 'H:i')) : '';
            } else {
              var to = !isNaN(event_to) && event_to ? $('<span></span>').addClass('cal-to').text($.fn.df(event_to, 'd.m.Y H:i')) : '';
            }
            var str_datetime = $('<div></div>').addClass('datetime');
            if (!isNaN(Number(new Date(event_from)))) {
              str_datetime.append(from);
            }
            if (!isNaN(event_to) && event_to) {
              str_datetime.append('-');
              str_datetime.append(to);
            }
            lft.append(
              $('<div></div>').addClass('excerpt')
                .append(str_datetime)
              .append($('<div></div>').addClass('location').html(location))
            );
          }
          else {
            var exlength = 300;
            trim = $.trim(excerpt);
            if (trim.length > exlength) {
              var trim = excerpt.substring(0, exlength);
              trim = trim.substr(0, Math.min(trim.length, trim.lastIndexOf(" ")));
              trim += ' ' + '&hellip;';
            }
            lft.append(
              $('<div></div>').addClass('excerpt').html(trim)
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
                  w3_type == 'area'
                  || w3_type == 'uib_article'
                  || w3_type == 'uib_external_content'
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
        $().searchDelay(function() {
          $().executeQuery(postdata, $.uib_search.currentquery);
        }, 1 );


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
        console.log("Execution time (with execution delay subtracted): " +
          ((new Date().getTime() - uib_timer - $.uib_search.delay)/1000) + "sec"
        );
      }
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
      size: 15,
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
      debug: 0,
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
        $().searchDelay(function() {
          $().executeQuery(postdata, query);
        }, $.uib_search.delay );

      });
    }

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

      var postdata = $().createQuery($.uib_search.currentquery);
      $().searchDelay(function() {
        $().executeQuery(postdata, $.uib_search.currentquery);
      }, 1 );
    }
  });

})(jQuery);
