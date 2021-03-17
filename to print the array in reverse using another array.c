//to print array in reverse in o(n)times
#include<stdio.h>
int main()
{
int n,arr1[100],arr[100],i,j=0;
printf("enter no. of elements in array:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
for(i=n-1;i>=0;i--)
{
arr1[j]=arr[i];
j++;
}
for(i=0;i<n;i++)
  printf("%d ",arr1[i]);
return 0;
}
