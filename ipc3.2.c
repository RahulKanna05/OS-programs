#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main() {
    char *s;
    int p = shmget(1234,20,IPC_CREAT|0666);
    s = (char* )shmat(p,NULL,0);
    printf("Msge received:'%s'\n",s);
}