#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void create(struct node *);
void newcreate(struct node *);
void display(struct node *);
void merge(struct node *, struct node *);
void main(){ 
    struct node *head,*newhead;
    head=(struct node *) malloc (sizeof(struct node));
    if(head==NULL){
        printf("Unable To Allocate Memory");
        exit(0);
    }
    newhead=(struct node *) malloc (sizeof(struct node));
    if(newhead==NULL){
        printf("Unable To Allocate Memory");
        exit(0);
    }
    printf("Enter First List Data\n");
    create(head);
    printf("Your First List is \n");
    display(head);
    printf("Enter Second List Data\n");
    newcreate(newhead);
    printf("Your Second List is \n");
    display(head);
    merge(head, newhead);
    printf("Your List after Merging \n");
    display(head);
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
void newcreate(struct node *newhead){
    struct node *newnode, *temp;
    printf("Enter Node Data : ");
    scanf("%d", &newhead->data);
    getchar();
    newhead->next=NULL;
    char c;
    temp=newhead;
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
void merge(struct node *head, struct node *newhead){
    struct node *temp;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newhead;
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
