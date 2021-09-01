#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

void insertTail(struct ListNode **head, int value){
    struct ListNode *newnode = malloc(sizeof(struct ListNode));
    newnode->val = value;
    newnode->next = NULL;
    if((*head)==NULL){
        *head = newnode;
        return;
    }
    struct ListNode *temp = *head;
    while(temp!=NULL){
        if(temp->next==NULL){
            break;
        }
        temp = temp->next;
    }
    temp->next = newnode;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *temp1 = l1;
    struct ListNode *temp2 = l2;
    struct ListNode *head = NULL;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->val<=temp2->val){
            insertTail(&head, temp1->val);
            temp1 = temp1->next;
        }
        else{
            insertTail(&head, temp2->val);
            temp2 = temp2->next;
        }
    }
    if(temp1!=NULL && temp2==NULL){
        while(temp1!=NULL){
            insertTail(&head, temp1->val);
            temp1 = temp1->next;
        }
    }
    else if(temp1==NULL && temp2!=NULL){
        while(temp2!=NULL){
            insertTail(&head, temp2->val);
            temp2 = temp2->next;
        }
    }
    return head;
}

void printList(struct ListNode *head){
    struct ListNode *temp = head;
    while(temp!=NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct ListNode *l1 = NULL, *l2 = NULL;
    insertTail(&l1, 1);
    insertTail(&l1, 2);
    insertTail(&l1, 4);
    printList(l1);
    insertTail(&l2, 1);
    insertTail(&l2, 3);
    insertTail(&l2, 4);
    printList(l2);
    printList(mergeTwoLists(l1, l2));
    return 0;
}