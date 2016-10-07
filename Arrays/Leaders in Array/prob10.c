#include<stdio.h>

int main(void)
{
    int n,i;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("Maximum elements are:\n");
    int max;
    max=arr[n-1];
    for(i=n-2;i>=0;i--)
    {
        if(max<arr[i])
        {
            max=arr[i];
        printf("%d\t",max);
        }
    }
    printf("%d\n",arr[n-1]);
}