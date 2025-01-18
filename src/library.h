#include "book.h"

// Works as a linked list to store books.
struct Library {
    struct Book* first_book; // Works as a head of the linked list.
    struct Book* last_book; // Works as a tail of the linked list.
};

/* Will initialize the library with some default book. */
const struct Library* init_library();

void add_book(struct Library* lib, const char* name, const char* author, const int pages, const int year_of_publication);

void free_memory(struct Library* lib);
