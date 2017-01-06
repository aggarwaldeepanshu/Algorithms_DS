#include<stdio.h>

int compare(int arr1[],int arr2[],int n,int m);
int partition(int arr[],int low,int high);
void q_sort(int arr[],int low,int high);
int main(void)
{
int i,n,m,v;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr1[n];
printf("Enter the values\n");
for(i=0;i<n;i++)
scanf("%d",&arr1[i]);
printf("Enter the size of subarray\n");
scanf("%d",&m);
int arr2[m];
printf("Enter the values\n");
for(i=0;i<m;i++)
scanf("%d",&arr2[i]);
q_sort(arr1,0,n-1);
q_sort(arr2,0,m-1);
v=compare(arr1,arr2,n,m);
if(v==1)
printf("It is a subarray\n");
else
printf("It is not a subarray\n");
}

void q_sort(int arr[],int low,int high)
{
int q;
if(low<high)
{
q=partition(arr,low,high);
q_sort(arr,low,q-1);
q_sort(arr,q+1,high);

}
}
int partition(int arr[],int low,int high)
{
int p,r,i,j,temp;
p=low;
i=low-1;
r=high;
for(j=low;j<r;j++)
{
if(arr[j]<arr[r])
{
i++;
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
temp=arr[i+1];
arr[i+1]=arr[r];
arr[r]=temp;
return i+1;
}
int compare(int arr1[],int arr2[],int n,int m)
{
int i=0,j=0;
while(i<n&&j<m)
{
if(arr1[i]==arr2[j])
{
i++;
j++;
}
else if(arr1[i]<arr2[j])
i++;
else 
return -1;
}
if(j==m)
return 1;
else
return -1;
}
