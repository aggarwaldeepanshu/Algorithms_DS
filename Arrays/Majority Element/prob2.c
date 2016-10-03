#include <stdio.h>
#include <limits.h>

int main(void)
{
    int i,n,max,flag=0;
    scanf("%d",&n);
    int arr[n];
    max=INT_MIN;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        if(max<arr[i])
        {
            max=arr[i];
        }
        
    }
    int count[max+1];
    for(i=0;i<=max;i++)
    {
        count[i]=0;
    }
    for(i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    for(i=0;i<=max;i++)
    {
        if(count[i]>n/2)
        {
            flag=i;
            break;
        }
    }
    if(flag==0)
        printf("NONE\n");
    else
        printf("%d",flag);
}