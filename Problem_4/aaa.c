/*
PROBLEM 4

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // prevedi z gcc -o aaa aaa.c -lm -std=c99

// mejni števili za loop zanki
#define FLOOR 100
#define CEIL 1000

// vrne dolzino stevila recimo za 10 vrne 2 za 100 3 itd...
int len(int x)
{
    int return_val = 0;
    while(x != 0)
    {
        return_val++;
        x /= 10;
    }
    
    return return_val;
}

// metoda vrača 1 če je x palindrom, drugače 0
int is_pal(int x)
{
    // pomozna spremenljivka, ki jo bomo spreminjali
    int temp = x;
    // stevilo, ki predstavlja prezrcaljen x;
    int x_rev = 0;
    // stevec za pomoc pri mnozenju z potencami stevila 10
    int stevec = len(x);
    // delimo temp in pristevamo zadnje stevke*primerna potecna števila 10
    while(temp != 0)
    {
        x_rev += temp % 10 * pow(10, stevec);
        stevec--;
        temp /= 10;
    }
    x_rev /= 10;
    
    if(x_rev - x == 0)
        return 1;
        
    return 0;
}

int main()
{
    int res = 0;
    
    // preverjamo produkte vseh števil i*j (obe tromestni)
    for(int i = FLOOR; i < CEIL; i++)
    {
        for(int j = FLOOR; j <= i; j++)
        {
            // z metodo is_pal preverimo če je produkt palindrom
            int check = is_pal(i*j);
            
            if(check == 1 && i*j > res)  res = i*j;
        }
    }
    
    printf("Rezultat je %d.\n", res);
    
    return 0;
}