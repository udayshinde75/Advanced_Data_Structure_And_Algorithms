#include <stdio.h>

void forever(void);
int main(void)
{
    forever();
    return (0);
}

void forever(void)
{
    printf("This function will call itself forever\n");
    forever();
}

// After some time, the program will crash with a stack overflow error, because the function will keep calling itself until the stack is full.  
// abnormal termination of process due to segmentation fault (core dumped)