#ifndef FILEREAD_H
#define FILEREAD_H

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

int read_words(char *input_file, int n, char *wtype, char words[][MAX_WORD_LENGTH], char *skip_words[], int num_skip_words);
void parse_skip_words(int argc, char *argv[], char *skip_words[], int *num_skip_words);

#endif /* FILEREAD_H */
