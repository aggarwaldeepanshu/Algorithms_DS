#include<stdio.h>

void q_sort(int arr[],int l,int r);
int partition(int arr[],int l,int r);

int main(void)
{
    int i,n,l,r,val;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    q_sort(arr,0,n-1);
    //for(i=0;i<n;i++)
      //  printf("%d\t",arr[i]);
    l=0;
    r=n-1;
    int flag=0;
    scanf("%d",&val);
    while(l<r)
    {
        if((arr[l]+arr[r])==val)
        {
        flag=1;
            break;
    }
        else if((arr[l]+arr[r])>val)
            r--;
        else
            l--;
    }
    if(flag==1)
        printf("2 elements exist with sum %d",val);
    
    return 0;
    
}

void q_sort(int arr[],int l,int r)
{
    if(l<r)
    {
    int q;
    q=partition(arr,l,r);
    q_sort(arr,l,q-1);
    q_sort(arr,q+1,r);
}
    
}

int partition(int arr[],int l,int r)
{
    int i,j,temp;
    i=l-1;
    for(j=l;j<r;j++)
    {
        if(arr[j]<arr[r])
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=temp;
    return (i+1);
}
