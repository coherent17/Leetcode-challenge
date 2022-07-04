struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *temp = head;
    struct ListNode *newhead = NULL;
    while(head){
        temp = head;
        head = head->next;
        temp->next = newhead;
        newhead = temp;
    }
    return newhead;
}