#include<stdio.h>

int key_search(int arr[],int low,int high,int key);
int pivot_search(int arr[],int low,int high);
int search(int arr[],int low,int high,int key);
int main(void)
{
int i,n,val;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("Enter the values\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("Enter the value to be searched\n");
scanf("%d",&val);
int v= search(arr,0,n-1,val);
if(v==-1)
printf("Value not present\n");
else 
printf("Index of value is:%d\n",v);
}

int search(int arr[],int low,int high,int key)
{
int pivot=pivot_search(arr,low,high);
if(pivot==-1)
return key_search(arr,low,high,key);
else if(arr[pivot]==key)
return pivot;
else if(arr[low]<=key)
return key_search(arr,low,pivot-1,key);
else 
return key_search(arr,pivot+1,high,key);
}
int pivot_search(int arr[],int low,int high)
{
int mid;
if(low>high)
return -1;
if(low==high)
return low;
if(low<high)
{
mid=(low+high)/2;
if(mid<high&&arr[mid]>arr[mid+1])
return mid;
else if(mid>low&&arr[mid]<arr[mid-1])
return mid-1;
else if(arr[low]>=arr[mid])
return pivot_search(arr,low,mid-1);
else
return pivot_search(arr,mid+1,high);
}
}
int key_search(int arr[],int low,int high,int key)
{
int mid;
if(low<=high)
{
mid=(low+high)/2;
if(arr[mid]==key)
return mid;
else if(arr[mid]>key)
return key_search(arr,low,mid-1,key);
else
return key_search(arr,mid+1,high,key);
}
return -1;
}
