#define MAX_WORD_LENGTH 15

// Tree of words
typedef struct word {
    char word [MAX_WORD_LENGTH];
    unsigned counter;
    struct word *upper;
    struct word *bellow;
}word_t;

word_t** search_word (word_t *tree, char word []);
int insert_word (word_t **tree, char line []);
word_t* create_word_element (char word []);
void print_words (word_t *list);