dnl $Id$
dnl config.m4 for extension phasher

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(phasher, for phasher support,
dnl Make sure that the comment is aligned:
dnl [  --with-phasher             Include phasher support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(phasher, whether to enable phasher support,
[  --enable-phasher           Enable phasher support])

if test "$PHP_PHASHER" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-phasher -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/phasher.h"  # you most likely want to change this
  dnl if test -r $PHP_PHASHER/$SEARCH_FOR; then # path given as parameter
  dnl   PHASHER_DIR=$PHP_PHASHER
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for phasher files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       PHASHER_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$PHASHER_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the phasher distribution])
  dnl fi

  dnl # --with-phasher -> add include path
  dnl PHP_ADD_INCLUDE($PHASHER_DIR/include)

  dnl # --with-phasher -> check for lib and symbol presence
  dnl LIBNAME=phasher # you may want to change this
  dnl LIBSYMBOL=phasher # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $PHASHER_DIR/lib, PHASHER_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_PHASHERLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong phasher lib version or lib not found])
  dnl ],[
  dnl   -L$PHASHER_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(PHASHER_SHARED_LIBADD)

  PHP_NEW_EXTENSION(phasher, phasher.c, $ext_shared)
fi
