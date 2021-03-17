//to check whether the list is palindrome
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
}*head=NULL,*last=NULL,*temp,*newnode;
void insertfirst();
void insertlast();
void insertmiddle();
void display();
void palindrome();
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
void insertfirst()
{
int a;
printf("enter the element tobe inserted:\n");
scanf("%d",&a);
newnode=createnode(a);
if(isempty())
   head=last=newnode;
else
{
newnode->next=head;
head=newnode;
}
}
void insertlast()
{
int a,count=0;
printf("Enter the element to be inserted:\n");
scanf("%d",&a);
newnode=createnode(a);
if(isempty())
   head=last=newnode;
else
{
last->next=newnode;
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
else if(head->next==NULL)
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
while(temp!=NULL)
{
count++;
temp=temp->next;
}
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
temp->next=newnode;
}
else
 printf("position out of range\n");
}
}
void palindrome()
{
   int count=0,i,flag=0;
   temp=head;
   struct node *temp1;
   while(temp!=NULL)
     {
     count++;
     temp=temp->next;
     }
   struct node *previous;
   temp=last;
   temp1=head;
   for(i=0;i<count/2;i++)
   {
        previous=head;
   while(previous->next!=temp)
     previous=previous->next;
   if(temp->data!=temp1->data)
   {
    flag++;
    break;
   }
   temp1=temp1->next;
   temp=previous;
   }
   if(flag==0)
     printf("the list is palindrome\n");
   else
     printf("the list is not palindrome\n");
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
printf("choice list:\n1.insertfirst\n2.insertlast\n3.insertmiddle\n4.display list\n5.odd numbers\n6.exit\n");
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
case 4:display();
       break;
case 5:palindrome();
       break;
case 6:exit(1);
       break;
default:printf("choice is out of range\n");
}
}
return 0;
}
