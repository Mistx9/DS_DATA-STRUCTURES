#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createSortedList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    for (int i = 0; i < n; i++) {
        newNode = malloc(sizeof(struct Node));
        printf("Enter data %d (in sorted order): ", i + 1);
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

struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node* result = NULL;
    if (list1->data <= list2->data) {
        result = list1;
        result->next = mergeLists(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeLists(list1, list2->next);
    }
    return result;
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
    struct Node* list1 = createSortedList(n1);

    printf("Enter number of nodes for List 2: ");
    scanf("%d", &n2);
    struct Node* list2 = createSortedList(n2);

    printf("\nList 1: "); display(list1);
    printf("List 2: "); display(list2);

    struct Node* merged = mergeLists(list1, list2);
    printf("\nMerged Sorted List: ");
    display(merged);
    return 0;
}
