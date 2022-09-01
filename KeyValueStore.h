#ifndef _KEY_VALUE_STORE_H_
#define _KEY_VALUE_STORE_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define KVS_SPACE_INCREMENT 8

typedef int         KVScompare(const char *a, const char *b);
typedef const void  KVSkey;
typedef void        KVSvalue;
typedef struct      {  KVSkey *key; KVSvalue *value;  } KVSpair;
typedef struct      KVSstore KVSstore;

KVSstore *kvs_create(KVScompare *compare);
void      kvs_destroy(KVSstore *store);
void      kvs_put(KVSstore *store, KVSkey *key, KVSvalue *value);
KVSvalue *kvs_get(KVSstore *store, KVSkey *key);
void      kvs_remove(KVSstore *store, KVSkey *key);
size_t    kvs_length(KVSstore *store);
KVSpair  *kvs_pair(KVSstore *store, size_t index);

#endif
