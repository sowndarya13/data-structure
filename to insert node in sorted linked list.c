//to insert node in sorted singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
}*head=NULL,*last=NULL,*temp,*newnode,*head1=NULL,*last1=NULL;
void insert();
void display();
void deletefirst();
void deletelast();
void deletemiddle();
struct node *createnode(int);
int isempty();
struct node *createnode(int a)
{
newnode=(struct node*)malloc(sizeof(struct node));
if(newnode!=NULL)
{
newnode->data=a;
newnode->next=NULL;
}
else
  printf("space not allocated\n");
return newnode;
}
int isempty()
{
if(head==NULL)
  return 1;
else
  return 0;
}
void insert()
{
int a,count=0;
struct node *current;
printf("enter the element to be inserted\n");
scanf("%d",&a);
newnode=createnode(a);
if(isempty())
{
 head=last=newnode;
}
else
{
 temp=head;
 while(temp!=NULL)
 {
     count++;
    if(a<temp->data)
    {
     if(count==1)
     {
        newnode->next=head;
        head=newnode;
     }
     else
     {
      newnode->next=temp;
      current->next=newnode;
     }
     return ;
    }
     current=temp;
     temp=temp->next;
 }
    current->next=newnode;
    last=newnode;
}
}
void deletefirst()
{
    struct node *del;
    if(head==NULL)
        printf("list is empty deletion not possible\n");
    else if(head->next==NULL)
    {
        del=head;
        printf("the element deleted is %d\n",del->data);
        free(del);
        head=last=NULL;
    }
    else
    {
        del=head;
        printf("the element deleted is %d\n",del->data);
        head=head->next;
        free(del);
    }
}
void deletelast()
{
    struct node *del;
    if(head==NULL)
        printf("list is empty deletion not possible\n");
    else if(head->next==NULL)
    {
        del=last;
        printf("the element deleted is %d\n",del->data);
        free(del);
        head=last=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=last)
          temp=temp->next;
        del=last;
        printf("the element deleted is %d\n",del->data);
        last=temp;
        last->next=NULL;
        free(del);
    }
}
void deletemiddle()
{
   int count=0,position,i;
   struct node *del;
   printf("enter the position of the element u want to delete:\n");
   scanf("%d",&position);
    if(head->next==NULL)
    {
        if(position==1)
            deletefirst();
        else
            printf("position out of range\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
         if(position==1)
            deletefirst();
         else if(position==count)
            deletelast();
         else if(position<count)
         {
             temp=head;
             for(i=1;i<position-1;i++)
                temp=temp->next;
             del=temp->next;
             printf("the element deleted is %d\n",del->data);
             temp->next=temp->next->next;
             free(del);
        }
        else
            printf("position out of range\n");
    }
}
void display()
{
temp=head;
if(isempty())
  printf("the list is empty\n");
else if(head->next==NULL)
  printf("%d\n",head->data);
else
{
while(temp!=NULL)
{
if(temp->next!=NULL)
  printf("%d->",temp->data);
else
  printf("%d",temp->data);
 temp=temp->next;
}
printf("\n");
}
}
int main()
{
int choice;
printf("choice list:\n1.insert\n2.deletefirst\n3.deletelast\n4.deletemiddle\n5.display list\n6.exit\n");
while(1)
{
printf("enter ur choice:\n");
scanf("%d",&choice);
switch(choice)
{
case 1:insert();
       break;
case 2:deletefirst();
       break;
case 3:deletelast();
       break;

case 4:if(head!=NULL)
         deletemiddle();
       else
        printf("list empty deletion not possible\n");
       break;
case 5:display();
       break;
case 6:exit(1);
       break;
default:printf("choice is out of range\n");
}
}
return 0;
}
