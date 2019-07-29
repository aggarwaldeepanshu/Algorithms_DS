#include<stdio.h>

int last_occurence(int arr[],int low,int high,int key,int n);
int first_occurence(int arr[],int low,int high,int key,int n);
int main(void)
{
int i,n,a,b,key;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("enter the values\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("Enter the number\n");
scanf("%d",&key);
a=first_occurence(arr,0,n-1,key,n);
b=last_occurence(arr,0,n-1,key,n);
if(a==-1||b==-1)
printf("Value does not exist\n");
else
printf("Number of occurences of %d is %d\n",key,(b-a+1));
}

int first_occurence(int arr[],int low,int high,int key,int n)
{
int mid;
mid=(low+high)/2;

if(low<=high)
{
if(mid==0||arr[mid]==key&&arr[mid-1]<key)
return mid;
else if(key>arr[mid])
return first_occurence(arr,mid+1,high,key,n);
else
return first_occurence(arr,low,mid-1,key,n);
}
return -1;
}

int last_occurence(int arr[],int low,int high,int key,int n)
{
int mid;
mid=(low+high)/2;

if(low<=high)
{
if(mid==n-1||arr[mid]==key&&arr[mid+1]>key)
return mid;
else if(arr[mid]>key)
return last_occurence(arr,low,mid-1,key,n);
else
return last_occurence(arr,mid+1,high,key,n);
}
return -1;
}
