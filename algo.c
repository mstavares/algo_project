#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "word.h"
#include "algo.h"

//Force to read .txt files
void extension (char filename []) {
    const char extension [] = ".txt";
    int i = 0, lenght_filename = (strlen(filename)-1);
    for (i = 0; filename[i] != '.' && i <= lenght_filename; i++);
    strcpy(filename+i, extension);
}

int main () 
{
    word_t *root = NULL;
    vldt_word_t *v_head = NULL;
    line_t *head = NULL;
    char filename [MAX_FILENAME_LENGTH];
    char line [MAX_LINE_LENGTH];
	printf("Type filename to be read.\n");
    scanf("%s", filename);
    extension(filename);
    FILE *handle = fopen(filename, "r");
    if (!handle) {
        printf("The specified file was not found .\n");
    } else {
        while (!feof(handle)) {
            fgets (line, MAX_LINE_LENGTH, handle);
            if(line[(strlen(line)-1)] == '\n') {
                line[(strlen(line)-1)] = '\0';
            }
            insert_line_element(&head, line);
        }
        line2word(head, &v_head);
        insert_words(&root, v_head);
        //imprime(v_head);
        //print_line(head);
        print_words(root);
    }
    printf("\n");
    return 0;
}