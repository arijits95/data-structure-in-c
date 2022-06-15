#include<stdio.h>
#include<stdlib.h>
#include "../include/binary_tree.h"

Node* create_binary_tree(int elements[], int size) {
    
    static int i = -1;
    i++;

    if (i >= size) {
        return NULL;
    }

    if (elements[i] == -1) {
        return NULL;
    }

    Node* root = (Node*)malloc(sizeof(Node));
    root->data = elements[i];
    root->left_child = create_binary_tree(elements, size);
    root->right_child = create_binary_tree(elements, size);
    return root;
}

void preorder_traversal(Node* root) {

    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder_traversal(root->left_child);
    preorder_traversal(root->right_child);
}

void inorder_traversal(Node* root) {

    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left_child);
    printf("%d ", root->data);
    inorder_traversal(root->right_child);
}

void postorder_traversal(Node *root) {

    if (root == NULL) {
        return;
    }

    postorder_traversal(root->left_child);
    postorder_traversal(root->right_child);
    printf("%d ", root->data);
}

int height(Node* root) {

    if (root == NULL) {
        return 0;
    }

    int left_subtree_height = height(root->left_child);
    int right_subtree_height = height(root->right_child);
    int current_height = (left_subtree_height > right_subtree_height ? left_subtree_height : right_subtree_height) + 1;
    return current_height;
}

void print_item(int level, Node* node) {

    if (node == NULL) {
        return;
    }

    if (level == 0) {
        printf("%d ", node->data);
        return;
    }

    print_item(level - 1, node->left_child);
    print_item(level - 1, node->right_child);
}

void levelorder_traversal(Node* root) {

    for(int i = 0; i < height(root); i++) {
        print_item(i, root);
        printf("");
    }
}