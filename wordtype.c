// wordtype.c
#include <ctype.h>
#include <string.h>
#include "wordtype.h"

int is_valid_word(const char *word, const char *wtype) {
    if (strcmp(wtype, "ALPHA") == 0) {
        for (int i = 0; word[i] != '\0'; i++) {
            if (!isalpha(word[i])) {
                return 0;
            }
        }
        return 1;
    } else if (strcmp(wtype, "ALPHANUM") == 0) {
        for (int i = 0; word[i] != '\0'; i++) {
            if (!isalnum(word[i])) {
                return 0;
            }
        }
        return 1;
    } else if (strcmp(wtype, "ALL") == 0) {
        return 1;
    }
    return 0;
}

int compare_asc(const void *a, const void *b) {
    const char *word_a = *(const char **)a;
    const char *word_b = *(const char **)b;
    return strcmp(word_a, word_b);
}

int compare_desc(const void *a, const void *b) {
    const char *word_a = *(const char **)a;
    const char *word_b = *(const char **)b;
    return strcmp(word_b, word_a);
}
