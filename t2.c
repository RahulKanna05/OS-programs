#include<stdio.h>
#include<pthread.h>

void *hi() {
    printf("performing operations here in HI thread\n");
}

int main() {
    pthread_t tid;
    pthread_create(&tid,NULL,hi,NULL);
    pthread_join(tid,NULL);
    printf("Im a main thread\n");
}