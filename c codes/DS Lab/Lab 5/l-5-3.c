// 5.3 Write a program to represent the given sparse matrix using header single linked list and
// display it.
// Sample Input:

// Enter size of the sparse matrix: 4 5
// Enter elements of sparse matrix: 0 0 33 0 0 0 17 0 0 0 0 0 0 46 0 0 0 0 0 51
// Sample Output:
// sparse matrix in 3-tuple format
// 4 5 4
// 0 2 33
// 1 1 17
// 2 3 46
// 3 4 51

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
};

struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}


void insertNode(struct Node** head, int row, int col, int value) {
    struct Node* newNode = createNode(row, col, value);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void displaySparseMatrix(struct Node* head, int rows, int cols) {
    struct Node* current = head;
    struct Node* p=head;
     int i=0;
  while(p!=NULL)
  {
   p=p->next;
   i++;
  }  
    printf("sparse matrix in 3-tuple format\n");
    printf("%d %d %d\n", rows, cols, i); 

    while (current != NULL) {
        printf("%d %d %d\n", current->row, current->col, current->value);
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;
    int rows, cols;

    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    printf("Enter elements of sparse matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                insertNode(&head, i, j, matrix[i][j]);
            }
        }
    }

    displaySparseMatrix(head, rows, cols);
    return 0;
}