/*
PROBLEM 2

Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

*/

#include <stdio.h>
#include <stdlib.h>

#define CEIL 4000000

// rekurzivna funkcija fibo() x in y sta člena fibo. zaporedja, kjer je y vedno večji člen
int fibo(int x, int y)
{
    // izhodni pogoj če y presega vrh
    if(y >= CEIL)
        return 0;
        
    // vrednost povečamo če y deljiv z 2
    int return_val = 0;
    if(y % 2 == 0)  return_val += y;
    
    // izračun novih dveh členov rekurzije x in y    
    int temp = x;
    x = y; 
    y += temp;
    
    // nov klic rekurzije
    return_val += fibo(x, y);
    
    return return_val;
}

int main()
{
    // klic rekurzije z začetnima členoma fibo.zaporedja (1,2)
    int res = fibo(1, 2);   
        
    printf("Rezultat je %d.\n", res);
    
    return 0;
}