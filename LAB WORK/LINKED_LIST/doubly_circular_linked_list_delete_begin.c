#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* deleteBeginning(struct Node* head) {
    if (head == NULL) return NULL;

    if (head->next == head) {
        free(head);
        return NULL;
    }

    struct Node* tail = head->prev;
    struct Node* newHead = head->next;

    tail->next = newHead;
    newHead->prev = tail;
    free(head);

    return newHead;
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

    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    display(head);
    head = deleteBeginning(head);
    display(head);

    return 0;
}
