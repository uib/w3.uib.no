jQuery( document ).ready(function ($) {
  var language = $('html').attr('lang');
  var jso = new JSO({
    providerID: "dataporten",
    client_id: getClientID(),
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
              console.log(json_obj[i]);
              output += "<span class='message-area'>" + Drupal.checkPlain(json_obj[i].area) + "</span>";
              output += "<span class='message-age'>" + timeSince(json_obj[i].posted_time) + "</span>";
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

function timeSince(posted_time) {

  var msPerMinute = 60 * 1000;
  var msPerHour = msPerMinute * 60;
  var msPerDay = msPerHour * 24;
  var msPerMonth = msPerDay * 30;
  var msPerYear = msPerDay * 365;

  var now = new Date();
  var elapsed =  now.getTime() - posted_time*1000;

  if (elapsed < msPerMinute) {
       return Math.round(elapsed/1000) + ' seconds ago';
  }
  else if (elapsed < msPerHour) {
       return Math.round(elapsed/msPerMinute) + ' minutes ago';
  }
  else if (elapsed < msPerDay ) {
       return Math.round(elapsed/msPerHour ) + ' hours ago';
  }
  else if (elapsed < msPerMonth) {
      return 'approximately ' + Math.round(elapsed/msPerDay) + ' days ago';
  }
  else if (elapsed < msPerYear) {
      return 'approximately ' + Math.round(elapsed/msPerMonth) + ' months ago';
  }
  else {
      return 'approximately ' + Math.round(elapsed/msPerYear ) + ' years ago';
  }
}

function getClientID() {
  if (location.origin == 'http://localhost:3000') return 'ebb2d254-a8a1-4bbb-a98e-fb7b4eab63f0';
  else return 'c2d666d7-b029-46fa-91eb-1b340ef12ea0';
}
