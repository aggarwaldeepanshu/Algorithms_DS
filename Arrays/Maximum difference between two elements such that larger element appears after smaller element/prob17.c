#include<stdio.h>

int maxdif(int arr[],int n);

int main(void)
{
    int i,n,val;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the values\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    val=maxdif(arr,n);
    printf("maximum difference is %d\n",val);
}

int maxdif(int arr[],int n)
{
    int i,diff,min;
    diff=arr[1]-arr[0];
    min=arr[0];
    for(i=1;i<n;i++)
    {
        if((arr[i]-min)>diff)
            diff=arr[i]-min;
        if(arr[i]<min)
            min=arr[i];
    }
    return diff;
}