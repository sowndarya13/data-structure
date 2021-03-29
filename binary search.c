//binary search
#include<stdio.h>
int main()
{
 int arr[100],n,i,data,mid,low,high;
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
low=0;
high=n-1;
while(low<=high)
{
   mid=(low+high)/2;
   if(arr[mid]==data)
   {
      printf("\nThe given element %d is present at position %d\n",data,mid+1);
      break;
   }
   else if(arr[mid]<data)
      low=mid+1;
   else
      high=mid-1;
}
if(low>high)
   printf("\nthe given element %d is not present\n",data);
return 0;
}
