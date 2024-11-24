#include <stdio.h>
#include <string.h>

#define SIZE 5 // Number of people

// Define a structure for a person in the linked list
typedef struct {
    char name[50]; // Name of the person
    int next;      // Index of the next node (-1 for end of list)
} Node;

int main() {
    // Array to hold names entered by the user
    char names[SIZE][50];
    
    // Prompt the user to input names
    printf("Enter %d names:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Name %d: ", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);
        // Remove trailing newline character
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    // Sort the names alphabetically
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char temp[50];
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    // Create an array of nodes
    Node list[SIZE];
    for (int i = 0; i < SIZE; i++) {
        strcpy(list[i].name, names[i]); // Copy name into the node
        if (i == SIZE - 1) {
            list[i].next = -1; // Last node points to -1
        } else {
            list[i].next = i + 1; // Link to the next node
        }
    }

    // Traverse and print the linked list
    int current = 0; // Start from the first node
    printf("\nNames in alphabetical order:\n");
    while (current != -1) {
        printf("%s\n", list[current].name);
        current = list[current].next; // Move to the next node
    }

    return 0;
}
