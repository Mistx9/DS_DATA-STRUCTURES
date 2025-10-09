#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
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
    head->next->next = NULL;

    display(head);
    head = deleteEnd(head);
    display(head);

    return 0;
}
