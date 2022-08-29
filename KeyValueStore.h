#ifndef KEYVALUESTORE_H
#define KEYVALUESTORE_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

void getTimestamp(char *pBuf);
void printTimestamp();
void printShortTimestamp();

void addressToHex(char *pBuf, uintptr_t Address);

int str(char *pStr);

void increase();
int get_result();

#endif
