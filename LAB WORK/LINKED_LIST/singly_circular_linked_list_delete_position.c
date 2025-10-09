#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (head == NULL) return NULL;

    if (pos == 1) {
        if (head->next == head) {
            free(head);
            return NULL;
        }
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        struct Node* toDelete = head;
        head = head->next;
        temp->next = head;
        free(toDelete);
        return head;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head) return head;

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
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
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* n1 = malloc(sizeof(struct Node));
    struct Node* n2 = malloc(sizeof(struct Node));
    struct Node* n3 = malloc(sizeof(struct Node));

    n1->data = 10; n2->data = 20; n3->data = 30;
    n1->next = n2; n2->next = n3; n3->next = n1;
    head = n1;

    display(head);
    head = deleteAtPosition(head, 2);
    display(head);
    return 0;
}
