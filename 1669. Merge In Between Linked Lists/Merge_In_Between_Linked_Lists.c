#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};


//time complexity: O(m+n)
struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    
    //get the edges need to be changed node_a-1 & node_b
    struct ListNode *node_cut = NULL, *node_b = NULL, *node_tail = NULL;
    struct ListNode *temp = list1;
    int count = 0;

    while(count<=b){
        if(count==a-1)
            node_cut = temp;
        temp = temp->next;
        count++;
    }
    node_b = temp;

    //get the tail of the list2
    temp = list2;
    while(temp!=NULL){
        if(temp->next==NULL)
            break;
        temp = temp->next;
    }
    node_tail = temp;

    //connect them;
    node_cut->next = list2;
    node_tail->next = node_b;

    return list1;
}

typedef struct ListNode node;
void insertTail(node **head, int value){
    node *newnode = malloc(sizeof(node));
    newnode->val = value;
    newnode->next = NULL;
    if((*head)==NULL){
        (*head) = newnode;
        return;
    }
    node *temp = *head;
    while(temp!=NULL){
        if(temp->next==NULL)
            break;
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

int main(){
    node *list1 = NULL, *list2 = NULL;
    insertTail(&list1, 0);
    insertTail(&list1, 1);
    insertTail(&list1, 2);
    insertTail(&list1, 3);
    insertTail(&list1, 4);
    insertTail(&list1, 5);
    insertTail(&list1, 6);
    printList(list1);

    insertTail(&list2, 1000000);
    insertTail(&list2, 1000001);
    insertTail(&list2, 1000002);
    insertTail(&list2, 1000003);
    insertTail(&list2, 1000004);
    printList(list2);

    node *mergeList = mergeInBetween(list1, 2, 5, list2);
    printList(mergeList);

    return 0;
}