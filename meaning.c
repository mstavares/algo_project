#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "tree_of_strings.h"
#include "meaning.h"


meaning_t* search_meaning (meaning_t *meaning_list, char meaning [])
{
    meaning_t *temp = NULL;
    for(temp = meaning_list; temp; temp = temp->next) {
        if(strcmp(meaning, temp->description) == 0)
            return temp;
    }
    return NULL;
}

void meaning_search_delete (tree_of_strings_t **tree)
{
    char meaning [MAX_WORD_LENGTH];
    puts("Write the meaning who want to delete.");
    scanf("%s", meaning);
    tree_of_strings_t *result = delete_string(&(*tree), meaning);
    if(result)
        puts("Delete succeeded.");
    else
        puts("\nThe meaning you searched for was not found.\n");
}

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
    meaning_t *temp = NULL;
    char meaning [MAX_WORD_LENGTH];
    puts("Type the meaning description");
    scanf("%s", meaning);
    if(search_meaning(*meaning_list, meaning)) {
        puts("This meaning is already exists.");
    } else {
        if(!*meaning_list)
            *meaning_list = create_meaning_element(meaning);
        else {
            for(temp = *meaning_list; temp->next; temp = temp->next);
            temp->next = create_meaning_element(meaning);   
        }
    }
}

void insert_meaning (meaning_t **meaning_list)
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
    meaning_t *temp = NULL;
    if(meaning_list) {
        for(temp = meaning_list; temp; temp = temp->next) {
            puts("-----------");
            puts(temp->description);
            puts("-----------");
            print_strings(temp->data, 1);
            puts("-----------\n");
        }
    }
}

void clear2 (tree_of_strings_t *tree_meanings)
{
	if(tree_meanings) {
		clear2(tree_meanings->left);
		tree_meanings->counter = 0;
		clear2(tree_meanings->right);
	}
}

void clear (meaning_t *head_meanings)
{
    meaning_t *temp = NULL;
    for(temp = head_meanings; temp; temp = temp->next)
        clear2(temp->data);
}

void update2 (meaning_t *head_meanings, tree_of_strings_t *word)
{
	meaning_t *temp = NULL;
	tree_of_strings_t *result = NULL;
    for(temp = head_meanings; temp; temp = temp->next) {
		result = search_string(temp->data, word->string);
		if(result) {
			result->counter = word->counter;
		}				
	}
}

void update (meaning_t *head_meanings, tree_of_strings_t *list_words)
{
	if(list_words) {
		update(head_meanings, list_words->left);
		update2(head_meanings, list_words);
		update(head_meanings, list_words->right);
	}
}







