#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
void create(struct node *);
void display(struct node *);
struct node * insertatbegin(struct node *);
struct node * InsertAtMiddle(struct node *, int );
void InsertAtEnd(struct node *);
void main(){
    struct node *head;
    head=(struct node *) malloc (sizeof(struct node));
    if(head==NULL){
        printf("Unable To Allocate Memory");
        exit(0);
    }
    int press, key;
    printf("Press 1 for Insert At Beigning\n");
    printf("Press 2 for Insert At Specific Position\n");
    printf("Press 3 for Insert At END\n");
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
    head->prev=NULL;
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
            newnode->prev=temp;
            temp->next=newnode;
            temp=temp->next;
        }
        else{
            break;
        }
    }
}
struct node * insertatbegin(struct node *head){
    struct node *ptr;
    ptr=(struct node *)malloc (sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &ptr->data);
    ptr->prev=NULL;
    ptr->next=head;
    return ptr;
}
struct node * InsertAtMiddle(struct node *head, int index){
    struct node *p, *ptr, *prev1;
    p=head;
    ptr= (struct node *) malloc (sizeof(struct node));
    printf("Enter Data You Want To Insert : ");
    scanf("%d", &ptr->data);
    ptr->next=NULL;
    ptr->prev=NULL;
    int i=1;
    while (i!=index)
    {
        prev1=p;
        p=p->next;
        i++;
    }
    ptr->next=p;
    ptr->prev=prev1;
    prev1->next=ptr;
    p->prev=ptr;
    return head;
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
    ptr->prev=p;
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
