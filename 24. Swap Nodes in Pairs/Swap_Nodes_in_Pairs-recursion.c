#include <stdio.h>
#include <stdlib.h>
#include "../linkedlist.h"

struct ListNode{
    int val;
    struct ListNode *next;
};

typedef struct ListNode node;

struct ListNode* swapPairs(struct ListNode* head){
    //one element or head = NULL
    if(!head || !head->next){
        return head;
    }
    struct ListNode *temp = head;
    head = head->next;
    temp->next = head->next;
    head->next = temp;
    head->next->next = swapPairs(head->next->next);
    return head;
}

int main(){
    node *head = NULL;
    insertTail(&head, 1);
    insertTail(&head, 2);
    insertTail(&head, 3);
    insertTail(&head, 4);
    printList(head);
    head = swapPairs(head);
    printList(head);
    return 0;
}