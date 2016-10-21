#include<stdio.h>
#include<stdlib.h>

void sort(int arr[],int p,int r);
int q_sort(int arr[],int p,int r);
void scan(int arr[],int start,int n);

int main(void)
{
    int i,n;
    printf("enter size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    sort(arr,0,n-1);
    scan(arr,0,n);
}

void scan(int arr[],int start,int n)
{
    int l,r,a,b,temp,min,var;
    l=start;
    r=n-1;
    a=arr[l];
    b=arr[r];
    min=abs(arr[l]+arr[r]);
    while(l<r)
    {
        temp=arr[l]+arr[r];
        var=abs(temp);
        if(var<min)
        {
            a=arr[l];
            b=arr[r];
        }
        if(temp>0)
            r--;
        else if(temp<0)
            l++;
    }
    printf("a=%d b=%d\n",a,b);
}


void sort(int arr[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=q_sort(arr,p,r);
        sort(arr,p,q-1);
        sort(arr,q+1,r);
    }
}

int q_sort(int arr[],int p,int r)
{
    int i,j,temp;
    i=p-1;
    for(j=p;j<r;j++)
    {
        if(arr[j]<arr[r])
        {
            i++;
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;
    return (i+1);
}