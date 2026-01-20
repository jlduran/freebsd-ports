--- nnrpd/nnrpd.h.orig	2026-03-28 02:28:28 UTC
+++ nnrpd/nnrpd.h
@@ -181,7 +181,7 @@ EXTERN bool initialSSL;
 EXTERN bool Tracing;
 EXTERN bool Offlinepost;
 EXTERN bool initialSSL;
-EXTERN bool BlacklistEnabled;
+EXTERN bool BlocklistEnabled;
 EXTERN char **PERMreadlist;
 EXTERN char **PERMpostlist;
 EXTERN struct client Client;
