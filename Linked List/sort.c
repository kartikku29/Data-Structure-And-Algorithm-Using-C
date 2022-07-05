#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void create(struct node *);
void display(struct node *);
void sort(struct node *);
void main(){
    struct node *head;
    head=(struct node *) malloc (sizeof(struct node));
    if(head==NULL){
        printf("Unable To Allocate Memory");
        exit(0);
    }
    create(head);
    sort(head);
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
void sort(struct node *head){
    struct node *temp, *ptr;
    temp=ptr=head;
    while(temp!=NULL){
        ptr=temp->next;
        while(ptr!=NULL){
            if(temp->data>ptr->data){
                int temp_data=ptr->data;
                ptr->data=temp->data;
                temp->data=temp_data;
            }
        }
    }
}
void display(struct node *head){
    printf("Your List is \n");-
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
