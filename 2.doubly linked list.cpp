#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node * prev;
}*head,*temp,*t;
void createnode();
void insertbeg();
void traverse();
void insertend();
void insertmid();
void deletionbeg();
void deletionmid();
void deletionend();
int main()
{
    int n,i,choice;
    while(1)
    {
        printf("enter 1 for insert at beginning ,2 for insert at mid ,3 for insert end, 4 for deletebed ,5 for delete mid ,6 for delete end ,7 for exit :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:{
                printf("enter no of element want to insert at beg :");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                insertbeg();
                traverse();
                break;
                }
            case 2:{
                insertmid();
                traverse();
                break;
            }
            case 3:{
                printf("enter no of element want to insert at end :");
                scanf("%d",&n);
                for(i=0;i<n;i++)                
                insertend();
                traverse();
                break;
            }
            case 4:{
                deletionbeg();
                traverse();
                break;
            }
            case 5:{
                deletionmid();
                traverse();
                break;
            }
            case 6:{
                deletionend();
                traverse();
                break;
            }                      
            case 7:exit(0);
        }
    }
    return 0;
}
void createnode()
{
    temp=(struct node*) malloc(sizeof (struct node));
    printf("enter data :");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;
}
void insertbeg()
{
    
    createnode();
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
void traverse()
{
    t=head;
    printf("the linked list are \n");
    while(t!=NULL)
    {
        printf("%d->",t->data);
        t=t->next;
    }
}
void insertend()
{
    if (head==NULL)
    {
        createnode();
        head=temp;
    }
    else
    {
        
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        if(head==NULL)
        {
            createnode();
            head=temp;
        }
        else
        {
            createnode();
            t->next=temp;
            temp->prev=t;
        }
    }
}
void insertmid()
{
    int n,a;
    printf("enter the element after which insert ");
    scanf("%d",&a);
    t=head;
    while(t->data!=a)
    {
        t=t->next;
    }
    if(t->data==a)
    {
        createnode();
        temp->next=t->next;
        t->next->prev=temp;
        t->next=temp;
        temp->prev=t;
    }
    else
    printf("the element not found");
        
}
void deletionbeg()
{
    if(head==NULL)
    {
        printf("the linked list not found");
    }
    else if( head->next==NULL)
    {
        free(head);
    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}
void deletionmid()
{
    int a;
    printf("enter data to be deleted ");
    scanf("%d",&a);
    temp=head;
    if(head==NULL)
    {
        printf("link is ememty");
    }
    else
    {
        while(temp->data!=a)
        {
            t=temp;
            temp=temp->next;
        }
        if(temp->data==a)
        {
            if(temp==head)
            {
                head=head->next;
                head->prev=NULL;
            }
            else if(temp->next==NULL)
            {
                t->next=NULL;
            }
            else
            {
                t->next=temp->next;
                temp->next->prev=t;
            }
        }
    }
}
void deletionend()
{
    temp=head;
    while(temp->next!=NULL)
    {
        t=temp;
        temp=temp->next;
    }
    t->next=NULL;
}
/*output
enter 1 for insert at beginning ,2 for insert at mid ,3 for insert end, 4 for deletebed ,5 for delete mid ,6 for delete end ,7 for exit :1
enter no of element want to insert at beg :2
enter data :13
enter data :14
the linked list are
14->13->enter 1 for insert at beginning ,2 for insert at mid ,3 for insert end, 4 for deletebed ,5 for delete mid ,6 for delete end ,7 for exit :7
