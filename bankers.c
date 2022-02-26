// #include<stdio.h>
// void main()
// {
// 	int p,r,instances,i=0,j=0,k=0,count1=0,count2=0;
// 	printf("\nenter no of process: ");
// 	scanf("%d",&p);
// 	printf("\nenter no of resources: ");
// 	scanf("%d",&r);
// 	int available[r],max[p][r],allocated[p][r],need[p][r],completed[p];
// 	for(i=0;i<p;i++)
// 		completed[i]=0;
// 	printf("\nenter no of avalible instances: \n");
// 	for(i=0;i<r;i++)
// 	{
// 		printf("R[%d]: ",i);
// 		scanf("%d",&instances);
// 		available[i]=instances;
// 	}
// 	printf("\nenter maximum(max table) NO of instances of resources that a process need: \n");
// 	for(i=0;i<p;i++)
// 	{
// 		printf("P[%d]: ",i);
// 		for(j=0;j<r;j++)
// 		{
// 			scanf("%d",&instances);
// 			max[i][j]=instances;
// 		}
// 	}
// 	printf("\nenter no of instances already allocated to process of a resource: \n");
// 	for(i=0;i<p;i++)
// 	{
// 		printf("P[%d]: ",i);
// 		for(j=0;j<r;j++)
// 		{
// 			scanf("%d",&instances);
// 			allocated[i][j] = instances;
// 			need[i][j]=max[i][j]-allocated[i][j];
// 		}
// 	}

// 	printf("\npossible sequence is: ");
// 	while(count1!=p)
// 	{
// 		count2=count1;
// 		for(i=0;i<p;i++)
// 		{
// 			for(j=0;j<r;j++)
// 			{
// 				if(need[i][j]<=available[j])
// 				{
// 					k++;
// 				}
// 			}
// 			if(k==r && completed[i]==0)
// 			{
// 				printf("P[%d]\t",i);
// 				completed[i]=1;
// 				for(j=0;j<r;j++)
// 				{
// 					available[j]=available[j]+allocated[i][j];
// 				}
// 				count1++;
// 			}
// 			k=0;
// 		}
// 		if(count1==count2)
// 		{
// 			printf("...and then deadlock occurs");
// 			break;
// 		}
// 	}
// 	printf("\n\n");
// }

#include<stdio.h>
#include<unistd.h>
int main() {
    system("clear");
    int p,r,i,j,k=0,count1=0,count2=0;
    printf("\nEnter no of processes: ");
    scanf("%d",&p);
    printf("\nEnter no of resouces: ");
    scanf("%d",&r);
    int max[p][r],allocated[p][r],need[p][r],available[r],completed[p];
    printf("\nEnter the max resources(matrix) required by the process");
    for(i=0;i<p;i++) {
        printf("\nP[%d]: ",i);
        for(j=0;j<r;j++) {
            scanf("%d",&max[i][j]);
        }
    }
    printf("\nEnter the allocated resources(matrix) of the process");
    for(i=0;i<p;i++) {
        printf("\nP[%d]: ",i);
        for(j=0;j<r;j++) {
            scanf("%d",&allocated[i][j]);
            need[i][j] = max[i][j]-allocated[i][j];
        }
    }

    printf("\nEnter the available resources: ");
    for(i=0;i<r;i++) {
        scanf("%d",&available[i]);
    }

    for(i=0;i<p;i++) 
        completed[i] = 0;

    printf("The possible sequence is: ");
    while(count1!=p) {
        count2 = count1;
        for(i=0;i<p;i++) {
            for(j=0;j<r;j++) {
                if(need[i][j] <= available[j]) {
                    k++;
                }
            }
            if(k==r && completed[i] == 0) {
                printf("P[%d]\t",i);
                count1++;
                completed[i] = 1;
                for(j=0;j<r;j++) {
                    available[j] = available[j] + allocated[i][j];
                }
            }
            k=0;
        }
        if(count1 == count2) {
            printf("...and deadlock occurs\n");
            break;
        }
    }
    printf("\n");
}