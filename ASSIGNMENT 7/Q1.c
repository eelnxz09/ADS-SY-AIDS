#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push();
void pop();
void display();

int main() {
    int choice;
    printf("\n MENU:");
    printf("\n 1. PUSH");
    printf("\n 2. POP");
    printf("\n 3. DISPLAY");
    printf("\n 4. EXIT");

    do {
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("\n Invalid choice!");
        }
    } while (choice != 4);
    return 0;
}

void push() {
    int element;
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter value: ");
        scanf("%d", &element);
        top++;
        stack[top] = element;
        printf("Item pushed\n");
    }
}

void pop() {
    int item;
    if (top == -1)
        printf("Stack Underflow\n");
    else {
        item = stack[top];
        top--;
        printf("Deleted element is %d\n", item);
    }
}

void display() {
    if (top == -1)
        printf("Stack Empty\n");
    else {
        printf("Stack elements are: ");
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
}
