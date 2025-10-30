#include <stdio.h>
#include <stdlib.h>

struct node {
    int item;
    struct node *left;
    struct node *right;
};

struct node *createNode (int item)
{
    struct node *newNode = (struct node *) malloc (sizeof (struct node));
    newNode -> item = item;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

struct node *insertAtLeft (struct node *root, int item)
{
    root -> left = createNode (item);
    return root -> left;
}

struct node *insertAtRight (
struct node *root, int item)
{
    root -> right = createNode (item);
    return root -> right;
}

void inorder (struct node *root)
{
    if (root == NULL)
        return;
    inorder (root -> left);
    printf ("%d", root -> item);
    inorder (root -> right);
}

void preorder (struct node *root)
{
    if (root == NULL)
        return;
    printf ("%d", root -> item);
    preorder (root -> left);
    preorder (root -> right);
}

void postorder (struct node *root)
{
    if (root == NULL)
        return;
    postorder (root -> left);
    postorder (root -> right);
    printf ("%d", root -> item);
}

int main()
{
    struct node *root = createNode (40);
    insertAtLeft (root, 20);
    insertAtRight (root, 60);
    insertAtLeft (root -> left, 10);
    insertAtRight (root -> left, 30);
    insertAtLeft (root -> right, 50);
    insertAtRight (root -> right, 70);
}
