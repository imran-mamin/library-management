#include <stdio.h>
#include <string.h>

#include "book.h"

#define NAME_SIZE 50

int process_command(char c, const char* name, const char* author, const int pages, const int year_of_publication) {
    int result = -1;
    switch (c)
    {
        case 'A':
            // TODO: Add a book.
            printf("Add a book\n");
            result = 0;
            break;
        case 'U':
            // TODO: Update the information about the book.
            printf("Update a book\n");
            result = 1;
            break;
        default:
            printf("Unknown command. Please, ensure that the command is one of the following: A or U\n");
    }

    return result;
}

int main() {
    char command = '\0';
    char name[NAME_SIZE];
    char author[NAME_SIZE];
    int pages = -1;
    int year_of_publication = -1;
    
    printf("Please, enter the command that you want to execute\n");
    int args_count = scanf(" %c;%49[^;];%49[^;];%d;%d", &command, name, author, &pages, &year_of_publication);
    
    if (args_count != 5) {
        printf("Invalid input. Please enter 'command;name;author;pages;year of publication \n");
        return -1;
    } else if (args_count == EOF) {
        printf("End of input detected.\n");
        return -1;
    }

    const int res_process_command = process_command(command, name, author, pages, year_of_publication);

    if (res_process_command == -1) {
        return -1;
    }

    struct Book b;
    strncpy(b.name, name, sizeof(b.name) - 1);
    b.name[sizeof(b.name) - 1] = '\0';
    strncpy(b.author, author, sizeof(b.name) - 1);
    b.author[sizeof(b.author) - 1] = '\0';
    b.pages = pages;
    b.year_of_publication = year_of_publication;

    printf("Name: %s, author: %s, pages: %d, year_of_publication: %d\n", b.name, b.author, b.pages, b.year_of_publication);

    return 0;
}