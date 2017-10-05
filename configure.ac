AC_INIT([gnarwl], [3.7])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src])
AC_CONFIG_AUX_DIR([config.aux])
AM_INIT_AUTOMAKE
AC_CANONICAL_HOST

AC_PROG_CC
AM_PROG_CC_C_O
AC_CHECK_TOOL([STRIP],[strip])
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_MKDIR_P

AC_LANG_PUSH([C])
AC_LANG_WERROR

AC_CHECK_FUNCS([iconv])
AC_CHECK_LIB([gdbm], [gdbm_open])
AC_CHECK_LIB([ldap],[ldap_init])
AC_CHECK_FUNCS([ldap_set_option])



AC_ARG_WITH(homedir,
    AC_HELP_STRING([--with-homedir=DIR], [Homedir for the gnarwl user]),
    [gnarwlhome="\"$withval\""],
    [gnarwlhome="\${prefix}/var/lib/gnarwl"])
dnl AC_ARG_WITH(useradd_prog,
dnl     AC_HELP_STRING([--with-useradd_prog=DIR], [Programm for adding users]),
dnl     [useradd_prog="$withval"],
dnl     [useradd_prog="/usr/sbin/useradd"])
dnl AC_ARG_WITH(useradd_args,
dnl    AC_HELP_STRING([--with-useradd_args=ARG],
dnl                   [Arguments for the useradd programm]),
dnl    [useradd_args="$withval"],
dnl    [useradd_args="-r -s /bin/false -c \"Email autoreply agent\" -d \$(gnarwlhome) gnarwl"])
AC_ARG_WITH(mta,
    AC_HELP_STRING([--with-mta=prog],[MTA to use]),
    [mta="$withval"],
    [mta="/usr/sbin/sendmail"])
AC_ARG_WITH(permmask,
    AC_HELP_STRING([--with-permmask=MASK],
                   [File creation mask for database files]),
    [permmask="$withval"],
    [permmask="0600"])
AC_ARG_WITH(maxline,
    AC_HELP_STRING([--with-maxline=NUMBER],
                   [Maximum input buffer line length]),
    [maxline="$withval"],
    [maxline="2100"])

# conf.h
AC_DEFINE_UNQUOTED([UMASK], [${permmask}])
AC_DEFINE_UNQUOTED([MAXLINE], [${maxline}])
dnl AC_DEFINE_UNQUOTED([DEFAULT_MTA], ["${mta}"])
AH_TEMPLATE([UMASK], [File permission mask])
AH_TEMPLATE([MAXLINE], [Maximum size for input buffer])
dnl AH_TEMPLATE([DEFAULT_MTA], [What to use as default MTA])

GNAWRL_HOMEDIR="${gnarwlhome}"
GNAWRL_CFGFILE="${sysconfdir}/gnarwl.cfg"
GNAWRL_MTA="${mta}"
AC_SUBST([GNAWRL_HOMEDIR])
AC_SUBST([GNAWRL_CFGFILE])
AC_SUBST([GNAWRL_MTA])
dnl AC_SUBST(useradd_prog)
dnl AC_SUBST(useradd_args)

AC_CONFIG_HEADERS([conf.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
