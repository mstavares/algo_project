#define MAX_LINE_LENGTH 60
#ifndef MAX_WORD_LENGTH
#define MAX_WORD_LENGTH 15
#endif

// List of lines
typedef struct line {
    char line [MAX_LINE_LENGTH];
    struct line *next;
}line_t;

void line2word (line_t **list, char *line);