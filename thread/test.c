#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

int main()
{
    int i= 0;
    uint64_t a = 0;
    pthread_mutex_t mutex;

    pthread_mutex_init(&mutex, NULL);
    while(a++ < 1000000) {
        pthread_mutex_lock(&mutex);
        pthread_mutex_unlock(&mutex);
    }
    return 0;
}
