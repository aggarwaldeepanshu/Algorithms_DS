#include<stdio.h>

int main(void)
{
int i,n,a,b,x,y,min,j;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("Enter the values\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("Enter the two numbers\n");
scanf("%d%d",&x,&y);
i=0;
min=n+1;
for(i=0;i<n;i++)
{
if(arr[i]==x||arr[i]==y)
{
a=i;
break;
}
}
for(j=i;j<n;j++)
{
if(arr[j]==x||arr[j]==y)
{
if(arr[j]==arr[a])
a=j;
else
{
min=(min<(j-a))?min:(j-a);
a=j;
}
}
}
printf("Minimum distance is %d",min);
}
