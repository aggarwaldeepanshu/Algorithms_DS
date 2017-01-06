#include<stdio.h>

int search(int arr[],int low,int high);

int main(void)
{
int i,n,v;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("Enter the values\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
v=search(arr,0,n-1);
printf("Maximum element is %d\n",arr[v]);
}
int search(int arr[],int low,int high)
{
int mid;
if(low==high)
return low;
else if(low<high)
{
mid=(low+high)/2;
if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1])
return mid;
else if(arr[mid]>arr[mid+1]&&arr[mid]<arr[mid-1])
return search(arr,low,mid-1);
else
return search(arr,mid+1,high);
}
return -1;
}
