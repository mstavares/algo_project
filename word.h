#ifndef WORD_H_
#define WORD_H
#define MAX_WORD_LENGTH 15

// Tree of words
typedef struct word {
    char word [MAX_WORD_LENGTH];
    unsigned counter;
    struct word *right;
    struct word *left;
}word_t;

void user_search (word_t *tree, char word []);
word_t* search_word (word_t *tree, char word []);
//word_t* insert_word (word_t **tree, char word []);

void insert_word (word_t **tree, char word []);

void insert_words (word_t **tree, vldt_word_t *list);



word_t* create_word (char word []);
void comma_and_dot (char word []);
int invalid_word (char word []);
void word_validation (vldt_word_t **list);
void print_words (word_t *list);

#endif

