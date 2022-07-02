struct ListNode* removeElements(struct ListNode* head, int val){
    while(head){
        if(head->val == val) head = head->next;
        else break;
    }
    if(!head) return NULL;
    
    struct ListNode *curr = head;
    while(curr->next){
        if(curr->next->val == val){
            curr->next = curr->next->next;
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}