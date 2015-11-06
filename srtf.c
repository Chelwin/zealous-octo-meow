/***
*
* Shortest Runtime First Scheduling Algorithm
*@VS 4-Nov-2015
* *Super Buggy* Will debug later.
***/
#include<stdio.h>

int main()
{
    char p[10][10],t[10];
    int at[10], bt[10], st[10], wt[10], ft[10],tt[10], rt[10];
    int i, m, time, remaining, smallest, endtime;

    printf("Enter the total no. of processes: "); scanf("%d",&m);

    printf("\nEnter the process names: ");
    for( i = 0; i<m; i++)
        {
            scanf("%c",&p[i][10]);
        }

    printf("\n\nNow, enter arrival time and burst time for each process: ");
    for( i = 0; i< m; i++)
    {
            printf("\n%c",p[i][10]);
            scanf("%d%d",&at[i],&bt[i]);
            rt[i] = bt[i];
    }

    rt[9] = 9999;
    printf("\nProcess Name\tArrival TIme\tBurst Time\tWaiting Time\t Finish Time\t Turnaround Time");
    for(time = 0; remaining!=m; time++)
    {
        smallest = 9;
        for(i = 0; i < m; i++)
        {
            if(at[i]<time && rt[i]<rt[smallest] && rt[i]>0)
                smallest = i;
            rt[smallest] = rt[smallest] - 1;
        }


            if(rt[smallest] == 0 ){

                remaining = remaining - 1;
                ft[smallest] = time + 1;
                tt[smallest] = ft[smallest] - at[smallest];
                wt[smallest] = ft[smallest] - bt[smallest] - at[smallest];
                printf("\n%c\t%d\t%d\t%d\t%d\%d",p[smallest],at[smallest],bt[smallest],&wt[smallest],&ft[smallest],&tt[smallest]);

            }
    }

    return 0;
}
