#include <stdio.h>

int Factorial(int n)
{
    if (n==0)
    return 1;
    else
    return n * Factorial(n-1);
}

int main(void)
{
    printf("5! = %d",Factorial(5));
    return 0;
}