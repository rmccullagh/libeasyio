AC_INIT([libeasyio], [1.0.0], [bug-automake@gnu.org])
AM_INIT_AUTOMAKE([foreign])
LT_INIT([disable-static])
AC_SUBST([LIBTOOL_DEPS])
AC_PROG_CC
AC_PROG_CC_C99
AC_PROG_INSTALL
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([src/config.h])
AC_ARG_ENABLE(debug,
              [AS_HELP_STRING([--enable-debug],
                             [Turn on debugging [default=no]])],[enable_debug=yes],
              [enable_debug=no])

AC_MSG_CHECKING([if we are enabling debug support])
AS_IF([test "x$enable_debug" = "xyes"], [
       AC_DEFINE(HAVE_LIBEASY_IO_DEBUG, 1, [Wheather to enable debugging messages])
       AC_MSG_RESULT([yes])
], [ AC_MSG_RESULT([no]) ])
AC_CHECK_HEADERS([sys/stat.h sys/types.h stdio.h stdlib.h])
AC_CHECK_FUNCS([stat malloc fopen fread fclose fprintf], [],
	       [AC_MSG_ERROR([We need a function])]
	       )
AC_CHECK_MEMBER([struct stat.st_mode], [], 
		[AC_MSG_ERROR([We need stat.st_mode])],
		[[#include <sys/stat.h>]])

AC_CHECK_MEMBER([struct stat.st_size], [], 
		[AC_MSG_ERROR([We need stat.st_size])],
		[[#include <sys/stat.h>]])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
 test/Makefile
])
AC_OUTPUT
