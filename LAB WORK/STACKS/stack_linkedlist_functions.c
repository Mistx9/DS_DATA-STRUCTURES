#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push();
void pop();
void display();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
        printf("\n--- Stack Menu (Linked List Implementation) ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); return;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

void push() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow! Memory not available.\n");
        return;
    }

    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed to stack.\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("%d popped from stack.\n", top->data);
    top = top->next;
    free(temp);
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (top to bottom): ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
