//to check string palindrome using stack
#include<stdio.h>
#define max 100
int top=-1;
char stack[max];
void push(char);
char pop();
void push(char a)
{
  if(top<max-1)
     stack[++top]=a;
  else
    printf("overflow\n");
}
char pop()
{
 char a;
 if(top==-1)
   printf("underflow");
 else
 {
  a=stack[top];
  top--;
  return a;
 }
}
int main()
{
  char str[100],a;
  int l,i,flag=0;
  printf("enter the string:\n");
  scanf("%[^\n]%*c",str);
  for(l=0;str[l]!='\0';l++);
  for(i=0;i<l;i++)
    push(str[i]);
  for(i=0;i<(l/2);i++)
  {
    if(stack[i]!=pop())
    {
        flag=1;
        break;
    }
  }
  if(flag==1)
    printf("the given string %s is not a palindrome\n",str);
  else
   printf("the given string %s is palindrome\n",str);
  return 0;
  }
