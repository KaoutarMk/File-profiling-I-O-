// ssort.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileread.h"
#include "wordtype.h"
#include "output.h"

#define MAX_WORDS 1000

void usage(const char *progname) {
    fprintf(stderr, "Usage: %s <inputfile> <n> <wtype> <sorttype> [<skipword1> <skipword2> ...]\n", progname);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        usage(argv[0]);
    }

    const char *inputfile = argv[1];
    int n = atoi(argv[2]);
    if (n <= 0) {
        fprintf(stderr, "Error: Invalid array size.\n");
        exit(1);
    }

    const char *wtype = argv[3];
    if (strcmp(wtype, "ALPHA") != 0 && strcmp(wtype, "ALPHANUM") != 0 && strcmp(wtype, "ALL") != 0) {
        fprintf(stderr, "Error: Invalid word type.\n");
        exit(2);
    }

    const char *sorttype = (argc > 4 && (strcmp(argv[4], "ASC") == 0 || strcmp(argv[4], "DESC") == 0)) ? argv[4] : "ASC";

    char *skipwords[MAX_WORDS];
    int skipcount = 0;
    for (int i = (strcmp(sorttype, "ASC") == 0 || strcmp(sorttype, "DESC") == 0) ? 5 : 4; i < argc; i++) {
        skipwords[skipcount++] = argv[i];
    }

    char **words = malloc(n * sizeof(char *));
    if (!words) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(1);
    }

    int wordcount = read_words(inputfile, words, n, wtype, skipwords, skipcount);
    if (wordcount < 0) {
        fprintf(stderr, "Error: Failed to read words from file.\n");
        free(words);
        exit(1);
    }

    if (strcmp(sorttype, "DESC") == 0) {
        qsort(words, wordcount, sizeof(char *), compare_desc);
    } else {
        qsort(words, wordcount, sizeof(char *), compare_asc);
    }

    print_words(words, wordcount);

    for (int i = 0; i < wordcount; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}
