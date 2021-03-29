//quick sort
#include<stdio.h>
void quicksort(int arr[],int lb,int ub);
int partition(int arr[],int lb,int ub);
void quicksort(int arr[],int lb,int ub)
{
  int loc;
 if(lb<ub)
 {
 loc=partition(arr,lb,ub);
 quicksort(arr,lb,loc-1);
 quicksort(arr,loc+1,ub);
 }
}
int partition(int arr[],int lb,int ub)
{
 int start=lb,pivot=arr[lb],end=ub,k=0,temp;
 while(start<end)
 {
   while(arr[start]<=pivot)
      start++;
    while(arr[end]>pivot)
       end--;
     if(start<end)
    {
      temp=arr[start];
      arr[start]=arr[end];
      arr[end]=temp;
    }
 }
 temp=arr[end];
 arr[end]=arr[lb];
 arr[lb]=temp;;
 return end;
}
int main()
{
  int arr[100],i,j,temp,n,gap;
  printf("enter no. of elemnts in array:\n");
  scanf("%d",&n);
  printf("enter the array elements:\n");
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
  quicksort(arr,0,n-1);
  printf("the sorted array:\n");
  for(i=0;i<n;i++)
     printf("%d ",arr[i]);
  return 0;
}
