#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>

struct msg {
    long id;
    char text[20];
};

int main() {
    struct msg m;
    int msgid = msgget(124,IPC_CREAT|0666);
    m.id = 1;
    msgrcv(msgid,&m,20,1,0);
    printf("msge received from parent is '%s'\n",m.text);
    return 0;
}