#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *left;
    int data;
    struct node *right;
    int thread;
};

struct node *createnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->thread = 1;
    return n;
}

void insertleft(struct node *p, int val)
{
    struct node *newnode = createnode(val);
    p->left = newnode;
    newnode->right = p;
    newnode->thread = 1;
}

void insertright(struct node *q, int val)
{
    struct node *newnode = createnode(val);
    struct node *tmp;
    tmp = q->right;
    q->right = newnode;
    newnode->right = tmp;
    q->thread = 0;
    newnode->thread = 1;
}

struct node *insert(struct node *root, int value)
{
    if(root == NULL)
    {
        root = createnode(value);
    }
    else if (value < root->data && root->left == NULL)
    {
        insertleft(root, value);
    }
    else if(value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->data && root->thread == 1)
    {
        insertright(root, value);
    }
    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void Inorder(struct node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    } 
    while (root != NULL)
    {
        printf("%d ",root->data);
        if (root->thread == 1)
        {
            root = root->right;
        }
        else
        {
            root = root->right;
            while (root->left != NULL)
            {
                root = root->left;
            }
        }
    }
}

int main()
{
    struct node *root = NULL;
    int element;
    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &element);
    for (int i = 0; i < element; i++)
    {
        int data;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("Inorder traversal of threaded binary tree is: ");
    Inorder(root);
    return 0;
}