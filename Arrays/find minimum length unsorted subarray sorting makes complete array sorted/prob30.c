#include<stdio.h>
int main(void)
{
int i,n,a,b;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("enter the values\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
i=0;a=0;
while(arr[i]<arr[i+1])
{
i++;
a=i;
}
i=n-1;
b=n-1;
while(arr[i]>arr[i-1])
{
i--;
b=i;
}
int max=-500;
for(i=a;i<=b;i++)
{
if(arr[i]>max)
max=arr[i];
}
int min=9999;
for(i=a;i<=b;i++)
{
if(arr[i]<min)
min=arr[i];
}
int v1=a,v2=b;
for(i=0;i<a;i++)
{
if(arr[i]>=min){
v1=i;
break;
}
}
for(i=n-1;i>b;i--)
{
if(arr[i]<=max){
v2=i;
break;
}
}
printf("Subarray lies between %d and %d\n",v1,v2);
}
