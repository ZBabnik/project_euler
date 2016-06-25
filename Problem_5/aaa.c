/*
PROBLEM 5

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

// x predstavlja število za katere preverjamo deljivost n pa število z katerim delimo
int is_div(ull x, int n)
{
    // izhodni pogoj če zanka pride do sem smo našli rezultat x
    if(n == 1)
        return 1;
    
    int res = 0;
    // če pogoj ni izpolnjen skočimo nazaj z rezultatom ==0    
    if(x % n != 0)
        return 0;
       
    // če x je deljiv z n pa kličemo metodo z za 1 manjšim n-jem torej od 20 do 1
    res = is_div(x, n-1);
    
    return res;
}

 int main()
{
    // rezultat je velik zato uporabljamo tip unsigned longlong
    ull res = 20;
    
    // check nam pove če je pogoj izpolnjen (== 1)
    int check = 0;
    while(check != 1)
    {
        // povrsti se za vsako stevilo klice metoda, ki preverja deljivost od 20 do 1
        check = is_div(res, 20);
        res++;
    }
    // zaradi while zanke je rezultat na koncu za 1 prevelik
    res--;
    
    printf("Rezultat je %llu.\n", res);
    
    return 0;
}