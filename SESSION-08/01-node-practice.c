#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node* next;
} node;

void build_linked_list(void);


int main(void)
{
    build_linked_list();
    return 0;
}

void build_linked_list(void)
{
    node N1;
    node N2;
    node N3;
    node N4;

    N1.data = 100;
    N1.next = &N2;
    
    N2.data = 200;
    N2.next = &N3;

    N3.data = 300;
    N3.next = &N4;

    N4.data = 400;
    N4.next = NULL;

    node* run = NULL;

    run = &N1;

    while (run != NULL)
    {
        printf("data:run->data:%d\n", run->data);
        run = run->next;
    }

    node* pNode = &N1;

    printf("pNode->data : %d\n", pNode->data);
    printf("pNode->next->data : %d\n", pNode->next->data);
    printf("pNode->next->next->data : %d\n", pNode->next->next->data);
    printf("pNode->next->next->next->data : %d\n", pNode->next->next->next->data);

        
}