#include <stdio.h>

#define MAX_SIZE 100

void insertAtBeginning(int arr[], int *size, int element) {
    if (*size >= MAX_SIZE) {
        printf("Overflow: Array is full\n");
        return;
    }
    for (int i = *size; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = element;
    ++*size;
}

void deleteFromBeginning(int arr[], int *size) {
    if (*size <= 0) {
        printf("Underflow: Array is empty\n");
        return;
    }
    for (int i = 0; i < *size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --*size;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    // Insertion at beginning
    insertAtBeginning(arr, &size, 10);
    insertAtBeginning(arr, &size, 20);

    // Display array after insertion
    printf("Array after insertion at beginning: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Deletion from beginning
    deleteFromBeginning(arr, &size);

    // Display array after deletion
    printf("Array after deletion from beginning: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
