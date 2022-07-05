
struct Node* copyRandomList(struct Node* head) {
    if(head==NULL){
        return head;
    }
	struct Node* temp, *newnode, *copy, *new, *pt;
    temp=head;
    while(temp!=NULL){
            newnode=(struct Node *) malloc (sizeof(struct Node ));
            newnode->val=temp->val;
            newnode->random=NULL;
            newnode->next=temp->next;
            temp->next=newnode;
            temp=temp->next->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->next!=NULL){
            if(temp->random==NULL)
                temp->next->random=NULL;
            else
                temp->next->random=temp->random->next;
        }
        temp=temp->next->next;
    }
    temp=head;
    copy=NULL;
    while(temp!=NULL){
        if(copy!=NULL){
            pt->next=temp->next;
            pt=pt->next;
        }
        else{
            copy=temp->next;
            pt=copy;
        }
        temp->next=temp->next->next;
        temp=temp->next;
    }
    return copy;
}
