#ifndef _API_H_
#define _API_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

#include "KeyValueStore.h"
#include "Cache.h"

KVSstore *mStore;

char EMPTY[];

void _InitStore();

void set(char *K, char *V);
char *get(char *K);

#endif
