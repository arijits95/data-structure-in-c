#include "../include/binary_tree.h"
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv) {

    int size;

    printf("\nEnter size of the element list: ");
    scanf("%d", &size);

    int* elements = (int*)malloc(size * sizeof(int));
    
    for(int i = 0; i < size; i++) {
        printf("\nElement at index %d: ", i);
        scanf("%d", &elements[i]);
    }    

    Node* root = create_binary_tree(elements, size);

    printf("\nPreorder traversal:\n");
    preorder_traversal(root);
    printf("\n");

    printf("\nInorder traversal:\n");
    inorder_traversal(root);
    printf("\n");

    printf("\nPostorder traversal:\n");
    postorder_traversal(root);
    printf("\n");

    printf("\nLevelorder traversal:\n");
    levelorder_traversal(root);
    printf("\n");

    return 0;
}
