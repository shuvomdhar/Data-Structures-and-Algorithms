#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of the linkedlist:-\n");
    while (ptr != NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

void EnqueuefromFront(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    if (f == NULL)
    {
        f = r = n;
    }
    else
    {
        n->next = f;
        f = n;
        printf("The front data is %d\n", f->data);
    }
}

void EnqueueatEnd(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        n->data = data;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int DequeuefromFront()
{
    struct Node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        f = f->next;
        int val = ptr->data;
        free(ptr);
        return val;
    }
}

int DequeuefromEnd(struct Node *r)
{
    struct Node *ptr = f->next;
    if (f == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct Node *p = f;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            p = p->next;
        }
        r = p;
        int val = ptr->data;
        r->next = NULL;
        free(ptr);
        return val;
    }
}

int main()
{
    EnqueueatEnd(34);
    EnqueueatEnd(4);
    EnqueueatEnd(7);
    EnqueueatEnd(10);
    EnqueueatEnd(17);
    EnqueueatEnd(23);
    linkedListTraversal(f);
    printf("Dequeueing %d\n", DequeuefromFront());
    printf("Dequeueing %d\n", DequeuefromFront());
    EnqueuefromFront(40);
    EnqueuefromFront(37);
    EnqueuefromFront(50);
    linkedListTraversal(f);
    printf("Dequeueing %d\n", DequeuefromEnd(r));
    printf("Dequeueing %d\n", DequeuefromEnd(r));
    return 0;
}