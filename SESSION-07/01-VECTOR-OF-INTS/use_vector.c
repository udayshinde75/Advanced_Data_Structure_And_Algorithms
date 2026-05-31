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
        printf("Want to enter data, yes-1, popback-2, pushfront-3, popfront-4 no-0 : ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }

        if (choice == 1)
        {
            printf("Enter an intger : ");
            scanf("%d", &data);
            push_back(p_vector, data);
        }

        if (choice == 2)
        {
            data_t value;
            if (pop_back(p_vector, &value) != -1)
            {
                printf("Popped data : %d\n", value);
            }
            else
            {
                printf("Vector is empty\n");
            }
        }

        if (choice == 3)
        {
            printf("Enter an intger to push front : ");
            scanf("%d", &data);
            push_front(p_vector, data);
        }

        if (choice == 4)
        {
            data_t value;
            if (pop_front(p_vector, &value) != -1)
            {
                printf("Popped data : %d\n", value);
            }
            else
            {
                printf("Vector is empty\n");
            }
        }

        printf("Size of vector : %d\n", p_vector->size);
    }

    show(p_vector, "Show data");
    release_vector(&p_vector);  
}