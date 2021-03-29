//addition of two polynomials
#include<stdio.h>
#include<stdlib.h>
struct poly
{
 int data,expo;
 struct poly *next;
}*head1=NULL,*head2=NULL,*head3=NULL,*temp,*newnode;
struct poly *createnode(int data,int expo);
void insert(struct poly **head,int data,int expo);
void poly(struct poly **head1,struct poly **head2);
void display(struct poly **head);
void freeall(struct poly **head)
{
    if(*head!=NULL)
  {
    while(*head!=NULL)
    {
     temp=*head;
     *head=(*head)->next;
     free(temp);
    }
    *head=NULL;
  }
}
struct poly *createnode(int data,int expo)
{
  newnode=(struct poly*)malloc(sizeof(struct poly));
  if(newnode!=NULL)
  {
    newnode->data=data;
    newnode->expo=expo;
    newnode->next=NULL;
  }
  else
    printf("memory not allocated\n");

}
void insert(struct poly **head,int data,int expo)
{
  newnode=createnode(data,expo);
  if(*head==NULL)
    *head=newnode;
  else
  {
    temp=*head;
    while(temp->next!=NULL)
     temp=temp->next;
    temp->next=newnode;
  }
}
void poly(struct poly **head1,struct poly **head2)
{
  freeall(&head3);
  int data1;
  struct poly *temp1,*temp2;
  temp1=*head1;
  temp2=*head2;
  while(temp1!=NULL&&temp2!=NULL)
  {
    if(temp1->expo>temp2->expo)
    {
       insert(&head3,temp1->data,temp1->expo);
       temp1=temp1->next;
    }
    else if(temp1->expo<temp2->expo)
    {
       insert(&head3,temp2->data,temp2->expo);
       temp2=temp2->next;
    }
    else
    {
      data1=temp1->data+temp2->data;
      insert(&head3,data1,temp1->expo);
      temp1=temp1->next;
      temp2=temp2->next;
    }
  }
  while(temp1!=NULL)
  {
    insert(&head3,temp1->data,temp1->expo);
    temp1=temp1->next;
  }
   while(temp2!=NULL)
  {
    insert(&head3,temp2->data,temp2->expo);
    temp2=temp2->next;
  }
}
void display(struct poly **head)
{
 if(*head==NULL)
    printf("list is empty\n");
 else if((*head)->next==NULL)
    printf("%dX^%d\n",(*head)->data,(*head)->expo);
 else
  {
    temp=*head;
    while(temp!=NULL)
    {
      if(temp->next!=NULL)
      {
        if((temp->next->data)>=0)
          printf("%dX^%d+",temp->data,temp->expo);
        else
          printf("%dX^%d",temp->data,temp->expo);
      }
      else
          printf("%dX^%d\n",temp->data,temp->expo);
      temp=temp->next;
    }
  }
}
int main()
{
 int choice,data,expo,hexpo,i;
 while(1)
 {
   printf("CHOICE LIST:\n1.create poly\n2.addpoly\n3.display poly(s)\n4.exit\n");
   printf("enter your choice:\n");
   scanf("%d",&choice);
   switch(choice)
   {
   case 1:while(1)
          {
           printf("1.poly1\n2.poly2\n3.exit\n");
           printf("enter your choice:\n");
           scanf("%d",&choice);
           switch(choice)
           {
            case 1:freeall(&head1);
                   printf("enter the highest power:\n");
                   scanf("%d",&hexpo);
                   printf("enter the coeficient and exponent in descending order.If inbetween any expo not present then enter coeff and expo as 0\n");
                   for(i=0;i<=hexpo;i++)
                   {
                    scanf("%d%d",&data,&expo);
                    insert(&head1,data,expo);
                   }
                   break;
            case 2:freeall(&head2);
                   printf("enter the highest power:\n");
                   scanf("%d",&hexpo);
                   printf("enter the coeficient and exponent in descending order.If inbetween any expo not present then enter coeff and expo as 0\n");
                   for(i=0;i<=hexpo;i++)
                   {
                    scanf("%d%d",&data,&expo);
                    insert(&head2,data,expo);
                   }
                   break;
            case 3:break;
            default:printf("invalid choice\n");
           }
           if(choice==3)
              break;
          }
            break;
    case 2:poly(&head1,&head2);
           break;
    case 3:while(1)
           {
            printf("1.poly1\n2.poly2\n3.additionpoly\n4.exit\n");
            printf("enter ur choice:\n");
            scanf("%d",&choice);
            switch(choice)
            {
             case 1:display(&head1);
                    break;
             case 2:display(&head2);
                    break;
             case 3:display(&head3);
                    break;
             case 4:break;
             default:printf("invalid choice\n");
            }
            if(choice==4)
                break;
           }
            break;
    case 4:exit(1);
           break;
    default:printf("invalid choice\n");
   }
 }
 return 0;
}
