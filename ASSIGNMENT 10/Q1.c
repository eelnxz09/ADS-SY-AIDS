#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void enqueue();
void dequeue();
void display();
//meow
int queue[SIZE];
int front = -1, rear = -1;

int main() {
    int ch;

    printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }

    } while (ch != 4);

    return 0;
}

void enqueue() {
    int value;
    if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front)) {
        printf("\nQueue is Full.\n");
    } else {
        printf("\nEnter value to insert: ");
        scanf("%d", &value);

        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        queue[rear] = value;

        printf("%d inserted into queue.\n", value);
    }
}

void dequeue() {
    if (front == -1) {
        printf("\nQueue is Empty.\n");
    } else {
        printf("\nDeleted %d from queue.\n", queue[front]);

        if (front == rear) {
            front = rear = -1;  // Queue becomes empty
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

void display() {
    if (front == -1) {
        printf("\nQueue is Empty!\n");
    } else {
        int i = front;
        printf("\nQueue elements are: ");

        while (1) {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }

        printf("\n");
    }
}
