AUTOMAKE_OPTIONS= foreign subdir-objects -Wall -Werror
ACLOCAL_AMFLAGS = -I m4 --install

bin_PROGRAMS = gnarwl damnit

sysconf_DATA = \
	data/gnarwl.cfg

man8_MANS = \
	doc/gnarwl.8 \
	doc/damnit.8

gnarwl_SOURCES = \
	src/config.h src/config.c \
	src/dbaccess.h src/dbaccess.c \
	src/mailhandler.h src/mailhandler.c \
	src/util.h src/util.c \
	src/gnarwl.c
gnarwl_CPPFLAGS = \
	-DLDAP_DEPRECATED=1 \
	-DGNAWRL_HOMEDIR="\"@GNAWRL_HOMEDIR@\"" \
	-DGNAWRL_CFGFILE="\"@GNAWRL_CFGFILE@\"" \
	-DGNAWRL_MTA="\"@GNAWRL_MTA@\""

damnit_SOURCES = \
	src/defaults.h \
	src/config.h src/config.c \
	src/dbaccess.h src/dbaccess.c \
	src/util.h src/util.c \
	src/damnit.c
damnit_CPPFLAGS = \
	-DLDAP_DEPRECATED=1 \
	-DGNAWRL_HOMEDIR="\"@GNAWRL_HOMEDIR@\"" \
	-DGNAWRL_CFGFILE="\"@GNAWRL_CFGFILE@\"" \
	-DGNAWRL_MTA="\"@GNAWRL_MTA@\""

gnarwldatadir = $(GNAWRL_HOMEDIR)
gnarwldata_DATA = \
	data/header.txt \
	data/footer.txt \
	data/badheaders.db \
	data/blacklist.db

EXTRA_DIST = \
	m4/.keepme

doc_DATA = \
	doc/AUTHORS \
	doc/FAQ \
	doc/HISTORY \
	doc/INSTALL \
	doc/LICENSE \
	doc/README \
	doc/README.upgrade \
	doc/ISPEnv.schema \
	doc/ISPEnv2.schema \
	doc/example.ldif

CLEANFILES = \
	src/defaults.h \
	data/gnarwl.cfg \
	data/badheaders.db \
	data/blacklist.db \
	doc/gnarwl.8 \
	doc/damnit.8

distclean-local:
	-rm -rf autom4te.cache/
	-rm -f *~ DEADJOE

install-data-local:
	$(MKDIR_P) $(DESTDIR)$(GNAWRL_HOMEDIR)/block
	echo "|$(bindir)/gnarwl" > $(DESTDIR)$(GNAWRL_HOMEDIR)/.forward

do_subst = sed \
	-e 's,__GNAWRL_HOMEDIR__,$(GNAWRL_HOMEDIR),g' \
	-e 's,__GNAWRL_CFGFILE__,$(GNAWRL_CFGFILE),g' \
	-e 's,__GNAWRL_MTA__,$(GNAWRL_MTA),g'

data/gnarwl.cfg: data/gnarwl.cfg.in
	$(do_subst) $< >$@

doc/gnarwl.8: doc/gnarwl.8.in
	$(do_subst) $< >$@

doc/damnit.8: doc/damnit.8.in
	$(do_subst) $< >$@

.txt.db: $(top_builddir)/damnit
	cat $< | $(top_builddir)/damnit -a $@
