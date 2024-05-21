#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "fileread.h"
#include "wordtype.h"

int read_words(char *input_file, int n, char *wtype, char words[][MAX_WORD_LENGTH], char *skip_words[], int num_skip_words) {
    FILE *file = fopen(input_file, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", input_file);
        return -1;
    }

    int num_words = 0;
    char word[MAX_WORD_LENGTH];
    int word_index = 0;
    char c;

    while ((c = fgetc(file)) != EOF && num_words < n) {
        if (is_word_char(c, wtype)) {
            if (word_index < MAX_WORD_LENGTH - 1) {
                word[word_index++] = c;
            }
        } else if (word_index > 0) {
            word[word_index] = '\0';
            int skip = 0;
            // Check if word should be skipped
            for (int i = 0; i < num_skip_words; i++) {
                if (strcmp(word, skip_words[i]) == 0) {
                    skip = 1;
                    break;
                }
            }
            if (!skip) {
                // Print the word
                printf("Word: %s\n", word);
                strcpy(words[num_words++], word);
            }
            word_index = 0;
        }
    }

    fclose(file);
    return num_words;
}

void parse_skip_words(int argc, char *argv[], char *skip_words[], int *num_skip_words) {
    for (int i = 5; i < argc; i++) {
        skip_words[*num_skip_words++] = argv[i];
    }
}

