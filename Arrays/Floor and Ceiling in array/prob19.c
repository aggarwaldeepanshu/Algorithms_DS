#include<stdio.h>

int _binary(int arr[],int low,int high,int val);
int search(int arr[],int low,int high,int val,int x);

int main(void)
{
    int i,n,x,val1,val2;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the values\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the value whose ceiling and floor is to be found\n");
    scanf("%d",&x);
    val1=_binary(arr,0,n-1,x);
    val2=search(arr,0,n-1,val1,x);
    if(val1==-1)
        printf("Ceiling does not exist\n");
    else
        printf("Ceiling is %d\n",arr[val1]);
    
    if(val2==-1)
        printf("Floor does not exist\n");
    else
        printf("Floor is %d\n",arr[val2]);
}

int _binary(int arr[],int low,int high,int val)
{
    if(val<=arr[low])
        return low;
    if(val>arr[high])
        return -1;
    int mid=(low+high)/2;
    if(val==arr[mid])
        return mid;
    else if(val>arr[mid])
    {
        if((mid+1)<=high && val<=arr[mid+1])
            return mid+1;
        else
            return _binary(arr,(mid+1),high,val);
    }
    else
    {
        if((mid-1)>=low && arr[mid-1]<val)
            return mid-1;
        else
            return _binary(arr,low,(mid-1),val);
    }
}

int search(int arr[],int low,int high,int val,int x)
{
    if(val==-1)
        return high;
    else if(val==low)
        return -1;
    else if(arr[val]==x)
        return val;
    else
        return val-1;
}