#include <pebble.h>
#include "api.h"

Window* m_window;

typedef enum {
  APP_MESSAGE_KEY_READY = 0
} E_APP_MESSAGE_KEY;

static void handle_app_message_ready() {
  // get_matches(E_MATCHDAY_TODAY);
}

static void in_received_handler(DictionaryIterator *iter, void *context) {
  Tuple *tuple;

  tuple = dict_find(iter, APP_MESSAGE_KEY_READY);
  
  if (tuple) {
    handle_app_message_ready();
  }
}

static void init_app_messages() {
  app_message_register_inbox_received(in_received_handler);
  app_message_open(256, 256);
}

static void init() {
  init_app_messages();
}

static void deinit() {
  window_destroy(m_window);
}

int main() {
  init();
  app_event_loop();
  deinit();
  
  return 0;
}
