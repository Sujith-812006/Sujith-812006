#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;               
    struct TreeNode *left;    
    struct TreeNode *right;  
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printInOrder(TreeNode* node) {
    if (node != NULL) {
        printInOrder(node->left);
        printf("%d\n", node->value);
        printInOrder(node->right);
    }
}

int main() {
    // Create nodes
    TreeNode* root = createNode(1);
    root->left = createNode(4);
    root->right = createNode(5);

    root->left->left = createNode(2);
    root->left->right = createNode(6);
    root->right->left = createNode(16);
    root->right->right = createNode(20);
    printf("In-order inorders of the binary tree:\n");
    printInOrder(root);

    return 0;
}
