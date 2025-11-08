#include "../Book/book.h"
#include "../User/user.h"
#include "../Utils/utils.h"
#include <stdio.h>

void manageLibrary(void) {
    Book_t books[MAX_BOOKS];
    User_t users[MAX_USERS];
    int bookCount = 0, userCount = 0;
    int choice;
    BookError_t bErr;
    UserError_t uErr;

    while (1) {
        printf("\n===== MENU =====\n");
        printf("1. Them sach\n");
        printf("2. Sua sach\n");
        printf("3. Xoa sach\n");
        printf("4. Them nguoi dung\n");
        printf("5. Xoa nguoi dung\n");
        printf("6. Muon sach\n");
        printf("7. Tra sach\n");
        printf("8. Tim sach\n");
        printf("9. Danh sach sach\n");
        printf("10. Danh sach nguoi dung\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: bErr = addBook(books, &bookCount); printf("[LOG] %s\n", bookErrorToString(bErr)); break;
            case 2: bErr = editBook(books, bookCount); printf("[LOG] %s\n", bookErrorToString(bErr)); break;
            case 3: bErr = deleteBook(books, &bookCount); printf("[LOG] %s\n", bookErrorToString(bErr)); break;
            case 4: uErr = addUser(users, &userCount); printf("[LOG] %s\n", userErrorToString(uErr)); break;
            case 5: uErr = deleteUser(users, &userCount); printf("[LOG] %s\n", userErrorToString(uErr)); break;
            case 6: handleBorrowBook(books, bookCount, users, userCount); break;
            case 7: handleReturnBook(books, bookCount, users, userCount); break;
            case 8: searchBook(books, bookCount); break;
            case 9: listBooks(books, bookCount); break;
            case 10: listUsers(users, userCount); break;
            case 0: printf("Thoat chuong trinh.\n"); return;
            default: printf("Lua chon khong hop le.\n");
        }
    }
}
