FROM php:7.2-apache
LABEL maintainer="w3@it.uib.no"

RUN a2enmod rewrite \
    && curl -s -L https://github.com/drush-ops/drush/releases/download/8.1.17/drush.phar >/usr/local/bin/drush \
    && chmod +x /usr/local/bin/drush \
    && echo '9c5b245c3a437851bded21fd52014dddd1f5eb8f3e9ee8230047533bd02829ba /usr/local/bin/drush' | sha256sum -c - \
    && apt-get update \
    && mkdir /usr/share/man/man1 && mkdir /usr/share/man/man7 \
    && apt-get install -y postgresql-client \
    && savedAptMark="$(apt-mark showmanual)" \
    && apt-get update && apt-get install -y \
        imagemagick \
        libpng-dev \
        libpq-dev \
        zlib1g-dev \
    && docker-php-ext-install \
        gd \
        mbstring \
        pdo \
        pdo_pgsql \
        zip \
    # Cleanup
    ## Source: https://github.com/docker-library/drupal/blob/ff8962fc943001457c6919fa42e3d875b9fab9f7/7/apache/Dockerfile
    # reset apt-mark's "manual" list so that "purge --auto-remove" will remove all build dependencies
    && apt-mark auto '.*' > /dev/null \
    && apt-mark manual $savedAptMark \
    && ldd "$(php -r 'echo ini_get("extension_dir");')"/*.so \
        | awk '/=>/ { print $3 }' \
        | sort -u \
        | xargs -r dpkg-query -S \
        | cut -d: -f1 \
        | sort -u \
        | xargs -rt apt-mark manual \
    && apt-get purge -y --auto-remove -o APT::AutoRemove::RecommendsImportant=false \
    && rm -rf /var/lib/apt/lists/*

COPY drupal/ .
COPY profiles/uib/ profiles/uib/
COPY themes/ sites/all/themes/uib
COPY modules/ sites/all/modules/uib
COPY doc/release-notes.md /var/www/doc/release-notes.md

RUN mkdir -p sites/default/files ../var/private \
    && chown www-data:www-data sites/default/files ../var/private \
    && ln -s default sites/w3.uib.no

COPY docker/settings.php sites/default/settings.php

ARG W3_VERSION
LABEL W3_VERSION=$W3_VERSION
ENV W3_VERSION=$W3_VERSION
