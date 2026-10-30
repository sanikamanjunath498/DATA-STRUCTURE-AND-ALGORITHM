#define MAX_SIZE 100

typedef struct {
    int s1[MAX_SIZE];
    int s2[MAX_SIZE];
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj->top1 < MAX_SIZE - 1) {
        obj->s1[++(obj->top1)] = x;
    }
}

int myQueuePop(MyQueue* obj) {
    // If output stack is empty, transfer elements from input stack
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->s2[++(obj->top2)] = obj->s1[(obj->top1)--];
        }
    }
    // Pop from output stack if it's not empty
    if (obj->top2 != -1) {
        return obj->s2[(obj->top2)--];
    }
    return -1; // Error case
}

int myQueuePeek(MyQueue* obj) {
    // If output stack is empty, transfer elements from input stack
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->s2[++(obj->top2)] = obj->s1[(obj->top1)--];
        }
    }
    // Peek from output stack if it's not empty
    if (obj->top2 != -1) {
        return obj->s2[obj->top2];
    }
    return -1; // Error case
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
