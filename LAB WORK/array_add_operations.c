#include <stdio.h>

int main() {
    int arr[100], n, x;
    printf("Enter size: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    // Add at end
    printf("Enter element to add at end: ");
    scanf("%d", &x);
    arr[n] = x;
    n++;
    printf("After adding at end:\n");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    // Add at beginning
    printf("Enter element to add at beginning: ");
    scanf("%d", &x);
    for(int i=n; i>0; i--) arr[i] = arr[i-1];
    arr[0] = x;
    n++;
    printf("After adding at beginning:\n");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    return 0;
}
