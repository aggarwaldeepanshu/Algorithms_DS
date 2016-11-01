#include<stdio.h>
void segregate(int arr[],int n);
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
    segregate(arr,n);
    printf("The require array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void segregate(int arr[],int n)
{
    int a,b,temp;
    a=0;
    b=n-1;
    while(a<b)
    {
        while(arr[a]!=1)
            a++;
        while(arr[b]!=0)
            b--;
        if(a<b)
        {
            temp=arr[a];
            arr[a]=arr[b];
            arr[b]=temp;
        }
        a++;
        b--;
    }
}

