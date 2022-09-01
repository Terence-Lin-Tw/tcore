#ifndef _CACHE_H_
#define _CACHE_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <time.h>

typedef struct timespec timespec;

typedef struct{
    char *k;
    char *v;
    size_t sz;
    timespec stamp;
}kv_t;

typedef struct ELE{
    kv_t *kv;
    struct ELE *next;
}list_ele_t;

typedef struct{
    list_ele_t *head;
    list_ele_t *tail;
    int size;
} queue_t;

queue_t *createQueue    (                       );
void     q_free         (queue_t *q             );
bool     q_add          (queue_t *q, char *s    );
int      q_size         (queue_t *q             );

void ping();

#endif
