#include<stdio.h>
#include<pthread.h>

void *hi() {
    printf("hi im child thread=%d\n",getpid());
}

int main() {
    pthread_t tid;
    printf("Im parent thread, creting child thread\n");
    pthread_create(&tid, NULL, hi,NULL);    
    printf("Hi im parent thread=%d\n",getpid());
}

// #include<stdio.h>
// #include<pthread.h>
// void* hi()
// {
// printf("Hi I am a thread. My ID is: %d",getpid());
// }
// int main()
// {
// pthread_t tid;
// printf("Im parent thread creating child\n");
// pthread_create(&tid,NULL,hi,NULL);
// printf("\n I am main process. My ID is: %d \n", getpid());
// }