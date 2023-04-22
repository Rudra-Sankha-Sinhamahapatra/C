#include <stdio.h>

int main() {
    int m, n, i, j;
    int matrix[100][100];

    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The matrix is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate row sums
    printf("Row sums:\n");
    for (i = 0; i < m; i++) {
        int row_sum = 0;
        for (j = 0; j < n; j++) {
            row_sum += matrix[i][j];
        }
        printf("%d ", row_sum);
    }
    printf("\n");

    // Calculate column sums
    printf("Column sums:\n");
    for (j = 0; j < n; j++) {
        int col_sum = 0;
        for (i = 0; i < m; i++) {
            col_sum += matrix[i][j];
        }
        printf("%d ", col_sum);
    }
    printf("\n");

    return 0;
}