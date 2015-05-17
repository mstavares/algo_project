#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "word.h"

/* Search one word on tree struct
 * if exist sum 1 to counter variable 
 * else return the address to allocate the new word
 */
word_t** search_word (word_t *tree, char word []) 
{
    int compare_result = 0;
    for (;;) {
        compare_result = strcmp(word, tree->word);
        if (compare_result == 0) {
            tree->counter += 1;
            return NULL;
        } else if(compare_result > 0) {
            if (!tree->right) {
                return(&tree->right);
            } else {
                tree = tree->right;
            }
        } else {
            if (!tree->left) {
                return(&tree->left);
            } else {
                tree = tree->left;
            }
        }
    }
}

// Adds word into word list
void insert_words (word_t **tree, vldt_word_t *list)
{
    vldt_word_t *ptr = NULL;
    for(ptr = list; ptr; ptr = ptr->next) {
        if(!*tree) {
            *tree = create_word(ptr->word);
        } else {
            word_t **new = (search_word(*tree, ptr->word));
            if (new) {
                *new = create_word(ptr->word);
            }
        }
    }        
}

// Allocates memory for a new word
word_t* create_word (char word [])
{
    word_t *new = (word_t*) malloc (sizeof(word_t));
    if (new) {
        strcpy(new->word, word);
        new->counter = 1;
        new->right = NULL;
        new->left = NULL;
    }
    return new;
}

// Remove comma and dot from word
void comma_and_dot (char word [])
{
    int tam = strlen(word)-1;
    char symbols [] = {',', '.'};
    if(word[tam] == symbols[0] || word[tam] == symbols[1]) {
        word[tam] = '\0';
    }
}

// Remove invalid words from list
/*void invalid_word (vldt_word_t **list)
{
    int tam = 0;
    int i = 0;
    vldt_word_t *ptr = NULL;
    for(ptr = *list; ptr; ptr = ptr->next) {
        tam = strlen(ptr->word)-1;
        for(i = 0; i < tam; i++) {
            if(((ptr->word)+i) > 'A' && ((ptr->word)+i) < 'Z') {
                continue;
            } else if (((ptr->word)+i) > 'a' && ((ptr->word)+i) < 'a') {
                continue;
            } else if (((ptr->word)+i) == '-') {
                
            } else {
                
            }
        }
    }
}*/

void word_validation (vldt_word_t **list)
{
    vldt_word_t *ptr = NULL;
    for(ptr = *list; ptr; ptr = ptr->next) {
        comma_and_dot(ptr->word);
    }
}

// Print words list
void print_words (word_t *list)
{
    if (!list)
        return;
    print_words(list->left);
    printf("Word: %s - Occurrences: %d\n", list->word, list->counter);
    print_words(list->right);
}
