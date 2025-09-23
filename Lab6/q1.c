#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Global pointers
struct Node *first = NULL;
struct Node *last = NULL;

// Function to insert at the end
void insertEnd(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (first == NULL) {
        // First node
        first = newNode;
        last = newNode;
        newNode->next = first;  // Circular link
    } else {
        last->next = newNode;
        last = newNode;
        last->next = first;  // Maintain circular link
    }
    printf("Inserted %d at the end.\n", value);
}

// Function to delete from the beginning
void deleteBegin() {
    if (first == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node *temp = first;
    if (first == last) {  // Only one node
        first = NULL;
        last = NULL;
    } else {
        first = first->next;
        last->next = first;
    }
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

// Function to delete from the end
void deleteEnd() {
    if (first == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node *temp = last;
    if (first == last) {  // Only one node
        first = NULL;
        last = NULL;
    } else {
        struct Node *current = first;
        while (current->next != last) {
            current = current->next;
        }
        current->next = first;
        last = current;
    }
    printf("Deleted %d from the end.\n", temp->data);
    free(temp);
}

// Function to display the list
void display() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *current = first;
    printf("Circular Linked List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != first);
    printf("\n");
}

// Main function with menu
int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Singly Linked List Menu ---\n");
        printf("1. Insert at end\n");
        printf("2. Delete from beginning\n");
        printf("3. Delete from end\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(value);
                display();
                break;
            case 2:
                deleteBegin();
                display();
                break;
            case 3:
                deleteEnd();
                display();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
