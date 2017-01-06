#include<stdio.h>
int main(void)
{
int i,n,j,val=-1;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("enter the values\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
int max[n],min[n];
min[0]=arr[0];
max[n-1]=arr[n-1];
for(i=1;i<n;i++)
{
if(arr[i]<min[i-1])
min[i]=arr[i];
else
min[i]=min[i-1];
}
for(i=n-2;i>=0;i--)
{
if(arr[i]>max[i+1])
max[i]=arr[i];
else
max[i]=max[i+1];
}
i=0;
j=0;
while(i<n&&j<n)
{
if(max[j]>min[i])
{
val=(val>(j-i))?val:(j-i);
j++;
}
else
i++;
}
printf("Maximum difference is %d\n",val);
}
