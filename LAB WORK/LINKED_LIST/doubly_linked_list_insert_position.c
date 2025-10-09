#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

struct Node* insertAtPosition(struct Node* head, int data, int pos) {
    struct Node* newNode = createNode(data);
    if (pos == 1) {
        newNode->next = head;
        if (head) head->prev = newNode;
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) return head;

    newNode->next = temp->next;
    if (temp->next) temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;

    return head;
}

void display(struct Node* head) {
    struct Node* temp = head;
    printf("\nList: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
