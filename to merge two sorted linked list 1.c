//to merge two sorted linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
}*head=NULL,*last=NULL,*temp,*newnode,*head1=NULL,*last1=NULL,*temp1,*head2=NULL,*last2=NULL;
void insertfirst(struct node **h,struct node **l);
void insertlast(struct node **h,struct node **l);
void insertmiddle(struct node **h,struct node **l);
void display(struct node *h);
void mergesort();
struct node *createnode(int);
int isempty(struct node *h);
void mergefree();
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
int isempty(struct node *h)
{
if(h==NULL)
  return 1;
else
  return 0;
}
void insertfirst(struct node **h,struct node **l)
{
int a;
printf("enter the element tobe inserted:\n");
scanf("%d",&a);
newnode=createnode(a);
if(isempty(*h))
   *h=*l=newnode;
else
{
newnode->next=*h;
*h=newnode;
}
}
void insertlast(struct node **h,struct node **l)
{
int a,count=0;
printf("Enter the element to be inserted:\n");
scanf("%d",&a);
newnode=createnode(a);
if(isempty(*h))
   *h=*l=newnode;
else
{
(*l)->next=newnode;
*l=newnode;
}
}
void insertmiddle(struct node **h,struct node **l)
{
int a,position,count=0,i;
printf("enter the position in which u want to insert:\n");
scanf("%d",&position);
if(isempty(*h))
{
  if(position==1)
    insertfirst(h,l);
  else
   printf("position out of range\n");
}
else if((*h)->next==NULL)
 {
 if(position==1)
  insertfirst(h,l);
 else if(position==2)
   insertlast(h,l);
  else
   printf("position out of range\n");
 }
else
{
temp=*h;
while(temp!=NULL)
{
count++;
temp=temp->next;
}
temp=*h;
if(position==1)
 insertfirst(h,l);
else if(position==count+1)
  insertlast(h,l);
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
void mergesort()
{
    if(head==NULL&&head1==NULL)
        printf("merge not possible as two list are empty");
else
{
temp=head;
temp1=head1;
while(temp!=NULL&&temp1!=NULL)
{
if(temp->data<temp1->data)
{
    if(isempty(head2))
    {
        newnode=createnode(temp->data);
        head2=last2=newnode;
    }
    else
    {
        newnode=createnode(temp->data);
        last2->next=newnode;
        last2=last2->next;
    }
    temp=temp->next;
}
else if(temp->data>temp1->data)
{
    if(isempty(head2))
    {
        newnode=createnode(temp1->data);
        head2=last2=newnode;
    }
    else
    {
        newnode=createnode(temp1->data);
        last2->next=newnode;
        last2=last2->next;
    }
    temp1=temp1->next;
}
else
{
    if(isempty(head2))
    {
        newnode=createnode(temp1->data);
        head2=last2=newnode;
        newnode=createnode(temp->data);
        last2->next=newnode;
        last2=last2->next;
    }
    else
    {
        newnode=createnode(temp->data);
        last2->next=newnode;
        newnode=createnode(temp1->data);
        last2->next->next=newnode;
        last2=last2->next->next;
    }
    temp1=temp1->next;
    temp=temp->next;
}
}
while(temp!=NULL)
{
    if(isempty(head2))
    {
        newnode=createnode(temp->data);
        head2=last2=newnode;
    }
    else
    {
        newnode=createnode(temp->data);
        last2->next=newnode;
        last2=last2->next;
    }
    temp=temp->next;
}
while(temp1!=NULL)
{
    if(isempty(head2))
    {
        newnode=createnode(temp1->data);
        head2=last2=newnode;
    }
    else
    {
         newnode=createnode(temp1->data);
        last2->next=newnode;
        last2=last2->next;
    }
    temp1=temp1->next;
}
printf("merge of two sorted list:\n");
display(head2);
if(head2!=NULL)
    mergefree();
}
}
void display(struct node *h)
{
temp=h;
if(isempty(h))
  printf("the list is empty\n");
else if(h->next==NULL)
  printf("%d\n",h->data);
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
void mergefree()
{
    temp=head2;
    while(temp!=NULL)
    {
      head2=temp->next;
      free(temp);
      temp=head2;
    }
}
int main()
{
int choice;
printf("1.list1\n2.list2\n3.exit\n");
printf("choice list:\n1.insertfirst\n2.insertlast\n3.insertmiddle\n4.display list\n5.mergesort\n6.exit\n");
while(1)
{
printf("enter the list number");
scanf("%d",&choice);
switch(choice)
{

   case 1:while(1)
         {
          printf("enter the task choice:\n");
          scanf("%d",&choice);
         switch(choice)
         {
         case 1:insertfirst(&head,&last);
                 break;
         case 2:insertlast(&head,&last);
                break;
         case 3:insertmiddle(&head,&last);
                break;
         case 4:display(head);
                break;
         case 5:mergesort();
                break;
         case 6:break;
         default:printf("choice is out of range\n");
        }
        if(choice==6)
            break;
        }
        break;
   case 2:while(1)
         {
          printf("enter the task choice:\n");
          scanf("%d",&choice);
         switch(choice)
         {
         case 1:insertfirst(&head1,&last1);
                 break;
         case 2:insertlast(&head1,&last1);
                break;
         case 3:insertmiddle(&head1,&last1);
                break;
         case 4:display(head1);
                break;
         case 5:mergesort();
                break;
         case 6:break;
         default:printf("choice is out of range\n");
        }
        if(choice==6)
            break;
         }
         break;
     case 3:exit(1);
            break;
     default:printf("choice out of range\n");
             break;
}
}
return 0;
}
