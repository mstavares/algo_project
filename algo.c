#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// force to read .txt files
void extension_find (char filename []) {
    char extension [] = ".txt";
    int i = 0, lenght_filename = (strlen(filename)-1);
    for (i = 0; filename[i] != '.' && i <= lenght_filename; i++);
    strcpy(filename+i, extension);
}

int main () 
{
    char filename [15];
	printf("Introduza o nome do ficheiro a ser lido.\n");
    scanf("%s", filename);
    extension_find(filename);
    printf("O nome do ficheiro e': %s\n", filename);
    return 0;
}
