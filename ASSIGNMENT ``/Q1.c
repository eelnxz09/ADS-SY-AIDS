#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct node {
    int item;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *createNode(int item) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->item = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert node at left
struct node *insertAtLeft(struct node *root, int item) {
    root->left = createNode(item);
    return root->left;
}

// Function to insert node at right
struct node *insertAtRight(struct node *root, int item) {
    root->right = createNode(item);
    return root->right;
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->item);
    inorder(root->right);
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->item);
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct node *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->item);
}

// Main function
int main() {
    struct node *root = createNode(40);
    insertAtLeft(root, 20);
    insertAtRight(root, 60);
    insertAtLeft(root->left, 10);
    insertAtRight(root->left, 30);
    insertAtLeft(root->right, 50);
    insertAtRight(root->right, 70);

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPreorder traversal: ");
    preorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\n");
    return 0;
}
