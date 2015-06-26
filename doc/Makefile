HTML = \
  area.html \
  adding-article-type.html \
  course_site-w3-kurs.uib.no.html \
  development-setup.html \
  drupal-sync-course-site.html \
  drupal-update.html \
  fs-pres.html \
  git.html \
  hints.html \
  index.html \
  model.html \
  modules.html \
  release-notes.html \
  release-process.html \
  release1.html \
  render-array.html \
  repo-readme.html \
  repo.html \
  server-setup.html \
  spec.html \
  style.html \
  terms.html \
  workflow.html \
  w3_server_layout.html \
  man1/make-drupal.html \
  man1/module-update.html \
  man1/patches.html \
  man1/pick.html \
  man1/rts.html \
  man1/site-drush.html \
  man1/site-dump.html \
  man1/site-init.html \
  man1/site-install.html \
  man1/site-open.html \
  man1/site-prod-reset.html \
  man1/site-restore.html \
  man1/site-uninstall.html \
  man1/site-upgrade.html \

PYTHON = python
PERL = perl
DOT = dot
BOOTSTRAP_PY = bootstrap.py
BOOTSTRAP_ARGS =

.SUFFIXES: .md .html .dot .svg
.PHONY: makefile clean realclean

.md.html:
	bin/python htmlify.py $< >$@

.dot.svg:
	$(DOT) -Tsvg $< >$@

all: bin/python $(HTML) mockups/index.html man1/index.html

svg: img/model.svg img/model-simple.svg img/model-study.svg img/module-dep.svg

img/module-dep.dot:
	(cd .. && bin/site-drush scr uib-mod-dep-in-dot) >$@

mockups/index.html: mockups/mkindex
	$(PERL) mockups/mkindex

man1/index.html: man1/mkindex
	$(PERL) man1/mkindex

bin/python: bin/buildout
	bin/buildout
	touch $@

bin/buildout: $(BOOTSTRAP_PY)
	$(PYTHON) $(BOOTSTRAP_PY) $(BOOTSTRAP_ARGS)
	touch $@

makefile:
	$(PERL) update-makefile.pl >Makefile.new
	mv Makefile.new Makefile

clean:
	rm -f $(HTML)
	rm -f man1/index.html
	rm -f mockups/index.html

realclean: clean
	rm -f bin/buildout bin/markdown2 bin/python
	-rmdir bin
	rm -rf .installed.cfg develop-eggs parts
