ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS = $(CFLAG_VISIBILITY)
lib_LTLIBRARIES = libeasyio.la
libeasyio_la_SOURCES = easyio.c
libeasyio_la_CFLAGS = $(AM_CFLAGS)
libeasyio_la_CPPFLAGS = -DBUILDING_LIBEASYIO 
# http://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html
# current[:revision[:age]]
libeasyio_la_LDFLAGS = -no-undefined -version-info 1:2:0
include_HEADERS = easyio.h
