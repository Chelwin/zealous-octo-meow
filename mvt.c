/****
*Memory Variable Type
*@VS 01-Nov-2015
****/
#include<stdio.h>

int main(){

int m = 0, n = 0, m1 = 0, m2 = 0, count = 0, i;
/***
    m: memory capacity
    n: no. of processors
    m1: size of required memory
    m2: fragment size
***/

    printf("enter memory capacity: ");
    scanf("%d",&m);
    printf("\nenter then no. of processors: ");
    scanf("%d",&n);

    for(i = 0; i<n; i++)
    {
        printf("\nenter the required memory size by process %d: ",i+1);
        scanf("%d", &m1);
        count = count + m1;
        if(m1<=m)
        {
            if(count == m) printf("\nNo more processes can be allocated.");
            printf("\nThe memory allocated for process %d is: %d", i+1,m1);
            m2 = m - m1;
            //printf("\nInternal Fragmentation is: %d", m2);
            printf("\nExternal Fragmentation is: %d", m2);
            m = m2;
        }
        else
            printf("\nMemory too small to be allocated by process %d",i+1);

    }

return 0;
}

