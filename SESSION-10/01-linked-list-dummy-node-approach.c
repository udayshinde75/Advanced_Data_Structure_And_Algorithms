#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};


struct node* create_list(void);
struct node* get_node(int new_data);
void* xmalloc(size_t size_in_bytes);

void test_list();

int main(void)
{
    test_list();
    return 0;
}

void test_list(void)
{
    struct node* my_new_list = create_list();
    printf("my_new_list : %p\n", my_new_list);
    struct node* odd_number_list = create_list();
    printf("odd_number_list : %p\n", odd_number_list);
    struct node* prime_number_list = create_list();
    printf("prime_number_list : %p\n", prime_number_list);
}

struct node* create_list(void)
{
    struct node* head_node;
    head_node = get_node(0);
    return (head_node);
    return head_node;
}

struct node* get_node(int new_data)
{
    struct node* new_node;
    new_node = (struct node*)xmalloc(sizeof(struct node));
    return new_node;
}

void* xmalloc(size_t size_in_bytes)
{
    void* ptr = NULL;

    ptr = malloc(size_in_bytes);
    if (ptr == NULL)
    {
        exit (EXIT_FAILURE);
    }
    
    return ptr;
}