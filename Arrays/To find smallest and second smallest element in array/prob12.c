#include <stdio.h>
#include<limits.h>

void scan(int arr[],int n);
int main(void)
{
    int i,n;
    printf("Enter array size\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the values\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scan(arr,n);
}

void scan(int arr[],int n)
{
    int i,a,b;
    a=b=INT_MAX;
    for(i=0;i<n;i++)
    {
        if(arr[i]<a)
        {
            b=a;
            a=arr[i];
        }
        else if(arr[i]<b && arr[i]!=a)
        {
            b=arr[i];
        }
    }
    printf("Smallest Element is %d",a);
    printf("\nSecond Smallest Element is %d",b);
}