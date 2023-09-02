#include <stdio.h>

#define MAX 100

typedef struct {
  int row, col, val;
} Sparse;

void transpose(Sparse *sparse, int m, int n) {
  int i, j;
  Sparse temp;

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (sparse[i].val != 0) {
        temp.row = j;
        temp.col = i;
        temp.val = sparse[i].val;
        sparse[i].val = 0;
        sparse[j] = temp;
      }
    }
  }
}

int main() {
  int m, n, i, j;
  Sparse sparse[MAX];

  printf("Enter the number of rows and columns of the sparse matrix: ");
  scanf("%d %d", &m, &n);

  printf("Enter the elements of the sparse matrix in 3-tuple format (row, column, value): ");
  for (i = 0; i < m; i++) {
    scanf("%d %d %d", &sparse[i].row, &sparse[i].col, &sparse[i].val);
  }

  transpose(sparse, m, n);

  printf("The transpose of the sparse matrix is: \n");
  for (i = 0; i < n; i++) {
    printf("%d %d %d\n", sparse[i].row, sparse[i].col, sparse[i].val);
  }

  return 0;
}
