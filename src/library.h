#include "book.h"

// Works as a linked list to store books.
struct Library {
    struct Book* first_book; // Works as a head of the linked list.
    struct Book* last_book; // Works as a tail of the linked list.
};

/* Will initialize the library with first_book and last_book pointing to NULL. */
struct Library* init_library();

void add_book(struct Library* lib, const char* name, const char* author, int pages, int year_of_publication, const char* isbn);

void delete_book(struct Library* lib, const char* isbn);

void show_library(struct Library* lib);

void free_memory(struct Library* lib);
