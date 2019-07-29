#include<stdio.h>

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
int max[n],min[n];
min[0]=1;
for(i=1;i<n;i++)
{
if(arr[i]>=arr[i-1])
min[i]=min[i-1]+1;
else
min[i]=1;
}
max[n-1]=1;
for(i=n-2;i>=0;i--)
{
if(arr[i]>=arr[i+1])
max[i]=max[i+1]+1;
else
max[i]=1;
}
int v;
val=-1;
for(i=0;i<n;i++)
{
v=max[i]+min[i]-1;
if(val<v)
val=v;
}
printf("Maximum length is %d\n",val);
}
