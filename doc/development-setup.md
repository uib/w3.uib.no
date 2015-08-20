# Development setup

This document explains how to set up your box so that you can start hacking on
the w3.uib.no application.

## Software and Tools

Before we start we need make sure we have the following tools installed and set up.
This section explains how to obtain the tools on Mac OSX.  How to do the same on Linux
is left as an exercise for the interested reader.

### Git

Start by installing Xcode (from the AppStore).  Then open "Xcode >
Preferences... > Downloads > Components" and make sure the "Command Line
Tools" are installed.  This will install make, C compilers, and git.

### Apache

Apache is bundled with Mac OSX.  To enable it just run [`sudo apachectl
start`](http://superuser.com/questions/455505/how-do-i-start-apache-in-osx-mountain-lion).
This will both start up Apache and make sure it’s enabled on the next system
reboot.  The configuration files for Apache is found in the _/etc/apache2_ directory.

Verify that it works by visiting <http://localhost>.

### PHP

PHP is bundled with Mac OSX, but not enabled in Apache by default.  To enable it
remove the '#' mark in front of the "LoadModule php5\_module" line of
_/etc/apache2/httpd.conf_.  Run `sudo apachectl restart` for the change to take
effect.

Verify that it works by running:

    $ echo "<?php phpinfo();" >/Library/WebServer/Documents/phpinfo.php

and then visit <http://localhost/phpinfo.php>.

### Drush

Download the latest 7.x-version from <http://drupal.org/project/drush>.  Unpack
it and either add the directory to the PATH or set up a symbolic link to
_drush-7.x-*/drush_ from somewhere in your PATH.  Run `drush version` to verify
that it works.

Alternative clone the sources with git, and check out the latest 7.x-release:

    $ cd ~
    $ git clone http://git.drupal.org/project/drush.git
    $ git checkout $(git tag | grep 7.x-5 | tail -1)
    $ cd ~/bin
    $ ln -s ~/drush/drush

### Bundler

[Bundler](http://bundler.io/) is used to mange the dependencies on Ruby
applications and libraries used for w3 development. Our current dependencies are
[SASS](http://sass-lang.com/) and [Compass](http://compass-style.org/).

Bundler is installed by running:

    $ gem update --system
    $ gem install bundle

Run `"bundler version"` to verify that it worked.

The w3-application‘s install and reset scripts will automatically install all
dependencies under `vendor/` the first time they run. If you want to do it
manually run:

    $ bundle install

To use any of the dependencies specified in the Gemfile, run:

    $ bundle exec <command>

For instance to run `compass compile` you have to run it as:

    $ bundle exec compass compile

## Set up the application

### Grab the sources

Go somewhere you prefer to have your code checked out (we use _/tmp_ in the
following example, but you can probably come up with something better).
Then run:

    $ cd /tmp
    $ git clone --recursive git@git.uib.no:site/w3.uib.no
    $ cd w3.uib.no

This should give you the sources in the _/tmp/w3.uib.no_ directory and a Drupal instance
for Apache to serve at _/tmp/w3.uib.no/drupal_.

### Set up w3.uib.local

The w3.uib.no application wants to run from the root of its own domain, so we need
to enable a VirtualHost to serve the checked out directory.  The recommended name
is <http://w3.uib.local>.

First we add an entry for this name in the _/etc/hosts_ file:

    127.0.0.1       w3.uib.local

Then we create the file _/etc/apache2/other/w3.uib.no-vhosts.conf_ with this content:

    NameVirtualHost 127.0.0.1:80

    <VirtualHost 127.0.0.1:80>
        ServerName w3.uib.local
        DocumentRoot /tmp/w3.uib.no/drupal
    </VirtualHost>

    <Directory "/tmp/w3.uib.no/drupal">
        Options Indexes
        AllowOverride All
        Require all granted
    </Directory>

Then run `sudo apachectl restart` and visit <http://w3.uib.local> to verify that it
works.  You will get into the Drupal install dialog, which we will not use. We’ll
install the site from the command line instead:

    $ cd /tmp/w3.uib.no
    $ bin/site-init --sqlite w3.uib.local
    $ bin/site-install
    $ bin/site-drush pm-enable --yes uib_devel

Then goto  <http://w3.uib.local> once more.  You should now see the empty front page
of the w3 application and you can [login](http://w3.uib.local/user) as _admin:admin_.

Alternate recommendation is a use a name like <http://w3.uib.9zlhb.xip.io> as this
doesn’t require you to mess with the _/etc/hosts_ file. Visit [xip.io](http://xip.io)
to learn how this works.

### Set up PostgreSQL

The recipe above would set up the app using [sqlite](http://www.sqlite.org) as
database.  The production deployment uses
[PostgreSQL](http://www.postgresql.org) as database, so you might want to use if
for development as well.  You have the following options for where to get access
to such a database:

- Use the database server at _glory.uib.no_. The _user1:pass1_ account is given
  access to create and drop databases.  Please embed your user-id in the database
  names *you* create.

- Run [a virtual box](https://github.com/gisle/vm-pg).  This gives you
  a server that runs locally under Ubuntu.  This one also provide the _user1:pass1_
  account.

- Install Postgres natively/locally (on OS X for instance using homebrew).
  Create an account called 'user1' with password 'pass1' that is given permission
  to create new databases:

This sets up the recommended user if it doesn’t already exists:

    $ psql postgres
    postgres=# CREATE USER user1 WITH PASSWORD 'pass1' CREATEDB;

Running with postgres locally is much faster if you have anything but a very
fast connection to _glory_, that is if you are not wired to the UiB network
directly.

Select your preferred option above and make sure psql is able to connect to the
database.  In the examples below we use the first option, and then this should
work out-of-the-box:

    $ psql -h glory.uib.no postgres user1

If you run postgres in a virtual box or locally you will have to use _localhost_
as the hostname.

Now, at the psql prompt create a new database.  The new database must be using
the UTF-8 encoding.

    postgres=> CREATE DATABASE db42 TEMPLATE template0 ENCODING 'UTF-8';

exit psql and check that you can connect to the new database:

    $ psql -u glory.uib.no db42 user1

Jolly good!  Remember to replace _db42_ with something unique to you.  Also in
the examples below.

Now let’s reinstall w3.uib.local so that it connects to Postgres:

    $ bin/site-uninstall     # get rid of the old one
    $ DATABASE=pgsql://user1:pass1@glory.uib.no/db42 bin/site-install w3.uib.local

And visit  <http://w3.uib.local> again to verify that it worked and that:

    $ bin/site-drush status

says that you are connecting to postgres.

### Get data

If you install the app like above you end up with an empty one with no
areas or articles.  To fill it up with a copy of the data we currently have
in production run:

    $ bin/site-prod-reset

This takes a while the first time you run it because it syncs over all
files and images uploaded to production.  If the source code is different
from the production source code you probably want to run:

    $ bin/site-drush fd
    $ bin/site-drush fr
    $ bin/site-drush updb

To login to the admin account run:

    $ bin/site-drush user-login

You might also want to enable the uib\_devel module if you intend to update
views or stuff like that:

    $ bin/site-drush pm-enable --yes uib_devel

## Development workflow

Some commands you will run into often.  If you don’t understand what these
do, please ask:

    $ git checkout master
    $ git fetch --prune
    $ git checkout -b rts/XXXX
    $ git checkout rts/XXXX

    $ bin/site-drush cc all
    $ bin/site-drush fd
    $ bin/site-drush fd <module>
    $ bin/site-drush fu
    $ bin/site-drush fr

    $ bin/site-init
    $ bin/site-prod-reset
    $ bin/site-snapshot
    $ bin/site-snapshot pop

    $ compass compile --force themes/uib_zen

## Using [Grunt.js](http://gruntjs.com/) in frontend development

There is a configuration for grunt tasks available that may be useful when writing a lot
of styling. The provided `package.json` and `Gruntfile.js` files specifies the dependencies
and tasks setup for this project.

The tasks supplied by this configuration is:

1. `watch`: watches for changes to .scss files
2. `compass`: compiles css files using bundler
3. `shell`: runs a drush clear cache css-js
4. `browsersync`: refreshes all connected browsers

To use these grunt tasks in your workflow you need to install node.js with npm
on your development platform. On a mac node.js is available through homebrew.
Once node.js is installed in your system you need to do the following steps:

    $ npm install -g grunt-cli

This installs the grunt command allowing it to be run from any directory.

Then in the root folder of your w3 app run:

    $ npm install

This will install all dependecies for the grunt tasks in Gruntfile.js. Then to
run the grunt task you have to:

    $ grunt --proxy=<your_local_w3_url>

&lt;your\_local\_w3\_url> should be substituted with whatever url you use to access
your local instans of w3 in the browser. The grunt script will give you urls to
access the site local and external. You will *not* be abel to log in through
this site (for now, anyway).
