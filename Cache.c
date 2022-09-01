#include "Cache.h"

static inline void increase_size(queue_t *q){
    q->size += 1;
}

static bool _Copy_str_and_attach(list_ele_t *e, char *K, char *V){
    if(!e) return false;

    char *strK = calloc(1, strlen(K) + 1);
    if(!strK) return false;

    char *strV = calloc(1, strlen(V) + 1);
    if(!strV){
        free(strK);

        return false;
    }

    strncpy(strK, K, strlen(K));
    strncpy(strV, V, strlen(V));

    e->kv = calloc(1, sizeof(kv_t));
    e->kv->k = strK;
    e->kv->v = strV;
    e->kv->sz = strlen(K) + strlen(V);

    return true;
}

static list_ele_t *_Create_element(){
    list_ele_t *new_e = calloc(1, sizeof(list_ele_t));
    if (!new_e) return NULL;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &new_e->kv->stamp);

    return new_e;
}

/* -------- end of utilities -------- */

queue_t *createQueue(){
    queue_t *q = calloc(1, sizeof(queue_t));
    if (!q) return NULL;

    return q;
}

void freeQueue(queue_t *q){
    if (!q) return;

    list_ele_t *e = q->head;
    while(e){
        //QQ if(e->value) free(e->value);

        list_ele_t *old = e;
        e = e->next;
        free(old);
    }

    free(q);
}

bool queueAdd(queue_t *q, char *K, char *V){
    if (!q) return false;

    list_ele_t *e = _Create_element();
    if(!e) return false;

    if(!_Copy_str_and_attach(e, K, V)){
        free(e);

        return false;
    }

    if(q->head) e->next = q->head;

    increase_size(q);
    q->head = e;
    if (q->size == 1) q->tail = e;

    return true;
}

void ping(){
    printf("%d\n", (int)sizeof(timespec));
}
