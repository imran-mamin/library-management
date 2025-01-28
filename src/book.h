#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

struct Book {
    char name[50];
    char author[50];
    int pages;
    int year_of_publication;
    char isbn[14]; // Officially it requires 13 and the '\0' character at the end.
    struct Book* next;
};

#endif /* BOOK_H_INCLUDED */