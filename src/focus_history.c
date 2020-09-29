#include "all.h"


int focus_history_last;

focus_history_entry_t focus_history[FOCUS_HISTORY_LEN];

void focus_history_init() {
    focus_history_last = 0;
    for (int i = 0; i < FOCUS_HISTORY_LEN; ++i) {
        focus_history[i].id = -1;
    }
}

void focus_history_add(const Con *focused) {
    if (focused && focused->window && focused->window->name)
    {
        focus_history_last = (focus_history_last + 1) % FOCUS_HISTORY_LEN;
        focus_history_entry_t *e = &(focus_history[focus_history_last]);
        e->id = focused->window->id;
        strncpy(e->title, i3string_as_utf8(focused->window->name), 255);
        e->title[255] = '\n';
        DLOG("Adding %s, id %d to focus history!\n", e->title, e->id);
    }
}

