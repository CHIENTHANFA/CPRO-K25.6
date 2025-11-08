#include "user.h"
#include <stdio.h>
#include <string.h>

UserError_t addUser(User_t users[], int *count) {
    if (*count >= MAX_USERS) return USER_ERR_FULL;
    User_t newUser;
    newUser.id = *count + 1;
    printf("Nhap ten nguoi dung: ");
    scanf(" %[^\n]", newUser.name);
    newUser.borrowedCount = 0;
    users[*count] = newUser;
    (*count)++;
    return USER_OK;
}

UserError_t deleteUser(User_t users[], int *count) {
    int id;
    printf("Nhap ID nguoi dung can xoa: ");
    scanf("%d", &id);
    if (id < 1 || id > *count) return USER_ERR_NOT_FOUND;

    for (int i = id - 1; i < *count - 1; i++) {
        users[i] = users[i + 1];
    }
    (*count)--;
    return USER_OK;
}

void listUsers(User_t users[], int count) {
    printf("\n--- DANH SACH NGUOI DUNG ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Ten: %s | So sach muon: %d\n",
               users[i].id, users[i].name, users[i].borrowedCount);
    }
}

const char* userErrorToString(UserError_t err) {
    switch (err) {
        case USER_OK: return "SUCCESS";
        case USER_ERR_FULL: return "ERROR: Danh sach nguoi dung day.";
        case USER_ERR_NOT_FOUND: return "ERROR: Khong tim thay nguoi dung.";
        case USER_ERR_LIMIT: return "ERROR: Nguoi dung da muon toi da.";
        default: return "ERROR: Loi khong xac dinh.";
    }
}
