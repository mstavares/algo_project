#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "word.h"

// Search a word introduced by user
word_t* search_word (word_t *tree, char word [])
{
    word_t *ptr = NULL;
    for(ptr = tree; ptr;) {
        int compare_result = strcmp(word, ptr->word);
        if (compare_result == 0)
            return ptr;
        else if (compare_result > 0)
            ptr = ptr->right;
        else
            ptr = ptr->left;
    }  
    return NULL;
}

void user_search (word_t *tree, char word [])
{
    word_t *result = search_word(tree, word);
    if(result)
        printf("Word: %s - Occurrences: %d\n", result->word, result->counter);
    else
        puts("\nThe word you searched for was not found.\n");
}

// Checks if the right or left is free to enter the new word
void left_right (word_t **pos, char word [], word_t **ptr)
{
    if(*pos)
        *ptr = *pos;
    else {
        *pos = create_word(word);
        *ptr = NULL;
    }
}

/* Search one word on tree struct
 * if exist sum 1 to counter variable 
 * else return the address to allocate the new word
 */
// Gets validated words and inserts them in tree
void insert_word (word_t **tree, char word [])
{
    word_t *ptr = NULL;
    int compare_result = 0;
    if(!*tree) {
        *tree = create_word(word);
    } else {
        for(ptr = *tree; ptr;){
            compare_result = strcmp(word, ptr->word);
            if(compare_result == 0) {
                ptr->counter++;
                break;
            }
            compare_result > 0 ? left_right(&ptr->right, word, &ptr) : left_right(&ptr->left, word, &ptr);
        }
    }
}

// Recieve validated words list and insert them on tree
void insert_words (word_t **tree, vldt_word_t *list)
{
    vldt_word_t *ptr = NULL;
    for(ptr = list; ptr; ptr = ptr->next)
        insert_word(&(*tree), ptr->word);
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
    if(word[tam] == ',' || word[tam] == '.')
        word[tam] = '\0';
}

// Remove invalid words from list
int invalid_word (char word [])
{
    int i = 0;
    int tam = strlen(word);
    for(i = 0; i < tam; i++) {
        if((word[i] >= 'A') && (word[i] <= 'Z'))
            continue;
        else if ((word[i] >= 'a') && (word[i] <= 'z'))
            continue;
        else if (word[i] == '-')
            continue;
        else
            return 1;
    }
    return 0;
}

/* Check if word is really a word
 * Call comma_and_dot to remove commas and dots
 */
void word_validation (vldt_word_t **list)
{
    vldt_word_t *ptr = NULL, *temp = NULL;
    for(ptr = *list; ptr; ptr = ptr->next) {
        comma_and_dot(ptr->word);
        if(invalid_word(ptr->word)) {
            (ptr->prev)->next = ptr->next;
            (ptr->next)->prev = ptr->prev;
            temp = ptr;
            ptr = ptr->prev;
            free(temp);
        }
    }
}

// Print words list
void print_words (word_t *list)
{
    if (list) {
        print_words(list->left);
        printf("Word: %s - Occurrences: %d\n", list->word, list->counter);
        print_words(list->right);
    }
}
