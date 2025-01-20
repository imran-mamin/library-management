#include <stdio.h>
#include <string.h>

#include "library.h"

#define NAME_SIZE 50

int process_command(struct Library* lib, char* user_input) {
    int result = 1;
    const char s[2] = ";";
    char* token = strtok(user_input, s);
    char c = (*token); // Read a given command.
    char isbn[14];

    switch (c)
    {
        case 'A':
            if (token == NULL) {
                printf("Invalid input. Please enter 'command;name;author;pages;year of publication;isbn' \n");
                return -1;
            }

            char name[NAME_SIZE];
            token = strtok(NULL, s);
            
            if (token == NULL) {
                printf("Invalid input. Please enter 'command;name;author;pages;year of publication;isbn' \n");
                return -1;
            }
            
            strncpy(name, token, sizeof(name) - 1);
            name[NAME_SIZE - 1] = '\0';

            char author[NAME_SIZE];
            token = strtok(NULL, s);
            
            if (token == NULL) {
                printf("Invalid input. Please enter 'command;name;author;pages;year of publication;isbn' \n");
                return -1;
            }
            
            strncpy(author, token, sizeof(author) - 1);
            author[NAME_SIZE - 1] = '\0';

            token = strtok(NULL, s);
            if (token == NULL) {
                printf("Invalid input. Please enter 'command;name;author;pages;year of publication;isbn' \n");
                return -1;
            }
            int pages = (int) (*token);
            token = strtok(NULL, s);
            if (token == NULL) {
                printf("Invalid input. Please enter 'command;name;author;pages;year of publication;isbn' \n");
                return -1;
            }
            int year_of_publication = (int) (*token);
            
            token = strtok(NULL, s);
            if (token == NULL) {
                printf("Invalid input. Please enter 'command;name;author;pages;year of publication;isbn' \n");
                return -1;
            }
            strncpy(isbn, token, sizeof(isbn) - 1);
            isbn[13] = '\0';
            
            printf("Add a book\n");
            add_book(lib, name, author, pages, year_of_publication, isbn);
            break;
        case 'D':
            token = strtok(NULL, s);
            if (token == NULL) {
                printf("Invalid input. Please enter 'command;isbn'.\n");
                return -1;
            }
            strncpy(isbn, token, sizeof(isbn) - 1);
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
        char user_input[140];
    
        printf("Please, enter the command that you want to execute\n");
        if (fgets(user_input, sizeof(user_input), stdin) != NULL) {
            const int res_process_command = process_command(lib, user_input);

            if (res_process_command == 0) {
                break;
            }
        }
    }

    // Free the allocated memory: library, books.
    free_memory(lib);
    
    return 0;
}