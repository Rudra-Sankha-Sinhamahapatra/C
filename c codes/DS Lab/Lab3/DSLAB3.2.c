#include <stdio.h>

#define MAX 100

typedef struct {
  int row, col, val;
} Sparse;

void add_sparse(Sparse *sparse1, Sparse *sparse2, Sparse *sparse3, int m, int n) {
  int i, j;

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      sparse3[i].val = sparse1[i].val + sparse2[i].val;
    }
  }
}

int main() {
  int m, n, i, j;
  Sparse sparse1[MAX], sparse2[MAX], sparse3[MAX];

  printf("Enter the number of rows and columns of the first sparse matrix: ");
  scanf("%d %d", &m, &n);

  printf("Enter the elements of the first sparse matrix in 3-tuple format (row, column, value): ");
  for (i = 0; i < m; i++) {
    scanf("%d %d %d", &sparse1[i].row, &sparse1[i].col, &sparse1[i].val);
  }

  printf("Enter the number of rows and columns of the second sparse matrix: ");
  scanf("%d %d", &m, &n);

  printf("Enter the elements of the second sparse matrix in 3-tuple format (row, column, value): ");
  for (i = 0; i < m; i++) {
    scanf("%d %d %d", &sparse2[i].row, &sparse2[i].col, &sparse2[i].val);
  }

  add_sparse(sparse1, sparse2, sparse3, m, n);

  printf("The sum of the two sparse matrices is: \n");
  for (i = 0; i < m; i++) {
    printf("%d %d %d\n", sparse3[i].row, sparse3[i].col, sparse3[i].val);
  }

  return 0;
}
