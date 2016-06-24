/*
PROBLEM 3

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // prevedi z ---> gcc -o aaa aaa.c -lm -std=c99

#define SRC 600851475143

// metoda preverja če je podano število praštevilo
int is_prime(int x)
{
    for(int i = 2; i < sqrt(x); i++)
        // če število deljivo z i potem ni praštevilo
        if(x % i == 0) return 0;
        
    return 1;
}

int main()
{
    int res;
    
    // preverjamo vsa števila do korena danega števila
    for(int i = 2; i < sqrt(SRC); i++)
    {
        // če i praštevilo, ki deli dano število potem 
        if(SRC % i == 0 && is_prime(i) == 1)    res = i;
    }
    
    printf("Rezultat je %d.\n", res);
    
    return 0;
}