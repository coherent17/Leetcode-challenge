#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void insertAtTail(struct ListNode **head, int value){
    struct ListNode *newnode = malloc(sizeof(struct ListNode));
    newnode->val = value;
    newnode->next = NULL;
    struct ListNode *temp = (*head);

    if((*head)==NULL){
        (*head) = newnode;
        return;
    }

    while(temp!=NULL){
        if(temp->next == NULL){
            break;
        }
        temp = temp->next;
    }
    temp->next = newnode;
    return;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL;
    struct ListNode *head1 = l1;
    struct ListNode *head2 = l2;

    int cin = 0;
    while(head1!=NULL || head2!=NULL){
        int x = (head1 != NULL) ? head1->val : 0;
        int y = (head2 != NULL) ? head2->val : 0;
        int sum = x + y + cin;
        cin = sum / 10;
        insertAtTail(&head, sum%10);

        if(head1!=NULL)
            head1 = head1->next;
        if(head2!=NULL)
            head2 = head2->next;
    }
    if(cin>0)
        insertAtTail(&head, 1);
    return head;
}


void printList(struct ListNode *head){
    struct ListNode *temp = head;
    while(temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    struct ListNode *l1 = NULL;
    insertAtTail(&l1, 9);
    printList(l1);

    struct ListNode *l2 = NULL;
    insertAtTail(&l2, 1);
    insertAtTail(&l2, 9);
    insertAtTail(&l2, 9);
    insertAtTail(&l2, 9);
    insertAtTail(&l2, 9);
    insertAtTail(&l2, 9);
    insertAtTail(&l2, 9);
    insertAtTail(&l2, 9);
    insertAtTail(&l2, 9);
    insertAtTail(&l2, 9);
    printList(l2);

    struct ListNode *ll = addTwoNumbers(l1, l2);
    printList(ll);

    return 0;
}