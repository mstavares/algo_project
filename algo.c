#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algo.h"

// force to read .txt files
void extension_find (char filename []) {
    char extension [] = ".txt";
    int i = 0, lenght_filename = (strlen(filename)-1);
    for (i = 0; filename[i] != '.' && i <= lenght_filename; i++);
    strcpy(filename+i, extension);
}

int main () 
{
    char filename [MAX_FILENAME_LENGHT];
    char texto [MAX_LINE_LENGHT];
	printf("Introduza o nome do ficheiro a ser lido.\n");
    scanf("%s", filename);
    extension_find(filename);
    FILE *handle = fopen(filename, "rw");
    if (!handle) {
        printf("O ficheiro indicado nao foi encontrado.\n");
    } else {
        while (!feof(handle)) {
            fgets (texto, MAX_LINE_LENGHT, handle);
            printf("%s", texto);
        }
    }
    printf("\n");
    return 0;
}
