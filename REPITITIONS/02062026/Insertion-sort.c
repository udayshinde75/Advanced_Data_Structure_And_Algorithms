#include <stdlib.h>
#include <stdio.h>

void show_array(int* a, int N, const char* message);
void insertion_at_sorting_position(int* a, int a_size);
void insertion_sort(int* a, int N);

int main(void)
{
    int N = 10;
    int arr[10] = {123,34,234,23424,33,423,31,4,64534,132};

    show_array(arr, N, "Before Sorting : ");
    insertion_sort(arr, N); 
    show_array(arr, N, "After sort : ");
}

void show_array(int* a, int N, const char* message)
{
    puts(message);

    int i = 0;

    while (i < N)
    {
        printf("a[%d] : %d\n", i, *(a + i));
        i = i + 1;
    }
}

void insertion_at_sorting_position(int* a, int a_size)
{
    int temp = *(a + (a_size - 1));
    int i = a_size - 2;

    while (i >= 0 && *(a + i) > temp)
    {
        *(a + i + 1) = *(a + i);
        i = i - 1;
    }

    *(a + i + 1) = temp;
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
        i = i + 1;
    }
}
