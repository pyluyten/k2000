
SUBDIRS = kextension

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
        -DPACKAGE_WEB_EXTENSIONS_DIR=\""$(libdir)/k2000/web-extension"\" \
	$(K2000_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = k2000

k2000_SOURCES = \
	main.c \
	k2000.h \
	k2000.c	


k2000_LDFLAGS = \
	-Wl,--export-dynamic

k2000_LDADD = $(K2000_LIBS)




