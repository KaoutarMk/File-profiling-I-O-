// wordtype.c
#include <ctype.h>
#include <string.h>
#include "wordtype.h"

int is_valid_word(const char *word, const char *wtype) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (strcmp(wtype, "ALPHA") == 0 && !isalpha(word[i])) {
            return 0;
        }
        if (strcmp(wtype, "ALPHANUM") == 0 && !isalnum(word[i])) {
            return 0;
        }
        if (strcmp(wtype, "ALL") == 0 && !isalnum(word[i]) && word[i] != '_') {
            return 0;
        }
    }
    return 1;
}

int compare_asc(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int compare_desc(const void *a, const void *b) {
    return strcmp(*(const char **)b, *(const char **)a);
}
