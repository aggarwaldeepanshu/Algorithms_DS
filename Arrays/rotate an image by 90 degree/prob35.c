#include<stdio.h>
#include<stdlib.h>
int main(void)
{
int i,j,r,c;
printf("Enter the number of rows\n");
scanf("%d",&r);
printf("Enter the number of columns\n");
scanf("%d",&c);
int *arr1,*arr2;
arr1=(int*)malloc(c*r*sizeof(int));
arr2=(int*)malloc(c*r*sizeof(int));

printf("Enter the input\n");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
scanf("%d",/*&arr1[i][j]*/(arr1+i*c+j));
}
}
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
//arr2[j][r-i-1]=arr1[i][j];
*(arr2+j*r+(r-i-1))=*(arr1+i*c+j);
}
}
printf("The image after rotation is\n");
for(i=0;i<c;i++)
{
for(j=0;j<r;j++)
printf("%d\t",/*arr2[i][j]*/*(arr2+i*r+j));
printf("\n");
}
}
