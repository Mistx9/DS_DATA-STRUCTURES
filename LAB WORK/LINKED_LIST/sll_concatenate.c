#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    for (int i = 0; i < n; i++) {
        newNode = malloc(sizeof(struct Node));
        printf("Enter data %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;
        temp = newNode;
    }
    return head;
}

struct Node* concatenate(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    struct Node* temp = list1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = list2;
    return list1;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int n1, n2;
    printf("Enter number of nodes for List 1: ");
    scanf("%d", &n1);
    struct Node* list1 = createList(n1);

    printf("Enter number of nodes for List 2: ");
    scanf("%d", &n2);
    struct Node* list2 = createList(n2);

    printf("\nList 1: "); display(list1);
    printf("List 2: "); display(list2);

    struct Node* combined = concatenate(list1, list2);
    printf("\nConcatenated List: ");
    display(combined);
    return 0;
}
