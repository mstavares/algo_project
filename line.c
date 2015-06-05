#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

// Insert line on list by read order
void insert_line_element (line_t **list, char line [])
{
    line_t *temp = NULL;
    line_t *new = (line_t*) malloc (sizeof(line_t));
    if (new) {
        strcpy(new->line, line);
        new->next = NULL;
        if (!*list) {
            *list = new;
        } else {
            for (temp = *list; temp->next; temp = temp->next);
            temp->next = new;
        } 
    }
}

// Split line on words
void line2word (line_t *list, vldt_word_t **v_head)
{
    int i = 0;
    line_t *temp = NULL;
    vldt_word_t *v_temp = NULL;
    char word [MAX_WORD_LENGTH];
    for(temp = list; temp; temp = temp->next) {
        char *line = temp->line;    
        do {
            sscanf(line, "%s", word);
            i = strlen(line) - strlen(word);
            if (strlen(word) > 1) {
                if(!*v_head) {
                    *v_head = create_vldt_word (word);
                } else {
                    for(v_temp = *v_head; v_temp->next; v_temp = v_temp->next);
                    v_temp->next = create_vldt_word (word);
                    (v_temp->next)->prev = v_temp;
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
        new->prev = NULL;
    }    
    return new;
}

/* Print text
 * pause = 0 -> Print all text
 * pause = 1 -> Print text line by line
 */
void print_text (line_t *list, char pause)
{
    line_t *temp = NULL;
    for(temp = list; temp; temp = temp->next) {
        printf("%s\n", temp->line);
        if(pause)
            getchar();
    }
}