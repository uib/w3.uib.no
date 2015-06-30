# The source code

We use git to track the code behind `w3.uib.no`.  To check out a copy of the code
run:

    git clone --recursive git@git.uib.no:site/w3.uib.no

If this succeeds it will create a local directory called `w3.uib.no/` with the code.
This requires that you are on the UiB network and have the right permissions
set up.  Ask Gisle if you have trouble with this.

You can also browse the code repo directly both from
[rts](https://rts.uib.no/projects/w3/repository) and
[cgit](https://git.uib.no/cgit/site/w3.uib.no.git/tree/).  Both these will
require a UiB login for access.

The `--recursive` option used above instructs git to also fetch the submodules
used.  It’s needed to get a complete runnable checkout with the full Drupal
core and the contributed modules that we depend on.  Without `--recursive` you
only get "our" code, which is fine if you only need to inspect it.

## Two repos

We use 2 repos.  The root repo contains our own code and documentation.  The
directory `drupal/` in the root repo is a git submodule containing a UiB hosted
branch of the Drupal 7.x core with all the contributed modules that our code
depend on.  There are also symlinks back to the parent repo so that Drupal
will be able to locate our code.

This give us a clear separation between our code and the standard Drupal code.
The commit history in the root repo is then only about our code and we have
the full Drupal history in the sub-repo when we need to investigate Drupal
issues.  It’s also easy to upgrade Drupal with a simple git merge and to update
modules with drush download.

The cross-repo symlinks are:

    drupal/profiles/uib → ../../profiles/uib
    drupal/sites/all/modules/uib → ../../../modules
    drupal/sites/all/themes/uib → ../../../themes
    m → drupal/sites/all/modules

The last one is pure convenience as we found a frequent need to inspect
the source code of the modules we used.

Apache will run the PHP code with `drupal/` as the document root, and we
will normally also set up a symlink from `site` to the currently activated
sites directory (matching the virtual host name).  Typically:


    site → drupal/sites/w3.uib.local

This symlink is used by the various `bin/site-*` scripts to manipulate the
activated site.

## Layout

The directories found at the root of the repo are:

### `doc/`

This is where we put development documentation about the code and
the specifications we work from.

We prefer to write the documentation in
[markdown](http://daringfireball.net/projects/markdown).  Run `make` in this
directory to convert it to HTML and then start browsing at `doc/index.html`.

The `doc/doc/` directory is the place to drop off related MS-Word documents, PDFs, and
such.

### `bin/`

Some handy scripts.  The handiest of those are [`bin/site-drush`](man1/site-drush.html) and
[`bin/site-prod-reset`](man1/site-prod-reset.html).

### `etc/`

Configuration files (used by the scripts). Not much used yet.

### `drupal/`

This is a git submodule that contains core Drupal 7 and all the modules
that we depend on (found under `drupal/sites/all/modules/`).
The `drupal.make` is a manifest of the contents of the `drupal/` directory.
Running `drush make` should recreate the `drupal/` directory.

### `patches/`

Contains patches we have made to 3rd party modules and Drupal core.
The patches must be registered in the `drupal.make` file.
The `drupal.make` can also reference external patches and we prefer
that when the patch is available from a stable URL.

### `profiles/`

Our custom profiles.  Currently there is only one; `profiles/uib/`.
It’s used when installing the site from scratch.
It declares what modules need to be installed and some install code
that set things up.

### `modules/`

Our [custom modules](modules.html).  Many of these written by
[`features`](http://drupal.org/project/features).

### `themes/`

Our custom themes.  Currently there is only one; `themes/uib_zen/`
based on the [Zen theme](http://drupal.org/project/zen).

### `scripts/`

Various utility scripts that can be invoked with 'drush php-script'.

### `test-se/`

This is a non-working [Selenium](http://seleniumhq.org/) based test suite.  It contains
scripts (written in Python) that will drive Firefox to visit the pages of the
site and look for the expected content.

This test suite used to run automatically from [Jenkins when new stuff is
pushed](http://float.uib.no/jenkins/) to the repo.
