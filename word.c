#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "word.h"

/* Search one word on tree struct
 * if exist sum 1 to counter else return the address
 * to allocate the new word
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
            if (!tree->upper) {
                return(&tree->upper);
            } else {
                tree = tree->upper;
            }
        } else {
            if (!tree->bellow) {
                return(&tree->bellow);
            } else {
                tree = tree->bellow;
            }
        }
    }
}

int insert_word (word_t **tree, char line [])
{
    if(!*tree) {
        *tree = create_word_element(line);
    } else {
        word_t **temp = (search_word(*tree, line));
        if (temp) {
            *temp = create_word_element(line);
        }
    }    
    return 0;
}

word_t* create_word_element (char word [])
{
    word_t *new = (word_t*) malloc (sizeof(word_t));
    if (new) {
        strcpy(new->word, word);
        new->counter = 1;
        new->upper = NULL;
        new->bellow = NULL;
    }
    return new;
}


void print_words (word_t *list)
{
    if (!list)
        return;
    print_words(list->bellow);
    printf("%s:%d\n", list->word, list->counter);
    print_words(list->upper);
}

