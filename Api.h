#ifndef API_H
#define API_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

#include "kvs.h"

KVSstore *mStore;
char EMPTY[];

void _InitStore();

void set(char *K, char *V);
char *get(char *K);

#endif
