#include <stdio.h>

void fx(int n);

void gx(int n) {
    if (n > 0) {
        printf("gx: %d\n", n);
        fx(n - 1);   // gx calls fx
    }
}

void fx(int n) {
    if (n > 0) {
        printf("fx: %d\n", n);
        gx(n - 1);   // fx calls gx
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    fx(n);
    return 0;
}
