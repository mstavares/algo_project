#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "tree_of_strings.h"

// Search a string introduced by user
tree_of_strings_t* search_string (tree_of_strings_t *tree, char word [])
{
    tree_of_strings_t *ptr = NULL;
    for(ptr = tree; ptr;) {
        int compare_result = strcmp(word, ptr->string);
        if (compare_result == 0)
            return ptr;
        else if (compare_result > 0)
            ptr = ptr->right;
        else
            ptr = ptr->left;
    }  
    return NULL;
}

// Gets validated words and inserts them in tree
void insert_string (tree_of_strings_t **tree, char word [])
{
    tree_of_strings_t **ptr = NULL;
    int compare_result = 0;
        for(ptr = tree; *ptr;){
            compare_result = strcmp(word, (*ptr)->string);
            if(compare_result == 0) {
                (*ptr)->counter++;
                break;
            }
            else if (compare_result > 0)
                ptr = &(*ptr)->right;
            else
                ptr = &(*ptr)->left; 
        }
    if(!*ptr)
        *ptr = create_string_element(word);
}

// Loop to insert validated strings list
void insert_strings (tree_of_strings_t **tree, vldt_word_t *list)
{
    vldt_word_t *ptr = NULL;
    for(ptr = list; ptr; ptr = ptr->next)
        insert_string(&(*tree), ptr->word);
}

// Allocates memory for a new string
tree_of_strings_t* create_string_element (char word [])
{
    tree_of_strings_t *new = (tree_of_strings_t*) malloc (sizeof(tree_of_strings_t));
    if (new) {
        strcpy(new->string, word);
        new->counter = 1;
        new->right = NULL;
        new->left = NULL;
    }
    return new;
}

// Print strings tree
void print_strings (tree_of_strings_t *list, int ocurrences)
{
    if (list) {
        print_strings(list->left, ocurrences);
        printf("Word: %s ", list->string);
        if(ocurrences)
            printf("- Occurrences: %d",list->counter);
        printf("\n");
        print_strings(list->right, ocurrences);
    }
}