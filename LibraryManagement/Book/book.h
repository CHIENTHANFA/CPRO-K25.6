#ifndef BOOK_H
#define BOOK_H

#define MAX_BOOKS 100
#define MAX_TITLE_LEN 100
#define MAX_AUTHOR_LEN 100

typedef enum {
    BOOK_OK = 0,
    BOOK_ERR_FULL,
    BOOK_ERR_NOT_FOUND,
    BOOK_ERR_BORROWED,
    BOOK_ERR_INVALID_ID
} BookError_t;

typedef struct {
    int id;
    char title[MAX_TITLE_LEN];
    char author[MAX_AUTHOR_LEN];
    int isBorrowed; /* 0: available, 1: borrowed */
} Book_t;

BookError_t addBook(Book_t books[], int *count);
BookError_t editBook(Book_t books[], int count);
BookError_t deleteBook(Book_t books[], int *count);
BookError_t borrowBook(Book_t books[], int count, int id);
BookError_t returnBook(Book_t books[], int count, int id);
void listBooks(Book_t books[], int count);
const char* bookErrorToString(BookError_t err);

#endif
