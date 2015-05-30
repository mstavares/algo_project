#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "tree_of_strings.h"
#include "meaning.h"

// eliminar palavras
// eliminar significados
// uniformizar as pesquisas e outras partes do código
// eliminar lista auxiliar

meaning_t* create_meaning_element (char meaning [])
{
    meaning_t *new = (meaning_t*) malloc (sizeof(meaning_t));
    if(new) {
        strcpy(new->description, meaning);
        new->counter = 0;
        new->data = NULL;
        new->prev = NULL;
        new->next = NULL;        
    }
    return new;
}

void create_meaning (meaning_t **meaning_list)
{
    meaning_t *ptr = NULL;
    char meaning [MAX_WORD_LENGTH];
    puts("Type the meaning description");
    scanf("%s", meaning);
    if(search_meaning(*meaning_list, meaning)) {
        puts("This meaning is already exists.");
    } else {
        if(!*meaning_list)
            *meaning_list = create_meaning_element(meaning);
        else {
            for(ptr = *meaning_list; ptr->next; ptr = ptr->next);
            ptr->next = create_meaning_element(meaning);   
        }
    }
}

meaning_t* search_meaning (meaning_t *meaning_list, char meaning [])
{
    meaning_t *ptr = NULL;
    for(ptr = meaning_list; ptr; ptr = ptr->next) {
        if(strcmp(meaning, ptr->description) == 0)
            return ptr;
    }
    return NULL;
}

void insert_meaning_word (meaning_t **meaning) 
{
    char word [MAX_WORD_LENGTH];
    puts("Type the word you want to insert.");
    scanf("%s", word);
    insert_string(&(*meaning)->data, word);
}

/*
void remove_word_meaning (meaning_t **meaning_list)
{
    
}
*/
void insert_remove_meaning_word (meaning_t **meaning_list, void (*insert_remove) ())
{
    char meaning [MAX_WORD_LENGTH];
    meaning_t *meaning_ptr = NULL;
    puts("Type the meaning you want to search.");
    scanf("%s", meaning);
    while(scanf("%*c"));
    meaning_ptr = search_meaning(*meaning_list, meaning);
    if(meaning_ptr) {
        if(!search_string(meaning_ptr->data, meaning)) {
           insert_remove(&meaning_ptr);
        } 
    }
    else
        puts("The meaning searched could not be found.");
}



void print_meanings (meaning_t *meaning_list)
{
    meaning_t *ptr = NULL;
    if(meaning_list) {
        for(ptr = meaning_list; ptr; ptr = ptr->next) {
            puts(ptr->description);
            puts("++++++++++");
            print_strings(ptr->data, 0);
            puts("----------");
        }
    }
}












