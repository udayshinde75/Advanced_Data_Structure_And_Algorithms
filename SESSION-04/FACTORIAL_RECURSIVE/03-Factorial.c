#include <stdio.h>
#include <stdlib.h>

int print_factorial(int n);

int main()
{
    print_factorial(5);

    return 0;
}

int print_factorial(int n)
{
    if (n ==1 || n ==0)
    {
        printf("Factorial : %d\n", 1);
        return 1;
    }
    
    int result = n * print_factorial(n - 1);

    printf("Factorial : %d\n", result);

    return result;
}