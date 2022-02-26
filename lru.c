#include<stdio.h>

int frm[10],ref[100],i,j,nof,nor,victim=-1,flag=0,pf=0,tq[100],count=0;
int find();    
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
        tq[i] = 0;
    }
    printf("\n");
    for(i=0;i<nor;i++)
    {
        count++;
        flag = 0;
        printf("\n\t Reference pn %d->\t",ref[i]);
        for(j=0;j<nof;j++) {
            if(frm[j] == ref[i]) {
                printf("already in");
                tq[j] = count;
                flag=1;
                break;
            }
        }

        if(flag == 0) {
            pf++;
            if(pf<=nof)
                victim = (victim+1)%nof;
            else
                victim = find();       
            
            tq[victim] = count;
            frm[victim] = ref[i];
            for(j=0;j<nof;j++) {
                printf("%4d",frm[j]);
            }
        }
    }
    printf("\n\nPage faults:%4d\n\n",pf);
}

int find() {
    int temp=tq[0],index=0;
    for(i=1;i<nof;i++) {
        if(tq[i] < temp) {
            temp = tq[i];
            index=i;
        }
    }
    return index;
}

#include<stdio.h>
int i,j,nof,nor,flag=0,ref[10],frm[10],pf=0,victim=-1;
int recent[10],lrucal[10],count=0,tq[10];
int find();
int main()
{
    system("clear");
    printf("***** LRU (Least recently used) Page replacement algorithm ******\n");
    printf("\nEnter no.of Frames in memory : ");
    scanf("%d",&nof);
    printf("\nEnter no.of pages required to load : ");
    scanf("%d",&nor);
    printf("\nEnter page numbers required to load in sequence : ");
    for(i=0;i<nor;i++)
        scanf("%d",&ref[i]);
    for(i=0;i<nof;i++) {
        frm[i]=-1; 
        tq[i]=0; 
    }
    for(i=0;i<nor;i++) {
        count++;
        flag=0;
        printf("\n\t Reference pn%d->\t",ref[i]);
        for(j=0;j<nof;j++) {
            if(frm[j]==ref[i]) {
                flag=1;
                tq[j]=count;
                printf("already present in memory");
                break; 
            } 
        }
        if(flag==0) {
            pf++;
            if(pf<=nof)
                victim=(victim+1)%nof;
            else
                victim=find();
            tq[victim]=count;
            frm[victim]=ref[i];
            for(j=0;j<nof;j++)
                printf("%4d",frm[j]); 
        }
    }
    printf("\n\n No.of page faults : %d \n\n",pf);
}
int find()
{
    int i,index=0,temp=tq[0];
    for(i=1;i<nof;i++)
    {
        if(temp>tq[i])
        {
            temp=tq[i];
            index=i;
        }
    }
    return index;
}
