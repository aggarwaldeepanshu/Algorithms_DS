#include<stdio.h>
#include<stdlib.h>

int main(void)
{
int i,n,sum,prod,a,b,s,p;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("enter the values\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
for(i=0;i<n;i++)
{
if(arr[abs(arr[i])-1]>=0)
arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
else
{
printf("Repeating element is %d\n",abs(arr[i]));
}
}
for(i=0;i<n;i++)
{
if(arr[i]>0){
printf("Missing element is %d\n",i+1);
break;
}
}
}
