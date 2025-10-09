#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* deleteBeginning(struct Node* head) {
    if (head == NULL) return NULL;
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
    head = deleteBeginning(head); // empty check
    head = malloc(sizeof(struct Node));
    head->data = 10;
    head->next = head;
    head = deleteBeginning(head);

    display(head);
    return 0;
}
