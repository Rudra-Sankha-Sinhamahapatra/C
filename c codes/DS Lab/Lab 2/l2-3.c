//    WAP to represent a given sparse matrix in 3-tuple format using 2-D array.
 
// Sample Input:
 
// Enter size of the sparse matrix: 4 5
// Enter elements of sparse matrix: 0  0  33  0  0  0  17  0  0  0  0  0  0  46  0  0  0  0  0  51
 
// Sample Output:
// sparse matrix in 3-tuple format
// 4   5   4
// 0   2   33
// 1   1   17
// 2   3   46
// 3   4   51
#include <stdio.h>

int main() {
    int i, j, r, c, count = 0, r1 = 1, c1 = 0,arr[10][10];
    
    printf("Enter the size of the sparse matrix (rows columns): ");
    scanf("%d %d", &r, &c);
    
    printf("Enter elements of the sparse matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] != 0)
                count++;
        }
    }
    
    int sparse[count + 1][3];
    sparse[0][0] = r;
    sparse[0][1] = c;
    sparse[0][2] = count;
    
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (arr[i][j] != 0) {
                sparse[r1][0] = i;
                sparse[r1][1] = j;
                sparse[r1][2] = arr[i][j];
                r1++;
            }
        }
    }
    
    printf("Sparse matrix in 3-tuple format:\n");
    for (i = 0; i <= count; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", sparse[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}