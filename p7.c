#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 2000

// Define the Queue structure
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Helper functions for Circular Queue operations
void queueInit(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

bool queueIsEmpty(Queue* q) {
    return q->front == q->rear;
}

void queuePush(Queue* q, int x) {
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAX_SIZE; // Wrap around
}

int queuePop(Queue* q) {
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE; // Wrap around
    return val;
}

int queueSize(Queue* q) {
    return (q->rear - q->front + MAX_SIZE) % MAX_SIZE;
}

// Define the MyStack structure using a Queue
typedef struct {
    Queue q;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    queueInit(&(obj->q));
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    int size = queueSize(&(obj->q));
    queuePush(&(obj->q), x);
    
    // Rotate the queue to bring the newly added element to the front
    for (int i = 0; i < size; i++) {
        int val = queuePop(&(obj->q));
        queuePush(&(obj->q), val);
    }
}

int myStackPop(MyStack* obj) {
    return queuePop(&(obj->q));
}

int myStackTop(MyStack* obj) {
    return obj->q.data[obj->q.front];
}

bool myStackEmpty(MyStack* obj) {
    return queueIsEmpty(&(obj->q));
}

void myStackFree(MyStack* obj) {
    free(obj);
}
