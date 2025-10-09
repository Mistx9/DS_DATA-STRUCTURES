#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) return NULL;

    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* tail = head->prev;
    struct Node* newTail = tail->prev;

    newTail->next = head;
    head->prev = newTail;
    free(tail);

    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode->prev = newNode;
        return newNode;
    }

    struct Node* tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;

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

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    display(head);
    head = deleteEnd(head);
    display(head);

    return 0;
}
