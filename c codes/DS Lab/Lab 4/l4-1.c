// Write a program to create a single linked list of n nodes and perform the following menu based operations on it using function:
// i. Insert a node at specific position
// ii. Deletion of an element from specific position
// iii. Count nodes
// iv. Traverse the linked list
 
// Sample Input/Output:
// Enter number of nodes: 5
// Enter the elements: 17  23  47 11  78  92  51
// MENU:
// 1. Insert the node at a position
// 2. Delete a node from specific position
// 3. Count
// 4. Traversal
// 5. Exit
// Enter choice: 1
// Enter element: 66
// Enter position: 2
// Node inserted
// Enter choice: 4
// The list is: 17-> 66->23-> 47-> 11-> 78-> 92-> 51
// Enter the choice: 3
// The total number of nodes: 8
 
// Note: Other menu choices are similarly needs to verify.



#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void insertNode(struct Node** head, int element, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position to insert.\n");
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}


void deleteNode(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty, deletion not possible.\n");
        return;
    }

    struct Node* temp = *head;
    if (position == 1) {
        *head = temp->next;
        free(temp);
    } else {
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position to delete.\n");
        } else {
            struct Node* toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete);
        }
    }
}


int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


void traverseList(struct Node* head) {
    while (head != NULL) {
        printf("%d-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, choice, element, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        insertNode(&head, element, i + 1);
    }

    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Count\n");
        printf("4. Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &position);
                insertNode(&head, element, position);
                printf("Node inserted\n");
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;
            case 3:
                printf("The total number of nodes: %d\n", countNodes(head));
                break;
            case 4:
                printf("The list is: ");
                traverseList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
