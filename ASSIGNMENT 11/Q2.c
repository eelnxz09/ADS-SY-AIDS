#include <stdio.h>
#include <stdlib.h>

struct node {
    int item;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* createNode(int item) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->item = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert at left
struct node* insertAtLeft(struct node* root, int item) {
    root->left = createNode(item);
    return root->left;
}

// Function to insert at right
struct node* insertAtRight(struct node* root, int item) {
    root->right = createNode(item);
    return root->right;
}

int main() {
    // Creating root node
    struct node* root = createNode(40);

    // Adding child nodes
    insertAtLeft(root, 20);
    insertAtRight(root, 60);
    insertAtLeft(root->left, 10);
    insertAtRight(root->left, 30);
    insertAtLeft(root->right, 50);
    insertAtRight(root->right, 70);

    // No traversal or printing — tree is just created
    return 0;
}
