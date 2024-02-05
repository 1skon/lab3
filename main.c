#include <stdio.h>
#include <stdlib.h>
#include "array_operations.h"

int main() {
    int *array = NULL;
    int size = 0;
    char choice;

    while (1) {
        printf("\nSelect an action:\n");
        printf("(a) Initialize the array.\n");
        printf("(b) Insert a new element.\n");
        printf("(c) Delete an element.\n");
        printf("(d) Individual task.\n");
        printf("(e) Print the contents of the array.\n");
        printf("(q) Quit.\n");

        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                initializeArray(&array, &size);
                break;
            case 'b': {
                int index, value;
                printf("Enter the index for insertion: ");
                scanf("%d", &index);
                printf("Enter the value of the new element: ");
                scanf("%d", &value);
                insertElement(&array, &size, index, value);
                break;
            }
            case 'c': {
                int index;
                printf("Enter the index for deletion: ");
                scanf("%d", &index);
                deleteElement(&array, &size, index);
                break;
            }
            case 'd':
                processIndividualTask(&array, &size);
                break;
            case 'e':
                printArray(array, size);
                break;
            case 'q':
                free(array); // Free allocated memory before exiting
                printf("Program terminated.\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}



