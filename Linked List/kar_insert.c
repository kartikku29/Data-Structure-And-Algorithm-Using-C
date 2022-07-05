#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void create(struct node *);
void display(struct node *);
struct node * insertatbegin(struct node *);
struct node * InsertAtMiddle(struct node *, int );
void InsertAtBeforeKey(struct node *, int );
void InsertAtAfterKey(struct node *, int );
void InsertAtEnd(struct node *);
int main(){
    struct node *head;
    head=(struct node *) malloc (sizeof(struct node));
    if(head==NULL){
        printf("Unable To Allocate Memory");
        exit(0);
    }
    int press, key;
    printf("Press 1 for Insert At Beigning\n");
    printf("Press 2 for Insert At Specific Position\n");
    printf("Press 3 for Insert At Before Key Element\n");
    printf("Press 4 for Insert At After Key Element\n");
    printf("Press 5 for Insert At END\n");
    scanf("%d", &press);

    switch (press){
    case 1:
        create(head);
        printf("Your Linked List Is\n");
        display(head);
        head=insertatbegin(head);
        printf("Your Linked List After Insterting Is\n");
        display(head);
        break;
    case 2:
        create(head);
        printf("Your Linked List Is\n");
        display(head);
        printf("Enter The Position You Want To Insert : ");
        scanf("%d", &key);
        head=InsertAtMiddle(head, key);
        printf("Your Linked List After Insterting Is\n");
        display(head);
        break;
    case 3:
        create(head);
        printf("Enter Key To Insert Before The Key In Linked List\n");
        scanf("%d", &key);
        printf("Linked List is \n");
        display(head);
        InsertAtBeforeKey(head, key);
        printf("Linked List After Insterting Is\n");
        display(head);
        break;
    case 4:
        create(head);
        printf("Enter Key To Insert After The Key In Linked List\n");
        scanf("%d", &key);
        printf("Your Linked List\n");
        display(head);
        InsertAtAfterKey(head, key);
        printf("Linked List After Insterting Is \n");
        display(head);
        break;
    case 5:
        create(head);
        printf("Your Linked List\n");
        display(head);
        InsertAtEnd(head);
        printf("Linked List After Insterting Is \n");
        display(head);
        break;

    default:
        break;
    }
}
void create(struct node *head){
    struct node *newnode, *temp;
    printf("Enter Node Data : ");
    scanf("%d", &head->data);
    getchar();
    head->next=NULL;
    char c;
    temp=head;
    while (1){
        printf("Do You Want to Add More Data? Y or N : ");
        scanf("%c", &c);
        if(c=='Y'||c=='y'){
            newnode=(struct node *) malloc (sizeof(struct node));
            if(newnode==NULL){
                printf("Unable To Allocate Memory");
                break;
            }
            printf("Enter Node Data : ");
            scanf("%d", &newnode->data);
            getchar();
            newnode->next=NULL;
            temp->next=newnode;
            temp=temp->next;
        }
        else{
            break;
        }
    }
}
void display(struct node *head){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
struct node * insertatbegin(struct node *head){
    struct node *ptr;
    ptr=(struct node *)malloc (sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &ptr->data);
    ptr->next=head;
    return ptr;
}
struct node * InsertAtMiddle(struct node *head, int index){
    struct node *p, *ptr;
    p=head;
    ptr= (struct node *) malloc (sizeof(struct node));
    printf("Enter Data You Want To Insert : ");
    scanf("%d", &ptr->data);
    ptr->next=NULL;
    int i=1;
    while (i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
void InsertAtBeforeKey(struct node *head, int key){
    struct node *ptr, *prevnode, *p;
    p=head;
    prevnode=head;
    ptr=(struct node *) malloc (sizeof(struct node));
    printf("Enter Data You Want To Insert : ");
    scanf("%d", &ptr->data);
    ptr->next=NULL;
    while(key!=p->data){
        prevnode=p;
        p=p->next;
    }
    ptr->next=prevnode->next;
    prevnode->next=ptr;
}
void InsertAtAfterKey(struct node *head, int key ){
    struct node *ptr, *p;
    p=head;
    ptr=(struct node *) malloc (sizeof(struct node));
    printf("Enter Data You Want To Insert : ");
    scanf("%d", &ptr->data);
    ptr->next=NULL;
    while(key!=p->data){
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;
}
void InsertAtEnd(struct node *head){
    struct node *ptr, *p;
    p=head;
    ptr=(struct node *) malloc (sizeof(struct node));
    printf("Enter Data You Want To Insert : ");
    scanf("%d", &ptr->data);
    ptr->next=NULL;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
}
