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

void array_of_user_defined_type(void);

int main(void)
{
    array_of_user_defined_type();
    return (EXIT_SUCCESS);
}

void array_of_user_defined_type(void)
{
    struct Date* pDate_arr = NULL;
    int i;

    pDate_arr = (struct Date*)malloc(4*sizeof(struct Date));

    if (pDate_arr == NULL)
    {
        fprintf(stderr, "fatal:malloc():out of memory\n");
        exit(EXIT_FAILURE);
    }
    
    memset(pDate_arr, 0, 4*sizeof(struct Date));

    for (i = 0; i < 4; i++)
    {
        pDate_arr[i].day = 16 + i;
        pDate_arr[i].month = 5 + i;
        pDate_arr[i].year = 2026 + i;
    }

    for (i = 0; i < 4; i++)
    {
        printf("Date %d: %d/%d/%d\n", i + 1, pDate_arr[i].day, pDate_arr[i].month, pDate_arr[i].year);
    }

    free(pDate_arr);
    pDate_arr = NULL;
}
