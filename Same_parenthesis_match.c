#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
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

void Push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %c to the stack\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char Pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int parenthesisMatch(char *exp)
{
    // Create and initialize the stack
    struct stack *sp;
    sp->size = strlen(exp);
    printf("The length of the expression is %d\n", sp->size);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            if (isFull(sp))
            {
                return 0;
            }
            else
            {
                Push(sp, '(');
            }
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            else
            {
                Pop(sp);
            }
        }
    }
    if (isEmpty(sp))
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
    char *exp = "8*(9";
    // Check whether the stack is empty or not
    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is matching\n");
    }
    else
    {
        printf("The parenthesis is not matching\n");
    }
    return 0;
}