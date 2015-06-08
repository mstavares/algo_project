#ifndef TREE_OF_STRINGS_H_
#define TREE_OF_STRINGS_H_
#define MAX_WORD_LENGTH 15
#define TRUE 1
#define FALSE 0

// Tree of words
typedef struct tree_of_strings{
    char string [MAX_WORD_LENGTH];
    unsigned counter;
    unsigned categorized;
    struct tree_of_strings *right;
    struct tree_of_strings *left;
}tree_of_strings_t;

tree_of_strings_t* search_string (tree_of_strings_t *tree, char word []);
void insert_string (tree_of_strings_t **tree, char word []);
void insert_strings (tree_of_strings_t **tree, vldt_word_t *list);
tree_of_strings_t* create_string_element (char word []);
void print_strings (tree_of_strings_t *tree, int ocurrences);
void delete_tree (tree_of_strings_t **tree);
tree_of_strings_t* delete_string (tree_of_strings_t **tree, char to_remove[]);

#endif
