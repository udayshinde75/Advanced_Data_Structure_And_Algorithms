#include <stdio.h>
#include <stdlib.h>

void show_array(int* a, int N, const char* msg);
void insertion_at_sorting_position(int* a, int a_size);
void insertion_sort(int* a, int N);

int main()
{
    int N = 8;
    int arr[8] = {20, 59, 28, 49, 12, 99, 12, 79};

    show_array(arr, N, "before sorting : ");
    insertion_sort(arr, N);
    show_array(arr, N, "After sorting : ");

    return 0;
}

void insertion_at_sorting_position(int* a, int a_size)
{
    int temp = a[a_size-1];
    int i = a_size-2;

    while (i >= 0 && a[i] > temp)
    {
        a[i+1] = a[i];
        i = i-1;
    }
 
    a[i+1] = temp;
}

void insertion_sort(int* a, int N)
{
    if (N == 1)
    {
        return;
    }
    
    int i = 2;

    while (i <= N)
    {
        insertion_at_sorting_position(a, i);
        i = i+1;
    }
}

void show_array(int* a, int N, const char* msg)
{
    puts(msg);

    int i;

    i = 0;

    while (i < N)
    {
        printf("arr[%d]:%d\n", i, a[i]);
        i = i + 1;
    }
    
}
