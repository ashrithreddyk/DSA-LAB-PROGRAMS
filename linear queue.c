#include<stdio.h>
#define MAX 3
int front=-1,rear=-1,queue[MAX];
void insert(int a)
{
    if(rear==MAX-1)
        printf("Queue overflow\n");
    else
    {
        if(front==-1)
            front=0;
        rear++;
        queue[rear]=a;
    }
}
void delete()
{
    if(front==-1 || front==rear+1)
        printf("Queue underflow");
    else
    {
        printf("The deleted element:%d\n",queue[front]);
        front++;
    }
}
void display()
{
    if(front==-1 || front==rear+1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue:");
        for(int i=front;i<=rear;i++)
            printf("\t%d\t",queue[i]);
    }
}
void main()
{
    printf("Linear Queue\n");
    int c,ele;
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    while(1)
    {
        printf("\nEnter the choice:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("Enter the element to be inserted:");
            scanf("%d",&ele);
            insert(ele);
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:printf("terminating...");;
            break;
            default:printf("Invalid choice");
            break;
        }
        if(c==4)
            break;
    }
}
