<?php
  $style = <<<EOT
  <style>
    #search ::-webkit-input-placeholder { /* WebKit browsers */
      color: #333;
    }
    #search :-moz-placeholder { /* Mozilla Firefox 4 to 18 */
      color: #333;
      opacity:  1;
    }
    #search ::-moz-placeholder { /* Mozilla Firefox 19+ */
      color:    #333;
      opacity:  1;
    }
    #search :-ms-input-placeholder { /* Internet Explorer 10+ */
      color:    #333;
    }
    #search { /* General search box styling */
      font-family: 'verdana', 'trebuchet MS', 'Tahoma', sans-serif;
      font-size: 12px;
      margin: 10px auto;
      border-radius: 0;
      padding: 20px;
      background: #026f9c;
    }
    #search a {
      font-size: 14px;
      color: #fff;
    }
    #search input {
      width: 75%;
      font-size: 15px;
      box-sizing: border-box;
      border: 0 none;
      height: 3em;
      padding-left: 1.8%;
      float: left;
      background: #fff;
    }
    #search button {
      box-sizing: border-box;
      overflow: visible;
      position: relative;
      float: right;
      border: 0;
      padding: 0;
      cursor: pointer;
      height: 3em;
      width: 25%;
      font: bold 15px/40px 'verdana';
      color: #fff;
      text-transform: uppercase;
      background: #009de0;
      text-shadow: 0 -1px 0 rgba(0, 0 ,0, .3);
    }
    #search .alt-options {
      clear: left;
      margin: 0;
      padding: 20px 0 0;
    }
    #search .alt-options li{
      display: inline-block;
      margin-right: 2em;
    }
  </style>
EOT;

  $new_banner_value = <<<EOT
<div id="search" class="clearfix">
  $style
  <div>
    <form name='searchForm' role='search' method='post' action='http://www.oria.no/' enctype='application/x-www-form-urlencoded; charset=utf-8' id='simple' target='_self' >
      <label class="element-invisible element-focusable" for="artikler-mm">Søk etter artikler, bøker, tidsskrifter med mer i Oria</label>
      <input name='institution' value='UBB' type='hidden'>
      <input name='vid' value='UBB' type='hidden'>
      <input name='search_scope' value='default_scope' type='hidden'>
      <input name='lang' value='nor' type='hidden'>
      <input name='prefLang' value='no_NO' type='hidden'>
      <input type='hidden' value='true' name='afterPDS'>
      <input type='hidden' name='check' value='checked'>
      <input placeholder="Søk etter artikler, bøker, tidsskrifter med mer i Oria" type='text' size='25' id='query' value='' name='query'  />
      <button type="submit">Søk</button>
    </form>
    <ul class="alt-options">
      <li>
        <a href="http://bibsys-primo.hosted.exlibrisgroup.com/primo_library/libweb/action/search.do?mode=Advanced&vid=UBB&tab=default_tab&lang=nor&prefLang=no_NO">Avansert søk</a>
      </li>
      <li>
        <a href="http:// bibsys-primo.hosted.exlibrisgroup.com/primo_library/libweb/action/dlSearch.do?institution=UBB&vid=UBB&openFdb=true&prefLang=no_NO">Finn databaser</a>
      </li>
      <li>
        <a href="http://www.uib.no/ub/82586/forny-dine-lån">Forny dine lån</a>
      </li>
      <li>
        <a href="http://www.uib.no/ub/82578/søke-låne-og-fornye">Hjelp</a>
      </li>
    </ul>
  </div>
</div>
<script type="text/javascript" src="http://org.uib.no/form/js/simple.js"></script>
EOT;

  $new_banner_value_en = <<<EOT
<div id="search" class="clearfix">
  $style
  <div>
    <form name='searchForm' role='search' method='post' action='http://www.oria.no/' enctype='application/x-www-form-urlencoded; charset=utf-8' id='simple' target='_self' >
      <label class="element-invisible element-focusable" for="artikler-mm">Search Oria for articles, books, journals, and more</label>
      <input name='institution' value='UBB' type='hidden'>
      <input name='vid' value='UBB' type='hidden'>
      <input name='search_scope' value='default_scope' type='hidden'>
      <input name='lang' value='eng' type='hidden'>
      <input name='prefLang' value='en_US' type='hidden'>
      <input type='hidden' value='true' name='afterPDS'>
      <input type='hidden' name='check' value='checked'>
      <input placeholder="Search Oria for articles, books, journals, and more" type='text' size='25' id='query' value='' name='query'  />
      <button type="submit">Search</button>
    </form>
    <ul class="alt-options">
      <li>
        <a href="http://bibsys-primo.hosted.exlibrisgroup.com/primo_library/libweb/action/search.do?mode=Advanced&vid=UBB&tab=default_tab&lang=eng&prefLang=en_US">Advanced search</a>
      </li>
      <li>
        <a href="http://bibsys-primo.hosted.exlibrisgroup.com/primo_library/libweb/action/dlSearch.do?institution=UBB&vid=UBB&openFdb=true&prefLang = en_US">Find databases</a>
      </li>
      <li>
        <a href="http://www.uib.no/en/ub/84699/renewing-loans">Renewing loans</a>
      </li>
      <li>
        <a href="http://www.uib.no/en/ub/84582/searching-lending-and-renewing-loans">Help</a>
      </li>
    </ul>
  </div>
</div>
<script type="text/javascript" src="http://org.uib.no/form/js/simple.js"></script>
EOT;
