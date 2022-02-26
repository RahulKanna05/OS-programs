// #include<stdio.h>
// #include<unistd.h>
// #include<pthread.h>
// #include<semaphore.h>

// sem_t full,empty,b;
// int buff=0;
// void *prod() {
//     while(1) {
//         sem_wait(&empty);
//         sem_wait(&b);
//         buff++;
//         printf("Producer placed buffer %d\n",buff);
//         sleep(1);
//         sem_post(&b);
//         sem_post(&full);
//         if(buff == 5) {
//             sleep(60);
//         }
//     }
// }

// void *cons() {
//     while(1) {
//         sem_wait(&full);
//         sem_wait(&b);
//         printf("Consumer consumed buffer %d\n",buff);
//         buff--;
//         sem_post(&b);
//         sem_post(&empty);
//     }
// }

// int main() {
//     pthread_t p,c;
//     int i;
//     sem_init(&empty,0,5);
//     sem_init(&full,-5,0);
//     sem_init(&b,0,1);
//     pthread_create(&p,NULL,prod,NULL);
//     pthread_create(&c,NULL,cons,NULL);
//     pthread_join(p,NULL);
//     pthread_join(c,NULL);
// }

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t b,empty,full; //pthread_mutex_t mutex;
int buf=0;
void * prod()
{
    while(1)
    {
        sem_wait(&empty);
        sem_wait(&b); //pthread_mutex_lock(&mutex);
        buf++;
        printf("Produced buf = %d\n",buf);
        sleep(1);
        sem_post(&b); //pthread_mutex_unlock(&mutex);
        sem_post(&full);
        if(buf==5)
            sleep(60);
    }
}
void * cons()
{
    while(1)
    {
        sleep(5);
        sem_wait(&full);
        sem_wait(&b); //pthread_mutex_lock(&mutex);
        buf--;
        printf("Consumed buf = %d\n",buf);
        sleep(1);
        sem_post(&b); //pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}
void main()
{
    pthread_t p,c;
    sem_init(&empty,0,5);
    sem_init(&full,-5,0);
    sem_init(&b,0,1); //line to be removed when mutex is used along with semaphore
    pthread_create(&p,NULL,prod,NULL);
    pthread_create(&c,NULL,cons,NULL);
    pthread_join(p,NULL);
    pthread_join(c,NULL);
}