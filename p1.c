#include<stdio.h>
#include<unistd.h>
int main()
{
    pid_t pid;
    printf("\nhi i am parent process my pid=%d i am going to create a child\n",getpid());
    pid=fork();
    printf("\ncommon area-1 now accessed by pid=%d \n",getpid());
    if(pid==0)
        printf("\nhi i am child process my pid=%d my parents pid=%d \n",getpid(),getppid());
    else if(pid>0)
        printf("\nthis is parent pid=%d, this is mychild=%d\n",getpid(),pid);
    else
        printf("\nunknown error\n");
    printf("\ncommon area-2 now accessed by pid=%d \n",getpid());
}

// #include<stdio.h>
// #include<unistd.h>
// #include<sys/types.h>
// int main()
// {
// pid_t p;
// printf("before fork\n");
// p=fork();
// if(p==0)
// {
// printf("I am child having id %d\n",getpid());
// printf("My parent's id is %d\n",getppid());
// }
// else{
// printf("My child's id is %d\n",p);
// printf("I am parent having id %d\n",getpid());
// }
// printf("Common\n");
// }