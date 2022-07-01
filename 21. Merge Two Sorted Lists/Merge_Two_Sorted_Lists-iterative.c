struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(!list1) return list2;
    if(!list2) return list1;
    
    //decide the head node
    struct ListNode *head;
    if(list1->val <= list2->val){
        head = list1;
        list1 = list1->next;
    }
    else{
        head = list2;
        list2 = list2->next;
    }
    
    struct ListNode *tail = head;
    
    //insert the smaller node after tail node
    while(list1 && list2){
        if(list1->val <= list2->val){
            tail->next = list1;
            list1 = list1->next;
        }
        else{
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    
    //insert the remaining node if exists
    while(list1){
        tail->next = list1;
        list1 = list1->next;
        tail = tail->next;
    }
    
    while(list2){
        tail->next = list2;
        list2 = list2->next;
        tail = tail->next;
    }
    
    return head;
}