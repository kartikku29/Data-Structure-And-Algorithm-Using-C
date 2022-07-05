struct ListNode* reverseBetween(struct ListNode* head){
struct ListNode* temp, *cur, *prev;
prev=NULL;
cur=head;
while(temp!=NULL){
    temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
        
    }
}
