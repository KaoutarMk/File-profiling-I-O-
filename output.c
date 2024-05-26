// output.c
#include <stdio.h>
#include "output.h"

void print_words(char **words, int wordcount) {
for (int i = 0; i < wordcount; i++) {
printf("%s", words[i]);
if ((i + 1) % 10 == 0) {
printf("\n");
} else {
printf(" ");
}
}
printf("\n");
}
