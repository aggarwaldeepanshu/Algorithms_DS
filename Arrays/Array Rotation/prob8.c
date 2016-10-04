#include <stdio.h>
void rotate(int arr[],int n,int d);
int main(void)
{
    int i,n,d;
    scanf("%d%d",&n,&d);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    rotate(arr,n,d);
    printf("Elements after rotation are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

void rotate(int arr[],int n,int d)
{
    int i,j=0;
    int temp[d];
    //store first d elements in temporary array
    for(i=0;i<d;i++)
    {
        temp[i]=arr[i];
    }
    //shift the remaining elements in original array to beginning
    for(i=d;i<n;i++)
    {
        arr[j]=arr[i];
        j++;
    }
    j=0;
    //merge both arrays
    for(i=n-d;i<n;i++)
    {
        arr[i]=temp[j];
        j++;
    }
}