#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    };
    printf("\n");
}


int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *Push(struct Node *top, int value)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = value;
        n->next = top;
        top = n;
        return top;
    }
}

int Pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = *top;
        *top = (*top)->next;
        int data = n->data;
        free(n);
        return data;
    }
}

int Peek(int pos)
{
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n1, n2, n3, n4;
    printf("Enter 1st element: ");
    scanf("%d", &n1);
    printf("Enter 2nd element: ");
    scanf("%d", &n2);
    printf("Enter 3rd element: ");
    scanf("%d", &n3);
    printf("Enter 4th element: ");
    scanf("%d", &n4);
    printf("\n");

    // Pushing element into the stack
    top = Push(top, n1);
    top = Push(top, n2);
    top = Push(top, n3);
    top = Push(top, n4);
    linkedListTraversal(top);

    for (int i = 1; i <= 4; i++)
    {
        printf("Value at position %d is: %d\n", i, Peek(i));
    }
    printf("\n");

    // Popping element from the stack
    printf("Popped element is %d\n", Pop(&top));
    printf("Popped element is %d\n", Pop(&top));
    printf("Popped element is %d\n", Pop(&top));
    printf("Popped element is %d\n", Pop(&top));
    printf("Popped element is %d\n", Pop(&top));
    return 0;
}