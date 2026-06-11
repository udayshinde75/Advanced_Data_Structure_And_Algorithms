#include "vector.h"
#include <stdio.h>

void test_vector(void);
void handle_error(status_t result);

// Assignment 1 : sum of all elements in an array
long long summation_of_elements(vector_int_t* p_vector);


int main(void)
{
    test_vector();
    return 0;
}

void test_vector(void)
{
    vector_int_t* p_vector = NULL;
    p_vector = create_vector();

    int choice;
    int data;
    status_t result;
    int continue_loop = 1;
    printf("***************Custom vector**************");

    push_back(p_vector, 546);
    push_back(p_vector, 87);
    push_back(p_vector, 2345);
    push_back(p_vector, 908);
    push_back(p_vector, 453);
    push_back(p_vector, 786);
    push_back(p_vector, 76565);
    push_back(p_vector, 897);    
    

    while (continue_loop)
    {
        printf("Select an Option:\n 1.push back\n 2.pop back\n 3.push front\n 4.pop front\n 5.show\n 6.exit\n 7.Add all elements\n");
        scanf("%d", &choice);

        if (choice > 0 && choice < 8)
        {
            if (choice == 1)
            {
                printf("Enter an integer : ");
                scanf("%d", &data);
                result = push_back(p_vector, data);
                if (result == 1)
                {
                    puts("Data pushed successfully\n");
                }
                else
                {
                    handle_error(result);
                }
            }
            else if (choice == 2)
            {
                data_t value;
                result = pop_back(p_vector, &value);
                if (result == 1)
                {
                    printf("Popped data : %d\n", value);
                }
                else
                {
                    handle_error(result);
                }
            }
            else if (choice == 3)
            {
                printf("Enter an integer : ");
                scanf("%d", &data);
                result = push_front(p_vector, data);
                if (result == 1)
                {
                    puts("Data pushed successfully\n");
                }
                else
                {
                    handle_error(result);
                }
            }
            else if (choice == 4)
            {
                data_t value;
                result = pop_front(p_vector, &value);
                if (result == 1)
                {
                    printf("Popped data : %d\n", value);
                }
                else
                {
                    handle_error(result);
                }
            }
            else if (choice == 5)
            {
                show(p_vector, "Vector data : \n");
            }
            else if (choice == 6)
            {
                continue_loop = 0;
            }
            else if (choice == 7)
            {
                printf("total sum : %lld\n", summation_of_elements(p_vector));
            }
            
        }
        else
        {
            printf("Please select a valid option\n");
        }
    }
    release_vector(&p_vector);
}

void handle_error(status_t result)
{
    switch (result)
    {
        case -1:
            puts("ERROR : Vector is empty\n");
            break;

        case -2:
            puts("ERROR : Pointer used is NULL pointer\n");
            break;

        case -3:
            puts("ERROR : Memory allocation is failed\n");
            break;

        case -4:
            puts("ERROR : Vector is full\n");
            break;

        default:
            break;
    }
}

long long summation_of_elements(vector_int_t* p_vector)
{
    if (p_vector->size == 0)
    {
        return 0;
    }

    long long total = 0;

    for (size_t i = 0; i < p_vector->size; ++i)
    {
        total += p_vector->p_data[i];
    }
    
    return total;
}