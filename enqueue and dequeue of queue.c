//enqueue and dequeue
#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,n,queue[100];
void enqueue(int);
int dequeue();
int isfull();
int isempty();
void display();
void enqueue(int a)
{
    if(front==-1)
     front++;
    queue[++rear]=a;
}
int dequeue()
{
  int i;
  if(rear==front)
  {
      i=rear;
      front=-1;
      rear=-1;
      return queue[i];
  }
    return queue[front++];
}
int isfull()
{
if(rear==n-1)
  return 1;
else
  return 0;
}
int isempty()
{
 if(front==-1)
   return 1;
 else
return 0;
}
void display()
{
 int i;
 if(isempty())
   printf("queue is empty\n");
 else
 {
  printf("The queue elements:\n");
  for(i=front;i<=rear;i++)
      printf("%d ",queue[i]);
  printf("\n");
 }
 }
 int main()
{
    int choice,b;
    printf("enter max size of queue:\n");
    scanf("%d",&n);
    printf("1.enqueue\n2.dequeue\n3.dispaly\n4.exit\n");
    while(1)
    {
        printf("enter ur choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:if(isfull())
                      printf("queue overflow\n");
                    else
                    {
                     printf("enter the element to be pushed\n");
                     scanf("%d",&b);
                     enqueue(b);
                     }
                   break;
            case 2:if(isempty())
                       printf("queue underflow\n");
                   else
                     printf("the deleted element is %d\n",dequeue());
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


