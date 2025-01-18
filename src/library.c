#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "library.h"

/** 
 * This function is responsible for initializing the library.
 * @returns a pointer to the struct Library.
 */
struct Library* init_library() {
    struct Library* lib = malloc(sizeof(struct Library)); 
    
    if (lib == NULL) {
        fprintf(stderr, "malloc failed.\n");
    }

    lib->first_book = NULL;
    lib->last_book = NULL;

    return lib;
}

void add_book(struct Library* lib, const char* name, const char* author, int pages, int year_of_publication) {
    struct Book* b = malloc(sizeof(struct Book));

    if (b == NULL) {
        fprintf(stderr, "malloc failed.\n");
    }
    
    strncpy(b->name, name, sizeof(b->name) - 1);
    b->name[sizeof(b->name) - 1] = '\0';
    strncpy(b->author, author, sizeof(b->name) - 1);
    b->author[sizeof(b->author) - 1] = '\0';
    b->pages = pages;
    b->year_of_publication = year_of_publication;
    
    if (lib->first_book == NULL) {
        lib->first_book = b;
        lib->last_book = b;
    } else {
        lib->last_book->next = b;
    }
}

void show_library(struct Library* lib) {
    printf("The library:\n");

    struct Book* b = lib->first_book;
    
    while (b != NULL) {
        printf("%s --> ", b->name);
        b = b->next;
    }

    printf("NULL\n");
}

void free_memory(struct Library* lib) {
    struct Book* curr_book = lib->first_book;

    // Check whether the library is empty.
    if (curr_book == NULL) {
        return;
    }

    while (curr_book != NULL) {
        struct Book* next = curr_book->next;
        free(curr_book);
        curr_book = next;
    }

    // Free the library.
    free(lib);
}
