/***
* Round Robin Non Preemptive
*@VS 07-Nov-2015
* Woohoo! One Week!
***/

#include<stdio.h>
int main()
{
    int n, qt, i, count, c2;
    int bt[100];
    printf("Enter the no. of processes: "); scanf("%d",&n);

    printf("Enter the quantum time: ");scanf("%d",&qt);

    printf("Enter the burst time: ");
    for(i = 0; i<n; i++)
    {
        scanf("%d",&bt[i]);
    }

    count = 0;
    c2 = 0;
    for(i = 0; i < n; i++)
    {
        count = count + bt[i];
    }

    while(c2!= count)
    {
        for(i = 0; i < n; i++)
        {
            if (bt[i]> qt)
            {
                c2 = c2 + qt;
                printf("%d-->%d\n",i+1,qt);
                bt[i] = bt[i] - qt;
            }
            else if(bt[i] <= qt && bt[i]>0)
            {
                c2 = c2 + bt[i];
                printf("%d-->%d\n",i+1,bt[i]);
                bt[i] = 0;
            }
        }
    }

    return 0;
}

