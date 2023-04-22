#include <stdio.h>

int main() {
   int n, i, j;
   int matrix[100][100];

   printf("Enter the size of the square matrix: ");
   scanf("%d", &n);

   printf("Enter the elements of the matrix:\n");
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }

   printf("The upper triangular matrix is:\n");
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         if (j >= i) {
            printf("%d ", matrix[i][j]);
         } else {
            printf("  ");
         }
      }
      printf("\n");
   }

   printf("The lower triangular matrix is:\n");
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         if (j <= i) {
            printf("%d ", matrix[i][j]);
         } else {
            printf("  ");
         }
      }
      printf("\n");
   }

   return 0;
}
