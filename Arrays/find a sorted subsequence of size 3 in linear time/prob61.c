#include<stdio.h>

int main(void){
int i,n,min,max;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n],small[n],large[n];
printf("Enter the values\n");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
min=arr[0];
max=arr[n-1];
small[0]=-1;
large[n-1]=-1;
for(i=1;i<n;i++){
   if(arr[i]>min)
   small[i]=min;
   else if(arr[i]<=min){
   small[i]=-1;
   min=arr[i];
}
}
for(i=n-2;i>=0;i--){
   if(arr[i]<max)
   large[i]=max;
   else{
   large[i]=-1;
   max=arr[i];
}
}
int v=-1;
for(i=0;i<n;i++){
   if(large[i]!=-1 && small[i]!=-1){
   v=1;
   printf("%d %d %d\n",small[i],arr[i],large[i]);
}
}
if(v==-1)
printf("No such triplet\n");
}
