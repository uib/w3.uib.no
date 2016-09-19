jQuery( document ).ready(function ($) {
  var language = $('html').attr('lang');
  var jso = new JSO({
    providerID: "dataporten",
    client_id: "ebb2d254-a8a1-4bbb-a98e-fb7b4eab63f0",
    authorization: "https://auth.dataporten.no/oauth/authorization",
    default_lifetime: false,
    redirect_uri: window.location.href
  });
  jso.callback();
  JSO.enablejQuery($);
  if (jso.checkToken()) {
    jso.ajax({
      url: "https://auth.dataporten.no/userinfo",
      datatype: 'json',
      success: function(data) {
        var feideUser = data.user.userid_sec;
        var user = feideUser[0].split(":")[1].split("@")[0];
        var json = "/api/msg?user=" + user + "&limit=6&language="+language;
        $.getJSON(json, function(result){
          $("#messages-block-content").text("");
          $.each(result, function(i, field){
            var json_obj = field;
            var output = "<div class='uib-collapsible-container'>";
            output += "<h2 class='uib-collapsible-handle closed'>Vis meldinger</h2>";
            output += "<div class='uib-collapsible-content' style='display:none;'>";
            output += "<ul>";
            for (var i in json_obj) {
              output += "<li>";
              output +=  " <span class='message-tag'>" + Drupal.checkPlain(json_obj[i].tag) + "</span>"
                     + " <span class='message-text'>" + Drupal.checkPlain(json_obj[i].text) + "</span>";
              if(json_obj[i].link) {
                output += " <span class='message-link'><a href='" + json_obj[i].link + "'>Read more...</a></span>";
              }
              output += "<span class='message-area'>" + Drupal.checkPlain(json_obj[i].area) + "</span>";
              output += "</li>";
            }
            output += "</ul>";
            output += "<div class='uib-feide-login'>";
            output += "Logg inn";
            output += "</div>";
            output += "</div>";
            output += "</div>";
            $("#messages-block-content").append(output);
            $(".uib-collapsible-handle").click(function(event){
              $(".uib-collapsible-content").toggle();
              $(".uib-collapsible-handle").toggleClass('open closed');
              $(".uib-collapsible-handle").html($(".uib-collapsible-handle").html() == 'Vis meldinger' ? 'Skjul meldinger' : 'Vis meldinger');
            });
            $(".uib-feide-login").text("Logg ut");
            $(".uib-feide-login").click(function() {
              jso.wipeTokens();
              window.location.assign(location.origin + location.pathname);
            });
          });
        });
      }
    });
  }
  else {
      $("#messages-block-content").text("");
      var output = "<div class='uib-collapsible-container'>";
      output += "<h2 class='uib-collapsible-handle open'>Meldinger</h2>";
      output += "<div class='uib-collapsible-content'>"
      output += "<div class='uib-feide-login'>";
      output += "Logg inn";
      output += "</div>";
      output += "</div>"
      $("#messages-block-content").append(output);
      $(".uib-feide-login").click(function() {
        jso.ajax({
          url: "https://auth.dataporten.no/userinfo",
          datatype: 'json',
        });
      });
  }
});
