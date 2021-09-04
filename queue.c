#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

extern int QUEUE_EMPTY;
int QUEUE_EMPTY = (-2147483648);

struct ListNode{
    int val;
    struct ListNode *next;
};

typedef struct ListNode node;

typedef struct queue{
    node *head;
    node *tail;
} queue;

void init_queue(queue *q){
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(queue *q, int value){
    node *newnode = malloc(sizeof(node));
    newnode->val = value;
    newnode->next = NULL;

    if(q->head==NULL && q->tail==NULL){
        q->head = newnode;
        q->tail = newnode;
    }

    else{
        q->tail->next = newnode;
        q->tail = newnode;
    }
}

int dequeue(queue *q){
    if(q->head==NULL)
        return QUEUE_EMPTY;

    int result = q->head->val;
    node *temp = q->head;
    q->head = q->head->next;
    if(q->head==NULL){
        q->tail = NULL;
    }
    free(temp);
    return result;
}

void printQueue(queue *q){
    node *temp = q->head;
    while(temp!=NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}