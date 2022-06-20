// typedef allows us to provide an alternative name for primitive or user defined data type
typedef struct Item {
    int value;
    int priority;
} Item;

typedef struct PriorityQueue {
    int rear, front, size;
    unsigned capacity;
    Item* array;
} PriorityQueue;

PriorityQueue* create_priority_queue(unsigned capacity);
int is_priority_queue_full(PriorityQueue* queue);
int is_priority_queue_empty(PriorityQueue* queue);
void enqueue_with_priority(PriorityQueue* queue, int element, int priority);
int dequeue_with_priority(PriorityQueue* queue);
void display_priority_queue(PriorityQueue* queue);