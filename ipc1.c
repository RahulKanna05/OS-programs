#include<stdio.h>

int main() {
    int pip[2];
    pipe(pip);
    char s[10];
    int p = fork();
    if(p>0) {
        printf("this is parent process, sending msge to child\n");
        write(pip[1],"Heloo child",12); // the last arg defines the size of the msge
        wait();
        read(pip[0],s,12); // pip[1] means writing end and pip[0] is reading end
        printf("received msge from child '%s'\n",s);
    }

    if(p==0) {
        printf("this is child");
        read(pip[0],s,12);
        printf("msge received from parent: '%s'\n",s);
        write(pip[1],"hello parent",12);
    }
}

// #include<stdio.h>
// int main()
// {
// int pip[2];
// pipe(pip[2]);
// char s[10]; int
// p=fork();
// if(p>0)
// {
// printf("parent process, sending msg to child");
// write(pip[1],"Hello child",12);
// wait();
// read(pip[0],s,11);
// printf("\n Received msg from child: =%s\n",s);
// }
// if(p==0)
// {
// printf("Hi, this is child.");
// read(pip[0],s,12);
// printf("\n Recieved msg from parent=%s\n",s);
// write(pip[1],"Hello parent",12);
// } }
