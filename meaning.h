#ifndef MEANING_H_
#define MEANING_H_
#define MAX_WORD_LENGTH 15

typedef struct meaning {
    char description [MAX_WORD_LENGTH];
    tree_of_strings_t *data;
    unsigned absolute_frequency;
    float relative_frequency;
    struct meaning *prev;
    struct meaning *next;
}meaning_t;

meaning_t* create_meaning_element (char meaning []);
void create_meaning (meaning_t **meaning_list);
meaning_t* search_meaning (meaning_t *meaning_list, char meaning []);
void print_meanings (meaning_t *meaning_list);
void meaning_insert_delete (meaning_t **meaning_list, void (*insert_delete) ());

void meaning_insert (meaning_t **meaning_list);
void meaning_delete (meaning_t **meaning_list);
void delete_meaning_list (meaning_t **meaning_list);

void update2 (meaning_t *head_meanings, tree_of_strings_t *word);
void clear2 (tree_of_strings_t *tree_meanings);
void update (meaning_t *head_meanings, tree_of_strings_t *words);
void clear (meaning_t *head_meanings, tree_of_strings_t **ncategorized);
void without_categorization (tree_of_strings_t *words, tree_of_strings_t **ncategorized);

#endif
