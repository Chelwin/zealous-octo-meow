/***
* Least Recently Used Page Replacement Algorithm
* @VS 08-Nov-2015
* *will debug later in the night, perhaps.*
***/
#include<stdio.h>

int main()
{
    int frame[5], page[100];
    int i, n, h, j, k;
    int c1, c2, c3, c4, c5, m;
    char f = 'F';

    printf("Enter the no. of pages: "); scanf("%d",&n);
    printf("Enter the pages: ");
    for( i =0; i<n; i++) scanf("%d",&page[i]);

    c1 = 0; c2 = 0; c3 = 1; c4 = 0; m = 0;
    for(i = 0; i<n ; i++)
    {
        if (c1 == 0)
        {
            if(c2 >= 3)
                c2 = 0;
            frame[c2] = page[i];
            c2 = c2 + 1;
            if(c3<3)
                c3 = c2;
        }
        printf("%d",page[i]);
        printf("\t");
        for(h = 0; h < c3; h++) printf("%d",frame[h]);

        if( c1 == 0 && c2<=3)
        {
            printf("-->%c\n",f);
            m = m + 1;
        }
        else printf("\n");

        c1 = 0;
        c4 = 0;

        if(c3 == 3)
        {
            for( k = 0; k < c3; k++)
            {
                if(page[i + 1]==frame[k])
                    c1 = 1;
                for(j = 0; j < c3; j++)
                {
                    c5 = 0;
                    k = i;
                    while(k >= (i - 1) && k>=0)
                    {
                        if( frame[j] == page[k])
                            {
                                c5 = c5 + 1;
                                k = k - 1;
                            }
                        if (c5 == 0)
                            c2 = j;
                    }
                }
            }

        }

        else
        {
            for( k = 0; k < c2; k++)
                {
                    if(page[i + 1]==frame[k])
                        c1 = 1;
                }
        }
    }

    return 0;
}
