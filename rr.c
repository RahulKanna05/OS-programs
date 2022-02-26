// #include<stdio.h>

// int main() {
//     int bt[10],temp_bt[10],wt[10],tat[10],i,n,qt,temp,x=0,count=0;
//     float twt=0,ttat=0;
//     system("clear");
//     printf("RR\n");
//     printf("\nenter the no of processes: ");
//     scanf("%d",&n);
//     printf("\nenter the bt of the processes: ");
//     for(i=0;i<n;i++) {
//         scanf("%d",&bt[i]);
//         temp_bt[i] = bt[i];
//     }
//     printf("\nenter the quantum time: ");
//     scanf("%d",&qt);

//     while(1) {
//         for(i=0,count=0;i<n;i++) {
//             temp = qt;
//             if(temp_bt[i] == 0) {
//                 count++;
//                 continue;
//             }
//             if(temp_bt[i]>qt) {
//                 temp_bt[i] -= qt;
//             }
//             else if(temp_bt[i] >= 0) {
//                 temp = temp_bt[i];
//                 temp_bt[i] = 0;
//             }
//             x = x+temp;
//             tat[i] = x;
//         }
//         if(count == n) {
//             break;
//         }
//     }

//     for(i=0;i<n;i++) {
//         wt[i] = tat[i] - bt[i];
//         twt += wt[i];
//         ttat += tat[i];
//     }
//     printf("\nProcess\t|Burst Time\t|Wait Time\t|Turn-Around Time\n");

//     for(i=0;i<n;i++) {
//         printf("\n%d\t|%d\t\t|%d\t\t|%d",i,bt[i],wt[i],tat[i]);
//     }   
//     printf("\n\nTotal waiting time is %f",twt);
//     printf("\n\tAverage waiting time is %f",twt/n);
//     printf("\n\nTotal turn around time is %f",ttat);
//     printf("\n\tAverage turn around time is %f\n",ttat/n);
// }

#include<stdio.h>

void main()
{
	int n,i,q,x=0,count=0,temp;
	int bt[10],temp_bt[10],tat[10],wt[10];
	float twt=0,ttat=0;
	system("clear");
	printf("***RR (ROUND ROBIN) SCHEDULING***\n");
	printf("enter the number of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the burst time of process %d:",i);
		scanf("%d",&bt[i]);
		temp_bt[i] = bt[i];
	}
	printf("\nEnter the time quantum: ");
	scanf("%d",&q);
	while(1)
	{
		for(i=0,count=0;i<n;i++)
		{
			temp=q;
			if(temp_bt[i] == 0)
			{
				count++;
				continue;
			}
			if(temp_bt[i]>q)
				temp_bt[i] = temp_bt[i]-q;
			else 
                if(temp_bt[i]>=0)
                {
                    temp = temp_bt[i];
                    temp_bt[i] = 0;
                }
                x+=temp;
                tat[i] = x;
		}
		if(n==count)
			break;
	}
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
		twt=twt+wt[i];
		ttat=ttat+tat[i];
	}
	printf("\nProcess\t|Burst Time\t|Wait time\t|Turn-Around Time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t|%d\t\t|%d\t\t|%d\n",i,bt[i],wt[i],tat[i]);
	}
	printf("\nTotal waiting time is %f",twt);
	printf("\nAvg waiting time is %f",twt/n);
	printf("\nTotal turn around time is %f",ttat);
	printf("\nAvg turn around time is %f\n",ttat/n);
}