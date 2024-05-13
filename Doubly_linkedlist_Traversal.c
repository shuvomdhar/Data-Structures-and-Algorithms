#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *Doubly_Linkedlist_Traversal(struct Node *ptr)
{
    do
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    } while (ptr != NULL);
    printf("\n");
}

struct Node *Doubly_Linkedlist_Reverse_Traversal(struct Node *p)
{
    do
    {
        printf("%d  ", p->data);
        p = p->prev;
    } while (p != NULL);
    printf("\n");
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    int n1, n2, n3, n4;
    printf("Enter a value at 1st node: ");
    scanf("%d", &n1);
    printf("Enter a value at 2nd node: ");
    scanf("%d", &n2);
    printf("Enter a value at 3rd node: ");
    scanf("%d", &n3);
    printf("Enter a value at 4th node: ");
    scanf("%d", &n4);

    // 1st node
    head->prev = NULL;
    head->data = n1;
    head->next = second;
    // 2nd node
    second->prev = head;
    second->data = n2;
    second->next = third;
    // 3rd node
    third->prev = second;
    third->data = n3;
    third->next = fourth;
    // 4th node
    fourth->prev = third;
    fourth->data = n4;
    fourth->next = NULL;

    printf("The Doubly Linkedlist Traversal:-\n");
    Doubly_Linkedlist_Traversal(head);

    printf("The Doubly Linkedlist Reverse Traversal:-\n");
    struct Node *temp = fourth;
    Doubly_Linkedlist_Reverse_Traversal(temp);
    return 0;
}