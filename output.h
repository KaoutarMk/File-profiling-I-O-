#ifndef OUTPUT_H
#define OUTPUT_H

#define MAX_WORD_LENGTH 100

void sort_words(char words[][MAX_WORD_LENGTH], int num_words, char *sorttype);
void print_sorted_words(char words[][MAX_WORD_LENGTH], int num_words);
void print_usage(char *program_name);

#endif /* OUTPUT_H */
