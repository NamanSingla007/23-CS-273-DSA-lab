#include <stdio.h>

#define NUM_STUDENTS 3
#define NUM_SUBJECTS 5

void inputMarks(int marks[NUM_STUDENTS][NUM_SUBJECTS]) {
    printf("Enter marks for %d students in %d subjects:\n", NUM_STUDENTS, NUM_SUBJECTS);
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        printf("Student %d:\n", i + 1);
        for (int j = 0; j < NUM_SUBJECTS; ++j) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }
    }
}

void calculateTotals(int marks[NUM_STUDENTS][NUM_SUBJECTS]) {
    printf("Total marks of each student:\n");
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        int total = 0;
        for (int j = 0; j < NUM_SUBJECTS; ++j) {
            total += marks[i][j];
        }
        printf("Student %d: %d\n", i + 1, total);
    }
}

void calculateAverages(int marks[NUM_STUDENTS][NUM_SUBJECTS]) {
    printf("Average marks of each subject:\n");
    for (int j = 0; j < NUM_SUBJECTS; ++j) {
        int total = 0;
        for (int i = 0; i < NUM_STUDENTS; ++i) {
            total += marks[i][j];
        }
        printf("Subject %d: %.2f\n", j + 1, (float)total / NUM_STUDENTS);
    }
}

int main() {
    int marks[NUM_STUDENTS][NUM_SUBJECTS];
    inputMarks(marks);
    calculateTotals(marks);
    calculateAverages(marks);
    return 0;
}
