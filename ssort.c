#include <stdio.h>
#include <stdlib.h>
#include "fileread.h"
#include "wordtype.h"
#include "output.h"

int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage(argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    int n = atoi(argv[2]);
    char *wtype = argv[3];
    char *sorttype = "ASC"; // Default sort type is ascending
    char *skip_words[MAX_WORDS] = {0};
    int num_skip_words = 0;

    // Check if sort type is provided
    if (argc >= 5) {
        sorttype = argv[4];
    }

    // Parse skip words
    parse_skip_words(argc, argv, skip_words, &num_skip_words);

    // Read words from file
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int num_words = read_words(input_file, n, wtype, words, skip_words, num_skip_words);
    if (num_words == -1) {
        fprintf(stderr, "Error reading words from file.\n");
        return 2;
    }

    // Sort the array
    sort_words(words, num_words, sorttype);

    // Print sorted array
    print_sorted_words(words, num_words);

    return 0;
}

