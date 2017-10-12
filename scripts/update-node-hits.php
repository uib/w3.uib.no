<?php

/*******************************************************************************
*
* This script loops over access logs in /log - folders, and updates access-
* frequencies for urls.
*
* How many days to process, default 7, can be set with the variable
* uib_search_days_to_process_hits (eg. using drush vset)
*******************************************************************************/

$folder = '/nettapp_w3/logs';
if (!file_exists($folder)) {
  // staging - server mounts this folder at prod_nettapp_w3
  $folder = '/prod_nettapp_w3/logs';
}
if (!file_exists($folder)) {
  // Development setup. You need to sync logs to your developemtn environment
  // by running the sync-w3-logs-dev - script
  $folder = '/tmp/w3logs';
}
$dir = new DirectoryIterator($folder);

$ignore_end = array(
  '.jpg',
  '.jpeg',
  'calrss.xml',
  'card.vcf',
  'meldinger.xml',
  'autodiscover.xml',
  '.css',
  '.js',
  '.png',
  '.svg',
  '.ico',
  '.xml',
  '.gif',
  'robots.txt',
  '.ics',
  '/calendar',
  '/kalender',
  '/persons',
  '/personer',
  '.htm',
  '.html',
  '.pdf',
);
$ignore_start = array(
  '/file',
  '/nb/file',
  '/en/file',
);
$ignore_all = array(
  '/',
  '/nb',
  '/nb/',
  '/en',
  '/en/',
  '/wp-login.php',
  '/index.php',
);

// Ignore these (might be more...)
$robots = array(
  'http://www.google.com/bot.html',
  'Twitterbot/1.0',
  'http://archive.org/details/archive.org_bot',
  'http://help.naver.com/support/robots.html',
  'http://help.yahoo.com/help/us/ysearch/slurp',
  'http://mj12bot.com/',
  'http://napoveda.seznam.cz/en/seznambot-intro/',
  'http://www.apple.com/go/applebot',
  'http://www.baidu.com/search/spider.html',
  'http://www.bing.com/bingbot.htm',
  'TelegramBot (like TwitterBot)',
  'http://ahrefs.com/robot/)',
  'http://www.semrush.com/bot.html',
  'Startsidenbot/1.. (+http://www.startsiden.no)',
  'http://socialrank.io/about',
  'http://www.thinglink.com/help/ThinglinkImageBot',
  'http://www.exabot.com/go/robot',
  'http://www.majestic12.co.uk/bot.php',
  'http://www.opensiteexplorer.org/dotbot',
  'http://www.uptimerobot.com/',
  'http://yandex.com/bots',
  'https://discordapp.com',
  'http://naver.me/bot',
  'http://www.nb.no/vevfangst',
  'Barbarossa Spider',
  'Sogou web spider',
);

$days = variable_get('uib_search_days_to_process_hits', 7);
variable_set('uib_search_days_to_process_hits', $days);
$filepattern = array();
// Only files that match the dates in $filepattern will be processed
for ($i = 0; $i < $days; $i++ ) {
  $filepattern[] = date('Ymd', time() - ($i * 24 * 60 * 60));
}

$access_frequencies = array();
// Loop over access logs
foreach ($dir as $fi) {
  $p = '/(' . implode(')|(', $filepattern) . '\.gz)/';
  if (!preg_match($p, $fi->getFilename()) || $fi->isDot()) {
    continue;
  }
  $fid = gzopen($fi->getPathname(), 'r');
  while ($fid && !feof($fid)) {
    $buffer = fgets($fid, 4096);
    $url = array();
    if (preg_match('/^.*"GET ([^" \?]+).*$/', $buffer, $url)) {
      $break = FALSE;
      // Ignore urls ending with ...
      foreach ($ignore_end as $v) {
        if (substr($url[1], -strlen($v)) == $v) {
          $break = TRUE;
        }
      }
      // Ignore urls starting with ...
      foreach ($ignore_start as $v) {
        if (substr($url[1], 0, strlen($v)) == $v) {
          $break = TRUE;
        }
      }
      // Ignore urls equal to ...
      foreach ($ignore_all as $v) {
        if ($url[1] == $v) {
          $break = TRUE;
        }
      }
      // Ignore robots ...
      foreach ($robots as $v) {
        if (strpos($url[0], $v) > 0) {
          $break = TRUE;
        }
      }
      if ($break) {
        continue;
      }
      // Handle the url
      $ux = explode('/', trim($url[1], '/'));
      $lang = 'nb';
      if($ux[0] == 'en' || $ux[0] == 'nb'){
        $lang = $ux[0];
        unset($ux[0]);
        $ux=array_values($ux);
      }

      if (@is_numeric($ux[1])) {
        if(in_array($ux[0], array('user', 'node'))) {
          $u ="{$ux[0]}/{$ux[1]}";
        }
        else {
          continue;
        }
      }
      else {
        $u = drupal_get_normal_path(implode('/', $ux), $lang);
        $ux = explode('/', trim($u, '/'));
        if (!in_array($ux[0],array('node', 'user'))) {
          continue;
        }
        // Url not on the form node/88888
        if (count($ux) != 2) {
          continue;
        }
        if (!@is_numeric($ux[1])) {
          continue;
        }
      }
      @$access_frequencies[$u]++;
    }
  }
  gzclose($fid);
}

// Only process if hits is 10 or more
$access_frequencies = array_filter($access_frequencies, function($a) { return $a>9; });
uasort($access_frequencies, function($a, $b) {return $b-$a;});

foreach ($access_frequencies as $key => $value) {
  $id = substr($key, strpos($key, '/')+1);
  $type = substr($key, 0, strpos( $key, '/'));
  if (!in_array($type, array('node', 'user'))) {
    continue;
  }
  try {
    $wrapper = entity_metadata_wrapper($type, $id);
    $max_hits = $value;
    if($current = $wrapper->field_uib_search_hits->value()) {
      $current = json_decode($current);
      $max_hits = max($current->max_hits, $max_hits);
    }
    $wrapper->field_uib_search_hits = json_encode(
      array(
        'max_hits' =>$max_hits,
        'hits' => $value,
        'last_hit' => time(),
      )
    );
    $wrapper->save();
  } catch (Exception $e) {
    uibx_log("Link $key ignored due to error", 'warning');
    uibx_log(print_r($e, true), 'warning');
  }
}
