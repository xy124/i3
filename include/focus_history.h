
#define FOCUS_HISTORY_LEN 10

int focus_history_last;

struct focus_history_entry {
    char title[256];
    int id;
};

typedef struct focus_history_entry focus_history_entry_t;


focus_history_entry_t focus_history[FOCUS_HISTORY_LEN];
void focus_history_init();
void focus_history_add(const Con *focused);
