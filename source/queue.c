#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include "../include/queue.h"

Queue* create_queue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

int front(Queue* queue) {
    if (isEmpty(queue)) {
        return INT_MIN;
    }
    return queue->array[queue->front];
}

int rear(Queue* queue) {
    if (isEmpty(queue)) {
        return INT_MIN;
    }
    return queue->array[queue->rear];
}

void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("\nQueue overflow\n");
        return;
    }

    queue->rear = ((queue->rear + 1) % queue->capacity);
    queue->array[queue->rear] = data;
    queue->size++;
    return;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nQueue underflow");
        return INT_MIN;
    }

    int data = queue->array[queue->front];
    queue->front = ((queue->front + 1) % queue->capacity);
    queue->size--;
    return data;
}

void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nQueue is empty");
    }
    int front_index = queue->front;
    int rear_index = queue->rear;
    
    printf("");
    while(front_index != rear_index) {
        int data = queue->array[front_index];
        printf("%d ", data);
        front_index = ((front_index + 1) % queue->capacity);
    }

    int data = queue->array[front_index];
    printf("%d ", data);
    printf("");
}



