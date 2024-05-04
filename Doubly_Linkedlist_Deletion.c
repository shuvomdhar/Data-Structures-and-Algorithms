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

struct Node *deletionAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        free(ptr);
    }
    struct Node *ptr = head;
    head = head->next;
    head->next->prev = NULL;
    free(ptr);
    return head;
}

struct Node *deletionInBetween(struct Node *head, int index)
{
    struct Node *ptr = head;
    struct Node *p = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = p->next;
    p->next->prev = ptr;
    free(p);
    return head;
}

struct Node *deletionAtEnd(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *p = head->next;
    while (p->next != NULL)
    {
        p = p->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(p);
    return head;
}

struct Node *deletionAtValueNode(struct Node *head, int value)
{
    struct Node *ptr = head;
    struct Node *p = head->next;
    while (p->data != value && p->next != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }
    if (p->data == value)
    {
        ptr->next = p->next;
        p->next->prev = ptr;
        free(p);
    }
    else
    {
        printf("%d is not found in the linkedlist", value);
    }
    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *sixth = (struct Node *)malloc(sizeof(struct Node));

    int n1, n2, n3, n4, n5, n6;
    printf("Enter 1st data: ");
    scanf("%d", &n1);
    printf("Enter 2nd data: ");
    scanf("%d", &n2);
    printf("Enter 3rd data: ");
    scanf("%d", &n3);
    printf("Enter 4th data: ");
    scanf("%d", &n4);
    printf("Enter 5th data: ");
    scanf("%d", &n5);
    printf("Enter 6th data: ");
    scanf("%d", &n6);

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
    fourth->next = fifth;
    // 5th node
    fifth->prev = fourth;
    fifth->data = n5;
    fifth->next = sixth;
    // 6th node
    sixth->prev = fifth;
    sixth->data = n6;
    sixth->next = NULL;
    printf("LinkedList before any operation\n");
    Doubly_Linkedlist_Traversal(head);

    // Deletion at First
    printf("\nLinkedList Deletion at beginning\n");
    head = deletionAtFirst(head);
    Doubly_Linkedlist_Traversal(head);

    // Deletion in Between
    printf("\nLinkedList Deletion in between\n");
    int index;
    printf("Enter the index of the linkedlist that you want to delete: ");
    scanf("%d", &index);
    head = deletionInBetween(head, index);
    Doubly_Linkedlist_Traversal(head);

    // Deletion at End
    printf("\nLinkedList Deletion at end\n");
    head = deletionAtEnd(head);
    Doubly_Linkedlist_Traversal(head);

    // Delete a node with given value
    printf("\nLinkedList Deletion of the node with given value\n");
    int value;
    printf("Enter the value you want to delete: ");
    scanf("%d", &value);
    head = deletionAtValueNode(head, value);
    Doubly_Linkedlist_Traversal(head);
    return 0;
}