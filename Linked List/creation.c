#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void display(struct node *head){
    while (head!=NULL)
    {
        printf("%d \n", head->data);
        head=head->next;
    }
}
void creation(struct node *head){
    char c;
    do{
        printf("Enter Your Data : ");
        scanf("%d", &head->data);
        getchar();
        printf("Do you want to Contiune y or n ? ");
        scanf("%c", &c);
        if((c=='Y')|| (c=='y')){
            head->next= (struct node *) malloc (sizeof(struct node*));
            head=head->next;
        }
        else{
            head->next=NULL;
        }
    }while(c=='Y'|| c=='y');
}
void main(){
    struct node *head;
    head= (struct node *) malloc (sizeof(struct node *));
    creation(head);
    display(head);
    printf("After Swapping \n");
    head->data=(head->data+head->next->data);
    head->next->data=(head->data-head->next->data);
    head->data=head->data-head->next->data;
    display(head);

}
