//BUUBLE SORT
#include<stdio.h>
int main()
{
  int arr[100],i,j,temp,n;
  printf("enter no. of elemnts in array:\n");
  scanf("%d",&n);
  printf("enter the array elements:\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
       temp=arr[j];
       arr[j]=arr[j+1];
       arr[j+1]=temp;
      }
    }
  }
  printf("The sorted array:\n");
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}
