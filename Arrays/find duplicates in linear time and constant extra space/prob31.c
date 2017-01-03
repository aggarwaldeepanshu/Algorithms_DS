#include<stdio.h>
#include<stdlib.h>

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
for(i=0;i<n;i++)
{
if(arr[abs(arr[i])]>=0&&arr[abs(arr[i])]!=n+1)
arr[abs(arr[i])]=-arr[abs(arr[i])];
else if(arr[abs(arr[i])]<0)
{
printf("%d\t",abs(arr[i]));
arr[abs(arr[i])]=n+1;
}
}
}
