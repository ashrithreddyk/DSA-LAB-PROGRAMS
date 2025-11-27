#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head;
struct node *createnode(int value)
{
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->prev=NULL;
  newnode->next=NULL;
  newnode->data=value;
  return newnode;
};

void InsertAtEnd(int value)
{

struct node *newnode = createnode(value);
if(head==NULL)
{
    head=newnode;
}
else
{
struct node *ptr=head;
while(ptr->next!=NULL)
{
    ptr=ptr->next;
}
ptr->next=newnode;
newnode->prev=ptr;
printf("node inserted %d",value);
}
}
void InsertLeft(int value, int key)
{
    struct node *newnode=createnode(value);
    struct node *temp=head;
    if(head==NULL)
    {
        printf("list is empty");
        return;
    }
    if(head->next==NULL)
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return;
    }
    else
    {
        while(temp->data!=key && temp!=NULL)
        {
            temp=temp->next;
        }
        if(temp->next==NULL)
        {
            printf("element not found");
        }
        else
        {
           newnode->next=temp;
           newnode->prev=temp->prev;
           temp->prev->next=newnode;
           temp->prev=newnode;
        }

    }
}

void deleteval(int key)
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("empty");
        return;
    }
    while(temp->data!=key && temp->data!=NULL)
    {
        temp=temp->next;
    }
    if(temp->data=NULL)
    {
        printf("Value not found");
    }
    else
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}

void display()
{
    struct node *ptr=head;
    if(head==NULL)
    {
        printf("empty list");
    }
    else
    {
        while(ptr->next!=NULL)
        {
            printf("%d<->",ptr->data);
            ptr=ptr->next;
        }
    }
}
int main()
{
    int choice, val, target;

    while (1) {
        printf("\nDOUBLY LINKED LIST MENU");
        printf("\n1. Create List (Insert End)");
        printf("\n2. Insert to LEFT of a node");
        printf("\n3. Delete based on value");
        printf("\n4. Display contents");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                InsertAtEnd(val);
                break;
            case 2:
                printf("Enter target node value: ");
                scanf("%d", &key);
                printf("Enter new value to insert to the left: ");
                scanf("%d", &val);
                InsertLeft(val, key);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteval(val);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

