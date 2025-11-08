#include "utils.h"
#include <stdio.h>
#include <string.h>

void handleBorrowBook(Book_t books[], int bookCount, User_t users[], int userCount) {
    int userId, bookId;
    printf("Nhap ID nguoi dung: ");
    scanf("%d", &userId);
    printf("Nhap ID sach: ");
    scanf("%d", &bookId);

    if (userId < 1 || userId > userCount) {
        printf("ERROR: Nguoi dung khong ton tai.\n");
        return;
    }

    if (users[userId - 1].borrowedCount >= MAX_BORROWED_BOOKS) {
        printf("ERROR: Nguoi dung da muon toi da sach.\n");
        return;
    }

    BookError_t err = borrowBook(books, bookCount, bookId);
    printf("[LOG] %s\n", bookErrorToString(err));

    if (err == BOOK_OK) {
        users[userId - 1].borrowedBooks[users[userId - 1].borrowedCount++] = bookId;
    }
}

void handleReturnBook(Book_t books[], int bookCount, User_t users[], int userCount) {
    int userId, bookId;
    printf("Nhap ID nguoi dung: ");
    scanf("%d", &userId);
    printf("Nhap ID sach tra: ");
    scanf("%d", &bookId);

    if (userId < 1 || userId > userCount) {
        printf("ERROR: Nguoi dung khong ton tai.\n");
        return;
    }

    BookError_t err = returnBook(books, bookCount, bookId);
    printf("[LOG] %s\n", bookErrorToString(err));

    if (err == BOOK_OK) {
        for (int i = 0; i < users[userId - 1].borrowedCount; i++) {
            if (users[userId - 1].borrowedBooks[i] == bookId) {
                for (int j = i; j < users[userId - 1].borrowedCount - 1; j++) {
                    users[userId - 1].borrowedBooks[j] = users[userId - 1].borrowedBooks[j + 1];
                }
                users[userId - 1].borrowedCount--;
                break;
            }
        }
    }
}

void searchBook(Book_t books[], int count) {
    char keyword[100];
    printf("Nhap tu khoa (tieu de/tac gia): ");
    scanf(" %[^\n]", keyword);
    printf("\nKet qua tim kiem:\n");
    for (int i = 0; i < count; i++) {
        if (strstr(books[i].title, keyword) || strstr(books[i].author, keyword)) {
            printf("ID: %d | %s - %s | %s\n",
                   books[i].id, books[i].title, books[i].author,
                   books[i].isBorrowed ? "Da muon" : "Con trong");
        }
    }
}
