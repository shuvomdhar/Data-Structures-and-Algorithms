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
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int Pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack has been created successfully\n");

    printf("Before pushing, Empty: %d\n", isEmpty(s));
    printf("Before pushing, Full: %d\n", isFull(s));

    // Pushing elements into the stack
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11;
    printf("Enter 1st value you want to push into the stack: ");
    scanf("%d", &n1);
    Push(s, n1);
    printf("Enter 2nd value you want to push into the stack: ");
    scanf("%d", &n2);
    Push(s, n2);
    printf("Enter 3rd value you want to push into the stack: ");
    scanf("%d", &n3);
    Push(s, n3);
    printf("Enter 4th value you want to push into the stack: ");
    scanf("%d", &n4);
    Push(s, n4);
    printf("Enter 5th value you want to push into the stack: ");
    scanf("%d", &n5);
    Push(s, n1);
    printf("Enter 6th value you want to push into the stack: ");
    scanf("%d", &n6);
    Push(s, n6);
    printf("Enter 7th value you want to push into the stack: ");
    scanf("%d", &n7);
    Push(s, n7);
    printf("Enter 8th value you want to push into the stack: ");
    scanf("%d", &n8);
    Push(s, n8);
    printf("Enter 9th value you want to push into the stack: ");
    scanf("%d", &n9);
    Push(s, n9);
    printf("Enter 10th value you want to push into the stack: ");
    scanf("%d", &n10);
    Push(s, n10);
    printf("Enter 11th value you want to push into the stack: ");
    scanf("%d", &n11);
    Push(s, n11);
    printf("After pushing, Full: %d\n", isFull(s));
    printf("After pushing, Empty: %d\n", isEmpty(s));

    // Popping elements from the stack
    printf("Popped %d from the stack\n", Pop(s));
    printf("Popped %d from the stack\n", Pop(s));
    printf("Popped %d from the stack\n", Pop(s));
    printf("Popped %d from the stack\n", Pop(s));
    printf("Popped %d from the stack\n", Pop(s));
    printf("Popped %d from the stack\n", Pop(s));
    printf("Popped %d from the stack\n", Pop(s));
    printf("Popped %d from the stack\n", Pop(s));
    printf("Popped %d from the stack\n", Pop(s));
    printf("Popped %d from the stack\n", Pop(s));
    printf("Popped %d from the stack\n", Pop(s));
    printf("After popping, Full: %d\n", isFull(s));
    printf("After popping, Empty: %d\n", isEmpty(s));

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