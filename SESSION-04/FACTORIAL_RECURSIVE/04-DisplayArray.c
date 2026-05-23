#include <stdio.h>
#include <stdlib.h>

void DisplayArray(int* arr, int i, int size);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    DisplayArray(arr, 0, 10);

    printf("\n");
    
    return 0;
}

void DisplayArray(int* arr, int i, int size)
{
    if (i >= size)
    {
        return;
    }

    printf("%d ", arr[i]);

    DisplayArray(arr, i + 1, size);
}