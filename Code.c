#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 50

// Structure to represent a book
struct Book {
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int id;
};

// Global array to store books
struct Book library[MAX_BOOKS];
int numBooks = 0;

// Function prototypes
void addBook();
void displayBooks();
void searchBook(char *title);
void deleteBook(char *title);

int main() {
    int choice;
    char title[TITLE_LENGTH];

    do {
        // Display menu
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                printf("Enter the title of the book to search: ");
                getchar(); // Clear input buffer
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove trailing newline
                searchBook(title);
                break;
            case 4:
                printf("Enter the title of the book to delete: ");
                getchar(); // Clear input buffer
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove trailing newline
                deleteBook(title);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a book to the library
void addBook() {
    if (numBooks == MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter book title: ");
    getchar(); // Clear input buffer
    fgets(library[numBooks].title, TITLE_LENGTH, stdin);
    library[numBooks].title[strcspn(library[numBooks].title, "\n")] = '\0'; // Remove trailing newline

    printf("Enter author name: ");
    fgets(library[numBooks].author, AUTHOR_LENGTH, stdin);
    library[numBooks].author[strcspn(library[numBooks].author, "\n")] = '\0'; // Remove trailing newline

    library[numBooks].id = numBooks + 1;

    printf("Book added successfully.\n");

    numBooks++;
}

// Function to display all books in the library
void displayBooks() {
    if (numBooks == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("List of Books:\n");
    printf("ID\tTitle\t\tAuthor\n");
    for (int i = 0; i < numBooks; i++) {
        printf("%d\t%s\t\t%s\n", library[i].id, library[i].title, library[i].author);
    }
}

// Function to search for a book by title
void searchBook(char *title) {
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Book found:\n");
            printf("ID\tTitle\t\tAuthor\n");
            printf("%d\t%s\t\t%s\n", library[i].id, library[i].title, library[i].author);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}

// Function to delete a book from the library
void deleteBook(char *title) {
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Book deleted:\n");
            printf("ID\tTitle\t\tAuthor\n");
            printf("%d\t%s\t\t%s\n", library[i].id, library[i].title, library[i].author);
            found = 1;
            // Shift remaining books to fill the gap
            for (int j = i; j < numBooks - 1; j++) {
                library[j] = library[j + 1];
            }
            numBooks--;
            break;
        }
    }
    if (!found) {
        printf("Book not found.\n");
    }
}
