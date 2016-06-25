/* 
PROBLEM 6

The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>// gcc -o aaa aaa.c -lm -std=c99

#define CEIL 100

// za vsak slučaj
typedef long long ll;

 int main()
{
    // vsota kvadratov in kvadrat vsote
    ll sum_sq = 0;
    ll sq_sum = 0;
    // problem rešujemo za vsa manjša števila od CEIL
    for(int i = 1; i <= CEIL; i++)
    {
        // vsoti kvadratov kar sporoti prištevamo vse kvadrate
        sum_sq += pow(i , 2);
        // kvadratu vsot pa prišetvamo samo števila sama
        sq_sum += i;
    }
    
    // rezultat je kar enak razliki kvadrata seštevka in vsote kvadratov
    ll res = (pow(sq_sum, 2) - sum_sq);
    
    printf("Rezultat je %lld.\n", res);
    return 0;
}