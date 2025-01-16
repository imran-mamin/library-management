#include <stdio.h>
#include <string.h>

#include "book.h"

#define NAME_SIZE 50

int main() {
    char command = '\0';
    char name[NAME_SIZE];
    char author[NAME_SIZE];
    int pages = -1;
    int year_of_publication = -1;
    
    printf("Please, enter the command that you want to execute\n");
    int args_count = scanf(" %c;%49[^;];%49[^;];%d;%d", &command, name, author, &pages, &year_of_publication);
    
    if (args_count < 0) {
        printf("Read error encountered or end-of-file reached before any assignment was made. \n");
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