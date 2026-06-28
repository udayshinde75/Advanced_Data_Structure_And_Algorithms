#include <stdio.h>
#include <stdlib.h>

void show_array(int* a, int N, const char* msg);

void insert_at_sorting_position(int* a, int N);

void insertion_sort(int* a, int N);

int main(void)
{
    int N = 10;
    int arr[10] = {132,35423,35,422,4,24,23,13,534,131};

    show_array(arr, N, "before sorting : ");
    insertion_sort(arr, N);
    show_array(arr, N, "After Sorting : ");

    return 0;
}

void insert_at_sorting_position(int* a, int N)
{
    int temp = a[N-1];
    int i = N-2;

    while (i >= 0 && a[i] > temp)
    {
        a[i+1] = a[i];
        --i;
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
        insert_at_sorting_position(a, i);
        ++i;
    }
}

void show_array(int* a, int N, const char* msg)
{
    puts(msg);
    int i = 0;

    while (i < N)
    {
        printf("arr[%d]:%d\n", i, a[i]);
        ++i;
    }
}