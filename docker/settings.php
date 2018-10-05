<?php

$databases['default']['default'] = array (
  'driver' => 'pgsql',
  'host'     => getenv('PG_HOST') ?: 'postgres',
  'port'     => getenv('PG_PORT') ?: '5432',
  'database' => getenv('PG_DB')   ?: 'w3',
  'username' => getenv('PG_USER') ?: 'user1',
  'password' => getenv('PG_PASS') ?: 'pass1',
);

$drupal_hash_salt = 'sjjvmixirayppxnsqnucsdgwuuejktmlmwnknlggaznyoleidlxeqvdkgfyg';

if ($_SERVER['HTTP_HOST'] == 'www.uib.no') {
  $base_url = 'https://www.uib.no';
}

if ($_SERVER['HTTP_HOST'] == 'w3.uib.no') {
  $base_url = 'https://w3.uib.no';
}

$conf['uib_sws_url'] = getenv('SWS_URL') ?: 'https://sws.dataporten-api.no/';
$conf['uib_sws_access_token'] = getenv('SWS_ACCESS_TOKEN') ?: NULL;

$conf['hybridauth_provider_Dataporten_keys_id'] = getenv('DATAPORTEN_CLIENT_ID') ? NULL;
$conf['hybridauth_provider_Dataporten_keys_secret'] = getenv('DATAPORTEN_CLIENT_SECRET') ? NULL;

# stage_file_proxy
$conf['stage_file_proxy_origin'] = 'http://www.uib.no';
#$conf['stage_file_proxy_hotlink'] = TRUE;

$update_free_access = FALSE;
ini_set('memory_limit', '640M');
ini_set('session.gc_probability', 1);
ini_set('session.gc_divisor', 100);
ini_set('session.gc_maxlifetime', 200000);
ini_set('session.cookie_lifetime', 2000000);
$conf['404_fast_paths_exclude'] = '/\/(?:styles)\//';
$conf['404_fast_paths'] = '/.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['404_fast_html'] = '<!DOCTYPE html><html><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';
