#include<stdio.h>

void getData();
void wait();
void turnAround();
void display();

int i,n,at[10],bt[10],tat[10],wt[10];
float twt=0,ttat=0;

void main() {
    system("clear");
    printf("\nFCFS\n");
    printf("enter no of processes\n");
    scanf("%d",&n);
    getData();
    wait();
    turnAround();
    display();
}

void getData() {
    for(i=0;i<n;i++) {
        printf("enter at and bt for process %d\n",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }
}

void wait() {
    int s=0;
    wt[0]=0;
    for(i=1;i<n;i++) {
        s += bt[i-1];
        wt[i] = s - at[i];
        twt += wt[i];
    }
}

void turnAround() {
    tat[-1] = 0;
    for(i=0;i<n;i++) {
        tat[i] = bt[i]+wt[i];
        ttat += tat[i];
    }
}
void display()
{
	printf("\nPROCESS\t|BURST TIME\t|ARRIVAL TIME\t|WAIT TIME\t|TURN AROUND TIME\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t|%d\t\t|%d\t\t|%d\t\t|%d\n",i+1,bt[i],at[i],wt[i],tat[i]);
	}
	printf("\nTOTAL WAITING TIME (TWT) =%f",twt);
	printf("\nAVERAGE  WAITING TIME (AWT) =%f",twt/n);
        printf("\nTOTL TURN AROUND TIME (TAT) =%f",ttat);
        printf("\nAVERAGE TURN AROUND TIME AVG.(TAT) =%f\n\n",ttat/n);
}