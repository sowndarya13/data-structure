//stack implementation using array
#include<stdio.h>
#include<stdlib.h>
int top=-1,n;
int stack[100];
void push(int);
void pop();
void display();
int isempty();
int isfull();
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int isfull()
{
    if(top==n-1)
        return 1;
    else
        return 0;
}
void push(int a)
{
    if(isfull())
    {
        printf("overflow occurs\n");
        return ;
    }
    else
       stack[++top]=a;
}
void pop()
{
    int del;
    if(isempty())
    {
        printf("underflow occurs\n");
        return ;
    }
    else
    {
        del=stack[top];
        top--;
         printf("the element deleted is %d\n",del);
    }

}
void display()
{
    int i;
    if(isempty())
        printf("the stack is empty\n");
    else
        {
        printf("thr stack elements:\n")
         for(i=top;i>=0;i--)
                printf("%d ",stack[i]);
        }
        printf("\n");
}
int main()
{
    int choice,b;
    printf("enter max size of stack:\n");
    scanf("%d",&n);
    printf("1.push\n2.pop\n3.dispaly\n4.exit\n");
    while(1)
    {
        printf("enter ur choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the element to be pushed\n");
                   scanf("%d",&b);
                   push(b);
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            case 4:exit(1);
                   break;
            default:printf("invalid choice entry\n");
        }
    }
    return 0;
}
