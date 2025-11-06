#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *createnode(int value)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}

void insertfront(int value)
{
    struct node *newnode= createnode(value);
    newnode->next=head;
    head=newnode;
}

void insertrear(int value)
{
    struct node* newnode = createnode(value);
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}

void insertAtPos(int value, int position)
{
    struct node *newnode = createnode(value);
    if(position==1)
    {
        newnode->next=head;
        head=newnode;
        return;
    }
    struct node *temp=head;
    for(int i=1;temp!=NULL && i<position-i;i++)
    {
        temp=temp->next;
    }

if(temp==NULL)
{
    printf("position not inside the range");
    return;
}
newnode->next=temp->next;
temp->next=newnode;
}
void display()
{
    if(head==NULL)
    {
        printf("ëmpty");
        return;
    }
    struct node *temp=head;
    printf("Linked list");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice,value,position;
    while(1)
    {
        printf("Single linked list\n");
        printf("\n1)Insert at the front\n 2)Insert at the rear\n 3)Insert at a specific position\n 4)display\n 5)exit\n");
        printf("Enter the required choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter Value");
                scanf("%d",&value);
                insertfront(value);
                break;
            case 2:
                printf("Enter value");
                scanf("%d",&value);
                insertrear(value);
                break;
            case 3:
                printf("Enter value");
                scanf("%d",&value);
                printf("Enter the position to insert");
                scanf("%d",&position);
                insertAtPos(value,position);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("enter a valid choice");
        }
    }
    return 0;
}
