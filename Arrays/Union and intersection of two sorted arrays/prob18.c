#include<stdio.h>

void merge(int arr1[],int arr2[],int n,int m);

int main(void)
{
    int i,n,m;
    printf("Enter the size of first array\n");
    scanf("%d",&n);
    printf("Enter the size of second array\n");
    scanf("%d",&m);
    int arr1[n],arr2[m];
    printf("enter the values for first array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("enter the values for second array\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&arr2[i]);
    }
    merge(arr1,arr2,n,m);

}

void merge(int arr1[],int arr2[],int n,int m)
{
    int a,b,i,j,uni[n+m],inter[n],k;
    a=0;
    b=0;
    j=0;
    k=0;
    for(i=0;a<n&&b<m;i++)
    {
        if(arr1[a]<arr2[b])
        {
            uni[j]=arr1[a];
            j++;
            a++;
        }
        else if(arr2[b]<arr1[a])
        {
            uni[j]=arr2[b];
            j++;
            b++;
        }
        else
        {
            uni[j]=inter[k]=arr1[a];
            j++;
            a++;
            b++;
            k++;
        }
    }
    if(a==n)
        for(i=b;i<m;i++)
        {
            uni[j]=arr2[i];
            j++;
        }
    else if(b==m)
        for(i=a;i<n;i++)
        {
            uni[j]=arr1[i];
            j++;
        }
    printf("Union\n");
    for(i=0;i<j;i++)
    {
        printf("%d\t",uni[i]);
    }
    printf("\nIntersection\n");
    for(i=0;i<k;i++)
    {
        printf("%d\t",inter[i]);
    }
}