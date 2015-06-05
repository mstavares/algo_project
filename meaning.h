#ifndef MEANING_H_
#define MEANING_H_
#define MAX_WORD_LENGTH 15

typedef struct meaning {
    char description [MAX_WORD_LENGTH];
    tree_of_strings_t *data;
    unsigned counter;
    struct meaning *prev;
    struct meaning *next;
}meaning_t;

meaning_t* create_meaning_element (char meaning []);
void create_meaning (meaning_t **meaning_list);
meaning_t* search_meaning (meaning_t *meaning_list, char meaning []);
void insert_remove_meaning_word (meaning_t **meaning_list, void (*insert_remove) ());
void print_meanings (meaning_t *meaning_list);
void insert_meaning_word (meaning_t **meaning);
void meaning_search_delete (tree_of_strings_t **tree);

#endif