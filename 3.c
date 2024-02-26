#include <stdio.h>

#define MAX_SIZE 100

void insertElement(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Overflow: Array is full\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position\n");
        return;
    }
    for (int i = *size; i > position; --i) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    ++(*size);
}

void deleteElement(int arr[], int *size, int position) {
    if (*size <= 0) {
        printf("Underflow: Array is empty\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Invalid position\n");
        return;
    }
    for (int i = position; i < *size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --(*size);
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    // Insertion
    insertElement(arr, &size, 10, 0); // Insert 10 at position 0
    insertElement(arr, &size, 20, 1); // Insert 20 at position 1

    // Display array after insertion
    printf("Array after insertion: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Deletion
    deleteElement(arr, &size, 0); // Delete element at position 0

    // Display array after deletion
    printf("Array after deletion: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
