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

unsigned long long int powTen(int num){
    unsigned long long int result = 1;
    for (int i = 0; i < num;i++){
        result *= 10;
    }
    return result;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    unsigned long long int num1 = 0, num2 = 0;
    struct ListNode *head1 = l1;
    int count1 = 0;
    while(head1!=NULL){
        num1 += head1->val * powTen(count1);
        count1 += 1;
        head1 = head1->next;
    }

    struct ListNode *head2 = l2;
    int count2 = 0;
    while(head2!=NULL){
        num2 += head2->val * powTen(count2);
        count2 += 1;
        head2 = head2->next;
    }

    struct ListNode *head = NULL;
    unsigned long long int sum = num1 + num2;
    if(sum==0){
        insertAtTail(&head, 0);
        return head;
    }
    while(sum>0){
        insertAtTail(&head, sum % 10);
        sum = sum / 10;
    }
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