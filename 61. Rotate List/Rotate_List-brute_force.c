#include "../linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

void swapValue(struct ListNode *a, struct ListNode *b){
    int value = a->val;
    a->val = b->val;
    b->val = value;
}

bool insertTailAfterHead(struct ListNode *head, struct ListNode *insertNode){
    if(head->next == insertNode){
        return true;
    }
    insertNode->next = head->next;
    head->next = insertNode;
    return false;
}

struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head || !head->next)
        return head;

    typedef struct ListNode node;
    int count = 1;
    node *temp = head;
    while(temp!=NULL){
        if(temp->next==NULL){
            break;
        }
        count += 1;
        temp = temp->next;
    }

    while(k%count){
        temp = head;
        while(temp){
            if(!(temp->next->next)){
                break;
            }
            temp = temp->next;
        }
        bool flag = insertTailAfterHead(head, temp->next);
        if(!flag){
            temp->next = NULL;
        }
        swapValue(head, head->next);
        k--;
    }
    return head;
}

int main(){
    typedef struct ListNode node;
    node *head = NULL;
    insertTail(&head, 1);
    insertTail(&head, 2);

    printList(head);
    
    head = rotateRight(head, 1);
    printList(head);
    
    return 0;
}