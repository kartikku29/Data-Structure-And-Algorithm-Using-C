#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int count;
void create(struct node *);
void display(struct node *);
void delete(struct node *head){
    struct node *prev, *temp, *p;
    char c;
    do{
    int i=0, index;
    prev=p=head;
    printf("\nEnter Position : ");
    scanf("%d", &index);
    while(i!=index-1){
        prev=p;
        p=p->next;
        i++;
    }
    if(p==head){

        while(prev->next!=head){
            prev=prev->next;
        }
        head=head->next;
        prev->next=head;
        count--;
    }
    else{
        prev->next=p->next;
        count--;
    }
    temp=head;
    printf("\nYour Remaining Data is \n");
    while(temp->next!=head){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("%d", temp->data);
    printf("\n");
    if(count==1){
        printf("\nYou Can't Delete more Data\n");
        printf("Your Last Data Is %d", temp->data);
        printf("\n");
        break;
    }
    printf("Do You Want to Delete More Data? Y or N : ");
    getchar();
    scanf("%c", &c);

    }while(c=='y'|| c=='Y');
}
void main(){
    struct node *head;
    head=(struct node *) malloc (sizeof(struct node));
    if(head==NULL){
        printf("Unable To Allocate Memory");
        exit(0);
    }
    create(head);
    printf("Your Data is\n");
    display(head);
    delete(head);
    //display(head);
}
void create(struct node *head){
    struct node *newnode, *temp;
    printf("Enter Node Data : ");
    scanf("%d", &head->data);
    getchar();
    head->next=NULL;
    char c;
    count=1;
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
            count++;
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
    temp->next=head;
}
void display(struct node *head){
    struct node *temp;
    temp=head;
    while(temp->next!=head){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("%d", temp->data);
    printf("\n");
}
