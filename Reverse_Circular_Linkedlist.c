#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

void ReverseCircularLinkedlist(struct Node **head)
{
    struct Node *prevNode = NULL, *currentNode = *head, *nextNode;
    do
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    } while (currentNode != *head);
    (*head)->next = prevNode;
    *head = prevNode;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    int n1, n2, n3, n4;
    printf("Enter 1st element: ");
    scanf("%d", &n1);
    printf("Enter 2nd element: ");
    scanf("%d", &n2);
    printf("Enter 3rd element: ");
    scanf("%d", &n3);
    printf("Enter 4th element: ");
    scanf("%d", &n4);

    head->data = n1;
    head->next = second;
    second->data = n2;
    second->next = third;
    third->data = n3;
    third->next = fourth;
    fourth->data = n4;
    fourth->next = head;

    linkedlistTraversal(head);

    ReverseCircularLinkedlist(&head);
    printf("Reversed linkedlist:\n");
    linkedlistTraversal(head);
    return 0;
}