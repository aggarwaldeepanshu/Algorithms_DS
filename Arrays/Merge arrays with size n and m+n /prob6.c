#include <stdio.h>

void merge(int arr1[],int arr2[],int n,int m);
int main(void)
{
    int i,n,m;
    scanf("%d%d",&n,&m);
    int arr1[n],arr2[n+m];
    printf("give input for n element matrix\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("give input for (m+n) element matrix\nEnter -1 for denoting blank space\n");
    for(i=0;i<m+n;i++)
    {
        scanf("%d",&arr2[i]);
    }
    merge(arr1,arr2,n,m);
    printf("Array after merging is:\n");
    for(i=0;i<m+n;i++)
    {
        printf("%d\t",arr2[i]);
    }
}

void merge(int arr1[],int arr2[],int n,int m)
{
    int arr3[m+n];
    int i=0,j=0,k=0,v;
    while(i<n&&j<(m+n))
    {
        if(arr2[j]==-1)
        {
            j++;
        }
        
        else if(arr1[i]>arr2[j])
        {
            arr3[k]=arr2[j];
            k++;
            j++;
        }
        
        else{
            arr3[k]=arr1[i];
            k++;
            i++;
        }
    }
    if(i==n)
    {
        for(v=j;v<(m+n);v++)
        {
            if(v==-1)
                continue;
            arr3[k]=arr2[v];
            k++;
        }
    }
    else if(j==(m+n))
    {
        for(v=i;v<n;v++)
        {
            arr3[k]=arr1[v];
            k++;
        }
    }
        
    for(i=0;i<m+n;i++)
    {
        arr2[i]=arr3[i];
    }
}