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
        removeToken();
        var feideUser = data.user.userid_sec;
        var user = feideUser[0].split(":")[1].split("@")[0];
        var json = "/api/msg?user=" + user + "&limit=12&language="+language;
        $.getJSON(json, function(result){
          $("#messages-block-content").text("");
          $.each(result, function(i, field){
            var json_obj = field;
            var output = "<div class='uib-collapsible-container'>";
            output += "<h2 class='uib-collapsible-handle closed'>" + Drupal.t('Show messages') + "</h2>";
            output += "<div class='uib-collapsible-content' style='display:none;'>";
            output += "<ul>";
            var now = new Date();
            for (var i in json_obj) {
              var lapsed = now.getTime() - Drupal.checkPlain(json_obj[i].posted_time)*1000;
              if (lapsed < 1000*60*60*24*7) {
                output += "<li>";
                output +=  "<div class='message-tag'>" + Drupal.checkPlain(json_obj[i].tag) + "</div>"
                       + " <div class='message-text'><span class='text'>" + Drupal.checkPlain(json_obj[i].text) + "</span>";
                if(json_obj[i].link) {
                  output += " <span class='message-link'><a href='" + json_obj[i].link + "'>" + Drupal.t('Read more') + "...</a></span></div>";
                }
                output += "<div class='message-area'><a href='"
                        + arealink(Drupal.checkPlain(json_obj[i].area_link), language, Drupal.checkPlain(json_obj[i].tag))+ "'>"
                        + Drupal.checkPlain(json_obj[i].area) + "</a></div>";
                output += "<div class='message-age'>" + timeSince(json_obj[i].posted_time) + "</div>";
                output += "</li>";
              }
            }
            output += "</ul>";
            output += "<div class='uib-feide-login'>";
            output += "Log in";
            output += "</div>";
            output += "</div>";
            output += "</div>";
            $("#messages-block-content").append(output);
            $(".uib-collapsible-handle").click(function(event){
              $(".uib-collapsible-content").toggle();
              $(".uib-collapsible-handle").toggleClass('open closed');
              $(".uib-collapsible-handle").html($(".uib-collapsible-handle").html() == Drupal.t('Show messages') ? Drupal.t('Hide messages') : Drupal.t('Show messages'));
            });
            $(".uib-feide-login").text(Drupal.t('Log out'));
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
    output += "<h2 class='uib-collapsible-handle open'>" + Drupal.t('Messages') + "</h2>";
    output += "<div class='uib-collapsible-content'>"
    output += "<div class='uib-feide-login'>";
    output += Drupal.t('Log in');
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

function arealink(area,language,tag) {
  var msg = (language == 'en') ? 'messages' : 'meldinger';
  return area + "/" + msg + "?tag="+tag;
}

function removeToken() {
  if ("pushState" in history) {
    history.replaceState("", document.title, location.origin + location.pathname);
  }
  else {
    document.location.hash = "";
  }
}

function timeSince(posted_time) {

  var msPerMinute = 60 * 1000;
  var msPerHour = msPerMinute * 60;
  var msPerDay = msPerHour * 24;
  var msPerMonth = msPerDay * 30;
  var msPerYear = msPerDay * 365;

  var now = new Date();
  var elapsed =  now.getTime() - posted_time*1000;

  if (elapsed < msPerMinute) {
    return Math.round(elapsed/1000) + ' ' + Drupal.t('seconds ago');
  }
  else if (elapsed < 2*msPerMinute) {
    return Drupal.t('@elapsed minute ago', {'@elapsed':1});
  }
  else if (elapsed < msPerHour) {
       return Math.round(elapsed/msPerMinute) + ' ' + Drupal.t('minutes ago');
  }
  else if (elapsed < 2*msPerHour) {
    return Drupal.t('@elapsed hour ago', {'@elapsed':1});
  }
  else if (elapsed < msPerDay ) {
       return Math.round(elapsed/msPerHour ) + ' ' + Drupal.t(' hours ago');
  }
  else if (elapsed < 2*msPerDay) {
    return Drupal.t('@elapsed day ago', {'@elapsed':1});
  }
  else if (elapsed < msPerMonth) {
      return Drupal.t('@elapsed days ago', {'@elapsed':Math.round(elapsed/msPerDay)});
  }
  else if (elapsed < 2*msPerMonth) {
    return Drupal.t('@elapsed month ago', {'@elapsed':1});
  }
  else if (elapsed < msPerYear) {
      return Drupal.t('@elapsed months ago', {'@elapsed':Math.round(elapsed/msPerMonth)});
  }
  else if (elapsed < 2*msPerYear) {
    return Drupal.t('@elapsed year ago', {'@elapsed':1});
  }
  else {
      return Drupal.t('@elapsed years ago', {'@elapsed':Math.round(elapsed/msPerYear)});
  }
}

function getClientID() {
  if (location.origin == 'http://localhost:3000') return 'ebb2d254-a8a1-4bbb-a98e-fb7b4eab63f0';
  else return 'c2d666d7-b029-46fa-91eb-1b340ef12ea0';
}
