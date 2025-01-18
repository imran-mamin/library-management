#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "library.h"

struct Library* init_library() {
    struct Library* lib = malloc(sizeof(struct Library)); 
    struct Book* b = malloc(sizeof(struct Book));
    
    if ((lib == NULL) || (b == NULL)) {
        fprintf(stderr, "malloc failed.\n");
    }

    strncpy(b->name, "Unknown", sizeof(b->name) - 1);
    b->name[sizeof(b->name) - 1] = '\0';
    strncpy(b->author, "Unknown", sizeof(b->author) - 1);
    b->author[sizeof(b->author) - 1] = '\0';
    b->pages = -1;
    b->year_of_publication = -1;
    b->next = NULL;

    lib->first_book = b;
    lib->last_book = b;

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
    
    if (lib->first_book->pages == -1) {
        free(lib->first_book);
        lib->first_book = b;
        lib->last_book = b;
    } else {
        lib->last_book->next = b;
    }
}

void free_memory(struct Library* lib) {
    struct Book* curr_book = lib->first_book;

    while (curr_book->next != lib->last_book) {
        struct Book* next = curr_book->next;
        free(curr_book);
        curr_book = next;
    }

    free(lib->last_book);

    // Free the library.
    free(lib);
}
