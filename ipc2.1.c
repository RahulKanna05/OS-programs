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
    printf("enter some text\n");
    scanf("%s",m.text);
    msgsnd(msgid,&m,20,0);
    return 0;
}