#ifndef LINE_H_
#define LINE_H_
#define MAX_WORD_LENGTH 15
#define MAX_LINE_LENGTH 60

// List of lines
typedef struct line {
    char line [MAX_LINE_LENGTH];
    struct line *next;
}line_t;

// List of validated words
typedef struct vldt_word {
    char word [MAX_WORD_LENGTH];
    struct vldt_word *next;
    struct vldt_word *prev;
}vldt_word_t;

void line2word (line_t *list, vldt_word_t **v_head);
vldt_word_t* create_vldt_word (char word[]);
void insert_line_element (line_t **list, char line []);
void print_text (line_t *list, char pause);
void imprime (vldt_word_t *list);

#endif