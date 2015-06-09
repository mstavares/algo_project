#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "tree_of_strings.h"
#include "word.h"
#include "meaning.h"
#include "algo.h"

// Main menu
void main_menu (tree_of_strings_t *head_words, tree_of_strings_t* head_ncategorized, 
										meaning_t *head_meanings, line_t *head_lines) 
{
    int option = 0;
    int loop = 1;   
    while (loop) {
        puts("Select:");
        puts("1 - Print text.");
        puts("2 - Print text line by line.");
        puts("3 - Print all words with occurrences.");
        puts("4 - Search word.");
        puts("5 - Create meaning list.");
        puts("6 - Add meaning to list");
        puts("7 - Print meanings.");
        puts("8 - Delete meanings list.");
        puts("9 - Delete meaning from list.");
        puts("0 - Exit.");
        scanf("%d", &option);
        while(scanf("%*c"));
        switch (option) {
            case 1:
                print_text(head_lines, 0);
                break;
            case 2:
                print_text(head_lines, 1);
                break;
            case 3:
                print_strings(head_words, 1);
                break;
            case 4:
                word_search(head_words);
                break;
            case 5:
                create_meaning(&head_meanings);
                break;
            case 6:
                meaning_insert_delete(&head_meanings, meaning_insert);
                break;
            case 7:
                clear(head_meanings);
            	update(head_meanings, head_words);
            	without_categorization(head_words, &head_ncategorized);
                print_meanings(head_meanings);
                //puts("!!!!");
                //print_strings(head_ncategorized, 0);
                break;
            case 8:
                delete_tree(&head_words);
                break;
            case 9:
            	meaning_insert_delete(&head_meanings, meaning_delete);            	
                break;
            case 0:
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
    tree_of_strings_t *head_words = NULL;
    tree_of_strings_t *head_ncategorized = NULL;
    meaning_t *head_meanings = NULL;
    vldt_word_t *vldt_head = NULL;
    line_t *head_lines = NULL;
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
            insert_line_element(&head_lines, line);
        }
        line2word(head_lines, &vldt_head);
        word_validation(&vldt_head);
        insert_strings(&head_words, vldt_head);
        main_menu(head_words, head_ncategorized, head_meanings, head_lines);
    }
    printf("\n");
    puts("See ya");
    return 0;
}
