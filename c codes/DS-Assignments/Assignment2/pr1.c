// 1. You are given a binary tree in which each node contains a
// value. Design an algorithm to print all paths which sum up
// to that value. Note that it can be any path in the tree - it does
// not have to start at the root.

#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct PathNode {
    int val;
    struct PathNode* next;
};


void printPath(struct PathNode* path) {
    while (path != NULL) {
        printf("%d ", path->val);
        path = path->next;
    }
    printf("\n");
}


void findPaths(struct TreeNode* root, int targetSum, struct PathNode* currentPath, int currentSum) {
    if (root == NULL) {
        return;
    }

    struct PathNode* newNode = (struct PathNode*)malloc(sizeof(struct PathNode));
    newNode->val = root->val;
    newNode->next = currentPath;


    currentSum += root->val;
  
    if (currentSum == targetSum) {
        printPath(newNode);
    }


    findPaths(root->left, targetSum, newNode, currentSum);
    findPaths(root->right, targetSum, newNode, currentSum);

   
    findPaths(root->left, targetSum, NULL, 0);
    findPaths(root->right, targetSum, NULL, 0);


    free(newNode);
}


void printPathsSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return;
    }

    findPaths(root, targetSum, NULL, 0);
}

int main() {
   
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 10;

    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 5;

    root->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->left->val = 3;

    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->val = 2;

    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = -3;

    root->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right->val = 11;


    printf("Paths with sum 8:\n");
    printPathsSum(root, 8);

   
    free(root->right->right);
    free(root->right);
    free(root->left->right);
    free(root->left->left);
    free(root->left);
    free(root);

    return 0;
}

