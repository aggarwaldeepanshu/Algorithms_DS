#include<stdio.h>
int main(void)
{
int i,n,s,sum,count=0;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("Enter the values\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
sum+=arr[i];
}
sum-=arr[0];
s=0;
printf("Equilibrium index:\n");
for(i=0;i<n;i++)
{
if(sum==s){
printf("%d\t",i);
count++;
}
s+=arr[i];
sum-=arr[i+1];
}
if(count==0)
printf("-1\n");
}
