// 9.2 In addition to the 9.1, perform the following menu driven operations on BST.
// i. insert an element to the BST
// ii. display the largest element
// iii. display the smallest element
// iv. height of a node
// v. count number of leaf nodes

// Sample Input/Output:

// MAIN MENU
// 1. Insert
// 2. Largest
// 3. Smallest
// 4. Height
// 5. Count leaf nodes
// 6. Exit
// Enter option: 1

// Enter element to insert in BST: 21




//                 10
//                /   \
//              5      40
//           /  \     /  \
//          1    7   21   50

// Enter Option: 2
// Largest element in BST=50

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct Node *search(struct Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

int findLargest(struct Node *root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int findSmallest(struct Node *root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findHeight(struct Node *root) {
    if (root == NULL)
        return -1;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

int countLeafNodes(struct Node *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    struct Node *root = NULL;
    int n, key, option;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements of BST: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("BST Created:\n");
    

    do {
        printf("\nMAIN MENU\n");
        printf("1. Preorder\n");
        printf("2. Postorder\n");
        printf("3. Inorder\n");
        printf("4. Search\n");
        printf("5. Insert\n");
        printf("6. Largest\n");
        printf("7. Smallest\n");
        printf("8. Height\n");
        printf("9. Count leaf nodes\n");
        printf("10. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Preorder: ");
                preorder(root);
                break;
            case 2:
                printf("Postorder: ");
                postorder(root);
                break;
            case 3:
                printf("Inorder: ");
                inorder(root);
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL)
                    printf("%d is present in the BST.\n", key);
                else
                    printf("%d is not present in the BST.\n", key);
                break;
            case 5:
                printf("Enter element to insert in BST: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 6:
                if (root == NULL)
                    printf("BST is empty.\n");
                else
                    printf("Largest element in BST: %d\n", findLargest(root));
                break;
            case 7:
                if (root == NULL)
                    printf("BST is empty.\n");
                else
                    printf("Smallest element in BST: %d\n", findSmallest(root));
                break;
            case 8:
                if (root == NULL)
                    printf("BST is empty.\n");
                else {
                    printf("Enter element to find height: ");
                    scanf("%d", &key);
                    printf("Height of node %d: %d\n", key, findHeight(search(root, key)));
                }
                break;
            case 9:
                printf("Count of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 10:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

    } while (option != 10);

    return 0;
}



