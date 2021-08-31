#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

/*
         ⬇(node)  
-  1  -  2  -  3  -  4
               ⬆(node->next)

step 1:
    change node->value to node->next->value
             ⬇(node)  
    -  1  -  3  -  3  -  4
                   ⬆(node->next)

step 2:
    connect node->next as node->next->next, and disconnect the node->next

             ⬇(node)  
    -  1  -  3  -  4              3
                                  ⬆(node->next)

step 3:
    free the memmory
*/

void deleteNode(struct ListNode *node){
    struct ListNode *temp = node->next;
    node->val = node->next->val;
    node->next = temp->next;
    temp->next = NULL;
    free(temp);
}

struct ListNode *insertTail(struct ListNode **head, int value){
    struct ListNode *newnode = malloc(sizeof(struct ListNode));
    newnode->val = value;

    if((*head) ==NULL){
        newnode->next = (*head);
        (*head) = newnode;
        return newnode;
    }

    struct ListNode *temp = (*head);
    while(temp!=NULL){
        if(temp->next == NULL){
            break;
        }
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
    return newnode;
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
    struct ListNode *head = NULL;
    struct ListNode *n1, *n2, *n3, *n4;
    n1 = insertTail(&head, 1);
    n2 = insertTail(&head, 2);
    n3 = insertTail(&head, 3);
    n4 = insertTail(&head, 4);
    printList(head);
    deleteNode(n3);
    printList(head);
    return 0;
}