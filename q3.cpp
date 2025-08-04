#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 10000
#define WORD_LEN 100

// Structure to store words and their frequency
struct WordFreq {
    char word[WORD_LEN];
    int count;
};

// Function to convert string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int main() {
    char paragraph[MAX_LEN];
    struct WordFreq words[MAX_WORDS];
    int wordCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Replace punctuation with spaces
    for (int i = 0; paragraph[i]; i++) {
        if (ispunct(paragraph[i])) {
            paragraph[i] = ' ';
        }
    }

    // Tokenize the paragraph into words
    char *token = strtok(paragraph, " \n\t\r");

    while (token != NULL) {
        toLowerCase(token);

        // Check if word already exists
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        // If not found, add as new word
        if (!found && wordCount < MAX_WORDS) {
            strcpy(words[wordCount].word, token);
            words[wordCount].count = 1;
            wordCount++;
        }

        token = strtok(NULL, " \n\t\r");
    }

    // Print word frequencies
    printf("\nWord Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
