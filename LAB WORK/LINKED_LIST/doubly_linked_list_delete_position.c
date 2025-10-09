#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (head == NULL) return NULL;
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        free(temp);
        return head;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;

    if (temp == NULL) return head;

    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
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

    head = malloc(sizeof(struct Node));
    head->data = 10; head->prev = NULL;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 20; head->next->prev = head;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 30; head->next->next->prev = head->next;
    head->next->next->next = NULL;

    display(head);
    head = deleteAtPosition(head, 2);
    display(head);

    return 0;
}
