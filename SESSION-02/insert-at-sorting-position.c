//
// Created by Uday Shinde on 11/05/26.
//

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Define an array of 5 elements
    int N = 5;
    int arr[5] = {50, 60, 70,80, 10};

    // index variable for looping
    int i;

    // define a temp variable
    int temp = 0;

    // Display array as it is
    puts("Showing array before insert_at_sorting_position()");
    i = 0;

    while (i < N)
    {
        printf("arr[%d]:%d\n", i, arr[i]);
        i = i + 1;
    }

    // insert at sorting position logic
    temp = arr[N-1];
    i = N-2;

    while (i >= 0) {
        arr[i + 1] = arr[i];
        i = i -1;
    }

    arr[i+1] = temp;

    // Display array
    puts("Showing array after insert_at_sorting_position()");
    i = 0;
    while (i < N)
    {
        printf("arr[%d]:%d\n", i, arr[i]);
        i = i + 1;
    }

    exit(0);
}