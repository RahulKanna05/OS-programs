#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

sem_t chopsticks[5];
void *philos(void *i);
void eat(int p);

void main() {
    int i;
    pthread_t t[5];
    for(i=0;i<5;i++) {
        sem_init(&chopsticks[i],0,1);
    }
    for(i=0;i<5;i++) {
        pthread_create(&t[i],NULL,philos,&i);
        sleep(1);
    }
    for(i=0;i<5;i++) {
        pthread_join(t[i],NULL);
    }
}

void *philos(void *n) {
    int i = *(int* )n;
    printf("philospher %d is thinking\n",i);
    printf("philospher %d is tries to pick left chopstick\n",i);
    sem_wait(&chopsticks[i]);
    printf("philospher %d picking the left chopstick\n",i);
    printf("philospher %d is tries to pick right chopstick\n",i);
    sem_wait(&chopsticks[(i+1)%5]);
    printf("philospher %d picking the right chopstick\n",i);
    eat(i);
    sleep(2);
    sem_post(&chopsticks[i]);
    printf("philospher %d leaves the left chopstick\n",i);
    sem_post(&chopsticks[(i+1)%5]);
    printf("philospher %d leaves the right chopstick\n",i);
    printf("philospher %d completed eating\n",i);
}

void eat(int i) {
    printf("philospher %d is eating\n",i);
}