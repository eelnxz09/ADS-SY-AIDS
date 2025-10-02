#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAfterPosition(struct Node* head, int pos, int data) {
    struct Node* temp = head;
    int i = 1;
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position not found\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void createNewList(struct Node** head) {
    struct Node* temp = *head;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    printf("New list created!\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert after position\n4. Display\n5. Exit\n6. Create new list\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data: ");
                scanf("%d", &data);
                insertAfterPosition(head, pos, data);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            case 6:
                createNewList(&head);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

