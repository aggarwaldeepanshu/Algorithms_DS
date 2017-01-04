#include<stdio.h>

int empty();
int pop(int stack[]);
void push(int stack[],int v,int n);

int top=-1;
int main(void)
{
int i,n,val,v;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("Enter the values\n");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);

int stack[n];
push(stack,arr[0],n);
for(i=1;i<n;i++)
{
val=pop(stack);
while(val<arr[i])
{
printf("%d--%d\n",val,arr[i]);
if(!empty())
val=pop(stack);
else
break;
}
if(val>arr[i])
push(stack,val,n);

push(stack,arr[i],n);
}
while(!empty())
{
val=pop(stack);
printf("%d -- -1\n",val);
}
}
void push(int stack[],int v,int n)
{
if(top==n-1)
{
printf("Overflow\n");
}
else
{
top++;
stack[top]=v;
}
}
int pop(int stack[])
{
if(top==-1)
{
printf("Underflow\n");
return -1;
}
else
return stack[top--];
}
int empty()
{
if(top==-1)
return 1;
else 
return 0;
}
