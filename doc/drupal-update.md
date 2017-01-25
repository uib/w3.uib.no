# Drupal update
This document describe how to upgrade drupal on w3.uib.no.

There are in essence 2 types of update.
* Security update (only drupal code)
* Features update (uib-code and dupal)

## Peperations

This procedure shal first be updated on test first.

### New Features/version

* Log into server(s) as w3-drupal
* Check that git repo is clean
* Backup database
  (sudo /etc/cron.daily/w3_dbdump)
* Enable maintenance mode
  'bin/site-drush vset maintenance_mode 1'
* Update GIT-repo
  (git pull)
* List what module needs updating
  (bin/site-drush fl)
* Update one and one listed update
  (bin/site-drush fr <name>)
* Flush cachen
  (bin/site-drush cc all)
* Update the DB (if needed)
  (bin/site-drush updatedb)
* Flush cachen
  (bin/site-drush cc all)
* Update the other server [Attika vs Attila] (git and CSS)
* Double check if modules is updated
* Disable maintenance mode
  (bin/site-drush vset maintenance_mode 0)

## Security fix

### Update from prod to staging ###

Take make prod db-dump

On prod:
  #Backup prod DB
  sudo  /etc/cron.daily/w3_dbdump

On staging
  #Rsync files
  sudo rsync -aihH --delete /prod_nettapp_w3/sites/w3.uib.no/files/  /nettapp_w3/sites/attilatest.uib.no/files/
  #Shut down apache 
  sudo /etc/init.d/httpd stop
  #Go into drupal-dir
  cd /var/www/w3.uib.no
  #As w3-drupal, run
  bin/site-drush sql-cli

In pgsql run:
  \i /prod_nettapp_w3/pg_dump/w3.uib.no.sql

Start apache
  sudo /etc/init.d/httpd start

### Installing security fix ###

Note, you shuld run pull, commit and reset as the user w3-drupal

* bin/site-drush vset maintenance_mode 0

#### Setting staging = prod ####

* git fetch --all
* git checkout staging 
* git reset --hard origin/prod
* cd drupal
* git fetch --all
* cd ..
* git submodule update

#### Update Drupal ####

* bin/site-drush up drupal --no-backup
* cd drupal
* git commit -a
* cd .. 
* bin/site-drush up --security-only --no-backup
* cd drupal
* git commit -a
* cd ..
* git commit drupal

TEST!!!

* cd drupal ; git push ;  cd ..
* git push

### Update prod ###
* cd drupal
* git fetch --all
* cd ..
* git fetch --all
* git reset --hard origin/staging
* git submodule update

We copied the files into the server, we have to update the DB.

* bin/site-drush updatedb

Do the same with attika, but there is no need to run updatedb

Test, and disable 

* bin/site-drush vset maintenance_mode 0
