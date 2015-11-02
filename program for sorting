/*This program demonstrates the implementation of
*a brute force searching algorithm to embed in my
*scheduling codes.
*I was just trying recall all the sorting algos I'd
*done the sem before.
*   @author VS
*   @on 2-Nov-2015 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define n 10

int main(){
    int unsorted[n];
    int i, j, temp;

    for (i = 0; i < n; i++)
    {
        scanf("%d",&unsorted[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (unsorted[j] > unsorted[j + 1])
            {
                temp = unsorted[j];
                unsorted[j] = unsorted[j + 1];
                unsorted[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++){
        printf("%d\t", unsorted[i]);
    }
    return 0;
}
