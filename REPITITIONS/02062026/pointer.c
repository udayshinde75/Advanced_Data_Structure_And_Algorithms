#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Date
{
    int day;
    int month;
    int year;
};

void array_of_pointer_to_user_defined_type(void);

int main(void)
{
    array_of_pointer_to_user_defined_type();
    exit (EXIT_SUCCESS);
}

void array_of_pointer_to_user_defined_type(void)
{
    int N = 4;
    struct Date** ppDate_arr = NULL;
    int i = 0;

    ppDate_arr = (struct Date**)malloc(sizeof(struct Date*) * N);

    if (ppDate_arr == NULL)
    {
        fprintf(stderr, "fatal : malloc() : Out of memory\n");
        exit (EXIT_SUCCESS);
    }

    for (i = 0 ; i < N ; i++)
    {
        ppDate_arr[i] = (struct Date*)malloc(sizeof(struct Date));
        if (ppDate_arr[i] == NULL)
        {
            fprintf(stderr, "fatal : malloc() : Out of memory\n");
            exit (EXIT_SUCCESS);
        }
        memset(ppDate_arr[i], 0 , sizeof(struct Date));
    }
    
    for (i = 0; i < N ; i++)
    {
        ppDate_arr[i]->day = 15 + i;
        ppDate_arr[i]->month = 1 + i;
        ppDate_arr[i]->year = 2000 + i;
    }

    for ( i = 0; i < N; i++)
    {
        printf("Date (%d) : %d/%d/%d\n", i + 1, ppDate_arr[i]->day, ppDate_arr[i]->month,ppDate_arr[i]->year);
    }

    for ( i = 0; i < N; i++)
    {
        free(ppDate_arr[i]);
        ppDate_arr[i] = NULL;
    }

    free(ppDate_arr);
    ppDate_arr = NULL;
}