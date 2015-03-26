(function ($) {

  Drupal.behaviors.uib_study_prev = {
    attach: function (context, settings) {
      $(document).ready(function () {
          var curData = $( ".previous-exists" );
          var prevData = $( ".previous-semester" );
          var nextData = $( ".next-semester" );
          $( "a.previous" ).click(function() {
            curData.hide();
            prevData.show();
            nextData.hide();
            $( "a.previous" ).addClass( "is-active" );
            $( "a.current" ).removeClass( "is-active" );
            $( "a.next" ).removeClass( "is-active" );
          });
      });
    }
  }

  Drupal.behaviors.uib_study_curr = {
    attach: function (context, settings) {
      $(document).ready(function () {
          var curData = $( ".variants-exist" );
          var prevData = $( ".previous-semester" );
          var nextData = $( ".next-semester" );
          $( "a.current" ).click(function() {
            curData.show();
            prevData.hide();
            nextData.hide();
            $( "a.current" ).addClass( "is-active" );
            $( "a.previous" ).removeClass( "is-active" );
            $( "a.next" ).removeClass( "is-active" );
          });
      });
    }
  }

  Drupal.behaviors.uib_study_next = {
    attach: function (context, settings) {
      $(document).ready(function () {
          var curData = $( ".next-exists" );
          var prevData = $( ".previous-semester" );
          var nextData = $( ".next-semester" );
          $( "a.next" ).click(function() {
            curData.hide();
            prevData.hide();
            nextData.show();
            $( "a.previous" ).removeClass( "is-active" );
            $( "a.current" ).removeClass( "is-active" );
            $( "a.next" ).addClass( "is-active" );
          });
      });
    }
  }

})(jQuery);
