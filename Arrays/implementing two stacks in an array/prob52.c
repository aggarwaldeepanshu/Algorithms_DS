#include<stdio.h>
int top1=-1,top2;
void push1(int arr[],int v)
{
top1++;
if(top1==top2)
printf("Invalid insertion\n");
else
arr[top1]=v;
}
void push2(int arr[],int v)
{
top2--;
if(top2==top1)
printf("Invalid insertion\n");
else
arr[top2]=v;
}
int pop1(int arr[])
{
if(top1==-1)
printf("Invalid operation\n");
else
return arr[top1--];
}

int pop2(int arr[],int n)
{
if(top2==n)
printf("Invalid operation\n");
else
return arr[top2++];
}

int main(void)
{
int i,n,v,a,b;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
top2=n;
push1(arr,3);
push2(arr,2);
push1(arr,10);
push2(arr,5);
push2(arr,8);
v=pop1(arr);
printf("%d\n",v);
a=pop2(arr,n);
printf("%d\n",a);
push2(arr,1);
b=pop2(arr,n);
printf("%d\n",b);
}
