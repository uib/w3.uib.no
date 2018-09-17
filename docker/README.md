# W3 container

This directory contains the files supporting building a linux container that
can run the w3 application. You need to have [docker](https://www.docker.com/community-edition)
installed to proceed.

You build a new version of the container image by running command:

    $ make

To test the image during development run:

    $ make run

and visit <http://localhost:8080> and when you are done abort the server by
typing `^C`.  This assumes that you have a PostgreSQL server running locally
with a database set up and named `w3`.

The image is based off the "official" Docker Hub `php:7.2-apache` image which
is based off Debian Linux.  It means that you use `apt-get` to install additional
packages when needed.

The image contains the w3 Drupal installation at `/var/www/html` with the UiB
specific code expanded in place. Drush is functional and can be invoded directly, for instance as:

    $ docker exec $(docker ps -lq) drush status

## Tips & tricks

You can build and run it directly by running:

    $ make build run

When the image is running you can get a shell into it using:

    $ docker exec -it $(docker ps -lq) bash
