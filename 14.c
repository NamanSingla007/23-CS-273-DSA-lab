#include <stdio.h>

int findFloor(int arr[], int size, int key) {
    int floor = -1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] <= key) {
            floor = arr[i];
        } else {
            break;
        }
    }
    return floor;
}

int findCeil(int arr[], int size, int key) {
    int ceil = -1;
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= key) {
            ceil = arr[i];
            break;
        }
    }
    return ceil;
}

int findPeak(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (i == 0 && arr[i] > arr[i + 1]) {
            return arr[i];
        } else if (i == size - 1 && arr[i] > arr[i - 1]) {
            return arr[i];
        } else if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            return arr[i];
        }
    }
    return -1; // No peak found
}

int findMinimum(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 4;

    printf("Floor of %d: %d\n", key, findFloor(arr, size, key));
    printf("Ceil of %d: %d\n", key, findCeil(arr, size, key));
    printf("Peak element: %d\n", findPeak(arr, size));
    printf("Minimum element: %d\n", findMinimum(arr, size));

    return 0;
}
