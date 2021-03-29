#include<stdio.h>
int main()
{
  int arr[100],i,j,temp,n,min;
  printf("enter no. of elemnts in array:\n");
  scanf("%d",&n);
  printf("enter the array elements:\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  for(i=0;i<n-1;i++)
  {
   min=i;
   for(j=i+1;j<n;j++)
   {
     if(arr[min]>arr[j])
         min=j;
   }
   temp=arr[i];
   arr[i]=arr[min];
   arr[min]=temp;
  }
  printf("the sorted array:\n");
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}
