#include<iostream>
using namespace std;

class rearrange{
private:
 int size;
 int *arr;

public:

rearrange(int n=4){
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
void positive_negative();
void display(){
 cout<<"The required array is"<<endl;
 for(int i=0;i<size;i++)
  cout<<arr[i]<<" ";
}
~rearrange(){
  delete [] arr;
}
};

void rearrange::positive_negative(){
 int i,j,temp,k;
 i=0;
 j=size-1;
 while(i<j){
  if(arr[i]<0){
   temp=arr[i];
   arr[i]=arr[j];
   arr[j]=temp;
   j--;
}
  else
   i++;
}

 if(arr[j]<0&&arr[j-1]<0)
  while(arr[j-1]<0)
   j--;
 
 else if(arr[j]>0)
  while(arr[j]>0)
   j++;

i=1;
while(j<size&&i<j&&arr[i]>0){
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
i+=2;
j++;
}
}
int main(void){
rearrange ob;
ob.get();
ob.positive_negative();
ob.display();
}
