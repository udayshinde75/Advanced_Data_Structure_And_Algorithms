#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

void print_array_recursive_backward(int* A, int inde, int N);
void print_array_recursive(int* A, int inde, int N);
void print_array_recursive_backward_V2(int* A, int N);
void print_array_recursive_backward_V3(int* A, int index);


int main()
{
    int N = 8;
    int A[] = {100, 200, 300, 400, 500, 600, 700, 800};
    puts("Priniting array recursively in forward direction");
    print_array_recursive(A, 0, N);
    puts("Priniting array recursively in backward direction");
    print_array_recursive_backward(A, 0, N);

    puts("Priniting array recursively in backward direction V2");
    print_array_recursive_backward_V2( A, N);

        puts("Priniting array recursively in backward direction V3");
    print_array_recursive_backward_V3( A, N-1);

    return 0;
}

void print_array_recursive(int* A, int inde, int N)
{
    if (inde == N)
    {
        return; 
    }
    
    printf("A[%d]:%d\n", inde, A[inde]);
    print_array_recursive(A, inde+1, N);
}

void print_array_recursive_backward(int* A, int inde, int N)
{
    if (inde == N)
    {
        return;
    }

    print_array_recursive_backward(A, inde+1, N);
    printf("A[%d]:%d\n", inde, A[inde]);
}

void print_array_recursive_backward_V2(int*A, int N)
{
    if (N == 0)
    {
        return;
    }
    N = N-1;
    printf("A[%d]:%d\n", N, A[N]);
    print_array_recursive_backward_V2(A, N);
}

void print_array_recursive_backward_V3(int*A, int index)
{
    if (index < 0)
    {
        return;
    }
    printf("A[%d]:%d\n", index, A[index]);
    print_array_recursive_backward_V3(A, index -1);
}