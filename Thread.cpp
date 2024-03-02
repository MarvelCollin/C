#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *function1(void *arg) {
    while(1) {
        printf("Function 1 is running every 1 second.\n");
        sleep(1);
    }
    return NULL;
}

void *function2(void *arg) {
    while(1) {
        char c = getchar();
        printf("%c\n", c);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, function1, NULL);
    pthread_create(&thread2, NULL, function2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
