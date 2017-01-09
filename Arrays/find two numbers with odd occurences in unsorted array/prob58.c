#include<stdio.h>

int main(void){
int i,n,x,y,a,xor;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("Enter the values\n");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
//take xor of all elements
xor=arr[0];
for(i=1;i<n;i++)
xor=xor^arr[i];
a=xor & ~(xor-1);
x=0;
y=0;
//to find the two odd occuring elements
for(i=0;i<n;i++){
   if(arr[i]&a){
   x=x^arr[i];
}
   else{
   y=y^arr[i];
}
}
printf("the two odd occuring elements are %d and %d\n",x,y);
}
