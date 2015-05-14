#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algo.h"

// Tree struct
typedef struct word {
    char word [20];
    unsigned counter;
    struct word *upper;
    struct word *bellow;
}word_t;

int insert (word_t **list, char line [])
{
    word_t *new = (word_t*) malloc (sizeof(word_t));
    if (!new) {
        return 1;
    }
    strcpy(new->word, line);
    new->counter = 1;
    new->upper = NULL;
    new->bellow = NULL;
    while (1) {
        if(strcmp(new->word, (*list)->word) >= 0) {
            if (!(*list)->upper) {
                (*list)->upper = new;
                break;
            } else {
                *list = (*list)->upper;
            }
        } else {
            if (!(*list)->bellow) {
                (*list)->bellow = new;
                break;
            } else {
                *list = (*list)->bellow;
            }
        }
    }
    return 0;
}

// Create root if tree is empty
int create_root (word_t **list, char line [])
{
    word_t *new = (word_t*) malloc (sizeof(word_t));
    if (!new) {
        return 1;
    }
    strcpy(new->word, line);
    new->counter = 1;
    new->upper = NULL;
    new->bellow = NULL;
    *list = new;
    return 0;
}

void print (word_t *list)
{
    if (!list)
        return;
    print(list->bellow);
    printf("%s\n", list->word);
    print(list->upper);
}

// force to read .txt files
void extension_find (char filename []) {
    char extension [] = ".txt";
    int i = 0, lenght_filename = (strlen(filename)-1);
    for (i = 0; filename[i] != '.' && i <= lenght_filename; i++);
    strcpy(filename+i, extension);
}

int main () 
{
    word_t *root = NULL;
    char filename [MAX_FILENAME_LENGHT];
    char line [MAX_LINE_LENGHT];
	printf("Introduza o nome do ficheiro a ser lido.\n");
    scanf("%s", filename);
    extension_find(filename);
    FILE *handle = fopen(filename, "rw");
    if (!handle) {
        printf("O ficheiro indicado nao foi encontrado.\n");
    } else {
        while (!feof(handle)) {
            fgets (line, MAX_LINE_LENGHT, handle);
            if(line[(strlen(line)-1)] == '\n') {
                line[(strlen(line)-1)] = '\0';
            }
            if (!root) {
                create_root(&root, line);
            } else {
                insert(&root, line);
            }
        }
        print(root);
    }
    printf("\n");
    return 0;
}
