#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 100

typedef struct Node {
    char url[MAX_URL_LEN];
    struct Node* prev;
    struct Node* next;
} Node;

Node* current = NULL;

Node* createNode(const char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void visit(char* url) {
    Node* newPage = createNode(url);
    if (current != NULL) {
        
        if (current->next != NULL) {
            Node* temp = current->next;
            while (temp) {
                Node* toDelete = temp;
                temp = temp->next;
                free(toDelete);
            }
        }
        current->next = newPage;
        newPage->prev = current;
    }
    current = newPage;
    printf("Visited: %s\n", current->url);
}

void goBack() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Moved Back to: %s\n", current->url);
    } else {
        printf("No previous page to go back to.\n");
    }
}

void goForward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Moved Forward to: %s\n", current->url);
    } else {
        printf("No next page to go forward to.\n");
    }
}

void displayCurrentPage() {
    if (current != NULL) {
        printf("Current Page: %s\n", current->url);
    } else {
        printf("No page visited yet.\n");
    }
}

void freeAll() {

    while (current && current->prev) {
        current = current->prev;
    }
    Node* temp = current;
    while (temp) {
        Node* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
}

int main() {
    int choice;
    char url[MAX_URL_LEN];

    while (1) {
        printf("\n--- Browser Navigation ---\n");
        printf("1. Visit new page\n");
        printf("2. Go back\n");
        printf("3. Go forward\n");
        printf("4. Display current page\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter URL to visit: ");
                fgets(url, MAX_URL_LEN, stdin);
                url[strcspn(url, "\n")] = '\0';  
                visit(url);
                break;

            case 2:
                goBack();
                break;

            case 3:
                goForward();
                break;

            case 4:
                displayCurrentPage();
                break;

            case 5:
                freeAll();
                printf("Exiting browser...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
