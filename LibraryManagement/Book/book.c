#include "book.h"
#include <stdio.h>
#include <string.h>

BookError_t addBook(Book_t books[], int *count) {
    if (*count >= MAX_BOOKS) return BOOK_ERR_FULL;
    Book_t newBook;
    newBook.id = *count + 1;
    printf("Nhap tieu de sach: ");
    scanf(" %[^\n]", newBook.title);
    printf("Nhap ten tac gia: ");
    scanf(" %[^\n]", newBook.author);
    newBook.isBorrowed = 0;
    books[*count] = newBook;
    (*count)++;
    return BOOK_OK;
}

BookError_t editBook(Book_t books[], int count) {
    int id;
    printf("Nhap ID sach can sua: ");
    scanf("%d", &id);
    if (id < 1 || id > count) return BOOK_ERR_INVALID_ID;

    printf("Nhap tieu de moi: ");
    scanf(" %[^\n]", books[id - 1].title);
    printf("Nhap tac gia moi: ");
    scanf(" %[^\n]", books[id - 1].author);
    return BOOK_OK;
}

BookError_t deleteBook(Book_t books[], int *count) {
    int id;
    printf("Nhap ID sach can xoa: ");
    scanf("%d", &id);
    if (id < 1 || id > *count) return BOOK_ERR_NOT_FOUND;
    if (books[id - 1].isBorrowed) return BOOK_ERR_BORROWED;

    for (int i = id - 1; i < *count - 1; i++) {
        books[i] = books[i + 1];
    }
    (*count)--;
    return BOOK_OK;
}

BookError_t borrowBook(Book_t books[], int count, int id) {
    if (id < 1 || id > count) return BOOK_ERR_INVALID_ID;
    if (books[id - 1].isBorrowed) return BOOK_ERR_BORROWED;
    books[id - 1].isBorrowed = 1;
    return BOOK_OK;
}

BookError_t returnBook(Book_t books[], int count, int id) {
    if (id < 1 || id > count) return BOOK_ERR_INVALID_ID;
    books[id - 1].isBorrowed = 0;
    return BOOK_OK;
}

void listBooks(Book_t books[], int count) {
    printf("\n--- DANH SACH SACH ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | %s - %s | %s\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].isBorrowed ? "Da muon" : "Con trong");
    }
}

const char* bookErrorToString(BookError_t err) {
    switch (err) {
        case BOOK_OK: return "SUCCESS";
        case BOOK_ERR_FULL: return "ERROR: Thu vien da day.";
        case BOOK_ERR_NOT_FOUND: return "ERROR: Khong tim thay sach.";
        case BOOK_ERR_BORROWED: return "ERROR: Sach dang duoc muon.";
        case BOOK_ERR_INVALID_ID: return "ERROR: ID khong hop le.";
        default: return "ERROR: Loi khong xac dinh.";
    }
}
