#include<stdio.h>
void reverse(int arr[],int n);
int main(void)
{
    int i,n;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    reverse(arr,n);
    printf("Reversed array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void reverse(int arr[],int n)
{
    int start,end,temp;
    start=0;
    end=n-1;
    while (start<end) {
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}