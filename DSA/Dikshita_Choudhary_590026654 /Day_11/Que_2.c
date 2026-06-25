#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[1000];

    // Read the input string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Store all vowels in a string
    char vowels[] = "aeiou";

    // Traverse each character
    for (int i = 0; str[i] != '\0'; i++) {
        // Convert character to lowercase
        char ch = tolower(str[i]);

        // Check if it is a lowercase letter and not a vowel
        if (ch >= 'a' && ch <= 'z' && strchr(vowels, ch) == NULL) {
            printf(".%c", ch);
        }
    }

    return 0;
}
