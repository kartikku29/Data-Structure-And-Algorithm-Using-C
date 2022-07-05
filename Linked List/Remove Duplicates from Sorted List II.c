struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode*temp, *ptr,*ptr2;
    ptr=temp=head;
    while(temp!=NULL){
        if(temp->next!=NULL && temp->val==temp->next->val){
            while(temp->next!=NULL && temp->val==temp->next->val){
                if(temp==head){
                    ptr2=head;
                }
                temp=temp->next;
            }
            if(ptr2==head){
                head=temp->next;
            }
                ptr->next=temp->next;
                temp=ptr;
        }
        else{
            ptr=temp;
            temp=temp->next;
        }

    }
    return head;
}
