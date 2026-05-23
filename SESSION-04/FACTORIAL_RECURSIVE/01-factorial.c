#include <stdio.h>
#include <stdlib.h> 

unsigned long long factorial(unsigned int n);

int main()
{
    int N;

    unsigned long long result;

    N = 5;

    result = factorial(N);

    printf("Factorial of %d is %llu\n", N, result);
}

unsigned long long factorial(unsigned int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}