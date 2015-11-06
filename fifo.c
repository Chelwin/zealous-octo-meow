/****
* First in first out page replacement algorithm
* @VS 5-Nov-2015 updated
*  *Algorithm's not mine *sigh, I wish it was.
* But, I swear I think I make more efficient one.**
* *Done! Works brilliantly! Yoohoo*
***/

#include<stdio.h>

int main()
{
    int n, i,h,k, a[5], b[100];
    int c1, c2, c3, m;
    char f = 'F';

    printf("\nEnter the no. of pages: ");
    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        printf("Enter page no. %d: ",i+1);
        scanf("%d",&b[i]);
    }

    c1 = 0;
    c2 = 0;
    c3 = 1;
    m = 0;
    //loads page to frame of size 3
    for(i = 0; i < n; i++)
    {
        if (c1 == 0)
        {
            if (c2 >= 3)
                {c2 = 0;}

            a[c2] = b[i];
            c2 = c2 +1;
            if (c3 < 3)
                {c3 = c2;}
        }

          //prints the current page no.
        printf("%d",b[i]);
        printf("\t");

        //prints the contents of frame
        for(h = 0; h < c3; h++)
            {printf("%d",a[h]);}

        //prints the occurrence of a page fault
        if ( c1 == 0 && c2<= 3)
        {
            printf("-->%c\n",f);
            m = m + 1;
        }
        else
        {
            printf("\n");
        }
        c1 = 0;
        //checks if it is a page hit
        for(k = 0; k < c3; k++)
        {
            if (b[i+1] == a[k])
                {c1 = 1;}
        }
    }

    printf("\nTotal page hits are: %d.", n - m);


    return 0;
}
