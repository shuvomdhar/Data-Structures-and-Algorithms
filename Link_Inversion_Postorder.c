#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
struct node
{
    int data, tag;
    struct node *left;
    struct node *right;
};

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

void left_decend(struct node **pres, struct node **prev)
{
    (*pres)->tag = 0;
    struct node *temp = (*pres)->left;
    (*pres)->left = (*prev);
    (*prev) = (*pres);
    (*pres) = temp;
}

void right_decend(struct node **pres, struct node **prev)
{
    (*pres)->tag = 1;
    struct node *temp = (*pres)->right;
    (*pres)->right = (*prev);
    (*prev) = (*pres);
    (*pres) = temp;
}

void left_ascend(struct node **pres, struct node **prev)
{
    if ((*prev) != NULL && (*prev)->tag == 0)
    {
        struct node *temp = (*prev)->left;
        (*prev)->left = (*pres);
        (*pres) = (*prev);
        (*prev) = temp;
    }
}

void right_ascend(struct node **pres, struct node **prev)
{
    if ((*prev) != NULL && (*prev)->tag == 1)
    {
        (*prev)->tag = 0;
        struct node *temp = (*prev)->right;
        (*prev)->right = (*pres);
        (*pres) = (*prev);
        (*prev) = temp;
    }
}

void link_postorder(struct node *rt)
{
    struct node *prev = NULL;
    struct node *pres = rt;
    int flag = 0;
    while (prev != NULL || flag != 2)
    {
        if (pres->left != NULL && flag == 0)
        {
            left_decend(&pres, &prev);
            flag = 0;
        }
        else
        {
            if (flag == 2 || (pres->left == NULL && pres->right == NULL) || (pres->right == NULL && flag == 1))
            {
                printf("%d ", pres->data);
            }
            if (prev == NULL && pres->right == NULL)
            {
                flag = 2;
            }
            else if (pres->right != NULL && flag != 2)
            {
                right_decend(&pres, &prev);
                flag = 0;
            }
            else if (prev != NULL && prev->tag == 0)
            {
                left_ascend(&pres, &prev);
                flag = 1;
            }
            else if (prev != NULL && prev->tag == 1)
            {
                right_ascend(&pres, &prev);
                flag = 2;
                if (prev == NULL)
                {
                    printf("%d ",pres->data);
                }
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
    link_postorder(root);
    return 0;
}