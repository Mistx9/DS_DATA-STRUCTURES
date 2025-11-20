#include <stdio.h>

int main() {
    int a[100], n, key, i, low, high, mid;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter key: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == key) {
            printf("Found at index %d\n", mid);
            return 0;
        }

        if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    printf("Not found\n");
    return 0;
}
