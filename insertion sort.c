#include<stdio.h>
int main()
{
  int arr[100],i,j,n,key;
  printf("enter no. of elemnts in array:\n");
  scanf("%d",&n);
  printf("enter the array elements:\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  for(i=1;i<n;i++)
  {
   key=arr[i];
   j=i-1;
   while(j>=0&&arr[j]>key)
   {
      arr[j+1]=arr[j];
      j--;
   }
   arr[j+1]=key;
  }
  printf("the sorted array:\n");
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}
