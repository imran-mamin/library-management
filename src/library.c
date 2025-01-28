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
        return NULL;
    }

    lib->first_book = NULL;
    lib->last_book = NULL;

    return lib;
}

void add_book(struct Library* lib, const char* name, const char* author, int pages, int year_of_publication, const char* isbn) {
    // Ensure that there is no books with the same isbn.
    struct Book* curr = lib->first_book;

    while (curr != NULL) {
        if (strcmp(curr->isbn, isbn) == 0) {
            fprintf(stderr, "A book with isbn: %s already exists.\n", isbn);
            return;
        }

        curr = curr->next;
    }
    
    struct Book* b = malloc(sizeof(struct Book));

    if (b == NULL) {
        fprintf(stderr, "malloc failed.\n");
        return;
    }
    
    strncpy(b->name, name, sizeof(b->name) - 1);
    b->name[sizeof(b->name) - 1] = '\0';
    strncpy(b->author, author, sizeof(b->name) - 1);
    b->author[sizeof(b->author) - 1] = '\0';
    b->pages = pages;
    b->year_of_publication = year_of_publication;
    strncpy(b->isbn, isbn, sizeof(b->isbn) - 1);
    b->isbn[sizeof(b->isbn) - 1] = '\0';
    b->next = NULL;

    if (lib->first_book == NULL) {
        lib->first_book = b;
        lib->last_book = b;
    } else {
        lib->last_book->next = b;
        lib->last_book = b;
    }
}

void delete_book(struct Library* lib, const char* isbn) {
    struct Book* prev = NULL;
    struct Book* b = lib->first_book;

    while (b != NULL) {
        int same_isbn = (strcmp(isbn, b->isbn) == 0);

        if (same_isbn) {
            break;
        }
        
        prev = b;
        b = b->next;
    }

    if (b == NULL) {
        printf("The book was not found. Check that isbn was written correctly.\n");
    } else {
        // The only book in the library?
        if ((b->next == NULL) && (prev == NULL)) {
            lib->first_book = NULL;
            lib->last_book = NULL;
        } else if (prev == NULL) { // The first book in the library?
            lib->first_book = b->next;
        } else if (b->next == NULL) { // The last book in the library?
            lib->last_book = prev;
            prev->next = NULL;
        } else {
            prev->next = b->next;
        }
        
        free(b);
        printf("The book was successfully deleted.\n");
    }
}

void show_library(struct Library* lib) {
    printf("The library:\n\n");

    struct Book* b = lib->first_book;
    
    if (b == NULL) {
        printf("The library is empty.\n");
        return;
    }
    
    while (b != NULL) {
        printf("Name: %s, Author: %s, Pages: %d, Year: %d, ISBN: %s\n",
                b->name, b->author, b->pages, b->year_of_publication, b->isbn);
        b = b->next;
    }
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
