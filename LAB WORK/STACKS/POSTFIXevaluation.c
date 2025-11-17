#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100
int stack[MAX], top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char post[MAX];
    int i, a, b;

    printf("Enter Postfix Expression: ");
    scanf("%s", post);

    for (i = 0; post[i] != '\0'; i++) {

        if (isdigit(post[i])) {
            push(post[i] - '0');
        }

        else {
            b = pop();
            a = pop();

            switch (post[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '^': push(pow(a, b)); break;
            }
        }
    }

    printf("Result = %d\n", stack[top]);
    return 0;
}