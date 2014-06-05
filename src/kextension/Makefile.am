kextension_LTLIBRARIES = k2000webextension.la

kextensiondir = $(libdir)/k2000/web-extension

k2000webextension_la_SOURCES = kextension.c

k2000webextension_la_CFLAGS = \
	$(K2000_CFLAGS) \
	$(K2000_EXTENSION_CFLAGS)

k2000webextension_la_LIBADD = \
	$(K2000_LIBS) \
	$(K2000_EXTENSION_LIBS)

k2000webextension_la_LDFLAGS = -module -avoid-version -no-undefined

k2000_CPPFLAGS = \
	$(K2000_CFLAGS) \
	-DK2000_WEB_EXTENSIONS_DIR=\""$(libdir)/k2000/web-extension"\"
