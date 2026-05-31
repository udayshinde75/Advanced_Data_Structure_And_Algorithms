#include "vector.h"
#include <stdio.h>

void test_vector(void);

int main(void)
{
    test_vector();
    return 0;
}

void test_vector()
{
    vector_int_t* p_vector = NULL;

    p_vector = create_vector(); 

    int choice;
    int data;

    while (1 == 1)
    {
        printf("Want to enter data, yes-1, popback-2, no-0");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }

        if (choice == 1)
        {
            /* code */
        }

        if (choice == 2)
        {
            data_t value;
            pop_back(p_vector, &value);
            printf("Popped data : %d\n", value);
        }

        if (choice == 3)
        {
            printf("Enter an intger");
            scanf("%d", &data);
            push_front(p_vector, data);
        }
        
        
        

        printf("Enter an intger");
        scanf("%d", &data);
        push_back(p_vector, data);
    }

    show(p_vector, "Show data");
    release_vector(&p_vector);  
}