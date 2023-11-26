#include <stdio.h>
#include <stdlib.h>

struct Node {
    int INFO;
    struct Node *left_child;
    struct Node *right_child;
};

// Function to perform in-order traversal of the binary tree
void in_order_traversal(struct Node *node) {
    if (node != NULL) {
        // Traverse the left subtree
        in_order_traversal(node->left_child);

        // Process the current node
        printf("%d ", node->INFO);

        // Traverse the right subtree
        in_order_traversal(node->right_child);
    }
}

// Function to create a binary tree
void create_tree(struct Node *node) {
    int value;

    // Input for left child
    printf("Enter the value for left child of %d (Enter -1 if no left child): ", node->INFO);
    scanf("%d", &value);

    if (value != -1) {
        // Create left child
        node->left_child = (struct Node *)malloc(sizeof(struct Node));
        node->left_child->INFO = value;
        node->left_child->left_child = NULL;
        node->left_child->right_child = NULL;

        // Recursively create left subtree
        create_tree(node->left_child);
    } else {
        node->left_child = NULL;
    }

    // Input for right child
    printf("Enter the value for right child of %d (Enter -1 if no right child): ", node->INFO);
    scanf("%d", &value);

    if (value != -1) {
        // Create right child
        node->right_child = (struct Node *)malloc(sizeof(struct Node));
        node->right_child->INFO = value;
        node->right_child->left_child = NULL;
        node->right_child->right_child = NULL;

        // Recursively create right subtree
        create_tree(node->right_child);
    } else {
        node->right_child = NULL;
    }
}

int main() {
    struct Node *Root;
    Root = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the value for root: ");
    scanf("%d", &Root->INFO);

    Root->left_child = NULL;
    Root->right_child = NULL;

    // Create the binary tree
    create_tree(Root);

    // Perform in-order traversal
    printf("In-order Traversal: ");
    in_order_traversal(Root);

    // Free allocated memory (optional but recommended)
    // You may want to free the memory after using the tree
    // Uncomment the line below if you want to free the memory
    // free(Root);

    return 0;
}
