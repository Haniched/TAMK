#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *thread_function(void* arg) {
    printf("Thread is running\n");
    sleep(2);
    printf("Thread is doen\n");
    return NULL;
}

int main () {
    pthread_t thread;
    // make new thread
    if (pthread_create(&thread, NULL, thread_function, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // wait until new thread finished
    if (pthread_join(thread, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    printf("Thread has been executed");
    return 0;
}