#include<stdio.h>
int stack[10];
int top=-1;
void push(int x)
{
    if(top==9)
    {
        printf("Stack overflow");
    }
    else
    {
        top++;
    stack[top]=x;
    printf("%d pushed into the stack\n", x);
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Stack underflow");
    }
    else
    {
        printf("%d is popped from stack\n",stack[top]);
        top--;
    }
}
void display()
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("stack elements are as follows\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
void main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    pop();
    push(50);
    display();
}
