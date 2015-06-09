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

void meaning_insert (meaning_t **meaning_list)
{
    char string [MAX_WORD_LENGTH];
    puts("Type the word you want to insert.");
    scanf("%s", string);
    insert_string(&(*meaning_list)->data, string);
}    

void meaning_delete (meaning_t **meaning_list)
{
    char string [MAX_WORD_LENGTH];
    puts("Write the meaning who want to delete.");
    scanf("%s", string);
    delete_string(&(*meaning_list)->data, string);
    
}

void delete_meaning_list (meaning_t **meaning_list)
{
	delete_tree(&(*meaning_list)->data);
	
}

void meaning_insert_delete (meaning_t **meaning_list, void (*insert_delete) ())
{
    char string [MAX_WORD_LENGTH];
    meaning_t *meaning = NULL;
    puts("Type the meaning list you want.");
    scanf("%s", string);
    while(scanf("%*c"));
    meaning = search_meaning(*meaning_list, string);
    if(meaning) {
            insert_delete(&meaning);
    }
    else
        puts("The meaning list searched could not be found.");
}

meaning_t* create_meaning_element (char meaning [])
{
    meaning_t *new = (meaning_t*) malloc (sizeof(meaning_t));
    if(new) {
        strcpy(new->description, meaning);
        new->absolute_frequency = 0;
        new->relative_frequency = 0;
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

void print_meanings (meaning_t *meaning_list)
{
    meaning_t *temp = NULL;
    if(meaning_list) {
        for(temp = meaning_list; temp; temp = temp->next) {
            puts("----------------------");
            puts(temp->description);
            printf("Absolute Frequency: %d\n", temp->absolute_frequency);
            printf("Relative Frequency: %.2f%%\n", temp->relative_frequency);
            puts("----------------------");
            print_strings(temp->data, FALSE);
            puts("----------------------\n");
        }
    }
}

void clear2 (tree_of_strings_t *tree_meanings)
{
	if(tree_meanings) {
		clear2(tree_meanings->left);
		tree_meanings->categorized = FALSE;
		clear2(tree_meanings->right);
	}
}

void clear (meaning_t *head_meanings, tree_of_strings_t **ncategorized)
{
    meaning_t *temp = NULL;
    delete_tree(&(*ncategorized));
    for(temp = head_meanings; temp; temp = temp->next) {
        clear2(temp->data);
        temp->absolute_frequency = 0;
    }
}

void without_categorization (tree_of_strings_t *words, tree_of_strings_t **ncategorized)
{
	if(words) {
		without_categorization(words->left, &(*ncategorized));
        printf("***%s***%d\n", words->string, words->categorized);
		if(!words->categorized) {
            insert_string(&(*ncategorized), words->string);
            printf("***%s***%d\n", words->string, words->categorized);
        }
			
		without_categorization(words->right, &(*ncategorized));
	}
}

void update3 (meaning_t *head_meanings)
{
	int words_sum = 0;
	meaning_t *temp;
	for(temp = head_meanings; temp; temp = temp->next) {
		words_sum += temp->absolute_frequency;
		temp->relative_frequency = 0;
	}
	for(temp = head_meanings; temp; temp = temp->next)
		if(words_sum)
			temp->relative_frequency = (temp->absolute_frequency * 100) / words_sum;
}

void update2 (meaning_t *head_meanings, tree_of_strings_t *word)
{
	meaning_t *temp = NULL;
	tree_of_strings_t *result = NULL;
    for(temp = head_meanings; temp; temp = temp->next) {
		result = search_string(temp->data, word->string);
		if(result) {
			temp->absolute_frequency += word->counter;
			result->categorized = TRUE;
		}				
	}
}

void update (meaning_t *head_meanings, tree_of_strings_t *words)
{
	if(words) {
		update(head_meanings, words->left);
		update2(head_meanings, words);
		update(head_meanings, words->right);
		update3(head_meanings);
	}
}
