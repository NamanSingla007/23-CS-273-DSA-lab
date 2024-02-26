#include <stdio.h>

#define MAX_SIZE 100

void insertAtEnd(int arr[], int *size, int element) {
    if (*size >= MAX_SIZE) {
        printf("Overflow: Array is full\n");
        return;
    }
    arr[*size] = element;
    ++*size;
}

void deleteFromEnd(int arr[], int *size) {
    if (*size <= 0) {
        printf("Underflow: Array is empty\n");
        return;
    }
    --*size;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    // Insertion at end
    insertAtEnd(arr, &size, 10);
    insertAtEnd(arr, &size, 20);

    // Display array after insertion
    printf("Array after insertion at end: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Deletion from end
    deleteFromEnd(arr, &size);

    // Display array after deletion
    printf("Array after deletion from end: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

