#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void insertNode(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if (position == 1) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    int count = 1;

    while (count < position - 1 && current->next != NULL) {
        current = current->next;
        count++;
    }

    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
}


void deleteNode(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }

    if (position == 1) {
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    struct Node* current = *head;
    int count = 1;

    while (count < position && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid position for deletion.\n");
        return;
    }

    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
}


void traverse(struct Node* head) {
    printf("The list is: ");
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int numNodes, choice, position, element;

    printf("Enter number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the elements: ");
    for (int i = 0; i < numNodes; i++) {
        scanf("%d", &element);
        insertNode(&head, element, i + 1);
    }

    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert a node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
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
                traverse(head);
                break;
            case 4: 
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
