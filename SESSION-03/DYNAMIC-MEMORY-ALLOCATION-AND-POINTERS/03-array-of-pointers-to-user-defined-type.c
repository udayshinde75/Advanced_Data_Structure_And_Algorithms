#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Date
{
    /* data */
    int day;
    int month;
    int year;
};

void array_of_pointers_to_user_defined_type(void);

int main(void)
{
    array_of_pointers_to_user_defined_type();
    return (EXIT_SUCCESS);
}

void array_of_pointers_to_user_defined_type(void)
{
    int N = 4;
    struct Date** ppDate_arr = NULL;
    int i;

    ppDate_arr = (struct Date**)malloc(N*sizeof(struct Date*));

    if (ppDate_arr == NULL)
    {
        fprintf(stderr, "fatal:malloc():out of memory\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < N; i++)
    {
        ppDate_arr[i] = (struct Date*)malloc(sizeof(struct Date));

        if (ppDate_arr[i] == NULL)
        {
            fprintf(stderr, "fatal:malloc():out of memory\n");
            exit(EXIT_FAILURE);
        }

        memset(ppDate_arr[i], 0, sizeof(struct Date));
    }

    for (i = 0; i < N; i++)
    {
        ppDate_arr[i]->day = 16 + i;
        ppDate_arr[i]->month = 5 + i;
        ppDate_arr[i]->year = 2026 + i; 
    }

    for (i = 0; i < N; i++)
    {
        printf("Date %d: %d/%d/%d\n", i + 1, ppDate_arr[i]->day, ppDate_arr[i]->month, ppDate_arr[i]->year);
    }
    
    for (i = 0; i < N; i++)
    {
        free(ppDate_arr[i]);
        ppDate_arr[i] = NULL;
    }

    free(ppDate_arr);
    ppDate_arr = NULL;
}