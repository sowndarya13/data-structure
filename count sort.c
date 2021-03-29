//count sort
#include<stdio.h>
void countsort(int arr[],int n);
int max(int arr[],int n);
   int max(int arr[],int n)
  {
   int i,max=arr[0];
   for(i=1;i<n;i++)
    {
      if(max<arr[i])
         max=arr[i];
    }
    return max;
  }
  void countsort(int arr[],int n)
  {
   int k=max(arr,n);
   int count[k+1];
   int b[n],i;
   for(i=0;i<=k;i++)
      count[i]=0;
   for(i=0;i<n;i++)
      count[arr[i]]++;
   for(i=1;i<=k;i++)
        count[i]=count[i]+count[i-1];
   for(i=n-1;i>=0;i--)
      b[--count[arr[i]]]=arr[i];
   for(i=0;i<n;i++)
      arr[i]=b[i];
  }
  int main()
{
  int arr[100],i,j,temp,n,gap;
  printf("enter no. of elemnts in array:\n");
  scanf("%d",&n);
  printf("enter the array elements:\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  countsort(arr,n);
  printf("the sorted array :\n");
  for(i=0;i<n;i++)
     printf("%d ",arr[i]);
  return 0;
  }
