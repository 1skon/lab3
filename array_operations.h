
#ifndef ARRAY_OPERATIONS_H
#define ARRAY_OPERATIONS_H

void initializeArray(int **array, int *size);
void insertElement(int **array, int *size, int index, int value);
void deleteElement(int **array, int *size, int index);
void processIndividualTask(int **array, int *size);
void printArray(const int *array, int size);

#endif
