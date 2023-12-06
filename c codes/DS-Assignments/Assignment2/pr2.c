// 2. Given a binary search tree, design an algorithm which
// creates a linked list of all the nodes at each depth (eg, if you
// have a tree with depth D, you’ll have D linked lists).



#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct ListNode {
    int val;
    struct ListNode* next;
};

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode* insertAtEnd(struct ListNode* head, int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct ListNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

struct ListNode** createLevelLinkedLists(struct TreeNode* root, int* depth) {
    if (root == NULL) {
        *depth = 0;
        return NULL;
    }

    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    int front = -1, rear = -1;
    queue[++rear] = root;
    queue[++rear] = NULL;

    struct ListNode** result = (struct ListNode**)malloc(sizeof(struct ListNode*) * 1000);
    int currentDepth = 0;

    while (front != rear) {
        struct TreeNode* current = queue[++front];

        if (current == NULL) {
            if (front != rear) {
                queue[++rear] = NULL;
            }
            currentDepth++;
        } else {
            result[currentDepth] = insertAtEnd(result[currentDepth], current->val);

            if (current->left != NULL) {
                queue[++rear] = current->left;
            }
            if (current->right != NULL) {
                queue[++rear] = current->right;
            }
        }
    }

    *depth = currentDepth;
    free(queue);

    return result;
}

int main() {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 8;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 4;
    root->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->left->val = 2;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right->val = 6;
    root->left->right->left = NULL;
    root->left->right->right = NULL;

    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 12;
    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->left->val = 10;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->right->val = 14;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    int depth;
    struct ListNode** result = createLevelLinkedLists(root, &depth);

    for (int i = 0; i < depth; i++) {
        printf("Depth %d: ", i);
        printList(result[i]);
    }

    return 0;
}
