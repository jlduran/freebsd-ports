--- nnrpd/nnrpd.c.orig	2026-03-28 02:28:05 UTC
+++ nnrpd/nnrpd.c
@@ -51,10 +51,10 @@ bool encryption_layer_on = false;
 #endif
 
 /* Optional arguments for getopt. */
-#if defined(HAVE_BLACKLIST)
-#    define BLACKLIST_OPT "B"
+#if defined(HAVE_BLOCKLIST)
+#    define BLOCKLIST_OPT "B"
 #else
-#    define BLACKLIST_OPT ""
+#    define BLOCKLIST_OPT ""
 #endif
 
 #if defined(HAVE_OPENSSL)
@@ -1029,7 +1029,7 @@ main(int argc, char *argv[])
 #endif /* HAVE_SASL */
 
     while ((i = getopt(argc, argv,
-                       "4:6:b:" BLACKLIST_OPT "c:Dfi:I:nop:P:r:s:" OPENSSL_OPT
+                       "4:6:b:" BLOCKLIST_OPT "c:Dfi:I:nop:P:r:s:" OPENSSL_OPT
                        "t"))
            != EOF)
         switch (i) {
@@ -1045,11 +1045,11 @@ main(int argc, char *argv[])
         case '6': /* Bind to a certain IPv6 address. */
             ListenAddr6 = xstrdup(optarg);
             break;
-#if defined(HAVE_BLACKLIST)
-        case 'B': /* Enable blacklistd functionality. */
-            BlacklistEnabled = true;
+#if defined(HAVE_BLOCKLIST)
+        case 'B': /* Enable blocklistd functionality. */
+            BlocklistEnabled = true;
             break;
-#endif            /* HAVE_BLACKLIST */
+#endif            /* HAVE_BLOCKLIST */
         case 'c': /* Use alternate readers.conf. */
             ConfFile = concatpath(innconf->pathetc, optarg);
             break;
