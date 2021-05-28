#include <stdio.h>
#include <stdlib.h>

//Fonctions fibonacci

int fib(int n)  //Normal recursive version
{
    if(n == 0)
        return 1;
    else
    {
        if(n == 1)
            return 1;
        else
            return (fib(n-1) + fib(n-2));
    }
}

int fibTerm(int m, int x, int y, int count) //Tail recursive version
{
    //count = 2;
    if(count > m)
        return y;
    else
        return fibTerm(m, y, x+y, count+1);
}