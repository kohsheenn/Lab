#include <stdio.h>
#include <string.h>

int main() {
    char str[100]; // Buffer to store the input string
    int len, i;

    // Taking input from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin); // Reads input including spaces

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    len = strlen(str);

    // Printing the reversed string
    printf("Reversed string: ");
    for(i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");

    return 0;
}
