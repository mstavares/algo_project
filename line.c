#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

// Split line on words
void line2word (line_t **list, char *line)
{
    int i = 0;
    char word [MAX_WORD_LENGTH];
    do {
        sscanf(line, "%s", word);
        //printf("%s\n", line);
        //printf("%s\n", word);
        i = strlen(line) - strlen(word);
        line += strlen(word)+1;       
    } while (i);
}