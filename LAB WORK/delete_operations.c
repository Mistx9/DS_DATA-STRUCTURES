#include <stdio.h>

int main() {
    int arr[100], n;
    printf("Enter size: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    // Delete last
    n--;
    printf("After deleting last element:\n");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    // Delete first
    for(int i=0; i<n-1; i++) arr[i] = arr[i+1];
    n--;
    printf("After deleting first element:\n");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    return 0;
}
