#include<stdio.h>

void max_min(int arr[],int n);

int main(void)
{
    int i,n;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the values\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    max_min(arr,n);
}

void max_min(int arr[],int n)
{
    int i,min,max,a,b;
    if(n%2==0)
    {
        if(arr[0]>arr[1])
        {
            min=arr[1];
            max=arr[0];
        }
        else
        {
            min=arr[0];
            max=arr[1];
        }
        i=2;
    }
    else
    {
        min=max=arr[0];
        i=1;
    }
    while(i<=(n-1))
    {
        if(arr[i]<arr[i+1])
        {
            a=arr[i];
            b=arr[i+1];
        }
        else
        {
            a=arr[i+1];
            b=arr[i];
        }
        if(min>a)
            min=a;
        if(max<b)
            max=b;
        i+=2;
    }
    printf("Max is %d\nMin is %d\n",max,min);
}