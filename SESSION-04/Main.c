#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    /*
        Base condition

        factorial(1) = 1
    */
    if (n == 1)
    {
        return 1;
    }

    /*
        Recursive relation

        factorial(n) = n * factorial(n - 1)
    */
    return n * factorial(n - 1);
}

int main()
{
    int result = factorial(5);

    printf("Factorial : %d\n", result);

    return 0;
}