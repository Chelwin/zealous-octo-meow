/****
* @VS 03-Nov-2015
* program for memory fixed type
*       ***DISCLAIMER***
* It's buggy.
* I'm too sleepy, coffee ain't working :/
* I'll debug tomorrow. Ciao World!
***/
#include<stdio.h>
int m, n, p, s,m1, fra1, fra2, f1 = 0, f2 = 0, f = 0;

int main()
{
    input();
    mft();
    return 0;
}
void input()
{
    printf("Enter the memory size: ");
    scanf("%d",&m);
    printf("\nEnter the no. of partitions: ");
    scanf("%d",&p);
    s = m /p;
    printf("\nThe partition size: %d",s);
    printf("\n Enter the no. of processes: ");
    scanf("%d",&n );
}
void mft()
{
    int pos = m, i = 0, s1 = 0;

    for(i = 0; i < n; i++)
    {

        if(pos < s) {
                printf("\nMemory not available!");
                break;
        }
        else{
            printf("\nEnter size of process: ");
            scanf("%d",&m1);

            if(m1 <= s){

                printf("\nP%d allocated.",i+1);
                fra1 = s - m1;
                printf("\nInternal Fragmentation: %d",fra1);
                f1 = f1 + fra1;
                pos = pos - s;
            }
            else{
                printf("\nProcess is larger than partition! wait!");
                s1 = m1;
                while(s1>s){
                    s1 = s1 - s;
                    pos = pos - s;
                }
                pos = pos - s1;
                fra2 = s - s1;
                f2 = f2 + fra2;
            }
        }
    }
    f = f1 + f2;
    printf("\nExternal Fragmentation: %d ",f);
}
