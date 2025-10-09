#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List empty!\n");
        return NULL;
    }
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position not found!\n");
        return head;
    }

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
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
    struct Node *head = NULL, *temp;
    head = malloc(sizeof(struct Node));
    temp = head;
    for (int i = 1; i <= 4; i++) {
        temp->data = i * 10;
        if (i < 4) temp->next = malloc(sizeof(struct Node));
        else temp->next = NULL;
        temp = temp->next;
    }
    printf("Before Deletion:\n");
    display(head);
    head = deleteAtPosition(head, 3);
    printf("After Deletion at position 3:\n");
    display(head);
    return 0;
}
