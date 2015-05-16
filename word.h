#ifndef WORD_H_
#define WORD_H
#define MAX_WORD_LENGTH 15

// Tree of words
typedef struct word {
    char word [MAX_WORD_LENGTH];
    unsigned counter;
    struct word *upper;
    struct word *bellow;
}word_t;

word_t** search_word (word_t *tree, char word []);
void insert_words (word_t **tree, vldt_word_t *list);
word_t* create_word (char word []);
word_t* create_word (char word []);
void print_words (word_t *list);

#endif

