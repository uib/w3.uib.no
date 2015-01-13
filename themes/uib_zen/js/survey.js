// RTS-9274
(function () {
    var _wt = 'ea42c3';
    if (document.cookie.indexOf('VISITED_4031') < 0) {
        var ws = document.createElement('script'); ws.type = 'text/javascript'; ws.async = true;
        ws.src = ('https:' == document.location.protocol ? 'https://ssl.' : 'http://') + 'survey.webstatus.v2.userneeds.dk/wsi.ashx?t=' + _wt + (location.href.indexOf('wsiNoCookie') >= 0 ? '&nc=1' : '');
        var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ws, s);
}})();
