// 4.3 Write a program to represent the polynomial equation of single variable using single linked list and perform the addition of two polynomial equations.
// Sample Input:
// Polynomial-1:
// Enter the Maximum power of x: 2
// Enter the coefficient of degree 2: 4
// Enter the coefficient of degree 1: 3
 
// Enter the coefficient of degree 0:2
// Polynomial-2:
// Enter the Maximum power of x: 3
// Enter the coefficient of degree 3: 5
// Enter the coefficient of degree 2: 4
// Enter the coefficient of degree 1:6
// Enter the coefficient of degree 0:10
 
// Sample Output:
// Sum: 5x^3+8x^2+9x^1+12x^0.


#include <stdio.h>
#include <stdlib.h>

struct node {
    int power;
    int coeff;
    struct node* next;
};

void traverse(struct node* ptr);
struct node* insert();
struct node* add(struct node* head1, struct node* head2);

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;

    printf("\nPolynomial 1:");
    head1 = insert();
    printf("\nPolynomial 2:");
    head2 = insert();
    head3 = add(head1, head2);

    printf("\nThe Addition of two polynomials is:");
    traverse(head3);

    // Free memory
    while (head1 != NULL) {
        struct node* temp = head1;
        head1 = head1->next;
        free(temp);
    }

    while (head2 != NULL) {
        struct node* temp = head2;
        head2 = head2->next;
        free(temp);
    }

    while (head3 != NULL) {
        struct node* temp = head3;
        head3 = head3->next;
        free(temp);
    }

    return 0;
}

struct node* insert() {
    int data, n, i;
    struct node* head = NULL;
    struct node* temp = NULL;

    printf("\nEnter the maximum power of x:");
    scanf("%d", &n);

    for (i = n; i >= 0; i--) {
        printf("Enter the coefficient of degree %d:\n", i);
        scanf("%d", &data);

        if (data != 0) {
            struct node* newnode = (struct node*)malloc(sizeof(struct node));
            newnode->power = i;
            newnode->coeff = data;
            newnode->next = NULL;

            if (temp == NULL) {
                head = newnode;
                temp = newnode;
            } else {
                temp->next = newnode;
                temp = newnode;
            }
        }
    }

    return head;
}

struct node* add(struct node* head1, struct node* head2) {
    struct node* head3 = NULL;
    struct node* temp3 = NULL;

    while (head1 != NULL && head2 != NULL) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->next = NULL;

        if (head1->power > head2->power) {
            newnode->coeff = head1->coeff;
            newnode->power = head1->power;
            head1 = head1->next;
        } else if (head2->power > head1->power) {
            newnode->coeff = head2->coeff;
            newnode->power = head2->power;
            head2 = head2->next;
        } else {
            newnode->coeff = head1->coeff + head2->coeff;
            newnode->power = head1->power;
            head1 = head1->next;
            head2 = head2->next;
        }

        if (temp3 == NULL) {
            head3 = newnode;
            temp3 = newnode;
        } else {
            temp3->next = newnode;
            temp3 = newnode;
        }
    }

    // Append the remaining terms from head1 and head2
    while (head1 != NULL) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->coeff = head1->coeff;
        newnode->power = head1->power;
        newnode->next = NULL;

        temp3->next = newnode;
        temp3 = newnode;
        head1 = head1->next;
    }

    while (head2 != NULL) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->coeff = head2->coeff;
        newnode->power = head2->power;
        newnode->next = NULL;

        temp3->next = newnode;
        temp3 = newnode;
        head2 = head2->next;
    }

    return head3;
}

void traverse(struct node* ptr) {
    printf("\n");
    while (ptr != NULL) {
        if (ptr->next != NULL)
            printf("%dX^%d+", ptr->coeff, ptr->power);
        else
            printf("%dX^%d", ptr->coeff, ptr->power);

        ptr = ptr->next;
    }
}
