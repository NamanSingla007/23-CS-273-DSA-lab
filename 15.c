#include <stdio.h>

#define MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

typedef struct {
    Element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
} SparseMatrix;

void displaySparseMatrix(SparseMatrix *sparseMatrix) {
    printf("Sparse Matrix Representation:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < sparseMatrix->terms; ++i) {
        printf("%d\t%d\t%d\n", sparseMatrix->data[i].row, sparseMatrix->data[i].col, sparseMatrix->data[i].value);
    }
}

void initializeSparseMatrix(SparseMatrix *sparseMatrix, int rows, int cols) {
    sparseMatrix->rows = rows;
    sparseMatrix->cols = cols;
    sparseMatrix->terms = 0;
}

void insertElement(SparseMatrix *sparseMatrix, int row, int col, int value) {
    if (sparseMatrix->terms >= MAX_TERMS) {
        printf("Cannot insert more elements: Sparse matrix full\n");
        return;
    }
    if (row >= sparseMatrix->rows || col >= sparseMatrix->cols) {
        printf("Invalid position: Out of bounds\n");
        return;
    }
    sparseMatrix->data[sparseMatrix->terms].row = row;
    sparseMatrix->data[sparseMatrix->terms].col = col;
    sparseMatrix->data[sparseMatrix->terms].value = value;
    ++sparseMatrix->terms;
}

SparseMatrix addSparseMatrices(SparseMatrix *matrix1, SparseMatrix *matrix2) {
    SparseMatrix result;
    initializeSparseMatrix(&result, matrix1->rows, matrix1->cols);
    int i = 0, j = 0, k = 0;
    while (i < matrix1->terms && j < matrix2->terms) {
        if (matrix1->data[i].row < matrix2->data[j].row ||
            (matrix1->data[i].row == matrix2->data[j].row && matrix1->data[i].col < matrix2->data[j].col)) {
            result.data[k++] = matrix1->data[i++];
        } else if (matrix1->data[i].row == matrix2->data[j].row && matrix1->data[i].col == matrix2->data[j].col) {
            result.data[k].row = matrix1->data[i].row;
            result.data[k].col = matrix1->data[i].col;
            result.data[k++].value = matrix1->data[i++].value + matrix2->data[j++].value;
        } else {
            result.data[k++] = matrix2->data[j++];
        }
    }
    while (i < matrix1->terms) {
        result.data[k++] = matrix1->data[i++];
    }
    while (j < matrix2->terms) {
        result.data[k++] = matrix2->data[j++];
    }
    result.terms = k;
    return result;
}

int main() {
    SparseMatrix matrix1, matrix2, result;
    
    // Initialize matrices
    initializeSparseMatrix(&matrix1, 3, 3);
    initializeSparseMatrix(&matrix2, 3, 3);
    
    // Insert elements into matrices
    insertElement(&matrix1, 0, 0, 1);
    insertElement(&matrix1, 1, 1, 2);
    insertElement(&matrix1, 2, 2, 3);
    insertElement(&matrix2, 0, 0, 4);
    insertElement(&matrix2, 1, 1, 5);
    insertElement(&matrix2, 2, 2, 6);
    
    // Display matrices
    printf("Matrix 1:\n");
    displaySparseMatrix(&matrix1);
    printf("\nMatrix 2:\n");
    displaySparseMatrix(&matrix2);
    
    // Add matrices
    result = addSparseMatrices(&matrix1, &matrix2);
    printf("\nResultant Matrix after addition:\n");
    displaySparseMatrix(&result);
    
    return 0;
}
