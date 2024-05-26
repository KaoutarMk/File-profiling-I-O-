// fileread.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fileread.h"
#include "wordtype.h"

#define MAX_WORD_LEN 100

int is_skipword(char *word, char **skipwords, int skipcount) {
    for (int i = 0; i < skipcount; i++) {
        if (strcmp(word, skipwords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void normalize_word(char *word, const char *wtype) {
    char temp[MAX_WORD_LEN];
    int j = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        if ((strcmp(wtype, "ALPHA") == 0 && isalpha(word[i])) ||
            (strcmp(wtype, "ALPHANUM") == 0 && isalnum(word[i])) ||
            (strcmp(wtype, "ALL") == 0)) {
            temp[j++] = word[i];
        }
    }
    temp[j] = '\0';
    strcpy(word, temp);
}

int read_words(const char *filename, char **words, int maxwords, const char *wtype, char **skipwords, int skipcount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    char word[MAX_WORD_LEN];
    int count = 0;
    while (fscanf(file, "%s", word) != EOF && count < maxwords) {
        normalize_word(word, wtype);
        if (strlen(word) > 0 && !is_skipword(word, skipwords, skipcount) && is_valid_word(word, wtype)) {
            words[count] = strdup(word);
            count++;
        }
    }

    fclose(file);
    return count;
}
