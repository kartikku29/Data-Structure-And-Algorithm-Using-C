int has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *fast, *slow;
    fast=slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return 1;
        }
    }
    return 0;
}
