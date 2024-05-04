#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};

// Function to check whether the stack is empty or not
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function to check whether the stack is full or not
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 3;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    s->arr[0] = 7;
    s->top++;

    // Check whether the stack is empty or not
    if (isEmpty(s))
    {
        printf("The stack is Empty\n");
    }
    else
    {
        printf("The stack is not Empty\n");
    }

    // Check whether the stack is full or not
    if (isFull(s))
    {
        printf("The stack is Full\n");
    }
    else
    {
        printf("The stack is not Full\n");
    }
    return 0;
}