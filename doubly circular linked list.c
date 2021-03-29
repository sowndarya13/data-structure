//doubly circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
struct node *previous;
}*head=NULL,*last=NULL,*temp,*newnode;
void insertfirst();
void insertlast();
void insertmiddle();
void deletefirst();
void deletelast();
void deletemiddle();
void display();
struct node *createnode(int);
int isempty();
struct node *createnode(int a)
{
newnode=(struct node*)malloc(sizeof(struct node));
if(newnode!=NULL)
{
newnode->data=a;
newnode->next=NULL;
newnode->previous=NULL;
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
void insertfirst()
{
int a;
printf("enter the element to be inserted:\n");
scanf("%d",&a);
newnode=createnode(a);
if(isempty())
{
   head=last=newnode;
   head->previous=head->next=head;
   last->previous=last->next=last;
}
else
{
newnode->next=head;
head->previous=newnode;
newnode->previous=last;
head=newnode;
last->next=newnode;
}
}
void insertlast()
{
int a,count=0;
printf("Enter the element to be inserted:\n");
scanf("%d",&a);
newnode=createnode(a);
if(isempty())
{
   head=last=newnode;
   head->previous=head->next=head;
   last->previous=last->next=last;
}
else
{
last->next=newnode;
newnode->previous=last;
newnode->next=head;
head->previous=newnode;
last=newnode;
}
}
void insertmiddle()
{
int a,position,count=0,i;
printf("enter the position in which u want to insert:\n");
scanf("%d",&position);
if(isempty())
{
  if(position==1)
    insertfirst();
  else
   printf("position out of range\n");
}
else if(head->next==head)
 {
 if(position==1)
  insertfirst();
 else if(position==2)
   insertlast();
  else
   printf("position out of range\n");
 }
else
{
temp=head;
do
{
count++;
temp=temp->next;
}while(temp!=head);
temp=head;
if(position==1)
 insertfirst();
else if(position==count+1)
  insertlast();
else if(position<=count)
{
    printf("enter the element to be inserted\n");
    scanf("%d",&a);
    newnode=createnode(a);
for(i=1;i<position-1;i++)
{
temp=temp->next;
}
newnode->next=temp->next;
newnode->previous=temp;
temp->next->previous=newnode;
temp->next=newnode;
}
else
 printf("position out of range\n");
}
}
void deletefirst()
{
    struct node *del;
    if(head==NULL)
        printf("list is empty deletion not possible\n");
    else if(head->next==head)
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
        head->previous=last;
        last->next=head;
        free(del);
    }
}
void deletelast()
{
    struct node *del;
    if(head==NULL)
        printf("list is empty deletion not possible\n");
    else if(head->next==head)
    {
        del=last;
        printf("the element deleted is %d\n",del->data);
        free(del);
        head=last=NULL;
    }
    else
    {
        del=last;
        printf("the element deleted is %d\n",del->data);
        last=last->previous;
        last->next=head;
        head->previous=last;
        free(del);
    }
}
void deletemiddle()
{
   int count=0,position,i;
   struct node *del;
   printf("enter the position of the element u want to delete:\n");
   scanf("%d",&position);
    if(head->next==head)
    {
        if(position==1)
            deletefirst();
        else
            printf("position out of range\n");
    }
    else
    {
        temp=head;
        do
        {
            count++;
            temp=temp->next;
        }while(temp!=head);
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
             temp->next->next->previous=temp;
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
else if(head->next==head)
  printf("%d\n",head->data);
else
{
do
{
if(temp->next!=head)
  printf("%d->",temp->data);
else
  printf("%d",temp->data);
 temp=temp->next;
}while(temp!=head);
printf("\n");
}
}
int main()
{
int choice;
printf("choice list:\n1.insertfirst\n2.insertlast\n3.insertmiddle\n4.deletefirst\n5.deletelast\n6.deletemiddle\n7.display list\n8.exit\n");
while(1)
{
printf("enter ur choice:\n");
scanf("%d",&choice);
switch(choice)
{
case 1:insertfirst();
       break;
case 2:insertlast();
       break;
case 3:insertmiddle();
       break;
case 4:deletefirst();
       break;
case 5:deletelast();
       break;
case 6:if(head!=NULL)
       deletemiddle();
       else
        printf("list is empty deletion not possible\n");
       break;
case 7:display();
       break;
case 8:exit(1);
       break;
default:printf("choice is out of range\n");
}
}
return 0;
}
