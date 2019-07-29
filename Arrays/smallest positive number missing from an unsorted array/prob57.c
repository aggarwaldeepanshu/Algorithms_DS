#include<stdio.h>
#include<stdlib.h>

int search(int arr[],int n);

int main(void){
int i,n,j,temp,x;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("Enter the values\n");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
//to separate negative and positive numbers
i=n-1;
j=0;
while(j<i){
   if(arr[i]<0){
   temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
   j++;
}
   else
   i--;
}
x=search(arr+j,n-j);
printf("Smallest positive number missing is %d\n",x);
}

int search(int arr[],int n){
int i;
for(i=0;i<n;i++){
   if(abs(arr[i])-1<n && arr[abs(arr[i])-1]>0)
   arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
}
for(i=0;i<n;i++){
    if(arr[i]>0)
    return i+1;
}
return n+1;
}
