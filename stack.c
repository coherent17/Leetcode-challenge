#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int STACK_EMPTY;
int STACK_EMPTY = (-2147483648);

struct ListNode{
    int val;
    struct ListNode *next;
};

typedef struct ListNode node;

void push(node **head, int value){
    node *newnode = malloc(sizeof(node));
    newnode->val = value;
    newnode->next = *head;
    *head = newnode;
}

int pop(node **head){
    if((*head)==NULL)
        return STACK_EMPTY;
    int result = (*head)->val;
    node *temp = (*head);
    (*head) = (*head)->next;
    free(temp);
    return result;
}

int peek(node *head){
    if(head==NULL)
        return STACK_EMPTY;
    int result = head->val;
    return result;
}

void printStack(node *head){
    node *temp = head;
    while(temp!=NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}