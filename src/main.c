#include <stdio.h>
#include <string.h>

#include "library.h"

#define NAME_SIZE 50

int process_command(struct Library* lib, int args_count, char c, const char* name, const char* author, int pages, int year_of_publication) {
    int result = -1;
    switch (c)
    {
        case 'A':
            // TODO: Add a book.
            if (args_count != 5) {
                printf("Invalid input. Please enter 'command;name;author;pages;year of publication' \n");
            } else {
                printf("Add a book\n");
                add_book(lib, name, author, pages, year_of_publication);
                result = 0;
            }

            break;
        case 'Q':
            printf("Stop command encountered.\n");
            result = 1;
            break;
        case 'U':
            // TODO: Update the information about the book.
            printf("Update a book\n");
            result = 2;
            break;
        default:
            printf("Unknown command. Please, ensure that the command is one of the following: A or U\n");
    }

    return result;
}

int main() {
    struct Library* lib = init_library();

    while (1) {
        char command = '\0';
        char name[NAME_SIZE];
        char author[NAME_SIZE];
        int pages = -1;
        int year_of_publication = -1;
    
        printf("Please, enter the command that you want to execute\n");
        int args_count = scanf(" %c;%49[^;];%49[^;];%d;%d", &command, name, author, &pages, &year_of_publication);
       
        /*
        if (args_count != 5) {
            printf("Invalid input. Please enter 'command;name;author;pages;year of publication' \n");
        } else if (args_count == EOF) {
            printf("End of input detected.\n");
        }
        */

        const int res_process_command = process_command(lib, args_count, command, name, author, pages, year_of_publication);

        if (res_process_command == 1) {
            break;
        }
    }

    // Free the allocated memory: library, books.
    free_memory(lib);
    return 0;
}