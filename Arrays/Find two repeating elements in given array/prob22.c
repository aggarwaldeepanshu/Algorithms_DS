#include<stdio.h>
#include<math.h>

int fact(int n);

int main(void)
{
    int i,n,sum,prod,p,val,a,b;
    printf("Enter the range of numbers\n");
    scanf("%d",&n);
    int arr[n+2];
    sum=0;
    p=1;
    printf("enter the values\n");
    for(i=0;i<n+2;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
        p*=arr[i];
    }
    sum=sum-n*(n+1)/2;
    prod=fact(n);
    prod=p/prod;
    val=sqrt(sum*sum-4*prod);
    a=(sum+val)/2;
    b=(sum-val)/2;
    printf("The repeating elements are %d and %d\n",a,b);
}

int fact(int n)
{
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}