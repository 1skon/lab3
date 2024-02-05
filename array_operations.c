
#include <stdio.h>
#include <stdlib.h>
#include "array_operations.h"

void initializeArray(int **array, int *size) {
    printf("Enter the size of the array: ");
    scanf("%d", size);

    *array = (int *)malloc(*size * sizeof(int));

    if (*array == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter elements of the array:\n");
    for (int i = 0; i < *size; ++i) {
        printf("Element %d: ", i);
        scanf("%d", &(*array)[i]);
    }
}

void insertElement(int **array, int *size, int index, int value) {
    *array = (int *)realloc(*array, (*size + 1) * sizeof(int));

    if (*array == NULL) {
        fprintf(stderr, "Memory reallocation error.\n");
        exit(EXIT_FAILURE);
    }

    if (index < 0 || index > *size) {
        printf("Invalid index for insertion.\n");
        return;
    }

    for (int i = *size; i > index; --i) {
        (*array)[i] = (*array)[i - 1];
    }

    (*array)[index] = value;
    (*size)++;
}

void deleteElement(int **array, int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Invalid index for deletion.\n");
        return;
    }

    for (int i = index; i < *size - 1; ++i) {
        (*array)[i] = (*array)[i + 1];
    }

    *array = (int *)realloc(*array, (*size - 1) * sizeof(int));

    if (*size > 0 && *array == NULL) {
        fprintf(stderr, "Memory reallocation error.\n");
        exit(EXIT_FAILURE);
    }

    (*size)--;
}

void processIndividualTask(int **array, int *size) {
     int *newArray = (int *)malloc(size * sizeof(int)); 
    int newSize = 0;

    int i = 0;
    while (i < size) {
        newArray[newSize++] = array[i];

        // Находим группу подряд стоящих одинаковых чисел
        int j = i + 1;
        while (j < size && array[j] == array[i]) {
            j++;
        }

        i = j;
    }
    printf("Individual task completed.\n");
}

void printArray(const int *array, int size) {
    printf("Current state of the array:\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
