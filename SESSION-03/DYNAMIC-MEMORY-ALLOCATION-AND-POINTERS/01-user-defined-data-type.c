#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct Date Date;

struct Date 
{
    // to optimize storage always try to put the largest data type at the end of the structure, in this case, int is the largest data type, so we put it at the end of the structure.
    int day; 
    int month; 
    int year; 
}; 

void user_defined_type(void); 

int main(void)
{
    user_defined_type(); 
    return (EXIT_SUCCESS); 
}

void user_defined_type(void)
{
    //  Step-I: Declare pointer and make it NULL 
    Date* pDate = NULL; 

    //  Step II: Allocate memory 
    pDate = (Date*)malloc(sizeof(Date)); 

    //  Step III: Memory allocation validation check 
    if(NULL == pDate)
    {
        fprintf(stderr, "fatal:malloc():out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    //  Step IV: 
    memset(pDate, 0, sizeof(Date)); 

    //  Step V: Read / Write 
    pDate->day = 16; 
    pDate->month = 5; 
    pDate->year = 2026; 

    int dd = pDate->day; 
    int mm = pDate->month; 
    int yy = pDate->year; 

    printf("%d / %d / %d\n", dd, mm, yy); 

    //  Step VI: 
    free(pDate);
    // if we do not make the pointer null here, we might get error sometime, if we dereference the pointer after free, it will lead to undefined behavior, so it is a good practice to set the pointer to null after freeing the memory. 
    pDate = NULL; 
}