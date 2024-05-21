#include <stdio.h>
#include <string.h>
#include "output.h"

void sort_words(char words[][MAX_WORD_LENGTH], int num_words, char *sorttype) {
    // Bubble sort algorithm
    int i, j;
    char temp[MAX_WORD_LENGTH];

    if (strcmp(sorttype, "ASC") == 0) {
        for (i = 0; i < num_words - 1; i++) {
            for (j = 0; j < num_words - i - 1; j++) {
                if (strcmp(words[j], words[j + 1]) > 0) {
                    strcpy(temp, words[j]);
                    strcpy(words[j], words[j + 1]);
                    strcpy(words[j + 1], temp);
                }
            }
        }
    } else if (strcmp(sorttype, "DESC") == 0) {
        for (i = 0; i < num_words - 1; i++) {
            for (j = 0; j < num_words - i - 1; j++) {
                if (strcmp(words[j], words[j + 1]) < 0) {
                    strcpy(temp, words[j]);
                    strcpy(words[j], words[j + 1]);
                    strcpy(words[j + 1], temp);
                }
            }
        }
    } else {
        fprintf(stderr, "Invalid sort type.\n");
    }
}

void print_sorted_words(char words[][MAX_WORD_LENGTH], int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void print_usage(char *program_name) {
    fprintf(stderr, "Usage: %s <inputfile> <n> <wtype> [<sorttype>] [<skipword1> <skipword2> ...]\n", program_name);
}

