#include<stdio.h>
#include<pthread.h>

pthread_t tid[2];
int a,b;

void *op() {
    pthread_t p = pthread_self();
    if(pthread_equal(p,tid[0]))
        printf("Summation of %d and %d is %d\n",a,b,a+b);
    if(pthread_equal(p,tid[1]))
        printf("Difference of %d and %d is %d\n",a,b,a-b);
}

int main() {
    int i;
    printf("enter 2 nums\n");
    scanf("%d%d",&a,&b);
    for(i=0;i<2;i++)
        pthread_create(&tid[i],NULL,op,NULL);
    for(i=0;i<2;i++)    
        pthread_join(tid[i],NULL);
    printf("end of main\n");
}