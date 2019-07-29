#include <stdio.h>
#include <limits.h>
int main(void)
{
    int i,n,val,sum;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    val=INT_MIN;
    sum=0;
    for(i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>val)
            val=sum;
        else if(sum<0)
        {
            
            sum=0;
        }
    }
    printf("Max sum is:\n%d\n",val);
}