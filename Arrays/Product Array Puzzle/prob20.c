#include<stdio.h>

int main(void)
{
    int i,n,multiply;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n],prodarr[n];
    multiply=1;
    printf("enter the values\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        multiply*=arr[i];
    }
    for(i=0;i<n;i++)
    {
        prodarr[i]=multiply/arr[i];
    }
    printf("The required array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",prodarr[i]);
    }
    printf("\n");
}
