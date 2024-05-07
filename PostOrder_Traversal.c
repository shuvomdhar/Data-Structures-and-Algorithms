#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Define the structure of a stack
struct stack
{
    int top;
    int size;
    struct node **arr;
};

// Initialize the stack
void initStack(struct stack **s)
{
    (*s)->top = -1;
    (*s)->size = 10;
    (*s)->arr = (struct node **)malloc((*s)->size * sizeof(struct node *));
}

// Check if the stack is full
int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Push an element to the stack
void push(struct stack *s, struct node *n)
{
    if (isFull(s))
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = n;
    }
}

// Check if the stack is empty
int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Pop an element from the stack
struct node *pop(struct stack *s)
{
    if (isEmpty(s))
    {
        return NULL;
    }
    else
    {
        return s->arr[s->top--];
    }
}

struct node *peek(struct stack *s)
{
    if (isEmpty(s))
    {
        return NULL;
    }
    else
    {
        return s->arr[s->top];
    }
}

// Create a new binary tree node
struct node *newNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node *BST(struct node *root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }
    else if (data < root->data)
    {
        root->left = BST(root->left, data);
    }
    else
    {
        root->right = BST(root->right, data);
    }
    return root;
}

void Postorder(struct node *root)
{
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));
    initStack(&st);
    while (1)
    {
        while (root != NULL)
        {
            if (root->right != NULL)
            {
                push(st, root->right);
            }
            push(st, root);
            root = root->left;
        }
        if (isEmpty(st))
        {
            break;
        }
        else
        {
            root = pop(st);
            if (root->right == peek(st))
            {
                struct node *tmp = pop(st);
                push(st, root);
                root = tmp;
            }
            else
            {
                printf("%d ", root->data);
                root = NULL;
            }
        }
    }
}

int main()
{
    struct node *root = NULL;
    int element;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &element);
    for (int i = 0; i < element; i++)
    {
        int data;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        root = BST(root, data);
    }
    printf("Post-order traversal of the BST: ");
    Postorder(root);
    return 0;
}