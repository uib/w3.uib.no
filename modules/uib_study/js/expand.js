(function ($) {
  Drupal.behaviors.uibStudyBehavior = {
    attach: function (context, settings) {
      $('.study-listing').accordion({
        active: false,
        collapsible: true,
        heightStyle: 'content',
        icons: false
      });
      $(document).ready(function() {
        $('.page-studies-alphabetical #uib-study-filter-form').hide();
        setInitChecked();
      });
      $('.page-studies-alphabetical .study-filter-form-form h2').click(function(event) {
        $('.page-studies-alphabetical #uib-study-filter-form').toggle('blind');
        $(this).toggleClass('expanded');
      });
      $('.page-studies-alphabetical #edit-submit').click(function(event) {
        event.preventDefault();
        var checked = getChecked();
        if (checked.length > 0) {
          showSelectedCategories(checked);
        }
        else {
          showAllCategories();
        }
      });
      $('.page-studies-alphabetical #uib-study-filter-form :checkbox').change(function(event) {
        if ($(this).hasClass('study--all-categories')) {
          showAll();
        }
        else {
          showSelected();
        }
      });
      $('.uib-study--to-the-top').click(function(event) {
        event.preventDefault();
        scrollToAnchor('#block-system-main');
      });
      function showAll() {
        $('.page-studies-alphabetical #uib-study-filter-form :checkbox').prop('checked', false);
        $('.page-studies-alphabetical #uib-study-filter-form .study--all-categories').prop('checked', true);
      }
      function showSelected() {
        var checked = 0;
        var checkBoxes = $('.page-studies-alphabetical #uib-study-filter-form :checkbox');
        checkBoxes.each(function() {
          if ($(this).prop('checked')) {
            checked++;
          }
        });
        if (checked) {
          $('.page-studies-alphabetical #uib-study-filter-form .study--all-categories').prop('checked', false);
        }
        else {
          $('.page-studies-alphabetical #uib-study-filter-form .study--all-categories').prop('checked', true);
        }
      }
      function setInitChecked() {
        var params = window.location.search.substring(1).split('&');
        var cats = {bachelor: 'bachelorprogram', master: 'masterprogram', aar: 'arsstudium', masterprof: 'integrertemasterpr-profesjonsst'};
        if (params[0].length > 0) {
          var checked = [];
          params.forEach(function(param) {
            checked.push(cats[param]);
            $('.page-studies-alphabetical #uib-study-filter-form .study--all-categories').prop('checked', false);
            $('.page-studies-alphabetical #uib-study-filter-form .study--' + cats[param]).prop('checked', true);
          });
          showSelectedCategories(checked);
        }
      }
      function getChecked() {
        var filters = ['bachelorprogram', 'masterprogram', 'arsstudium', 'integrertemasterpr-profesjonsst'];
        var checked = [];
        var checkBoxes = $('.page-studies-alphabetical #uib-study-filter-form :checkbox');
        checkBoxes.each(function() {
          if ($(this).prop('checked') == true) {
            var thisCheckBox = $(this).attr('class');
            filters.forEach(function(filter) {
              if (thisCheckBox.indexOf(filter) > -1) {
                checked.push(filter);
              }
            });
          }
        });
        return checked;
      }
      function showSelectedCategories(checked) {
        var studyCategories = $('.page-studies-alphabetical .study-index-alpha > div');
        var newQueryString = ''
        var categories = {bac: 'bachelor', mas: 'master', ars: 'aar', int: 'masterprof'};
        studyCategories.hide();
        studyCategories.each(function() {
          var sc = $(this);
          checked.forEach(function(c) {
            if (sc.hasClass('study-cat--' + c)) {
              sc.show();
              newQueryString += categories[c.substr(0, 3)] + '&';
            }
          });
        });
        if (history.pushState) {
          history.replaceState(null, '', location.href.split('?')[0]);
          history.replaceState(null, null, '?' + newQueryString.substr(0, newQueryString.length - 1));
        }
      }
      function showAllCategories() {
        $('.page-studies-alphabetical .study-index-alpha > div').show();
        if (history.pushState) {
          history.replaceState(null, '', location.href.split('?')[0]);
        }
      }
      function scrollToAnchor(id) {
        $('html, body').animate({scrollTop: $(id).offset().top}, 'slow');
      }
    }
  };
})(jQuery);
