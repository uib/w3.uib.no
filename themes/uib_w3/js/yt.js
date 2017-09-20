var player;
function onYouTubeIframeAPIReady() {
  var primaryMedia = document.getElementsByClassName('media-youtube-player')[0].getAttribute('id');
  player = new YT.Player(primaryMedia, {
    events: {
      'onReady': onPlayerReady,
      'onStateChange': onPlayerStateChange
    }
  });
}
function onPlayerReady(event) {
  var playButton = document.getElementsByClassName('uib-play-video')[0].getElementsByTagName('a')[0];
  playButton.addEventListener('click', function(event) {
    event.preventDefault();
    videoPlay(true);
  }, false);
  if (!isMobile()) {
    videoPlay(false);
  }
}
function onPlayerStateChange(playerStatus) {
  if ((playerStatus.data == 2 || playerStatus.data == 0) && isMobile()) {
    videoStop();
  }
}
function videoPlay(mobile) {
  if (mobile) {
    var mediaContainer = document.getElementsByClassName('field-name-field-uib-primary-media')[0];
    mediaContainer.className = mediaContainer.className + ' focus';
  }
  player.playVideo();
}
function videoStop() {
  var mediaContainer = document.getElementsByClassName('field-name-field-uib-primary-media')[0];
  mediaContainer.className = mediaContainer.className.replace(' focus', '');
}
function isMobile() {
  var deviceHeight = window.innerHeight;
  var deviceWidth = window.innerWidth;
  if ((deviceHeight > 736 && deviceWidth > 414) || deviceHeight > 414 && deviceWidth > 736) {
    return false;
  }
  else {
    return true;
  }
}
