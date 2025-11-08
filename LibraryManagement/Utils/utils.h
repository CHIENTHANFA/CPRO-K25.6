#ifndef UTILS_H
#define UTILS_H

#include "../Book/book.h"
#include "../User/user.h"

void handleBorrowBook(Book_t books[], int bookCount, User_t users[], int userCount);
void handleReturnBook(Book_t books[], int bookCount, User_t users[], int userCount);
void searchBook(Book_t books[], int count);

#endif
