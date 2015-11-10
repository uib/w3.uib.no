w3.uib.no
============

This repository contains the code needed to run the Drupal based UiB web
application, also known as <http://www.uib.no>.

We use git submodules here, so after the initial clone you need to run:

    git submodule update --init

to grab the rest of the code.

To set up a test site, configure Apache to serve the 'drupal' directory at the
root of some virtual host.

Make sure you have 'drush' (version 5 or better) and Ruby's 'bundler' installed
before you proceed.

Then set up the Drupal site by invoking:

    bin/site-init w3.uib.example.com
    bin/site-install

The 'doc' directory contains further information you might want to read first.
The 'doc/development-setup.md' explains the details on how to set up your
development environment.  An up-to-date HTML version of the docs should always
be available at <http://phpdoc.devapp.uib.no/w3/> (only available on certain
networks within UiB).
