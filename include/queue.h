typedef struct Queue {
    int front, rear, size;
    int capacity;
    int* array;
} Queue;

Queue* create_queue(unsigned capacity);
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
int front(Queue* queue);
int rear(Queue* queue);
int isEmpty(Queue* queue);
int isFull(Queue* queue);
int size(Queue* queue);
void display(Queue* queue);