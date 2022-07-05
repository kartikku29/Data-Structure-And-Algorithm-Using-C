#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void creation(struct node *);
void display(struct node *);
void insert_at_end(struct node *head);
int main(void)
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Memory Not allocated\n");
        exit(0);
    }
    printf("Enter the node data: ");
    scanf("%d", &head->data);
    getchar();
    head->next = NULL;
    creation(head);
    display(head);
    insert_at_end(head);
    display(head);
    return 0;
}
void creation(struct node *head)
{

    struct node *newnode, *temp;
    char c;
    temp = head;
    while (1)
    {
        printf("Do you want to add more node (y/n)?");
        scanf("%c", &c);
        if (c == 'y' || c == 'Y')
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data: ");
            scanf("%d", &newnode->data);
            getchar();
            temp->next = newnode;
            temp = newnode;
            newnode->next = NULL;
        }
        else break;
    }
}
void display(struct node *head)
{
    struct node *temp;
    temp = head;
    while (temp != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
void insert_at_end(struct node *head)
{
    struct node *insertnode, *temp;
    temp=head;
    insertnode = (struct node *)malloc(sizeof(struct node));
    printf("\nENter data u want to insert: ");
    scanf("%d", &insertnode->data);
    insertnode->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = insertnode;
   // insertnode->next = 0;
}
