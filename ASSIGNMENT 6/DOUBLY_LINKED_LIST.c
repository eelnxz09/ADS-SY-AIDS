#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
    struct node* prev;
};

struct node* start = NULL;

void create();
void display();
void insert_begin();
void insert_end();
void insert_position();

int main() {
    int choice;
    while (1) {
        printf("\n MENU ");
        printf("\n 1. CREATE");
        printf("\n 2. DISPLAY");
        printf("\n 3. INSERT_BEGIN");
        printf("\n 4. INSERT_END");
        printf("\n 5. INSERT_POSITION");
        printf("\n 6. EXIT");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert_begin(); break;
            case 4: insert_end(); break;
            case 5: insert_position(); break;
            case 6: exit(0);
            default: printf("\n Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void create() {
    struct node* temp;
    struct node* ptr;

    temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\n Enter data: ");
    scanf("%d", &temp->info);
    temp->next = NULL;
    temp->prev = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
        temp->prev = ptr;
    }
    printf("Node created and added at the end.\n");
}

void display() {
    struct node* ptr;
    if (start == NULL) {
        printf("\n Empty List\n");
        return;
    }
    ptr = start;
    printf("\n List elements are: ");
    while (ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert_begin() {
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("\n Enter data to insert at beginning: ");
    scanf("%d", &temp->info);
    temp->next = start;
    temp->prev = NULL;
    if (start != NULL)
        start->prev = temp;
    start = temp;
    printf("Node inserted at the beginning.\n");
}

void insert_end() {
    struct node* temp;
    struct node* ptr;

    temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("\n Enter data to insert at end: ");
    scanf("%d", &temp->info);
    temp->next = NULL;
    temp->prev = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
        temp->prev = ptr;
    }
    printf("Node inserted at the end.\n");
}

void insert_position() {
    struct node* temp;
    struct node* ptr;
    int pos, i;

    temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\n Enter data to insert: ");
    scanf("%d", &temp->info);
    temp->next = NULL;
    temp->prev = NULL;

    printf(" Enter position to insert node (starting from 1): ");
    scanf("%d", &pos);

    if (pos == 1) {
        temp->next = start;
        temp->prev = NULL;
        if (start != NULL)
            start->prev = temp;
        start = temp;
        printf("Node inserted at position 1.\n");
        return;
    }

    ptr = start;
    for (i = 1; i < pos - 1 && ptr != NULL; i++)
        ptr = ptr->next;

    if (ptr == NULL) {
        printf("Position out of bounds.\n");
        free(temp);
    } else {
        temp->next = ptr->next;
        temp->prev = ptr;
        if (ptr->next != NULL)
            ptr->next->prev = temp;
        ptr->next = temp;
        printf("Node inserted at position %d.\n", pos);
    }
}


