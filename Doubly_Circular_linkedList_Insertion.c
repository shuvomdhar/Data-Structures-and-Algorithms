#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void Doubly_Circular_linkedlistTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    ptr->next = head;
    head->prev = ptr;
    p->next = ptr;
    ptr->prev = p;
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
    while (p->next != head)
    {
        p = p->next;
    };
    p->next = ptr;
    ptr->prev = p;
    ptr->next = head;
    head->prev = ptr;
    return head;
}

struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    prevNode->next->prev = ptr;
    ptr->next = prevNode->next;
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
    printf("Enter data for 1st node: ");
    scanf("%d", &n1);
    printf("Enter data for 2nd node: ");
    scanf("%d", &n2);
    printf("Enter data for 3rd node: ");
    scanf("%d", &n3);
    printf("Enter data for 4th node: ");
    scanf("%d", &n4);

    // 1st node
    head->prev = fourth;
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
    fourth->next = head;

    printf("Doubly Circular Linkedlist Traversal is:-\n");
    Doubly_Circular_linkedlistTraversal(head);

    // Insert at Beginning
    printf("\nLinkedList Insert at Beginning\n");
    int value1;
    printf("Enter the value you want to insert: ");
    scanf("%d", &value1);
    head = insertAtFirst(head, value1);
    Doubly_Circular_linkedlistTraversal(head);

    // Insert in between
    printf("\nLinkedList Insert in between\n");
    int value2, index1;
    printf("Enter the value you want to insert: ");
    scanf("%d", &value2);
    printf("Enter the index: ");
    scanf("%d", &index1);
    head = insertAtIndex(head, value2, index1);
    Doubly_Circular_linkedlistTraversal(head);

    // Insert at end
    printf("\nLinkedList Insert at end\n");
    int value3;
    printf("Enter the value you want to insert: ");
    scanf("%d", &value3);
    head = insertAtEnd(head, value3);
    Doubly_Circular_linkedlistTraversal(head);

    // Insert after Node
    printf("\nLinkedList Insert after node\n");
    int value4;
    printf("Enter the value you want to insert: ");
    scanf("%d", &value4);
    head = insertAfterNode(head, second, value4);
    Doubly_Circular_linkedlistTraversal(head);
    return 0;
}