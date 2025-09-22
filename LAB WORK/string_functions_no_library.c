#include <stdio.h>

// Find length of string
int stringLength(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

// Copy string
void stringCopy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Compare two strings
int stringCompare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

// Concatenate strings
void stringConcat(char str1[], char str2[]) {
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        i++;
    }
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

int main() {
    char str1[100], str2[100], copy[100];

    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    printf("Length of str1 = %d\n", stringLength(str1));
    printf("Length of str2 = %d\n", stringLength(str2));

    stringCopy(copy, str1);
    printf("Copy of str1: %s\n", copy);

    int cmp = stringCompare(str1, str2);
    if (cmp == 0)
        printf("Strings are equal\n");
    else if (cmp > 0)
        printf("str1 is greater\n");
    else
        printf("str2 is greater\n");

    stringConcat(str1, str2);
    printf("Concatenated string: %s\n", str1);

    return 0;
}
