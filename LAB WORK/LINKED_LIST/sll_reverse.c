#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL, *temp;
    head = malloc(sizeof(struct Node));
    temp = head;
    for (int i = 1; i <= 4; i++) {
        temp->data = i * 10;
        if (i < 4) temp->next = malloc(sizeof(struct Node));
        else temp->next = NULL;
        temp = temp->next;
    }

    printf("Original List:\n");
    display(head);
    head = reverseList(head);
    printf("Reversed List:\n");
    display(head);
    return 0;
}
