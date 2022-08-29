#include "increaseCounter.h"

pthread_mutex_t mCount_mutex;

int mCounter = 0;

void increase(){
    #ifdef THREAD_SAFE
        pthread_mutex_lock(&mCount_mutex);
    #endif

    mCounter = mCounter + 1;

    #ifdef THREAD_SAFE
        pthread_mutex_unlock(&mCount_mutex);
    #endif
}

int get_result(){
    return mCounter;
}

void reset(){
    mCounter = 0;
}
