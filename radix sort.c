//radix sort
# define buc 10
#include<stdio.h>
void radix(int arr[],int n);
void countsort(int arr[],int n,int pos);
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
  void radix(int arr[],int n)
  {
     int k,pos;
     k=max(arr,n);
    for(pos=1;(k/pos)>0;pos*=10)
        countsort(arr,n,pos);
  }
  void countsort(int arr[],int n,int pos)
  {
   int count[buc]={0};
   int b[n],i;
   for(i=0;i<n;i++)
      count[((arr[i]/pos)%10)]++;
   for(i=1;i<10;i++)
        count[i]=count[i]+count[i-1];
   for(i=n-1;i>=0;i--)
      b[--count[((arr[i]/pos)%10)]]=arr[i];
   for(i=0;i<n;i++)
      arr[i]=b[i];
  }
  int main()
{
  int arr[100],i,j,n;
  printf("enter no. of elemnts in array:\n");
  scanf("%d",&n);
  printf("enter the array elements:\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  radix(arr,n);
  printf("the sorted array :\n");
  for(i=0;i<n;i++)
     printf("%d ",arr[i]);
  return 0;
  }
