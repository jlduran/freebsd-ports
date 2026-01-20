--- sendmail/Makefile.m4.orig	2025-02-05 06:35:18 UTC
+++ sendmail/Makefile.m4
@@ -18,8 +19,8 @@ dnl hack: /etc/mail is not defined as "location of .cf
 
 
 dnl hack: /etc/mail is not defined as "location of .cf" in the build system
-define(`bldTARGET_INST_DEP', ifdef(`confINST_DEP', `confINST_DEP',
-`${DESTDIR}/etc/mail/submit.cf ${DESTDIR}${MSPQ}'))dnl
+define(`bldTARGET_INST_DEP', ifdef(`confINST_DEP', `confINST_DEP'))
+dnl
 define(`bldTARGET_LINKS', ifdef(`confLINKS', `confLINKS',
 `${DESTDIR}${UBINDIR}/newaliases ${DESTDIR}${UBINDIR}/mailq ${DESTDIR}${UBINDIR}/hoststat ${DESTDIR}${UBINDIR}/purgestat')
 )dnl
