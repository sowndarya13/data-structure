//shell sort
#include<stdio.h>
int main()
{
  int arr[100],i,j,temp,n,gap;
  printf("enter no. of elemnts in array:\n");
  scanf("%d",&n);
  printf("enter the array elements:\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  for(gap=n/2;gap>=1;gap/=2)
  {
    for(j=gap;j<n;j++)
    {
      for(i=j-gap;i>=0;i-=gap)
      {
        if(arr[i+gap]>arr[i])
            break;
        else
        {
        temp=arr[i+gap];
        arr[i+gap]=arr[i];
        arr[i]=temp;
        }
      }
    }
  }
   printf("the sorted array:\n");
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
  return 0;
}

