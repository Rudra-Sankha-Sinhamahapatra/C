// Q2.Write C programme to delete an element from BST.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}


struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}


struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

  
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
       
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


struct Node* insert(struct Node* node, int key) {
  
    if (node == NULL)
        return newNode(key);


    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

   
    return node;
}


int main() {
    struct Node* root = NULL;
    int n, keyToDelete;
    
    printf("Enter the number of elements in the BST: ");
    scanf("%d", &n);

    printf("Enter the elements of the BST:\n");
    for (int i = 0; i < n; ++i) {
        int key;
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("Enter the element to delete from the BST: ");
    scanf("%d", &keyToDelete);

    printf("\nInorder traversal before deletion: ");
    inorder(root);

    root = deleteNode(root, keyToDelete);

    printf("\nInorder traversal after deletion of %d: ", keyToDelete);
    inorder(root);

    return 0;
}