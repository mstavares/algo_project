#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

// Insert line on list by read order
void insert_line_element (line_t **list, char line [])
{
    line_t *ptr = NULL;
    line_t *new = (line_t*) malloc (sizeof(line_t));
    if (new) {
        strcpy(new->line, line);
        new->next = NULL;
        if (!*list) {
            *list = new;
        } else {
            for (ptr = *list; ptr->next; ptr = ptr->next);
            ptr->next = new;
        } 
    }
}

// Split line on words
void line2word (line_t *list, vldt_word_t **v_head)
{
    int i = 0;
    line_t *ptr = NULL;
    vldt_word_t *v_ptr = NULL;
    char word [MAX_WORD_LENGTH];
    for(ptr = list; ptr; ptr = ptr->next) {
        char *line = ptr->line;    
        do {
            sscanf(line, "%s", word);
            i = strlen(line) - strlen(word);
            if (strlen(word) > 1) {
                if(!*v_head) {
                    *v_head = create_vldt_word (word);
                } else {
                    for(v_ptr = *v_head; v_ptr->next; v_ptr = v_ptr->next);
                    v_ptr->next = create_vldt_word (word);
                }
            }
            line += strlen(word)+1;       
        } while (i);
    }
}

// Allocates memory for a new validated word
vldt_word_t* create_vldt_word (char word[])
{
    vldt_word_t *new = (vldt_word_t*) malloc (sizeof(vldt_word_t));
    if (new) {
        strcpy(new->word, word);
        new->next = NULL;
    }    
    return new;
}

// Print line list
void print_line (line_t *list)
{
    line_t *ptr = NULL;
    for(ptr = list; ptr; ptr = ptr->next) {
        printf("%s\n", ptr->line);
    }
}

void imprime (vldt_word_t *list)
{
    vldt_word_t *ptr = NULL;
    for(ptr = list; ptr; ptr = ptr->next) {
        printf("%s:%zu\n", ptr->word, strlen(ptr->word));
    }
}