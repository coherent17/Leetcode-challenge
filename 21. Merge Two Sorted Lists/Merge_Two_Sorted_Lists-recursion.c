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
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;

    struct ListNode *head = NULL;
    head = (l1->val <= l2->val) ?l1 :l2;
    head->next = (l1->val <= l2->val) ? mergeTwoLists(l1->next, l2) : mergeTwoLists(l1, l2->next);
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