#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int count = 0;
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
        count++;
    }
    printf("The length of the linkedlist is: %d",count);
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    int n1, n2, n3, n4;
    printf("Enter data for 1st node: ");
    scanf("%d", &n1);
    printf("Enter data for 2nd node: ");
    scanf("%d", &n2);
    printf("Enter data for 3rd node: ");
    scanf("%d", &n3);
    printf("Enter data for 4th node: ");
    scanf("%d", &n4);

    head->data = n1;
    head->next = second;
    second->data = n2;
    second->next = third;
    third->data = n3;
    third->next = fourth;
    fourth->data = n4;
    fourth->next = NULL;

    linkedListTraversal(head);
    return 0;
}