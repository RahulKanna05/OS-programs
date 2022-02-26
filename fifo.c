#include<stdio.h>

int frm[10],ref[100],i,j,nof,nor,victim=-1,flag=0,pf=0;

int main() {
    system("clear");
    printf("enter the page size: ");
    scanf("%d",&nor);
    printf("\nenter the frame size: ");
    scanf("%d",&nof);
    printf("\nenter the pages: ");
    for(i=0;i<nor;i++) {
        scanf("%d",&ref[i]);
    }
    for(i=0;i<nof;i++) {
        frm[i] = -1;
    }
    printf("\n");
    for(i=0;i<nor;i++)
    {
        flag = 0;
        printf("\n\t Reference pn %d->\t",ref[i]);
        for(j=0;j<nof;j++) {
            if(frm[j] == ref[i]) {
                printf("already in");
                flag=1;
                break;
            }
        }

        if(flag == 0) {
            pf++;
            victim = (victim+1)%nof;
            frm[victim] = ref[i];
            for(j=0;j<nof;j++) {
                printf("%4d",frm[j]);
            }
        }
    }
    printf("\n\nPage faults:%4d\n\n",pf);
}