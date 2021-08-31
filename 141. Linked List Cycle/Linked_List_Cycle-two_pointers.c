#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

//two pointers

/*
assume the linkedlist: 3 -> 2 -> 0 -> 4 and point back to 2
f = fast pointer, s = slow pointer


3   2   0   4   2   0   4   2   0   4   2   0   4   2   0   4
-------------------------------------------------------------
f
s
-------------------------------------------------------------
        f
    s
-------------------------------------------------------------
                f
        s
-------------------------------------------------------------
                        f
            s
fast meet slow: is a cycle linkedlist
*/

bool hasCycle(struct ListNode *head) {
    //linkedlist without cycle:
    if(head==NULL || head->next==NULL)
        return false;
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    //ensure the fast->next and fast->next->next exist
    while(fast->next!=NULL && fast->next->next!=NULL){
        //fast pointer move two steps, slow pointer move one step
        fast = fast->next->next;
        slow = slow->next;

        //if two pointers meet, then it's a cycle
        if(fast==slow)
            return true;
    }
    return false;
}

typedef struct ListNode node;

node *newnode(int value){
    node *newnode = malloc(sizeof(node));
    newnode->val = value;
    newnode->next = NULL;
    return newnode;
}

int main(){
    node *n1, *n2, *n3, *n4;
    n1 = newnode(3);
    n2 = newnode(2);
    n3 = newnode(0);
    n4 = newnode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;

    printf("%d\n", hasCycle(n1));
    return 0;
}