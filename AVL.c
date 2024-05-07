#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int getHeight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct node *CreateNode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int getBalaceFactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct node *RightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

struct node *LeftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return (CreateNode(key));
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalaceFactor(node);

    // Left Left Case
    if (bf > 1 && key < node->left->key)
    {
        return RightRotate(node);
    }

    // Right Right Case
    if (bf < -1 && key > node->right->key)
    {
        return LeftRotate(node);
    }

    // Left Right Case
    if (bf > 1 && key > node->left->key)
    {
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }

    // Right Left Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }
    return node;
}

void Preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        Preorder(root->left);
        Preorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    Preorder(root);
    return 0;
}