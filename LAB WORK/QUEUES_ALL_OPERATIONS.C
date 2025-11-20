#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int q[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == 0 && rear == MAX-1) || (rear == (front-1) % (MAX-1));
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
        q[rear] = x;
        return;
    }
    rear = (rear + 1) % MAX;
    q[rear] = x;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = q[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return val;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    return q[front];
}

int size() {
    if (isEmpty()) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", q[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, x, val;
    while (1) {
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Size\n5.Display\n6.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                val = dequeue();
                if (val != -1) printf("%d\n", val);
                break;
            case 3:
                val = peek();
                if (val != -1) printf("%d\n", val);
                break;
            case 4:
                printf("%d\n", size());
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid\n");
        }
    }
    return 0;
}
