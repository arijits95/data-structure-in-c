#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "../include/priority_queue.h"

PriorityQueue* create_priority_queue(unsigned capacity) {
    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->front = queue->size = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (Item*)malloc(capacity * sizeof(Item));
    return queue;
}

int is_priority_queue_full(PriorityQueue* queue) {
    return (queue->size == queue->capacity);
}

int is_priority_queue_empty(PriorityQueue* queue) {
    return (queue->size == 0);
}

int index_of_highest_priority_item(PriorityQueue* queue) {
    if (is_priority_queue_empty(queue)) {
        return INT_MIN;
    }

    int front_index = queue->front;
    int rear_index = queue->rear;
    int highest_priority = INT_MIN;
    int highest_priority_item_index = INT_MIN;

    while(front_index != rear_index) {
        Item current_element = queue->array[front_index];
        if (current_element.priority > highest_priority) {
            highest_priority = current_element.priority;
            highest_priority_item_index = front_index;
        }
        front_index = ((front_index + 1) % queue->capacity);
    }

    if (queue->array[front_index].priority > highest_priority) {
        return front_index;
    }

    return highest_priority_item_index;
}

// void sort(Item* array) {

// }

void enqueue_with_priority(PriorityQueue* queue, int element, int priority) {
    if (is_priority_queue_full(queue)) {
        printf("Queue overflow");
        return;
    }

    Item* item = (Item*)malloc(sizeof(Item));
    item->value = element;
    item->priority = priority;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = *item;
    queue->size++;
}

int dequeue_with_priority(PriorityQueue* queue) {
    if (is_priority_queue_empty(queue)) {
        printf("\nQueue is empty");
        return INT_MIN;
    }

    int highest_priority_item_index = index_of_highest_priority_item(queue);
    int element_to_return = queue->array[highest_priority_item_index].value;
    int front_index = queue->front;

    while(highest_priority_item_index != front_index) {
        int prev_index = (highest_priority_item_index - 1) >= 0 ? (highest_priority_item_index - 1) : (queue->capacity - 1);
        queue->array[highest_priority_item_index] = queue->array[prev_index];
        highest_priority_item_index = prev_index;
    }

    queue->front = ((queue->front + 1) % queue->capacity);
    queue->size--;
    return element_to_return;
}

void display_priority_queue(PriorityQueue* queue) {
    if (is_priority_queue_empty(queue)) {
        printf("\nQueue is empty");
    }
    int front_index = (queue->front >= 0 ? queue->front : 0);
    int rear_index = queue->rear;
    printf("");
    while(front_index != rear_index) {
        int data = queue->array[front_index].value;
        printf("%d ", data);
        front_index = ((front_index + 1) % queue->capacity);
    }

    int data = queue->array[front_index].value;
    printf("%d ", data);

    printf("");
}

