#include <ctype.h>
#include <string.h>
#include "wordtype.h"

int is_word_char(char c, char *wtype) {
    if (strcmp(wtype, "ALPHA") == 0) {
        return isalpha(c);
    } else if (strcmp(wtype, "ALPHANUM") == 0) {
        return isalnum(c);
    } else { // Assume ALL
        return !isspace(c) && c != ',';
    }
}
