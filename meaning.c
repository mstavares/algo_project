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

void insert_word_meaning (meaning_t **meaning_list)
{
    char string [MAX_WORD_LENGTH];
    meaning_t *meaning = NULL;
    puts("Type the meaning you want to search.");
    scanf("%s", string);
    while(scanf("%*c"));
    meaning = search_meaning(*meaning_list, string);
    if(meaning) {
        if(!search_string(meaning->data, string)) {
            puts("Type the word you want to insert.");
            scanf("%s", string);
            insert_string(&meaning->data ,string);
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
            printf("-----\n");
            print_strings(ptr->data, 0);
        }
    }
}












