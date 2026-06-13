#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test();

int main(void)
{
    test();
    return 0;
}

void test()
{
    int nr, dr;

    printf("Enter numerator : ");
    scanf("%d", &nr);

    printf("Enter denominator : ");
    scanf("%d", &dr);

    assert(dr != 0);

    int quotient = nr / dr;
}