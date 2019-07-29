#include<stdio.h>

void heapify(int arr[],int n);
void min_heap(int arr[],int i,int n);

int main(void)
{
    int i,n,k;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the values\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("How many numbers to be printed?\n");
    scanf("%d",&k);
    heapify(arr,n);
    printf("The required numbers are\n");
    for(i=0;i<k;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void heapify(int arr[],int n)
{
    int i,temp;
    for(i=n/2-1;i>=0;i--)
        min_heap(arr,i,n);
    for(i=n-1;i>=0;i--)
    {
        temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        min_heap(arr,0,i);
    }
}

void min_heap(int arr[],int i,int n)
{
    int smallest,temp;
    int l,r;
    smallest=i;
    l=2*i+1;
    r=2*i+2;
    if(l<n&&arr[smallest]>arr[l])
        smallest=l;
    if(r<n&&arr[smallest]>arr[r])
        smallest=r;
    if(smallest!=i)
    {
        temp=arr[i];
        arr[i]=arr[smallest];
        arr[smallest]=temp;
        min_heap(arr,smallest,n);
    }
}