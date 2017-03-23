; This file declares what modules are required for the w3 application.
; The 'drupal' directory can be rebuilt from scratch based on this file by
; invoking the 'make-drupal' command (which invokes 'drush make').
;
; Normally you should not edit this file directly.  The 'module-update'
; command is used to upgrade individual modules.
;
core = 7.x
api = 2

;translations[] = nb

; core
projects[drupal][version] = 7.54
projects[drupal][patch][] = https://drupal.org/files/issues/node-sql-rewrite-1969208-28.patch
projects[drupal][patch][] = https://drupal.org/files/issues/drupal-require_subdomain_for_mailto_links-2016739-49.patch

; themes
projects[adminimal_theme][version] = 1.24

; modules
projects[addressfield][version] = 1.2
projects[admin_menu][version] = 3.0-rc5
projects[adminimal_admin_menu][version] = 1.7
projects[advanced_help][version] = 1.3
projects[autocomplete_deluxe][version] = 2.2
projects[better_exposed_filters][version] = 3.4
projects[better_formats][version] = 1.0-beta2
projects[better_formats][patch][] = https://www.drupal.org/files/issues/better_formats-default-text-format-override-2272385-6.patch
projects[bot][revision] = d0e10c65616f267543e717addc17422979f83bd2
projects[breakpoints][version] = 1.4
projects[browsersync][version] = 1.1
projects[coder][version] = 2.6
projects[colorbox][version] = 2.12
projects[colorbox][patch] = https://www.drupal.org/files/issues/colorbox-fix_token_types_error-1.patch
projects[context][version] = 3.7
projects[context][patch][] = patches/context-disable-menu.patch
projects[ctools][version] = 1.12
projects[date][version] = 2.9
projects[datepicker][version] = 1.0
projects[devel][version] = 1.5
projects[diff][version] = 3.3
projects[entity][version] = 1.8
projects[entity_translation][version] = 1.0-beta6
projects[entity_view_mode][version] = 1.0-rc1
projects[entityreference][version] = 1.2
projects[entityreference][patch][] = https://drupal.org/files/issues/entityreference-autocomplete-items-limit-1700112-6.patch
projects[entityreference_prepopulate][version] = 1.7
projects[eu_cookie_compliance][version] = 1.14
projects[features][version] = 2.10
projects[feeds][version] = 2.0-beta2
projects[feeds_xpathparser][version] = 1.1
projects[field_collection][version] = 1.0-beta12
projects[field_formatter_settings][version] = 1.1
projects[field_group][version] = 1.5
projects[field_multiple_limit][version] = 1.0-alpha5
projects[field_permissions][version] = 1.0
projects[file_entity][version] = 2.0-beta3
projects[filecache][version] = 1.0-beta4
projects[flag][version] = 3.9
projects[focal_point][version] = 1.0
projects[geocoder][version] = 1.3
projects[geofield][version] = 2.3
projects[geophp][version] = 1.7
projects[google_analytics][version] = 2.3
projects[google_tag][version] = 1.0
projects[i18n][version] = 1.15
projects[imagemagick][version] = 1.0
projects[job_scheduler][version] = 2.0-alpha3
projects[jquery_update][version] = 2.7
projects[l10n_client][version] = 1.3
projects[l10n_update][version] = 2.1
projects[ldap][version] = 1.0-beta14
projects[ldap][patch][] = https://www.drupal.org/files/ldap_server_init-1775658-1.patch
projects[libraries][version] = 2.3
projects[link][version] = 1.4
projects[linked_field][version] = 1.10
projects[login_destination][version] = 1.4
projects[manualcrop][version] = 1.6
projects[markdown][version] = 1.5
projects[maxlength][version] = 3.2
projects[media][version] = 2.0-rc12
projects[media_vimeo][version] = 2.1
projects[media_youtube][version] = 3.0
projects[menu_admin_per_menu][version] = 1.1
projects[menu_block][version] = 2.7
projects[module_filter][version] = 2.0
projects[node_revision_delete][version] = 2.6
projects[node_revision_delete][patch][] = https://www.drupal.org/files/issues/postgresql_pdoexception-2333555-1.patch
projects[office_hours][version] = 1.6
projects[override_node_options][version] = 1.13
projects[panels][version] = 3.9
projects[pathauto][version] = 1.3
projects[phone][version] = 1.0-beta1
projects[phone][patch][] = https://www.drupal.org/files/issues/phone-norwegian-support-2292299-3.patch
projects[picture][version] = 2.13
projects[redirect][version] = 1.0-rc3
projects[role_delegation][version] = 1.1
projects[role_export][version] = 1.0
projects[rules][version] = 2.9
projects[scheduler][version] = 1.5
projects[service_links][version] = 2.1
projects[stage_file_proxy][version] = 1.7
projects[strongarm][version] = 2.0
projects[styleguide][version] = 1.1
projects[subpathauto][version] = 1.3
projects[taxonomy_menu][version] = 1.5
projects[text_resize][version] = 1.9
projects[title][version] = 1.0-alpha9
projects[token][version] = 1.7
projects[transliteration][version] = 3.2
projects[variable][version] = 2.5
projects[view_unpublished][version] = 1.2
projects[views][version] = 3.15
projects[views][patch][] = https://www.drupal.org/files/issues/views-3.x-dev-issue_1331056-52.patch
projects[views_bulk_operations][version] = 3.4
projects[views_data_export][version] = 3.1
projects[views_field_view][version] = 1.2
projects[views_slideshow][version] = 3.1
projects[wysiwyg][revision] = 949039351d71d24d60faee4f63c6527e54761ee1

; libraries
libraries[jquery.cycle][download][type] = file
libraries[jquery.cycle][download][url] = https://github.com/malsup/cycle/archive/4fffa1d366e964267ca433db9f8bfc83723f04a4.zip

libraries[tinymce][download][type] = file
libraries[tinymce][download][url] = http://download.moxiecode.com/tinymce/tinymce_3.5.8.zip

libraries[ckeditor][download][type] = file
libraries[ckeditor][dowbload][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.5.7/ckeditor_4.5.7_full.zip
