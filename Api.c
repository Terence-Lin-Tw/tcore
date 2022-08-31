#include "Api.h"

char EMPTY[1] = {'\0'};

void set(char *K, char *V){
    if(!mStore) _InitStore();

    if(strlen(K) == 0) return;

    if(strlen(V) == 0){
        kvs_remove(mStore, K);
    }

    size_t kSz = strlen(K);
    char *k = calloc(1, kSz + 1);
    strcpy(k, K);

    size_t vSz = strlen(V);
    char *v = calloc(1, vSz + 1);
    strcpy(v, V);

    kvs_put(mStore, k, v);

    //kvs_put(mStore, K, V);
}

char *get(char *K){
    if(!mStore) _InitStore();

    if(strlen(K) == 0) return EMPTY;

    char *pValue = kvs_get(mStore, K);
    if(!pValue) return EMPTY;

    return pValue;
}

void _InitStore(){
    mStore = kvs_create(strcmp);

    // kvs_put(mStore, "abc", "123");
    // kvs_put(mStore, "ghi", "789");
    //kvs_put(mStore, "def", "456");

    // int i = 0;
    // KVSpair *p;
    // while(  (p = kvs_pair(mStore, i++))  ){
    //     printf("%s: %s\n", (char *)p->key, (char *)p->value);
    // }
}
