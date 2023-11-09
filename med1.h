#ifndef MED1_H
#define MED1_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define list (*lst)
#define RED           "\x1b[31;2m"
#define YELLOW        "\x1b[33;2m"
#define GREEN         "\x1b[32;2m"
#define BLUE          "\x1b[34;2m"
#define END_OF_COLOUR "\x1b[39;49m"

typedef struct _list
{
    double value;
    struct _list* next;
}LIST;

void list_dump(LIST* head);

LIST* list_ctor();

void list_insert_sort(LIST** lst, double number);

double list_med(LIST* lst);


#endif
