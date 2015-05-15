#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "algo.h"

/*
// Insert line on list by read order
void create_line_element (line_t **list, char line [])
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

// Print line list
void print_line (line_t *list)
{
    line_t *ptr = NULL;
    for(ptr = list; ptr; ptr = ptr->next) {
        printf("%s\n", ptr->line);
    }
}


*/

//Force to read .txt files
void extension (char filename []) {
    const char extension [] = ".txt";
    int i = 0, lenght_filename = (strlen(filename)-1);
    for (i = 0; filename[i] != '.' && i <= lenght_filename; i++);
    strcpy(filename+i, extension);
}

int main () 
{
    //word_t *root = NULL;
   //line_t *head = NULL;
	FILE *handle;
    char filename [MAX_FILENAME_LENGTH];
    char line [MAX_LINE_LENGTH];
	printf("Introduza o nome do ficheiro a ser lido.\n");
    scanf("%s", filename);
    extension(filename);
    handle = fopen(filename, "r");
    if (!handle) {
        printf("O ficheiro indicado nao foi encontrado.\n");
    } else {
        while (!feof(handle)) {
            fgets (line, MAX_LINE_LENGTH, handle);
            if(line[(strlen(line)-1)] == '\n') {
                line[(strlen(line)-1)] = '\0';
            }
            //create_line_element(&head, line);
            //insert_line(&head, line);
            //insert(&root, line);
        }
        //print_line(head);
        //print(root);
    }
    printf("\n");
    return 0;
}