#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "tree_of_strings.h"

// Search a string introduced by user
tree_of_strings_t* search_string (tree_of_strings_t *tree, char word [])
{
    tree_of_strings_t *temp = NULL;
    for(temp = tree; temp;) {
        int compare_result = strcmp(word, temp->string);
        if (compare_result == 0)
            return temp;
        else if (compare_result > 0)
            temp = temp->right;
        else
            temp = temp->left;
    }  
    return NULL;
}

// Gets validated words and inserts them in tree
void insert_string (tree_of_strings_t **tree, char word [])
{
    tree_of_strings_t **temp = NULL;
    int compare_result = 0;
        for(temp = tree; *temp;){
            compare_result = strcmp(word, (*temp)->string);
            if(compare_result == 0) {
                (*temp)->counter++;
                break;
            }
            else if (compare_result > 0)
                temp = &(*temp)->right;
            else
                temp = &(*temp)->left; 
        }
    if(!*temp)
        *temp = create_string_element(word);
}

// Loop to insert validated strings list
void insert_strings (tree_of_strings_t **tree, vldt_word_t *list)
{
    vldt_word_t *temp = NULL;
    for(temp = list; temp; temp = temp->next)
        insert_string(&(*tree), temp->word);
}

// Allocates memory for a new string
tree_of_strings_t* create_string_element (char word [])
{
    tree_of_strings_t *new = (tree_of_strings_t*) malloc (sizeof(tree_of_strings_t));
    if (new) {
        strcpy(new->string, word);
        new->counter = 1;
        new->categorized = FALSE;
        new->right = NULL;
        new->left = NULL;
    }
    return new;
}

// Print strings tree
void print_strings (tree_of_strings_t *tree, int ocurrences)
{
    if (tree) {
        print_strings(tree->left, ocurrences);
        printf("Word: %s ", tree->string);
        if(ocurrences)
            printf("- Occurrences: %d",tree->counter);
        printf("\n");
        print_strings(tree->right, ocurrences);
    }
}

// Delete all tree struct
void delete_tree (tree_of_strings_t **tree)
{
    if(*tree) {
        delete_tree(&(*tree)->left);
        free(*tree);
        delete_tree(&(*tree)->right);
        *tree = NULL;
    }
}

/* Delete string
 * Without leafs
 * Just one leaf
 * Two leafs
 */
tree_of_strings_t* delete_string (tree_of_strings_t **tree, char to_remove [])
{
    if (*tree) {
        tree_of_strings_t *temp = *tree;
	    if (strcmp(to_remove, (*tree)->string) > 0)
		    (*tree)->right = delete_string(&(*tree)->right, to_remove);
	    else if (strcmp(to_remove, (*tree)->string) < 0)
		    (*tree)->left = delete_string(&(*tree)->left, to_remove);
	    else {
		    if(!(*tree)->left && !(*tree)->right) {
                *tree = NULL;
                free(*tree);
		    } else if (!(*tree)->left) {
                free(*tree);
			    *tree = (*tree)->right;
		    } else if (!(*tree)->right) {
                free(*tree);
			    *tree = (*tree)->left;
		    } else {
                for(temp = (*tree)->right; temp->left; temp = temp->left);
			    strcpy((*tree)->string, temp->string);
			    (*tree)->right = delete_string(&(*tree)->right, temp->string);
		    }
            return NULL;
        }
	}
    return *tree;
}
