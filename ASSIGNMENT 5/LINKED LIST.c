#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning();
void insertAtEnd();
void insertAtPosition();
void deleteFirst();
void deleteLast();
void deleteAtPosition();
void display();
void createList();
void reverse();
void search();

int main() {
    int choice;

    while (1) {
        printf("\n--- SINGLY LINKED LIST (FULL OPERATIONS) ---\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete First Node\n");
        printf("6. Delete Last Node\n");
        printf("7. Delete from Position\n");
        printf("8. Display List\n");
        printf("9. Reverse List\n");
        printf("10. Search Node\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                insertAtBeginning();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                insertAtPosition();
                break;
            case 5:
                deleteFirst();
                break;
            case 6:
                deleteLast();
                break;
            case 7:
                deleteAtPosition();
                break;
            case 8:
                display();
                break;
            case 9:
                reverse();
                break;
            case 10:
                search();
                break;
            case 11:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void createList() {
    if (head != NULL) {
        printf("List already exists!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for first node: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    head = newNode;
    printf("List created with node: %d\n", newNode->data);
}

void insertAtBeginning() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data to insert at beginning: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", newNode->data);
}

void insertAtEnd() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data to insert at end: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        printf("Inserted %d as first node.\n", newNode->data);
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        printf("Inserted %d at the end.\n", newNode->data);
    }
}

void insertAtPosition() {
    int pos;
    printf("Enter position to insert at (1-based): ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Position must be >= 1!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for new node: ");
    scanf("%d", &newNode->data);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        printf("Inserted %d at position 1.\n", newNode->data);
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Position %d is out of bounds!\n", pos);
            free(newNode);
            return;
        }
    }

    if (temp == NULL) {
        printf("Position %d is out of bounds!\n", pos);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", newNode->data, pos);
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    printf("Deleted first node with data %d.\n", temp->data);
    free(temp);
}

void deleteLast() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted last node with data %d.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    printf("Deleted last node with data %d.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition() {
    int pos;
    printf("Enter position to delete from (1-based): ");
    scanf("%d", &pos);

    if (pos < 1 || head == NULL) {
        printf("Invalid position or empty list!\n");
        return;
    }

    if (pos == 1) {
        deleteFirst();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == NULL || temp->next == NULL) {
            printf("Position %d is out of bounds!\n", pos);
            return;
        }
    }

    if (temp->next == NULL) {
        printf("Position %d is out of bounds!\n", pos);
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("Deleted node at position %d with data %d.\n", pos, nodeToDelete->data);
    free(nodeToDelete);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


    printf("Value %d not found in the list.\n", value);
}
