#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
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
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* a = malloc(sizeof(struct Node));
    struct Node* b = malloc(sizeof(struct Node));
    a->data = 10; b->data = 20;
    a->next = b; b->next = NULL; head = a;
    printf("Before Deletion:\n");
    display(head);
    head = deleteEnd(head);
    printf("After Deletion at End:\n");
    display(head);
    return 0;
}
