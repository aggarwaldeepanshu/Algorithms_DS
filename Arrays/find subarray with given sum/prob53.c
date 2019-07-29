#include<stdio.h>
int main(void)
{
int i,n,a,sum,val,j;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("Enter the values\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("Enter the number\n");
scanf("%d",&val);
j=-1;
sum=arr[0];
a=0;
i=1;
while(i<n)
{
if(sum==val){
j=1;
break;
}
else if(sum>val)
{
while(sum>val && a<i)
{
sum-=arr[a];
a++;
}
}
else
while(sum<val)
{
sum+=arr[i];
i++;
}
}
if(j==1)
printf("sum found between %d and %d\n",a,i-1);
else
printf("No subarray found\n");
}
