#include "increaseCounter.h"

pthread_mutex_t mCount_mutex;

int mCounter = 0;

void increase(){
//    pthread_mutex_lock(&mCount_mutex);
    mCounter = mCounter + 1;
//    pthread_mutex_unlock(&mCount_mutex);
}

int get_result(){
    return mCounter;
}

void reset(){
    mCounter = 0;
}
