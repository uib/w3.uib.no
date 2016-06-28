jQuery( document ).ready(function ($) {
  var json = "/api/msg?area=IT-avdelingen&tag=1";
  $.getJSON(json, function(result){
    $("#messages-block-content").text("");
    $.each(result, function(i, field){
      var json_obj = field;
      var output = "<ul>";
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
      $("#messages-block-content").append(output);
    });
  });
});
