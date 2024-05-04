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

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    if (head != NULL)
    {
        (head)->prev = ptr;
    }
    head = ptr;
    return head;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    };
    p->next->prev = ptr;
    ptr->next = p->next;
    ptr->prev = p;
    p->next = ptr;
    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;
    return head;
}

struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next->prev = ptr;
    prevNode->next = ptr;
    ptr->prev = prevNode;
    return head;
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

    // Insert at beginning
    printf("\nLinkedList Insert at beginning\n");
    int value1;
    printf("Enter the value you want to insert the node: ");
    scanf("%d", &value1);
    head = insertAtFirst(head, value1);
    Doubly_Linkedlist_Traversal(head);

    // Insert at index
    printf("\nLinkedList Insert at index\n");
    int value2, index;
    printf("Enter the value you want to insert the node: ");
    scanf("%d", &value2);
    printf("Enter the index where you want to insert the node: ");
    scanf("%d", &index);
    head = insertAtIndex(head, value2, index);
    Doubly_Linkedlist_Traversal(head);

    // Insert at end
    printf("\nLinkedList Insert at end\n");
    int value3;
    printf("Enter the value you want to insert the node: ");
    scanf("%d", &value3);
    head = insertAtEnd(head, value3);
    Doubly_Linkedlist_Traversal(head);

    // Insert after Node
    printf("\nLinkedList Insert after node\n");
    int value4;
    printf("Enter the value you want to insert the node: ");
    scanf("%d", &value4);
    head = insertAfterNode(head, second, value4);
    Doubly_Linkedlist_Traversal(head);

    return 0;
}