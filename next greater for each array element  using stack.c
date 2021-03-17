//next greater element for every array element using stack
#include<stdio.h>
#include<stdlib.h>
int top=-1,top1=-1,n;
int stack[100],stack1[100];
void push(int a,int s[],int *t);
void pop(int s[],int *t);
void display(int s[],int *t);
int isempty(int *t);
int isfull(int *t);
void nextgreat(int s[],int *t);
int isempty(int *t)
{
    if(*t==-1)
        return 1;
    else
        return 0;
}
int isfull(int *t)
{
    if(*t==n-1)
        return 1;
    else
        return 0;
}
void push(int a,int s[],int *t)
{
    if(isfull(t))
    {
        printf("overflow occurs\n");
        return ;
    }
    else
       s[++(*t)]=a;
    if(*t!=top1)
    {
       free(stack1);
       top1=-1;
    }
}
void pop(int s[],int *t)
{
    int del;
    if(isempty(t))
    {
        printf("underflow occurs\n");
        return ;
    }
    else
    {
        del=s[*t];
        (*t)--;
         printf("the element deleted is %d\n",del);
    }
    if(*t!=top1)
    {
    free(stack1);
    top1=-1;
    }
}
void display(int s[],int *t)
{
    int i;
    if(isempty(t))
        printf("the stack is empty\n");
    else
        {
         for(i=*t;i>=0;i--)
                printf("%d ",s[i]);
        }
        printf("\n");
}
void nextgreat(int s[],int *t)
{
        int i=*t,j,count=0,c;
        if(isempty(t))
        printf("stack is empty\n");
        else
        {
            for(;i>=0;i--)
            {
                if(i!=*t)
                {
                    for(j=i+1;j<=*t;j++)
                    {
                        if(s[i]<s[j])
                        {
                            count++;
                            c=s[j];
                            push(c,stack1,&top1);
                            break;
                        }
                    }
                   if(count==0)
                        push(-1,stack1,&top1);
                    count=0;
                }
                else
                    push(-1,stack1,&top1);
            }
            printf("The given:\n");
            for(i=0;i<=*t;i++)
                printf("%d ",s[i]);
            printf("\nthe next greater element for each element:\n");
            display(stack1,&top1);
        }
}
int main()
{
    int choice,b;
    printf("enter max size of stack:\n");
    scanf("%d",&n);
    printf("1.push\n2.pop\n3.dispaly\n4.nextgreat\n5.exit\n");
    while(1)
    {
        printf("enter ur choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the element to be pushed\n");
                   scanf("%d",&b);
                   push(b,stack,&top);
                   break;
            case 2:pop(stack,&top);
                   break;
            case 3:display(stack,&top);
                   break;
            case 4:nextgreat(stack,&top);
                   break;
            case 5:exit(1);
                   break;
            default:printf("invalid choice entry\n");
        }
    }
    return 0;
}
