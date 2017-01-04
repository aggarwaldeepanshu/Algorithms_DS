#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int consecutive(int arr[],int max,int min,int n);
int main(void)
{
int i,n,max,min,v;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("Enter the values\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
max=INT_MIN;
min=INT_MAX;
for(i=0;i<n;i++)
{
if(arr[i]>max)
max=arr[i];
if(arr[i]<min)
min=arr[i];
}
v=consecutive(arr,max,min,n);
if(v==-1)
printf("Numbers are not consecutive\n");
else
printf("Numbers are consecutive\n");
}

int consecutive(int arr[],int max,int min,int n)
{
int i,v;

if((max-min+1)==n)
{
for(i=0;i<n;i++)
{
if(arr[i]>=0)
v=arr[i]-min;
else
v=-arr[i]-min;

if(arr[v]>=0)
arr[v]=-arr[v];
else
return -1;
}
return 1;
}

return -1;
}
