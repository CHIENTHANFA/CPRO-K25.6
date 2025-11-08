#ifndef USER_H
#define USER_H

#define MAX_USERS 50
#define MAX_NAME_LEN 100
#define MAX_BORROWED_BOOKS 5

typedef enum {
    USER_OK = 0,
    USER_ERR_FULL,
    USER_ERR_NOT_FOUND,
    USER_ERR_LIMIT
} UserError_t;

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int borrowedBooks[MAX_BORROWED_BOOKS];
    int borrowedCount;
} User_t;

UserError_t addUser(User_t users[], int *count);
UserError_t deleteUser(User_t users[], int *count);
void listUsers(User_t users[], int count);
const char* userErrorToString(UserError_t err);

#endif
