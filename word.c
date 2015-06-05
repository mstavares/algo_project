#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "tree_of_strings.h"
#include "word.h"

// Search word introduced by user
void word_search (tree_of_strings_t *tree)
{
    char word [MAX_WORD_LENGTH];
    puts("Write the word who want to search.");
    scanf("%s", word);
    tree_of_strings_t *result = search_string(tree, word);
    if(result)
        printf("Word: %s - Occurrences: %d\n", result->string, result->counter);
    else
        puts("\nThe word you searched for was not found.\n");
}

// Remove comma and dot from word
void comma_and_dot (char word [])
{
    int i = 0;
    int tam = strlen(word)-1;
    char symbols [6] = {',', '.', ';', ':', '!', '?'};
    for(i = 0; i <= 6; i++)
        if(word[tam] == symbols[i])
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