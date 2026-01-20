--- nnrpd/perm.c.orig	2026-03-28 02:30:11 UTC
+++ nnrpd/perm.c
@@ -9,14 +9,14 @@
 #include <signal.h>
 #include <sys/wait.h>
 
-#if defined(HAVE_BLACKLIST)
-#    include <blacklist.h>
+#if defined(HAVE_BLOCKLIST)
+#    include <blocklist.h>
 #    include <errno.h>
 /* Some systems (like NetBSD 9.2) do not define these pretty names. */
-#    ifndef BLACKLIST_API_ENUM
+#    ifndef BLOCKLIST_API_ENUM
 enum {
-    BLACKLIST_AUTH_OK = 0,
-    BLACKLIST_AUTH_FAIL
+    BLOCKLIST_AUTH_OK = 0,
+    BLOCKLIST_AUTH_FAIL
 };
 #    endif
 #endif
@@ -95,8 +95,8 @@ static void PERMvectortoaccess(ACCESSGROUP *acc, const
 static void PERMvectortoaccess(ACCESSGROUP *acc, const char *name,
                                struct vector *acccess_vec) UNUSED;
 
-#if defined(HAVE_BLACKLIST)
-static void BlacklistReport(const char *user);
+#if defined(HAVE_BLOCKLIST)
+static void BlocklistReport(const char *user);
 #endif
 
 /* Global variables. */
@@ -1640,8 +1640,8 @@ PERMlogin(char *uname, char *pass, int *code, char *er
     while (runame == NULL && i-- > 0)
         runame = AuthenticateUser(auth_realms[i], uname, pass, code, errorstr);
 
-#if defined(HAVE_BLACKLIST)
-    BlacklistReport(runame);
+#if defined(HAVE_BLOCKLIST)
+    BlocklistReport(runame);
 #endif
 
     if (runame != NULL) {
@@ -2250,38 +2250,38 @@ AuthenticateUser(AUTHGROUP *auth, char *username, char
 }
 
 
-#if defined(HAVE_BLACKLIST)
+#if defined(HAVE_BLOCKLIST)
 void
-BlacklistReport(const char *user)
+BlocklistReport(const char *user)
 {
     int ret;
-    struct blacklist *cookie;
+    struct blocklist *cookie;
 
     /* Only try reporting if nnrpd is started with -B. */
-    if (!BlacklistEnabled)
+    if (!BlocklistEnabled)
         return;
 
     /* One nnrpd process only handles one login attempt.  Connect to
-     * blacklistd, report and disconnect to avoid keeping the blacklistd
+     * blocklistd, report and disconnect to avoid keeping the blocklistd
      * connection open and unused. */
-    cookie = blacklist_open();
+    cookie = blocklist_open();
     if (cookie == NULL) {
-        syslog(L_ERROR, "could not connect to blacklistd: %s",
+        syslog(L_ERROR, "could not connect to blocklistd: %s",
                strerror(errno));
         return;
     }
 
     /* nnrpd always uses STDIN for client input. */
     if (user != NULL)
-        ret = blacklist_r(cookie, BLACKLIST_AUTH_OK, STDIN_FILENO,
+        ret = blocklist_r(cookie, BLOCKLIST_AUTH_OK, STDIN_FILENO,
                           "login successful");
     else
-        ret = blacklist_r(cookie, BLACKLIST_AUTH_FAIL, STDIN_FILENO,
+        ret = blocklist_r(cookie, BLOCKLIST_AUTH_FAIL, STDIN_FILENO,
                           "login failed");
     if (ret == -1)
-        syslog(L_ERROR, "blacklistd communication failed: %s",
+        syslog(L_ERROR, "blocklistd communication failed: %s",
                strerror(errno));
 
-    blacklist_close(cookie);
+    blocklist_close(cookie);
 }
 #endif
