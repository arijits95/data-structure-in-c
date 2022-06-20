#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "../include/binary_tree.h"
#include "../include/queue.h"

void test_queue_implementation() {

    Queue* queue = NULL;
    int option = 1;
    int element;
    unsigned size;
    const int exit_value = 8;

    do {
        printf("\n\n----------QUEUE OPERATION----------");
        printf("\n0.CREATE A QUEUE");
        printf("\n1.ENQUEUE");
        printf("\n2.DEQUEUE");
        printf("\n3.FRONT ITEM");
        printf("\n4.REAR ITEM");
        printf("\n5.IS QUEUE FULL");
        printf("\n6.IS QUEUE EMPTY");
        printf("\n7.DISPLAY");
        printf("\n8.Exit");
        printf("\n-----------------------------------\n");
        printf("\nChoose an operation between (1 to 6):");
        scanf("%d", &option);
        printf("\n\n");

        if (queue == NULL && option != 0) {
            printf("\nPlease create a queue first by choosing option 0");
            continue;
        }

        switch (option)
        {
        case 0:

            printf("\nEnter size of the queue: ");
            scanf("%u", &size);
            if (queue != NULL) {
                free(queue);
            }
            queue = create_queue(size);
            break;

        case 1:

            printf("\nEnter element to insert: ");
            scanf("%d", &element);
            enqueue(queue, element);
            printf("\nEnqueued %d\n", element);
            break;

        case 2:

            element = dequeue(queue);
            if (element == INT_MIN) {
                printf("\nQueue is empty");
            } else {
                printf("\nDequeued: %d", element);
            }
            break;

        case 3:

            element = front(queue);
            if (element == INT_MIN) {
                printf("\nQueue is empty");
            } else {
                printf("\nFront element: %d", element);
            }
            break;

        case 4:

            element = rear(queue);
            if (element == INT_MIN) {
                printf("\nQueue is empty");
            } else {
                printf("\nRear element: %d", element);
            }
            break;

        case 5:

            if (isFull(queue)) {
                printf("\nQueue is full");
            } else {
                printf("\nQueue is not full");
            }
            break;
            
        case 6:

            if (isEmpty(queue)) {
                printf("\nQueue is empty");
            } else {
                printf("\nQueue is not empty");
            }
            break;
        
        case 7:

            display(queue);
            break;

        case 8:

            if (queue != NULL) {
                free(queue);
            }
            return;

        default:

            printf("\nInvalid opeartion. Please choose a valic operation.");
            break;
        }

    } while (option != exit_value);

}

void test_binary_tree_implementation(int* input, int size) {
    Node* root = create_binary_tree(input, size);

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
}

int main(int argc, char** argv) {

    test_queue_implementation();

    // int size;

    // printf("\nEnter size of the element list: ");
    // scanf("%d", &size);

    // int* elements = (int*)malloc(size * sizeof(int));
    
    // for(int i = 0; i < size; i++) {
    //     printf("\nElement at index %d: ", i);
    //     scanf("%d", &elements[i]);
    // }    

    return 0;
}
