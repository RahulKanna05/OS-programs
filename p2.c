#include<stdio.h>
#include<unistd.h>
int main()
{
    int signal;
    pid_t pid;
    printf("\nhi i am parent process my pid=%d i am going to create a child\n",getpid());
    pid=fork();
    if(pid==0)
    {
        sleep(5);
        printf("\nhi i am child process my pid=%d my parents pid=%d \n",getpid(),getppid());
    }
    else if(pid>0)
    {
        printf("\nhi i am parent. i will wait for my child to complete\n");
        wait(&signal);
        printf("\ni got signal=%d so my child completed.i am exiting \n",signal);
    }
    else
        printf("\nerror creating process\n");
}