#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct UserInfo {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

union User {
    struct UserInfo info;
    int isActive;
};

union User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount == MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    union User newUser;

    printf("Enter username: ");
    scanf("%s", newUser.info.username);

    printf("Enter password: ");
    scanf("%s", newUser.info.password);

    printf("Activation Status (1 for active, 0 for inactive): ");
    scanf("%d", &newUser.isActive);

    users[userCount++] = newUser;

    printf("User registered successfully.\n");
}

void loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].info.username, username) == 0 && strcmp(users[i].info.password, password) == 0 && users[i].isActive == 1) {
            printf("Login successful. Welcome, %s!\n", username);
            return;
        }
    }

    printf("Invalid username or password or this user hasn't activated yet.\n");
}

int main() {
    int choice;

    do {
        printf("\n-- User Management System --\n");
        printf("1. Register a new user\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
