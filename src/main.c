#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listener.h"
#include "util.h"

const char **menu_cmd = NULL;

int main(int argc, const char **argv) {
  if (argc == 1) {
    fprintf(stderr, "usage: holopk <menu command>\n");
    return 1;
  }
  menu_cmd = argv + 1;

  PolkitAgentListener *listener = holo_polkit_listener_new();
  PolkitSubject *session =
      polkit_unix_session_new_for_process_sync(getpid(), NULL, NULL);
  GError *err = NULL;
  if (!polkit_agent_listener_register(listener,
                                      POLKIT_AGENT_REGISTER_FLAGS_NONE, session,
                                      NULL, NULL, &err)) {
    fprintf(stderr, "%s\n", err->message);

    g_object_unref(session);
    g_object_unref(listener);
    return 1;
  } else {
    GMainLoop *loop = g_main_loop_new(NULL, TRUE);

    g_main_loop_run(loop);

    g_main_loop_unref(loop);
    g_object_unref(session);
    g_object_unref(listener);
    return 0;
  }
}
