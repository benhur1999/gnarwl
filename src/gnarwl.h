#ifndef GNARWL_H
#define GNARWL_H

// Multiply config directive "db_expire" with this value
#define TIMEFACTOR 3600

// How many seconds to wait for LDAP data, before giving up
#define LDAPQUERY_MAXWAIT 10

// Defaults for several config directives
#define DEFAULT_SERVER "localhost"
#define DEFAULT_QFILTER "(&(mail=$recepient)(vacationActive=TRUE)"
#define DEFAULT_MES "vacationInfo"
#define DEFAULT_BASE ""
#define DEFAULT_EXPIRE 48
#define DEFAULT_MAIL_LIMIT 256
#define DEFAULT_MAP_SENDER "$sender"
#define DEFAULT_MAP_RECEIVER "$recepient"
#define DEFAULT_MAP_SUBJECT "$subject"
#define LDAP_PROTOCOL_DETECT 0
#define LDAP_CHARSET "UTF-8"

// Verbositylevel
#define LVL_CRIT 0
#define LVL_WARN 1
#define LVL_INFO 2
#define LVL_DEBUG 3

// Don't change ;-)
#define TRUE 1
#define FALSE 0

#endif /* GNARWL_H */
