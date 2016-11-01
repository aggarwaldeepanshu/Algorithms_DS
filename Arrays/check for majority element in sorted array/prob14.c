#include <stdio.h>

int maj_element(int arr[],int n,int val);
int _binary(int arr[],int p,int r,int val);

int main(void)
{
    int i,n,val,t;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the values\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the value to be searched\n");
    scanf("%d",&val);
    t=maj_element(arr,n,val);
    if(t==1)
        printf("It is a Majority Element\n");
    else
        printf("It is not a Majority Element\n");
    return 0;
}
int maj_element(int arr[],int n,int val)
{
    int v;
    v=_binary(arr,0,n-1,val);
    if(v==-1)
        return -1;
    
    
    if(((v+n/2)<=(n-1)) && arr[v+n/2]==val)
        return 1;
    else
        return -1;
}

int _binary(int arr[],int p,int r,int val)
{
    int mid;
    if(p<=r)
    {
        mid=(p+r)/2;
        if((mid==0|| arr[mid-1]<val)&&(arr[mid]==val))
            return mid;
        else if(val>arr[mid])
            return _binary(arr,(mid+1),r,val);
        else
            return _binary(arr,p,(mid-1),val);
    }
    return -1;
}