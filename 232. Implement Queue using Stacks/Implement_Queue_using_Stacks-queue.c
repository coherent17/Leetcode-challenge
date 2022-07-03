#define QUEUE_SIZE 100

typedef struct {
    int tail;
    int head;
    int value[QUEUE_SIZE];
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue *ret = malloc(sizeof(MyQueue));
    ret->tail = -1;
    ret->head = -1;
    return ret;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->value[++(obj->tail)] = x;
    if(obj->head == -1) obj->head = obj->tail;
}

int myQueuePop(MyQueue* obj) {
    int ret = obj->value[(obj->head)++];
    if(obj->head > obj->tail){
        obj->tail = -1;
        obj->head = -1;
    }
    return ret;
}

int myQueuePeek(MyQueue* obj) {
    return obj->value[obj->head];
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->head == -1) return true;
    else return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}