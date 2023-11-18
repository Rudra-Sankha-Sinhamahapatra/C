// 9.1 Write a program to create a binary search tree of n data elements using linked list and perform the following menu driven operations:
// i. preorder traversal 
// ii. postorder traversal
// iii. inorder traversal
// iv. search an element 

// Sample Input/Output:

// Enter number of nodes: 6
// Enter elements of BST: 10  5  1  7  40  50
// BST Created: 

//                 10
//                /   \
//              5      40
//           /  \       \
//          1    7        50

// MAIN MENU
// 1. Preorder
// 2. Postorder
// 3. Inorder
// 4. Search
// 5. Exit
// Enter option: 1
// Preorder: 10  5  1  7  40  50
// Enter option: 2
// Postorder: 1  7  5  50  40  10


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    } else {
        if (key < root->key) {
            root->left = insert(root->left, key);
        } else {
            root->right = insert(root->right, key);
        }
    }
    return root;
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

struct Node* searchElement(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return searchElement(root->left, key);
    }
    return searchElement(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int choice, element;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Search an element\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                root = insert(root, element);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                if (searchElement(root, element) != NULL) {
                    printf("Element %d found in the tree.\n", element);
                } else {
                    printf("Element %d not found in the tree.\n", element);
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}