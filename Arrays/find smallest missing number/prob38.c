#include<stdio.h>

int missing_number(int arr[],int n);
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
v=missing_number(arr,n);
printf("Smallest missing number is %d\n",v);
}

int missing_number(int arr[],int n)
{
int i=0;
if(arr[0]==0)
{
while(arr[i+1]==arr[i]+1)
i++;
return arr[i]+1;
}
else
return 0;
}

