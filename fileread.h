// fileread.h
#ifndef FILEREAD_H
#define FILEREAD_H

#define MAX_WORD_LEN 100  // Define the maximum length of a word

int read_words(const char *filename, char **words, int maxwords, const char *wtype, char **skipwords, int skipcount);

#endif // FILEREAD_H
