#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* insertAtPosition(struct Node* head, int data, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode->prev = newNode;
        return newNode;
    }

    if (pos == 1) {
        struct Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = head->prev = newNode;
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    struct Node* nextNode = temp->next;
    newNode->next = nextNode;
    newNode->prev = temp;
    temp->next = nextNode->prev = newNode;

    return head;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node* temp = head;
    printf("\nList: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    struct Node* head = NULL;

    head = insertAtPosition(head, 10, 1);
    head = insertAtPosition(head, 20, 2);
    head = insertAtPosition(head, 30, 3);
    head = insertAtPosition(head, 25, 3);

    display(head);
    return 0;
}
