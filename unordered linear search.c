//unordered linear search
#include<stdio.h>
int main()
{
 int arr[100],n,i,data;
 printf("enter the no. of elements in array:\n");
 scanf("%d",&n);
 printf("enter array elements:\n");
 for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
printf("enter the no. to be seached\n");
scanf("%d",&data);
printf("the given array:\n");
for(i=0;i<n;i++)
   printf("%d ",arr[i]);
for(i=0;i<n;i++)
{
  if(arr[i]==data)
  {
     printf("\nThe given element %d is present at position %d\n",data,i+1);
     break;
   }
}
if(i==n)
   printf("\nthe element is not present\n");
return 0;
}
