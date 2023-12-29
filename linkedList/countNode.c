#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to count the number of nodes in a linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head; // Start from the head of the list

    // Traverse the list until the end is reached (NULL)
    while (current != NULL) {
        count++; // Increment the count for each node
        current = current->next; // Move to the next node
    }

    return count;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int newData) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;

    // Update the head to point to the new node
    *head = newNode;
}

// Function to print the elements of the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Example usage
int main() {
    // Create an empty linked list
    struct Node* head = NULL;

    // Insert some nodes at the beginning of the list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 4);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Count the number of nodes
    int nodeCount = countNodes(head);
    printf("Number of nodes: %d\n", nodeCount);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
    }