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

void Enqueue(int data)
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

int Dequeue()
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

int main()
{
    printf("Dequeueing %d\n", Dequeue());
    Enqueue(34);
    Enqueue(4);
    Enqueue(7);
    linkedListTraversal(f);
    printf("Dequeueing %d\n", Dequeue());
    printf("Dequeueing %d\n", Dequeue());
    return 0;
}