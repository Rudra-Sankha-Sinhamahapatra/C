#include <stdio.h>

#define MAX 100

void add_polynomials(int poly1[], int poly2[], int n1, int n2, int poly3[]) {
  int i, j, k;

  // Initialize the sum polynomial.
  for (i = 0; i < MAX; i++) {
    poly3[i] = 0;
  }

  // Add the terms of the two polynomials.
  for (i = 0; i < n1; i++) {
    poly3[i] += poly1[i];
  }

  for (j = 0; j < n2; j++) {
    poly3[j] += poly2[j];
  }
}

int main() {
  int poly1[MAX], poly2[MAX], poly3[MAX];
  int n1, n2, i;

  printf("Enter the number of terms in the first polynomial: ");
  scanf("%d", &n1);

  printf("Enter the coefficients of the first polynomial: ");
  for (i = 0; i < n1; i++) {
    scanf("%d", &poly1[i]);
  }

  printf("Enter the number of terms in the second polynomial: ");
  scanf("%d", &n2);

  printf("Enter the coefficients of the second polynomial: ");
  for (i = 0; i < n2; i++) {
    scanf("%d", &poly2[i]);
  }

  // Add the two polynomials.
  add_polynomials(poly1, poly2, n1, n2, poly3);

  // Print the sum polynomial.
  printf("The sum of the two polynomials is: ");
  for (i = 0; i < MAX; i++) {
    if (poly3[i] != 0) {
      printf("%d x^%d + ", poly3[i], i);
    }
  }

  printf("\b\b\n");

  return 0;
}
