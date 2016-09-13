jQuery( document ).ready(function ($) {
  var language = $('html').attr('lang');
  var json = "/api/msg?area=IT-avdelingen&tag=1&limit=6&language="+language;
  $.getJSON(json, function(result){
    $("#messages-block-content").text("");
    $.each(result, function(i, field){
      var json_obj = field;
      var output = "<div class='uib-collapsible-container'>";
      output += "<h2 class='uib-collapsible-handle closed'>Vis meldinger</h2>";
      output += "<ul class='uib-collapsible-content' style='display:none;'>";
      for (var i in json_obj) {
        output += "<li>";
        output += "<span class='uib_message_area'>" + Drupal.checkPlain(json_obj[i].area) + "</span>"
               + " <span class='uib_message_tag'>" + Drupal.checkPlain(json_obj[i].tag) + "</span>"
               + " <span class='uib_message_text'>" + Drupal.checkPlain(json_obj[i].text) + "</span>";
        if(json_obj[i].link) {
          output += " <span class='uib_message_link'><a href='" + json_obj[i].link + "'>Read more...</a></span>";
        }
        output += "</li>";
      }
      output += "</ul>";
      output += "</div>";
      $("#messages-block-content").append(output);
      $(".uib-collapsible-handle").css("cursor", "pointer");
      $(".uib-collapsible-handle").click(function(event){
        $(".uib-collapsible-content").toggle();
        $(".uib-collapsible-handle").toggleClass('open closed');
        $(".uib-collapsible-handle").html($(".uib-collapsible-handle").html() == 'Vis meldinger' ? 'Skjul meldinger' : 'Vis meldinger');
      });
    });
  });
});
