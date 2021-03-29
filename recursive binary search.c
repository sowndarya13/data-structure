//recursive binary search
#include<stdio.h>
int bsearch(int arr[],int low,int high,int data);
int bsearch(int arr[],int low,int high,int data)
{
   int mid=(low+high)/2;
   if(low>high)
     return -1;
   if(arr[mid]==data)
      return mid;
   else if(arr[mid]<data)
      return bsearch(arr,mid+1,high,data);
   else
      return bsearch(arr,low,mid-1,data);
   return -1;
}

int main()
{
 int arr[100],n,i,data,pos;
 printf("enter the no. of elements in array:\n");
 scanf("%d",&n);
 printf("enter array elements in sorted order:\n");
 for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
printf("enter the no. to be seached\n");
scanf("%d",&data);
printf("the given array:\n");
for(i=0;i<n;i++)
   printf("%d ",arr[i]);
pos=bsearch(arr,0,n-1,data);
if(pos!=-1)
   printf("\nthe given element %d is at position %d\n",data,pos+1);
else
   printf("\nthe element is not present\n");
return 0;
}
