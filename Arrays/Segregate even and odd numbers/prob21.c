#include<stdio.h>

void segregate(int arr[],int low,int high);

int main(void)
{
    int i,n;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the values\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    segregate(arr,0,n-1);
    printf("The required aray is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void segregate(int arr[],int low,int high)
{
    int a,b,temp;
    a=low;
    b=high;
    while(a<b)
    {
        while(arr[a]%2==0)
            a++;
        while(arr[b]%2!=0)
            b--;
        if(a<b)
        {
            temp=arr[a];
            arr[a]=arr[b];
            arr[b]=temp;
            a++;
            b--;
        }
    }
}
