#include <stdio.h>
#include <limits.h>
int main(void)
{
    int i,n,v,flag=0;
    scanf("%d",&n);
    int arr[n+1];
    arr[0]=0;

    for(i=1;i<=n;i++)
    {
        arr[i]=1;
    }
    
    for(i=0;i<n-1;i++)
    {
        scanf("%d",&v);
        arr[v]=0;
    }
    for(i=1;i<=n;i++)
    {
        if(arr[i]!=0)
        {
            
            flag=i;
    }
    }
    printf("Missing Number is: %d\n",flag);
}
