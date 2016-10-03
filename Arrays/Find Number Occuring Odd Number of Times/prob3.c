#include <stdio.h>
int odd(int arr[],int n);
int main(void)
{
    int i,n,val;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    val=odd(arr,n);
    printf("Odd value is:\n%d\n",val);
}

int odd(int arr[],int n)
{
    int xor=0,i;
    for(i=0;i<n;i++)
    {
        xor^=arr[i];
    }
    return xor;
}