#include<stdio.h>

int max_sum(int arr[],int n);
int max(int val1,int val2);

int main(void)
{
    int n,i,val;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    val=max_sum(arr,n);
    printf("Maximum sum is:\n%d\n",val);
}

int max_sum(int arr[],int n)
{
    int val1,val2,i,temp;
    val2=0;
    val1=arr[0];
    for(i=1;i<n;i++)
    {
        temp=val1;
        val1=arr[i]+val2;
        val2=max(temp,val2);
    }
    val1=max(val1,val2);
    return val1;
}

int max(int val1,int val2)
{
    if(val1>val2)
        return val1;
    else
        return val2;
}