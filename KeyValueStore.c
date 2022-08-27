#include "KeyValueStore.h"

void getTimestamp(char *pBuf){
    time_t rawtime;
    time(&rawtime);

    struct tm *timeinfo = localtime(&rawtime);

    sprintf(pBuf, "---- %d.%02d.%02d %02d:%02d:%02d ----",
            timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec  );
}

void printTimestamp(){
    char buf[32];
    getTimestamp(buf);
    printf("%s\n\n", buf);
}

void printShortTimestamp(){
    char buf[32];
    getTimestamp(buf);
    printf("%s", buf);
}

void addressToHex(char *pBuf, uintptr_t Address){
    if(  sizeof(uintptr_t) != 8  ){
        sprintf(pBuf, "%s", "0xXXXX-XXXX-XXXX-XXXX");

        return;
    }

    sprintf(pBuf +  2, "%04lX", (Address & 0xFFFF000000000000) >> 48);
    sprintf(pBuf +  7, "%04lX", (Address & 0x0000FFFF00000000) >> 32);
    sprintf(pBuf + 12, "%04lX", (Address & 0x00000000FFFF0000) >> 16);
    sprintf(pBuf + 17, "%04lX", (Address & 0x000000000000FFFF)      );

    pBuf[ 0] = '0';
    pBuf[ 1] = 'x';
    pBuf[ 6] = '-';
    pBuf[11] = '-';
    pBuf[16] = '-';
}

int str(char *pStr){
    char* pBuff = calloc(1, 256);

    strcpy(pBuff, pStr);

    printf("'%s'\n", pBuff);
    printf("'%d %d'\n", (int)pStr[0], (int)pStr[1]);

    return 6;
}

int mNum = -1;
void func(int N){
    printf("mNum = %d, N = %d, ", mNum, N);
    mNum = N;

    printf("mNum = %d\n", mNum);
}

#include <pthread.h>
pthread_mutex_t mCount_mutex;

int mCounter = 0;
void increase(){
    pthread_mutex_lock(&mCount_mutex);
    mCounter = mCounter + 1;
    pthread_mutex_unlock(&mCount_mutex);
}
int get_result(){
    return mCounter;
}
