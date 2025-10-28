#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue();
void dequeue();
void display();

int main() {
    int ch;
    do {
        printf("\n 1. ENQUEUE\n 2. DEQUEUE\n 3. DISPLAY\n 4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("\nInvalid choice!\n");
        }
    } while (ch != 4);
    return 0;
}

void enqueue() {
    int element;
    if (rear == SIZE - 1)
        printf("\nQueue is Full.\n");
    else {
        printf("\nEnter value to insert: ");
        scanf("%d", &element);
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = element;
        printf("Item inserted into queue.\n");
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("\nQueue is Empty.\n");
    else {
        printf("\nDeleted element: %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear)
        printf("\nQueue is Empty.\n");
    else {
        printf("\nQueue elements are:\n");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
