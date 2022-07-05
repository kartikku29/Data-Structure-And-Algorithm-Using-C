/*Given the head of a singly linked list and two integers left and right where left <= right,
reverse the nodes of the list from position left to position right, and return the reversed list.*/
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode *temp, *cur, *prev, *last, *first;
    if(head == NULL || head->next == NULL || left == right)
        return head;
    if(left==1){
        first=head;
    }
    last=cur=head;
    prev=NULL;
    int i=1;
    while(i<left){
        first=cur;
        cur=cur->next;
        last=last->next;
        i++;
    }
    while(i<right+1){
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
        i++;
    }
    if(left==1){
        last->next=temp;
        return prev;
    }
    else{
        first->next=prev;
        last->next=temp;
        return head;
    }
}
