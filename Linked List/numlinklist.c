#include <stdio.h>

#define SIZE 5 // Number of numbers to sort

// Define a structure for a node in the linked list
typedef struct {
    int value; // The number
    int next;  // Index of the next node (-1 for end of the list)
} Node;

void insertNode(Node list[], int *head, int value, int *freeIndex) {
    // Find a free node
    int newIndex = *freeIndex;
    if (newIndex == -1) {
        printf("List is full!\n");
        return;
    }

    // Assign value to the new node
    list[newIndex].value = value;
    list[newIndex].next = -1;

    // Update free index
    *freeIndex = (*freeIndex + 1 < SIZE) ? *freeIndex + 1 : -1;

    // Insert into the linked list
    if (*head == -1) {
        // First node in the list
        *head = newIndex;
    } else {
        // Find the correct position for sorted insertion
        int current = *head, previous = -1;
        while (current != -1 && list[current].value < value) {
            previous = current;
            current = list[current].next;
        }
        if (previous == -1) {
            // Insert at the head
            list[newIndex].next = *head;
            *head = newIndex;
        } else {
            // Insert between previous and current
            list[newIndex].next = list[previous].next;
            list[previous].next = newIndex;
        }
    }
}

void printList(Node list[], int head) {
    printf("Sorted numbers:\n");
    int current = head;
    while (current != -1) {
        printf("%d ", list[current].value);
        current = list[current].next;
    }
    printf("\n");
}

int main() {
    Node list[SIZE]; // Array to store nodes
    int head = -1;   // Index of the first node in the list (-1 means empty)
    int freeIndex = 0; // Index of the next free node

    // Prompt the user to enter numbers
    int numbers[SIZE];
    printf("Enter %d numbers:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Insert numbers into the linked list in sorted order
    for (int i = 0; i < SIZE; i++) {
        insertNode(list, &head, numbers[i], &freeIndex);
    }

    // Print the sorted list
    printList(list, head);

    return 0;
}
