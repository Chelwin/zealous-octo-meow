/***
* First Come First Serve Scheduling
*@VS 09-Nov-2015
***/

#include<stdio.h>
#include<string.h>

int main()
{
    char p[100][100], t[100];
    int i, j, n, temp = 0, at[100], bt[100], st[100], wt[100], ft[100], tt[100];

    printf("Enter the no. of processes: ");scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the name, arrival time, and burst time for process %d: ",i+1);
        scanf("%s%d%d",&p[i],&at[i],&bt[i]);
    }

    for(i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if(at[i]<at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                strcpy(t,p[i]);
                strcpy(p[i],p[j]);
                strcpy(p[j],t);
            }}}

    for(i=0;i<n;i++)
    {
        if(i==0) {st[i] = at[i];}
        else {st[i] = ft[i-1];}
        wt[i] = st[i] - at[i];
        ft[i] = st[i] + bt[i];
        tt[i] = ft[i] - at[i];
    }

    printf("\nProcess\tArrival\tBurst\tStart\tWaiting\tFinishing\tTurnaround");
    for(i=0;i<n;i++)
    {
        printf("\n%3s\t%3d\t%3d\t%3d\t%5d\t%6d\t%12d",p[i],at[i],bt[i],st[i],wt[i],ft[i],tt[i]);
    }

    return 0;
}
