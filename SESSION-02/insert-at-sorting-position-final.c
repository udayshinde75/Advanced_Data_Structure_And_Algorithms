#include <stdio.h>
#include <stdlib.h>

void show_array(int* a, int N, const char* msg);

/*
Following function accepts array of N elements
with following properties;
property 1 : N >= 2
Property 2 : arr[0] to arr[N-2] are sorted inn ascending order
*/
void insert_at_sorting_position(int* a, int N);

int main(void)
{
    int N = 5;
    int arr[5] = {50, 60, 70, 80, 65};

    show_array(arr, 5, "before insert");
    insert_at_sorting_position(arr, N);
    show_array(arr, 5, "After insert");

    exit(0);
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

void insert_at_sorting_position(int* a, int N)
{
    int temp = a[N-1];
    int i = N-2;
    while (i >= 0 && a[i] > temp)
    {
        a[i+1] = a[i];
        i = i - 1;
    }
    a[i + 1] = temp;

}