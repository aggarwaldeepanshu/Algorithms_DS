#include<stdio.h>
int main(void)
{
int i,low,mid,high,n,temp;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("Enter the values\n");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
low=0;
high=n-1;
mid=0;
while(mid<=high)
{
if(arr[mid]==0)
{
temp=arr[low];
arr[low]=arr[mid];
arr[mid]=temp;
mid++;
low++;
}
else if(arr[mid]==2)
{
temp=arr[high];
arr[high]=arr[mid];
arr[mid]=temp;
high--;
}
else
mid++;
}
printf("Array after sorting is\n");
for(i=0;i<n;i++)
printf("%d\t",arr[i]);
}
