#include<stdio.h>

int search(int arr[],int k);

int main(void)
{
int i,n,max,k;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("Enter the values\n");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("Enter the size of subarray\n");
scanf("%d",&k);
max=search(arr,k);
printf("%d\t",max);
i=k-1;
int j=0;
while(i+1<n)
{
if(arr[j]==max)
{
j++;
max=search(arr+j,k);
i++;
}
else{
i++;
j++;
if(arr[i]>max){
max=arr[i];

}
}
printf("%d\t",max);
}
}

int search(int arr[],int k)
{
int i,max;
max=arr[0];
for(i=1;i<k;i++)
{
if(arr[i]>max)
max=arr[i];
}
return max;
}
