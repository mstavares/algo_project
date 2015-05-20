#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "word.h"
#include "algo.h"

// Main menu
void main_menu (word_t *root, line_t *head) 
{
    int option = 0;
    int loop = 1;
    char word [MAX_WORD_LENGTH];
    while (loop) {
        while(scanf("%*c"));
        puts("Select:");
        puts("1 - Print text.");
        puts("2 - Print text line by line.");
        puts("3 - Print all words with occurrences.");
        puts("4 - Search word.");
        puts("5 - Delete word.");
        puts("9 - Exit.");
        scanf("%d", &option);
        switch (option) {
            case 1:
                print_text(head, 0);
                break;
            case 2:
                while(scanf("%*c"));
                print_text(head, 1);
                break;
            case 3:
                print_words(root);
                break;
            case 4:
                puts("Write the word who want to search.");
                scanf("%s", word);
                user_search(&root, word);
                break;
            case 5:
                
                break;
            case 9:
                loop = 0;
                break;
            default:
                puts("Invalid option selected.");
        }
    }
}

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
	puts("Type filename to be read.");
    scanf("%s", filename);
    extension(filename);
    FILE *handle = fopen(filename, "r");
    if (!handle) {
        puts("The specified file was not found.");
    } else {
        while (!feof(handle)) {
            fgets (line, MAX_LINE_LENGTH, handle);
            if(line[(strlen(line)-1)] == '\n') {
                line[(strlen(line)-1)] = '\0';
            }
            insert_line_element(&head, line);
        }
        line2word(head, &v_head);
        word_validation(&v_head);
        insert_words(&root, v_head);
        main_menu(root, head);
    }
    printf("\n");
    puts("See ya");
    return 0;
}