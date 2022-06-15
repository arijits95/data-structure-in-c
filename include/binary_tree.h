typedef struct Node {
    int data;
    struct Node* left_child;
    struct Node* right_child;
} Node;

typedef enum Traversal {
    PreOrder = 0,
    InOrder = 1,
    PostOrder = 2
} Traversal;

Node* create_binary_tree(int elements[], int size);
void preorder_traversal(Node* root);
void inorder_traversal(Node* root);
void postorder_traversal(Node *root);
void levelorder_traversal(Node* root);