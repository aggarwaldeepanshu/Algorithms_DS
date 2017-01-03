#include<stdio.h>

int mid(int arr[],int n);
int median(int arr1[],int arr2[],int n);

int main(void)
{
int i,n,val;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr1[n],arr2[n];
printf("Enter the values for first array\n");
for(i=0;i<n;i++)
scanf("%d",&arr1[i]);
printf("Enter the values for second array\n");
for(i=0;i<n;i++)
scanf("%d",&arr2[i]);
val=median(arr1,arr2,n);
printf("Median is %d\n",val);
}

int median(int arr1[],int arr2[],int n)
{
int i,m1,m2,max,min;
max=(arr1[0]>arr2[0])?arr1[0]:arr2[0];
min=(arr1[1]>arr2[1])?arr2[1]:arr1[1];
if(n<=0)
return -1;
else if(n==1)
return (arr1[0]+arr2[0])/2;
else if(n==2)
return (max+min)/2;
m1=mid(arr1,n);
m2=mid(arr2,n);
if(m1==m2)
return m1;
if(m1>m2)
{
if(n%2==0)
return median(arr1,arr2+n/2-1,n-n/2+1);
else
return median(arr1,arr2+n/2,n-n/2);
}
else
{
if(n%2==0)
return median(arr1+n/2-1,arr2,n-n/2+1);
else
return median(arr1+n/2,arr2,n-n/2);
}
}

int mid(int arr[],int n)
{
if(n%2==0)
return (arr[n/2]+arr[n/2-1])/2;
else
return arr[n/2];
}

