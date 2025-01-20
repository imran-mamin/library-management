#include <stdio.h>
#include <string.h>

#include "library.h"

#define NAME_SIZE 50

int process_command(struct Library* lib, int args_count, char c, const char* name, const char* author, int pages, int year_of_publication, const char* isbn) {
    int result = 1;
    switch (c)
    {
        case 'A':
            if (args_count != 6) {
                printf("Invalid input. Please enter 'command;name;author;pages;year of publication;isbn' \n");
            } else {
                printf("Add a book\n");
                add_book(lib, name, author, pages, year_of_publication, isbn);
            }

            break;
        case 'D':
            // TODO: There should be 4 items in the command, not 5.
            delete_book(lib, isbn);
            break;
        case 'Q':
            printf("Stop command encountered.\n");
            result = 0;
            break;
        case 'S':
            show_library(lib);
            break;
        case 'U':
            // TODO: Update the information about the book.
            printf("Update a book\n");
            break;
        default:
            printf("Unknown command. Please, ensure that the command is one of the following: A or U\n");
    }

    return result;
}

int main() {
    struct Library* lib = init_library();

    // Get the input from the user.
    while (1) {
        char command = '\0';
        char name[NAME_SIZE];
        char author[NAME_SIZE];
        int pages = -1;
        int year_of_publication = -1;
        char isbn[14];
    
        printf("Please, enter the command that you want to execute\n");
        int args_count = scanf(" %c;%49[^;];%49[^;];%d;%d;%13c", &command, name, author, &pages, &year_of_publication, isbn);
       
        /*
        if (args_count != 5) {
            printf("Invalid input. Please enter 'command;name;author;pages;year of publication' \n");
        } else if (args_count == EOF) {
            printf("End of input detected.\n");
        }
        */

        const int res_process_command = process_command(lib, args_count, command, name, author, pages, year_of_publication, isbn);

        if (res_process_command == 0) {
            break;
        }
    }

    // Free the allocated memory: library, books.
    free_memory(lib);
    
    return 0;
}