#pragma once
#ifndef __FOCUS_HISTORY_H__
#define __FOCUS_HISTORY_H__

#define FOCUS_HISTORY_LEN 10

extern int focus_history_last;

struct focus_history_entry {
    char title[256];
    int id;
};

typedef struct focus_history_entry focus_history_entry_t;


extern focus_history_entry_t focus_history[];
void focus_history_init();
void focus_history_add(const Con *focused);

#endif // __FOCUS_HISTORY_H__
