#include<stdio.h>

void q_sort(int arr[],int low,int high);
int search(int arr[],int low,int high,int v);
int partition(int arr[],int low,int high);
int main(void){

int i,j,n,v,sum,s,k,l=-1;
printf("Enter the size of array\n");
scanf("%d",&n);
int arr[n];
printf("Enter the values\n");
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
printf("Enter the sum\n");
scanf("%d",&sum);
q_sort(arr,0,n-1);
i=0;
j=n-1;
while(i<j){
s=arr[i]+arr[j];
if(s>=sum)
j--;
else{
   v=sum-s;
   k=search(arr,0,n-1,v);
   if(k==-1){
      if(v<arr[j])
       j--;
      else
      i++; 
}
  else{
  l=1;
  printf("%d %d and %d is the required triplet\n",arr[i],arr[j],arr[k]);
  break;
}  
}
}
if(l==-1)
printf("No such triplet exist\n");
}

int search(int arr[],int low,int high,int v){

int mid;

if(low<=high){

mid=(low+high)/2;
   if(arr[mid]==v)
    return mid;
   else if(arr[mid]>v)
   return search(arr,low,mid-1,v);
   else
   return search(arr,mid+1,high,v);
}
return -1;
}

void q_sort(int arr[],int low,int high){

int q;
if(low<high){

q=partition(arr,low,high);
q_sort(arr,low,q-1);
q_sort(arr,q+1,high);
}
}

int partition(int arr[],int low,int high){

int i,j,r,temp;
r=high;
i=low-1;
for(j=low;j<r;j++){

   if(arr[j]<arr[r]){
   i++;
   temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
}
}
temp=arr[i+1];
arr[i+1]=arr[r];
arr[r]=temp;
return i+1;
}
