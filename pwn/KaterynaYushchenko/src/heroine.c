#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_NAMES 100

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

Node linkedList[MAX_NAMES];
int size = 0;

#define ANSI_COLOR_PINK "\x1b[38;5;207m"
#define ANSI_COLOR_RESET "\x1b[0m"

__attribute__((constructor)) void ignore_me() {
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
}

void printNames() {
    printf(ANSI_COLOR_PINK "<<< Cyber Heroines \n" ANSI_COLOR_RESET);
    Node* current = linkedList; // Start from the head of the linked list
    while (current != NULL) {
        printf("<<< Cyber Heroine: %s\n", current->name);
        current = current->next;
    }
}


void addName(const char* newName) {
    if (size >= MAX_NAMES) {
        printf(ANSI_COLOR_PINK "<<< Database is full \n" ANSI_COLOR_RESET);
        return;
    }

    Node* newNode = &linkedList[0];
    while (newNode->next != NULL) {
        newNode = newNode->next;
    }

    strcpy(newNode->name, newName); //, MAX_NAME_LENGTH);
    //newNode->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-terminated string

    newNode->next = (size < MAX_NAMES - 1) ? &linkedList[size + 1] : NULL;
    size++;

    printf(ANSI_COLOR_PINK "<<< Cyber Heroine added: %s\n" ANSI_COLOR_RESET, newName);
}


void deleteName(const char* targetName) {
    Node* current = &linkedList[0];
    Node* prev = NULL;

    while (current != NULL) {
        if (strncmp(current->name, targetName,50) == 0) {
            if (prev == NULL) {
                linkedList[0] = *current->next;
            } else {
                prev->next = current->next;
            }
            printf(ANSI_COLOR_PINK "<<< Cyber Heroine deleted: %s\n" ANSI_COLOR_RESET, targetName);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf(ANSI_COLOR_PINK "<<< Cyber Heroine not found: %s\n" ANSI_COLOR_RESET, targetName);
}

void editName(const char* oldName, const char* newName) {
    Node* current = &linkedList[0];

    while (current != NULL) {
        if (strncmp(current->name, oldName,50) == 0) {

            if (strlen(newName) < 50) {
                strncpy(current->name, newName, strlen(newName));
                current->name[50] = '\0';  
            } else {
                strncpy(current->name, newName, 60);
            }
            printf(ANSI_COLOR_PINK "<<< Cyber Heroine edited: %s -> %s\n" ANSI_COLOR_RESET, oldName, newName);
            return;
        }
        current = current->next;
    }
    printf(ANSI_COLOR_PINK "<<< Cyber Heroine not found: %s\n" ANSI_COLOR_RESET, oldName);
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH], newName[MAX_NAME_LENGTH];

    do {
        printf("\n");

        printf(ANSI_COLOR_PINK "---------------------------------------------\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_PINK "<<< Cyber Heroine Database v1.337\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_PINK "---------------------------------------------\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_PINK "<<< 1. Print all heroines\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_PINK "<<< 2. Add a new heroines\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_PINK "<<< 3. Delete a heroine\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_PINK "<<< 4. Edit a heroine\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_PINK "<<< 5. Exit\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_PINK "---------------------------------------------\n" ANSI_COLOR_RESET);
        printf(" Enter your choice >>> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printNames();
                break;
            case 2:
                printf("Enter a heroine to add >>> ");
                scanf("%s", name);
                addName(name);
                break;
            case 3:
                printf("Enter a heroine to delete >>> ");
                scanf("%s", name);
                deleteName(name);
                break;
            case 4:
                printf("Enter a heroine to edit >>> ");
                scanf("%s", name);
                printf("Enter the new heroine >>> ");
                scanf("%s", newName);
                editName(name, newName);
                break;
            case 5:
                printf(ANSI_COLOR_PINK "<<< Exiting program\n" ANSI_COLOR_RESET);
                break;
            default:
                printf(ANSI_COLOR_PINK "<<< Invalid choice\n" ANSI_COLOR_RESET);
                break;
        }
    } while (choice != 5);
    exit(0);
    return 0;
}
