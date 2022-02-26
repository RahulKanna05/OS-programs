#include<stdio.h>
#include<pthread.h>

int a,b;

void *add() {
    printf("Sum of %d and %d is %d\n",a,b,a+b);
}

void *sub() {
    printf("Diff of %d and %d is %d\n",a,b,a-b);
}

int main() {
    pthread_t tid1,tid2;
    printf("enter 2 nums\n");
    scanf("%d%d",&a,&b);
    pthread_create(&tid1,NULL,add,NULL);
    pthread_create(&tid2,NULL,sub,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    printf("end of main\n");
}