jQuery( document ).ready(function ($) {
  var language = $('html').attr('lang');
  if (Drupal.settings.user) {
    getMessages(Drupal.settings.user, language, false);
  }
  else {
    if (language === 'en') {
      var redirect_area = '/en/foremployees';
    }
    else {
      var redirect_area = location.origin === 'http://localhost:3000' ? '/nb/foransatte' : '/foransatte';
    }
    var redirect_uri = location.origin + redirect_area ;
    var jso = new JSO({
      providerID: "dataporten",
      client_id: getClientID(),
      authorization: "https://auth.dataporten.no/oauth/authorization",
      default_lifetime: false,
      redirect_uri: redirect_uri
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
          getMessages(user, language, true);
        }
      });
    }
    else {
      $("#messages-block-content").text("");
      var output = "<div class='uib-collapsible-container'>";
      output += "<h2 class='uib-collapsible-handle open'>" + Drupal.t('Messages') + "</h2>";
      output += "<div class='uib-collapsible-content'>"
      output += "<div class='uib-message-login'>";
      output += "<div class='uib-feide-login'>";
      output += Drupal.t('Log in');
      output += "</div>";
      output += "<p class='uib-message-login-description'>";
      output += Drupal.t('You will be redirected to a log in page. Choose University of Bergen and log in with your UiB username and password.');
      output += "</p>";
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
  }
  function toggleMessageBox(newMessages) {
    $(".uib-collapsible-content").toggle();
    $(".uib-collapsible-handle").toggleClass('open closed');
    $(".uib-collapsible-handle").html($(".uib-collapsible-handle").html().startsWith(Drupal.t('Show messages')) ? Drupal.t('Hide messages') : Drupal.t('Show messages'));
    if($(".uib-collapsible-handle").hasClass('open')) {
      now = new Date();
      document.cookie = "uib-messages-last-visit=" + now.getTime();
    }
    if (newMessages) {
      $(".uib-collapsible-handle").append(' <span class="new-messages-count">(' + newMessages + ' ' + Drupal.t('new') + ')</span>');
    }
  }
  function getMessages(user, language, dp) {
    var json = "/api/msg?user=" + user + "&limit=12&language="+language;
    $.getJSON(json, function(result){
      $("#messages-block-content").text("");
      $.each(result, function(i, field){
        var json_obj = field;
        var output = "<div class='uib-collapsible-container'>";
        output += "<h2 class='uib-collapsible-handle open'>" + Drupal.t('Hide messages') + "</h2>";
        output += "<div class='uib-collapsible-content'>";
        var now = new Date();
        var lastVisit = getCookie('uib-messages-last-visit');
        var newMessages = 0;
        var addToOutput = false;
        var offset = 0;
        for (var i in json_obj) {
          var lapsed = now.getTime() - Drupal.checkPlain(json_obj[i].posted_time)*1000;
          if (lapsed < 1000*60*60*24*7) {
            if (addToOutput) addToOutput += messageMarkup(i, json_obj, language);
            else addToOutput = messageMarkup(i, json_obj, language);
            if (Drupal.checkPlain(json_obj[i].posted_time)*1000 > lastVisit) {
              newMessages++;
            }
            offset++;
          }
        }
        if (addToOutput) {
          output += "<ul>"
          output += addToOutput;
          output += "</ul>";
        }
        else {
          output += "<p class='uib-no-messages'>" + Drupal.t('No new messages.') + "</p>";
        }
        if (dp) {
          output += "<div class='uib-feide-logout'>";
          output += "<a class='uib-feide-loggedin'>" + Drupal.t('Log out') + "</a>";
          output += "</div>";
        }
        output += "<div class='message-archive'>" + Drupal.t('Show older messages') + "</div>";
        output += "</div>";
        output += "</div>";
        $("#messages-block-content").append(output);
        $(".uib-collapsible-handle").click(function(event){
          toggleMessageBox(0);
        });
        $(".uib-feide-loggedin").click(function() {
          jso.wipeTokens();
          document.cookie = "uib-messages-logged-in=0; expires=-1"
          window.location.assign(location.origin + location.pathname);
        });
        $(".message-archive").click(function() {
          showArchive(user, language, offset);
        });
        if(!getCookie("uib-messages-logged-in") || getCookie("uib-messages-logged-in") == 0) {
          document.cookie = "uib-messages-logged-in=1";
        }
        else {
          toggleMessageBox(newMessages);
        }
      });
    });
  }
  function showArchive(user, language, offset) {
    var json = "/api/msg?user=" + user + "&offset=" + offset +"&language="+language;
    $.getJSON(json, function(result){
      var markup = '';
      $.each(result, function(i, field){
        for (var i in field) {
          markup += messageMarkup(i, field, language);
        }
      });
        $('.message-archive').remove();
      if (markup && $('.uib-collapsible-content ul').length) {
        $('.uib-collapsible-content ul').append(markup);
      }
      else if (markup) {
        $('.uib-collapsible-content .uib-no-messages').remove();
        $('.uib-collapsible-content').append('<ul></ul>');
        $('.uib-collapsible-content ul').append(markup);
      }
      else {
        $('.uib-collapsible-content').append('<p class="uib-no-messages">' + Drupal.t('No messages') + '</p>');
      }
    });
  }
});

function getCookie(name) {
    function escape(s) { return s.replace(/([.*+?\^${}()|\[\]\/\\])/g, '\\$1'); };
    var match = document.cookie.match(RegExp('(?:^|;\\s*)' + escape(name) + '=([^;]*)'));
    return match ? match[1] : null;
}

function arealink(area,language,tag) {
  var msg = (language == 'en') ? 'messages' : 'meldinger';
  return area + "/" + msg + "?tag="+tag;
}

function messageMarkup(i, json_obj, language) {
  var markup = "<li>";
  markup +=  "<div class='message-tag'>" + Drupal.checkPlain(json_obj[i].tag) + "</div>"
         + " <div class='message-text'><span class='text'>" + Drupal.checkPlain(json_obj[i].text) + "</span>";
  if(json_obj[i].link) {
    markup += " <span class='message-link'><a href='" + json_obj[i].link + "'>" + Drupal.t('Read more') + "...</a></span></div>";
  }
  markup += "<div class='message-area'><a href='"
          + arealink(Drupal.checkPlain(json_obj[i].area_link), language, Drupal.checkPlain(json_obj[i].tag))+ "'>"
          + Drupal.checkPlain(json_obj[i].area) + "</a></div>";
  markup += "<div class='message-age'>" + timeSince(json_obj[i].posted_time) + "</div>";
  markup += "</li>";
  return markup;
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
