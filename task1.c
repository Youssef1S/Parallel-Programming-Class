#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount == MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    struct User newUser;

    printf("Enter username: ");
    scanf("%s", newUser.username);

    printf("Enter password: ");
    scanf("%s", newUser.password);

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
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful. Welcome, %s!\n", username);
            return;
        }
    }

    printf("Invalid username or password.\n");
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