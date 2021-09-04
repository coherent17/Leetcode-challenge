#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

typedef struct ListNode node;

void insertTail(node **head, int value){
    node *newnode = malloc(sizeof(node));
    newnode->val = value;
    newnode->next = NULL;
    if(!(*head)){
        (*head) = newnode;
        return;
    }
    node *temp = (*head);
    while(temp){
        if(!temp->next){
            break;
        }
        temp = temp->next;
    }
    temp->next = newnode;
}

void printList(node *head){
    node *temp = head;
    while(temp){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}