#include <stdio.h>

int main() {
   int n, i, j;
   int matrix[100][100];
   int leading_diag_sum = 0, trailing_diag_sum = 0;

   printf("Enter the size of the square matrix: ");
   scanf("%d", &n);

   printf("Enter the elements of the matrix:\n");
   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }

   // Calculate the sum of the leading diagonal elements
   for (i = 0; i < n; i++) {
      leading_diag_sum += matrix[i][i];
   }

   // Calculate the sum of the trailing diagonal elements
   for (i = 0; i < n; i++) {
      trailing_diag_sum += matrix[i][n-i-1];
   }

   printf("The sum of the leading diagonal elements is %d\n", leading_diag_sum);
   printf("The sum of the trailing diagonal elements is %d\n", trailing_diag_sum);

   return 0;
}
