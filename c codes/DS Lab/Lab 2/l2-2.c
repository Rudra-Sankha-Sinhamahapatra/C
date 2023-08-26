// Write a program to perform the following operations on a given square matrix using functions:
// i. Find the no.of nonzero elements
// ii. Display upper triangular matrix
// iii. Display the elements of just above and below the main diagonal
// Sample Input:
// Enter size of the square matrix: 4

// CS29001 Data Structure Lab Manual

// School of Computer EngineeringPage 4
// Enter elements of the matrix:
// 8 2 1 0
// 1 0 7 6
// 0 6 2 4
// 3 9 5 0
// Sample Output:
// Nonzero elements : 12
// Upper triangular matrix:
// 2 1 0
// 7 6
//   4
#include <stdio.h>


int countNonZero(int matrix[][100], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}


void displayUpperTriangular(int matrix[][100], int size) {
    printf("Upper triangular matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j >= i) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}


void displayDiagonalElements(int matrix[][100], int size) {
    printf("Elements above the main diagonal:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j > i) {
                printf("%d ", matrix[i][j]);
            }
             else {
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("Elements below the main diagonal:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j < i) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter size of the square matrix: ");
    scanf("%d", &size);

    int matrix[100][100];
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }


    int nonzeroCount = countNonZero(matrix, size);
    printf("Nonzero elements: %d\n", nonzeroCount);


    displayUpperTriangular(matrix, size);

    
    displayDiagonalElements(matrix, size);

    return 0;
}