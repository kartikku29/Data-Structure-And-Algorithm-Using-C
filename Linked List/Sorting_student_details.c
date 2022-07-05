#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
    char name[20];
    int roll;
    int marks;
    struct student *next;
};
void input(struct student *);
void display(struct student *);
void sort(struct student *);
int main(){
    struct node *head;
    head=(struct student *) malloc (sizeof(struct student));
    if(head==NULL){
        printf("Unable To Allocate Memory");
        exit(0);
    }
    input(head);
    sort(head);
    display(head);
}
void input(struct student *head){
    struct student *newnode, *temp;
    printf("Enter Student Data \n");
    printf("Enter Name : ");
    scanf("%[^\n]s", head->name);
    printf("Enter Roll : ");
    scanf("%d", &head->roll);
    printf("Enter Marks : ");
    scanf("%d", &head->marks);
    getchar();
    head->next=NULL;
    char c;
    temp=head;
    while (1){
        printf("Do You Want to Add More Student Details ? Y or N : ");
        scanf("%c", &c);
        getchar();
        if(c=='Y'||c=='y'){
            newnode=(struct student *) malloc (sizeof(struct student));
            if(newnode==NULL){
                printf("Unable To Allocate Memory");
                break;
            }
            printf("Enter Name : ");
            scanf("%[^\n]s", newnode->name);
            printf("Enter Roll : ");
            scanf("%d", &newnode->roll);
            printf("Enter Marks : ");
            scanf("%d", &newnode->marks);
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
void sort(struct student *head){
    struct student *temp, *ptr;
    char t[20];
    temp=ptr=head;
    for(;temp!=NULL; temp=temp->next){
        for(ptr=temp->next;ptr!=NULL; ptr=ptr->next){
            if(strcmp(temp->name,ptr->name)>0){
                strcpy(t, temp->name);
                strcpy(temp->name, ptr->name);
                strcpy(ptr->name, t);
                int temp_roll=temp->roll;
                temp->roll=ptr->roll;
                ptr->roll=temp_roll;
                int temp_marks=temp->marks;
                temp->marks=ptr->marks;
                ptr->marks=temp_marks;
            }
        }
    }
}
void display(struct student *p){
    printf("After Sorting \n");
    while(p!=NULL){
        printf("Name : %s\n", p->name);
        printf("Roll : %d\n", p->roll);
        printf("Marks : %d\n", p->marks);
        p=p->next;
        printf("\n");
    }
}
