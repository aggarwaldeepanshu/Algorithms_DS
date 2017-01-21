#include<iostream>
using namespace std;

class iterative{
private:
 int size;
 int *arr;

public:
 iterative(int n=4){
 size=n;
 arr=new int[size];
}
 void get(){
  cout<<"Enter the array size"<<endl;
  cin>>size;
  arr=new int[size];
  cout<<"Enter the values"<<endl;
  for(int i=0;i<size;i++)
  cin>>arr[i];
}
 void q_sort();

void display(){
  cout<<"Sorted array is"<<endl;
  for(int i=0;i<size;i++)
   cout<<arr[i]<<" ";
 cout<<endl;
}

~iterative(){
  delete [] arr;
}
};

int partition(int arr[],int low,int high){
 int temp,i,j,r;
  r=arr[high];
  i=low-1;
  for(j=low;j<high;j++){
   if(arr[j]<r){
     i++;
     temp=arr[i];
     arr[i]=arr[j];
     arr[j]=temp;
}
}
  temp=arr[i+1];
  arr[i+1]=r;
  arr[high]=temp;
  return i+1;
}

void iterative::q_sort(){
  int low=0,high,val;
  int stack[size-1];
  int top=-1;
  stack[++top]=low;
  stack[++top]=size-1;
  while(top>=0){
   high=stack[top--];
   low=stack[top--];
   val=partition(arr,low,high);
   if(low<val-1){
     stack[++top]=low;
     stack[++top]=val-1;
}
   if(high>val+1){
    stack[++top]=val+1;
    stack[++top]=high;
}
}
}

int main(void){
iterative obj;
 obj.get();
 obj.q_sort();
 obj.display();
}
