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
    if(*head==NULL){
        (*head) = newnode;
        return;
    }
    node *temp = *head;
    while(temp!=NULL){
        if(temp->next ==NULL){
            break;
        }
        temp = temp->next;
    }
    temp->next = newnode;
}

void printList(node *head){
    node *temp = head;
    while(temp!=NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

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