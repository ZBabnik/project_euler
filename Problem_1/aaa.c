/*
PROBLEM 1

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>
#include <stdlib.h>

// zgornja meja do katere preverjamo
#define CEIL 1000

// stevili z katerimi preverjamo deljivost
#define DIV1 3
#define DIV2 5

int main()
{
    int res = 0;
    
    for(int i = 1; i < CEIL; i++)
    {
        // ce stevilo deljivo z i se le ta pristeje rezultatu -res-
        if(i % DIV1 == 0 || i % DIV2 == 0)    res += i;
    }
    
    printf("Rezultat je %d.\n", res);
    
    return 0;
}