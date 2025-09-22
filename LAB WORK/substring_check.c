#include <stdio.h>

// Check if sub is substring of str
int isSubstring(char str[], char sub[]) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        j = 0;
        while (str[i + j] != '\0' && sub[j] != '\0' && str[i + j] == sub[j]) {
            j++;
        }
        if (sub[j] == '\0')
            return 1;  // found
    }
    return 0;  // not found
}

int main() {
    char str[100], sub[50];
    printf("Enter main string: ");
    gets(str);
    printf("Enter substring: ");
    gets(sub);

    if (isSubstring(str, sub))
        printf("Substring found!\n");
    else
        printf("Substring not found!\n");

    return 0;
}