--- sendmail/Makefile.m4.orig	2025-02-05 06:35:18 UTC
+++ sendmail/Makefile.m4
@@ -7,6 +7,7 @@ define(`bldSOURCES', `main.c alias.c arpadate.c bf.c c
 define(`bldBIN_TYPE', `G')
 define(`bldINSTALL_DIR', `')
 define(`bldSOURCES', `main.c alias.c arpadate.c bf.c collect.c conf.c control.c convtime.c daemon.c deliver.c domain.c envelope.c err.c headers.c macro.c map.c mci.c milter.c mime.c parseaddr.c queue.c ratectrl.c readcf.c recipient.c sasl.c savemail.c sched.c sfsasl.c shmticklib.c sm_resolve.c srvrsmtp.c stab.c stats.c sysexits.c timers.c tlsh.c tls.c trace.c udb.c usersmtp.c util.c version.c ')
+APPENDDEF(`bldSOURCES',`blocklist.c ')
 PREPENDDEF(`confENVDEF', `confMAPDEF')
 PUSHDIVERT(3)
 ldap.c:
