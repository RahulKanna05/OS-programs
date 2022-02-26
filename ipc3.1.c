#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main() {
    char *s;
    int p = shmget(123,20,IPC_CREAT|0666);
    s = (char* )shmat(p,NULL,0);
    printf("enter smthg\n");
    scanf("%s",s);
}